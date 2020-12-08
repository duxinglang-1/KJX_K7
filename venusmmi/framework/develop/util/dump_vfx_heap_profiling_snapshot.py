import os, sys
import re
import bisect

blockinfo={}
notObjlist=[]
rootObjlist=[]
padding="  "

intermedia_report_list=[]
objects = []
structs = []

def get_blockinfo(log_list):
    for ln in log_list :    		
        ln = ln.strip()        
        if not ln:
            continue
                 
        #for first line: "HeapMaxUsedSize xxxx"
        if ln.find('HeapMaxUsedSize') == 0:
        	intermedia_report_list.append(ln)        	        	        	
        	continue              	          
        	
        ele=ln.split(',')
        if len(ele) != 6:         
        	continue

        memAddr=int(ele[2],10)
        ele[5]=int(ele[5],16)                    	
        size = int(ele[3], 10) & 0xffffff
        overhead = (int(ele[3], 10) >> 24) + (int(ele[3], 10) & 0xffffff)
        	
        try :
            blockinfo[memAddr]['fname'] = ele[0]
            blockinfo[memAddr]['line'] = ele[1]                        
            blockinfo[memAddr]['size'] = size
            blockinfo[memAddr]['overhead'] = overhead
            blockinfo[memAddr]['vtable'] = ele[4]
            blockinfo[memAddr]['parent'] = ele[5]
            blockinfo[memAddr]['child'] = 0
            blockinfo[memAddr]['next'] = 0
        except KeyError:
              blockinfo[memAddr] = {'fname':ele[0], 'line':ele[1],'size':size,'overhead':overhead,'vtable':ele[4], 
              'parent':ele[5], 'child':0, 'next':0}
        if blockinfo[memAddr]['vtable'] == '0x0' and  blockinfo[memAddr]['parent'] == 0 :
            notObjlist.append(memAddr)             
        else:
            rootObjlist.append(memAddr) #currently rootObjlist is a objlist

def set_parent_child():
    for memAddr in blockinfo.keys() :
        if memAddr in notObjlist:
            continue
        parentAddr = blockinfo[memAddr]['parent']
        if parentAddr in blockinfo.keys() :  
            # find parent in blockinfo, so memAddr is not a root object
            rootObjlist.remove(memAddr)
            if blockinfo[parentAddr]['child']!=0 :
                #parent already have child, make a link list 
                childAddr = blockinfo[parentAddr]['child']
                blockinfo[memAddr]['next'] = childAddr
            #set self as parent's child    
            blockinfo[parentAddr]['child']=memAddr
       
def print_obj_tree(memAddr, lvl):
    intermedia_report_list.append("%s(%s*)0x%X %s %sByte allocated at %s, line:%s" %(padding*lvl, blockinfo[memAddr]['vtable'], memAddr, blockinfo[memAddr]['size'], blockinfo[memAddr]['overhead'], blockinfo[memAddr]['fname'], blockinfo[memAddr]['line']))
    if blockinfo[memAddr]['child']!=0 :
        print_obj_tree(blockinfo[memAddr]['child'], lvl+1)
    if blockinfo[memAddr]['next'] != 0:
        print_obj_tree(blockinfo[memAddr]['next'], lvl)

def print_notobj_allocate(memAddr):
    if blockinfo[memAddr]['fname'] == "" and blockinfo[memAddr]['line'] == "65535":
        intermedia_report_list.append("0x%X %sByte allocated at UNKNOWN " %(memAddr, blockinfo[memAddr]['size']))
    else:
        intermedia_report_list.append("0x%X %s %sByte allocated at %s, line:%s" %(memAddr, blockinfo[memAddr]['size'], blockinfo[memAddr]['overhead'], blockinfo[memAddr]['fname'], blockinfo[memAddr]['line']))


##############################################
#                heap_data_parser.py         #
##############################################

g_re_object = re.compile(r'(\s*)\(([\w:]+)\*\)0x[0-9A-F]{8}\s+(\d+)\s+(\d+)Byte allocated at ([\w:]+), line:(\d+)')
g_re_struct = re.compile(r'0x[0-9A-F]{8}\s+(\d+)\s+(\d+)Byte allocated at ([\w:]+), line:(\d+)')

class VfxObject:
    def __init__(self, lvl, cls, size, overhead, func, line):
        self.lvl = lvl
        self.cls = cls
        self.size = size
        self.overhead = overhead
        self.func = func
        self.line = line
        self.total_size = 0
        self.total_overhead = 0
        self.child = set()

    def total(self):
        if self.total_size:
            return self.total_size
            
        t = self.size
        for o in self.child:
            t += o.total()
        self.total_size = t
        return self.total_size
        
    def t_overhead(self):
        if self.total_overhead:
            return self.total_overhead
            
        t = self.overhead
        for o in self.child:
            t += o.t_overhead()
        self.total_overhead = t
        return self.total_overhead

    def print_row(self):
        print "%d\t%s\t%d\t%d\t%d\t%d\t%s\t%d\t" % (self.lvl, self.cls, self.total(), self.size, self.t_overhead(), self.overhead, self.func, self.line)
        
if __name__  == "__main__":
  
    fpath = sys.argv[1]
    #fpath = "t:\dump_vfx_heap_graph.txt"
    log_list = list(file(fpath))
    get_blockinfo(log_list)     
    set_parent_child()
    #print rootObjlist
    for memAddr in rootObjlist:    		
        print_obj_tree(memAddr,0)
    #print "\n"
    for memAddr in notObjlist:
        print_notobj_allocate(memAddr)
		

##############################################
#                heap_data_parser.py         #
##############################################

    for ln in intermedia_report_list:
    
        #for first line: "HeapMaxUsedSize xxxx"                  
        if ln.find('HeapMaxUsedSize') == 0:
        	ln=ln.strip()        	        	
        	print "\t%s" %(ln)
        	continue
        	
        m = g_re_object.match(ln)
        if m:
            lvl = len(m.group(1))/2
            cls = m.group(2)
            size = int(m.group(3))
            overhead = int(m.group(4))
            func = m.group(5)
            line = int(m.group(6))
            objects.append(VfxObject(lvl, cls, size, overhead, func, line))
            continue
            
        m = g_re_struct.match(ln)
        if m:
            size = int(m.group(1))
            overhead = int(m.group(2))
            func = m.group(3)
            line = int(m.group(4))
            structs.append([func, line, size, overhead])
            continue
        
        print >> sys.stderr, "No match:", ln.strip()

    root = VfxObject(-1, "", "", 0, "", 0)
    prev = root
    objstack = []
    max_lvl = 0
    for o in objects:
        if prev.lvl < o.lvl:    # child
            parent = prev
            objstack.append(prev)
                
        elif prev.lvl > o.lvl: # back
            objstack = objstack[:o.lvl - prev.lvl]
            parent = objstack[-1]

        parent.child.add(o)
        prev = o
        
        if o.lvl > max_lvl:
            max_lvl = o.lvl

    print >> sys.stderr, "Max lvl:", max_lvl

    for o in objects:
        o.print_row()        

    print ""
    structs.sort()
    for s in structs:
        print "%s\t%d\t%d\t%d" % (s[0], s[1], s[2], s[3])