/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sqlite3ex.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  This file is the header file of SQLite3 context.
 *  The purpose of this file is to provide sqlite context in different applications.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef SQLITE3_CONTEXT_H
#define SQLITE3_CONTEXT_H

#include "sqlite3.h"
#include "kal_release.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif //__MTK_TARGET

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

typedef unsigned int u32;           /* 4-byte unsigned integer */
typedef struct sqlite3_mutex sqlite3_mutex;
typedef struct Vdbe Vdbe;
/*
** Maximum size (in Mem3Blocks) of a "small" chunk.
*/
#define MX_SMALL 10


/*
** Number of freelist hash slots
*/
#define N_HASH  61

/*
** A memory allocation (also called a "chunk") consists of two or 
** more blocks where each block is 8 bytes.  The first 8 bytes are 
** a header that is not returned to the user.
**
** A chunk is two or more blocks that is either checked out or
** free.  The first block has format u.hdr.  u.hdr.size4x is 4 times the
** size of the allocation in blocks if the allocation is free.
** The u.hdr.size4x&1 bit is true if the chunk is checked out and
** false if the chunk is on the freelist.  The u.hdr.size4x&2 bit
** is true if the previous chunk is checked out and false if the
** previous chunk is free.  The u.hdr.prevSize field is the size of
** the previous chunk in blocks if the previous chunk is on the
** freelist. If the previous chunk is checked out, then
** u.hdr.prevSize can be part of the data for that chunk and should
** not be read or written.
**
** We often identify a chunk by its index in mem->aPool[].  When
** this is done, the chunk index refers to the second block of
** the chunk.  In this way, the first chunk has an index of 1.
** A chunk index of 0 means "no such chunk" and is the equivalent
** of a NULL pointer.
**
** The second block of free chunks is of the form u.list.  The
** two fields form a double-linked list of chunks of related sizes.
** Pointers to the head of the list are stored in mem->aiSmall[] 
** for smaller chunks and mem->aiHash[] for larger chunks.
**
** The second block of a chunk is user data if the chunk is checked 
** out.  If a chunk is checked out, the user data may extend into
** the u.hdr.prevSize value of the following chunk.
*/
typedef struct Mem3Block Mem3Block;
struct Mem3Block {
  union {
    struct {
      u32 prevSize;   /* Size of previous chunk in Mem3Block elements */
      u32 size4x;     /* 4x the size of current chunk in Mem3Block elements */
    } hdr;
    struct {
      u32 next;       /* Index in mem->aPool[] of next free chunk */
      u32 prev;       /* Index in mem->aPool[] of previous free chunk */
    } list;
  } u;
};


typedef struct PgHdr PgHdr;

/*
** Each pager stores all currently unreferenced pages in a list sorted
** in least-recently-used (LRU) order (i.e. the first item on the list has 
** not been referenced in a long time, the last item has been recently
** used). An instance of this structure is included as part of each
** pager structure for this purpose (variable Pager.lru).
**
** Additionally, if memory-management is enabled, all unreferenced pages 
** are stored in a global LRU list (global variable sqlite3LruPageList).
**
** In both cases, the PagerLruList.pFirstSynced variable points to
** the first page in the corresponding list that does not require an
** fsync() operation before its memory can be reclaimed. If no such
** page exists, PagerLruList.pFirstSynced is set to NULL.
*/
typedef struct PagerLruList PagerLruList;
struct PagerLruList {
  PgHdr *pFirst;         /* First page in LRU list */
  PgHdr *pLast;          /* Last page in LRU list (the most recently used) */
  PgHdr *pFirstSynced;   /* First page in list with PgHdr.needSync==0 */
};

/*
** The following structure contains the next and previous pointers used
** to link a PgHdr structure into a PagerLruList linked list. 
*/
typedef struct PagerLruLink PagerLruLink;
struct PagerLruLink {
  PgHdr *pNext;
  PgHdr *pPrev;
};

typedef struct Mem3Mng 
{
  /*
  ** True if we are evaluating an out-of-memory callback.
  */
  int alarmBusy;
  
  /*
  ** Mutex to control access to the memory allocation subsystem.
  */
  sqlite3_mutex *mutex;
  
  /*
  ** The minimum amount of free space that we have seen.
  */
  u32 mnMaster;

  /*
  ** iMaster is the index of the master chunk.  Most new allocations
  ** occur off of this chunk.  szMaster is the size (in Mem3Blocks)
  ** of the current master.  iMaster is 0 if there is not master chunk.
  ** The master chunk is not in either the aiHash[] or aiSmall[].
  */
  u32 iMaster;
  u32 szMaster;

  /*
  ** Array of lists of free blocks according to the block size 
  ** for smaller chunks, or a hash on the block size for larger
  ** chunks.
  */
  u32 aiSmall[MX_SMALL-1];   /* For sizes 2 through MX_SMALL, inclusive */
  u32 aiHash[N_HASH];        /* For sizes MX_SMALL+1 and larger */

  /*
  ** Memory available for allocation
  */
  u32 memsize;

  /*
  ** How much memory used for Cache 
  */
  u32 cacheSize;

  Mem3Block* aPool;
} Mem3Mng;


/*
** The following structure contains pointers to the end points of a
** doubly-linked list of all compiled SQL statements that may be holding
** buffers eligible for release when the sqlite3_release_memory() interface is
** invoked. Access to this list is protected by the SQLITE_MUTEX_STATIC_LRU2
** mutex.
**
** Statements are added to the end of this list when sqlite3_reset() is
** called. They are removed either when sqlite3_step() or sqlite3_finalize()
** is called. When statements are added to this list, the associated 
** register array (p->aMem[1..p->nMem]) may contain dynamic buffers that
** can be freed using sqlite3VdbeReleaseMemory().
**
** When statements are added or removed from this list, the mutex
** associated with the Vdbe being added or removed (Vdbe.db->mutex) is
** already held. The LRU2 mutex is then obtained, blocking if necessary,
** the linked-list pointers manipulated and the LRU2 mutex relinquished.
*/
typedef struct StatementLruList {
  Vdbe *pFirst;
  Vdbe *pLast;
} StatementLruList;

typedef struct Pager Pager;
typedef struct BtShared BtShared;


/*
** The following object holds the list of automatically loaded
** extensions.
**
** This list is shared across threads.  The SQLITE_MUTEX_STATIC_MASTER
** mutex must be held while accessing this list.
*/
typedef struct Sqlite3LoadExt {
  int nExt;        /* Number of entries in aExt[] */          
  void **aExt;     /* Pointers to the extension init functions */
} 
Sqlite3LoadExt;

typedef struct sqlite3_instance
{
    Mem3Mng mem;

    /*
    ** The following variable points to the head of a double-linked list
    ** of all pagers that are eligible for page stealing by the
    ** sqlite3_release_memory() interface.  Access to this list is
    ** protected by the SQLITE_MUTEX_STATIC_MEM2 mutex.
    */
    Pager *             sqlite3PagerList;
    PagerLruList        sqlite3LruPageList;
    StatementLruList    sqlite3LruStatements;

    /*
    ** A flag to indicate whether or not shared cache is enabled.  Also,
    ** a list of BtShared objects that are eligible for participation
    ** in shared cache.  The variables have file scope during normal builds,
    ** but the test harness needs to access these variables so we make them
    ** global for test builds.
    */
    BtShared *          sqlite3SharedCacheList;
    int                 sqlite3SharedCacheEnabled;

    Sqlite3LoadExt      autoext;

    /*
    **  useful debug information
    */
    int                 db_count;
    int                 statement_count;

    /*
    **  default cache size
    */
    int					default_cache_size;
    int					default_temp_cache_size;    

    int                 taskid;
	kal_mutexid			mutex;
    int                 enterCount;
    struct sqlite3_instance *prev, *next;


    /*
    **  for recursive enter
    */
    struct sqlite3_instance *original;

    /*
    **  for recursive enter
    */
    char *sqlite3_temp_directory;

    /*
    **  FS error code for the last I/O error
    **  When sqlite API returns SQLITE_IOERR or one of its extended results,
    **  app may use sqlite3_instance_get_last_error(instance) to fetch this value.
    */
    int last_io_error;
    int fsal_buffer_size;
    int fsalCount;
} 
sqlite3_instance;

/*
**  Return Instance according to current task
*/
sqlite3_instance* sqlite3_get_instance(void);

/*
**  Initialize the instance, you must pass a buffer as working memory, and its size as well
**		if mutex is not NULL, that means instance will take/give mutex when enter/leave instance
*/
void    sqlite3_init_instance(sqlite3_instance* instance, void* buffer, int buffersize, kal_mutexid mutex);

/*
**  Config fsal buffer size to use fsal
*/
void sqlite3_set_fsal_buffer_size(sqlite3_instance* instance, int size);

/*
**  Set default cache size (in bytes) for table and temp table
*/
void    sqlite3_instance_set_default_cache_size(sqlite3_instance* instance, int default_cache_size);

/*
**  Free instance, the function will return the working buffer pointer, so that you can free this memory
*/
void*   sqlite3_free_instance(sqlite3_instance* instance);

/*
**  Declare this task is going to use sqlite via this instance
*/
void    sqlite3_enter_instance(sqlite3_instance* instance);

/*
**  This task will not use sqlite
*/
void    sqlite3_leave_instance(sqlite3_instance* instance);


/*
**  sqlite3_exit_instance is old name, make it compatible with old API
*/
#define sqlite3_exit_instance sqlite3_leave_instance

#define SQLITE3_ASSERT(a)    if(!(a)) { kal_assert_fail(#a, __FILE__, __LINE__, 0, 0, 0, 0, 0); }

/*
**  This function return the total time about IO if IO_VERVOSE_TRACE turn on.
*/
extern int sqlite3_get_IOTick(void);

/*
**  This function reset the total time about IO if IO_VERVOSE_TRACE turn on.
*/
extern void sqlite3_reset_IOTick(void);

/*
**  This function returns the KAL FS error code for the last file I/O operation.
**  Value returned by this function is only valid if the SQLite function returns SQLITE_IOERR or one of its extended results.
**  eg. SQLITE_IOERR_READ, SQLITE_IOERR_WRITE, SQLITE_IOERR_XXX...
*/
extern int sqlite3_instance_get_last_io_error(sqlite3_instance* instance);

#endif

