#!/usr/local/bin/perl -w

use Data::Dumper;
use Encode;
use File::Basename;
use Getopt::Std;
use XML::Parser;
use XML::Simple;
use File::stat;
use File::Compare;
use File::Copy;
use IPC::Open3;
use Symbol qw(gensym);
use IO::File;


&PrintDependency($0);

#############################################################################
#
# Config
#
#############################################################################

# Global Settings
my $g_configVersionMajor            = 1;
my $g_configVersionMinor            = 0;
my $g_configDebug                   = 0;        # Print debug messages
my $g_configExport                  = 0;        # Output tables (.i)
my $g_configExportPostprocess       = undef;    # The command after export
my $g_configPreprocess              = 1;        # Do XML preprocess


#
# Input Files
#
my $g_configInMapPath               = 'map.i';
my $g_configResIdHeader             = undef;
my $g_configPropTypeDefFile         = 'vfx_xml_prop_type_def.xml';
my $g_configTablePath               = '.';
my $g_configExportFile              = 'vfx_xml_export.xml';
my $g_configInputFile               = undef;

#
# Output Files
#
my $g_configOutputDefFile           = 'vfx_xml_enum.i';
my $g_configOutputTableFile         = 'vfx_xml_table.i';
my $g_configOutBinPath              = undef;
my $g_configOutLisPath              = undef;

#
# Output Settings
#
my $g_configIndent                  = ' ' x 4;
my $g_configOutputBytesPerLine      = 8;

# Enum Table Settings
my $g_configEnumTypeNameUnknown     = 'Unknown';
my $g_configEnumValueIdEnumName     = 'VfxXmlEnumIdEnum';
my $g_configEnumValueIdEnumPrefix   = 'VFX_XML_ENUM_ID_';
my $g_configEnumValueNameUnknown    = 'Unknown';
my $g_configEnumValueTableName      = 'g_vfx_XmlEnumValueTable';

#
# Struct Table Settings
#
my $g_configStructIdEnumName        = 'VfxXmlStructIdEnum';
my $g_configStructIdEnumPrefix      = 'VFX_XML_STRUCT_ID_';
my $g_configStructNameUnknown       = 'Unknown';
my $g_configStructTableName         = 'g_vfxXmlStructTable';

#
# Struct Member Table Settings
#
my $g_configMemberIdEnumName        = 'VfxXmlStructMemberIdEnum';
my $g_configMemberIdEnumPrefix      = 'VFX_XML_STRUCT_MEMBER_ID_';
my $g_configMemberNameUnknown       = 'Unknown';
my $g_configMemberTableName         = 'g_vfxXmlStructMemberTable';

#
# Class Table Settings
#
my $g_configClassIdEnumName         = 'VfxXmlClassIdEnum';
my $g_configClassIdEnumPrefix       = 'VFX_XML_CLASS_ID_';
my $g_configClassNameUnknown        = 'Unknown';
my $g_configClassTableName          = 'g_vfxXmlClassTable';

#
# Class Property Table Settings
#
my $g_configPropertyIdEnumName      = 'VfxXmlPropIdEnum';
my $g_configPropertyIdEnumPrefix    = 'VFX_XML_PROP_ID_';
my $g_configPropertyNameUnknown     = 'Unknown';
my $g_configPropertyTableName       = 'g_vfxXmlPropertyTable';

#
# Class Property Table Settings
#
my $g_configSlotIdEnumName      = 'VfxXmlSlotIdEnum';
my $g_configSlotIdEnumPrefix    = 'VFX_XML_SLOT_ID_';
my $g_configSlotNameUnknown     = 'Unknown';
my $g_configSlotTableName       = 'g_vfxXmlSlotTable';

#
# Color table
#
my $g_colorInfo =
{
    black       => { a=>255, r=>0,   g=>0,   b=>0}  ,
    white       => { a=>255, r=>255, g=>255, b=>255},
    red         => { a=>255, r=>255, g=>0,   b=>0}  ,
    green       => { a=>255, r=>0,   g=>255, b=>0}  ,
    blue        => { a=>255, r=>0,   g=>0,   b=>255},
    aqua        => { a=>255, r=>0,   g=>255, b=>255},
    fuchsia     => { a=>255, r=>255, g=>0,   b=>255},
    yellow      => { a=>255, r=>255, g=>255, b=>0}  ,
    grey        => { a=>255, r=>128, g=>128, b=>128},
    teal        => { a=>255, r=>0,   g=>128, b=>128},
    purple      => { a=>255, r=>128, g=>0,   b=>128},
    olive       => { a=>255, r=>128, g=>128, b=>0}  ,
    silver      => { a=>255, r=>192, g=>192, b=>192},
    transparent => { a=>0,   r=>0,   g=>0,   b=>255}
};

#############################################################################
#
# Global Variable
#
#############################################################################

# Enum Table
my $g_unknownEnumTypeInfo =
{
    name        =>  $g_configEnumTypeNameUnknown
};

my $g_unknownEnumValueInfo =
{
    enumId      =>  0,
    name        =>  $g_configEnumValueNameUnknown,
    enumName    =>  $g_configEnumValueIdEnumPrefix.$g_configEnumValueNameUnknown,
    type        =>  undef
};

my $g_enumTypeTable = { $g_configEnumTypeNameUnknown => $g_unknownEnumTypeInfo };
my $g_enumValueArray = [ $g_unknownEnumValueInfo ];
my $g_enumValueTable = { g_configEnumValueNameUnknown => $g_unknownEnumValueInfo };


# Struct Table
my $g_unknownMemberInfo =
{
    memberId    =>  0,
    name        =>  $g_configMemberNameUnknown,
    enumName    =>  $g_configMemberIdEnumPrefix.$g_configMemberNameUnknown,
    type        =>  undef,
    struct      =>  undef
};

my $g_unknownStructInfo =
{
    structId    => 0,
    name        => $g_configStructNameUnknown,
    enumName    => $g_configStructIdEnumPrefix.$g_configStructNameUnknown,
    memberTable => {}
};

my $g_structArray = [ $g_unknownStructInfo ];
my $g_structTable = { g_configStructNameUnknown => $g_unknownStructInfo };
my $g_memberArray = [ $g_unknownMemberInfo ];
my $g_mappingTable = {};

#
# Class Table
#
my $g_unknownPropertyInfo =
{
    propertyId  =>  0,
    propType    =>  'unknown',
    name        =>  $g_configPropertyNameUnknown,
    enumName    =>  $g_configPropertyIdEnumPrefix.$g_configPropertyNameUnknown,
    type        =>  undef,
    class       =>  undef,
    method      =>  undef
};

my $g_unknownSlotInfo =
{
    slotId  =>  0,
    name        =>  $g_configSlotNameUnknown,
    enumName    =>  $g_configSlotIdEnumPrefix.$g_configSlotNameUnknown,
    type        =>  undef,
    class       =>  undef
};

my $g_unknownClassInfo =
{
    classId     =>  0,
    name        =>  $g_configClassNameUnknown,
    enumName    =>  $g_configClassIdEnumPrefix.$g_configClassNameUnknown,
    parent      =>  undef,
    isAbstract  =>  0,
    propTable   =>  {}
};

my $g_classArray    = [ $g_unknownClassInfo ];
my $g_classTable    = { $g_configClassNameUnknown => $g_unknownClassInfo };
my $g_propertyArray = [ $g_unknownPropertyInfo ];
my $g_slotArray     = [ $g_unknownSlotInfo ];

my $g_errorFlag = 0;


#############################################################################
#
# Regular Expressions
#
#############################################################################

my $optSp       = qr/\s*/;
my $regHexCh    = qr/[0-9a-fA-F]/;
my $regInteger  = qr/[+-]?(?:0|[1-9][0-9]*)/;
my $regPosInteger = qr/(?:0|[1-9][0-9]*)/;
my $regFloat    = qr/[+-]?(?:(?:0|[1-9][0-9]*)(?:\.[0-9]*)?|\.[0-9]+)/;
my $regString1  = qr/'[^']*'/;
my $regString2  = qr/"[^"]*"/;
my $regString   = qr/$(?:regString1|$regString2)/;
my $regVarName  = qr/[_A-Za-z][_A-Za-z0-9]*/;
my $regResource = "$regInteger|\@$regVarName";


#############################################################################
#
# Parse Handler
#
#############################################################################

sub parseEnumValue
{
    my $valueStr = shift;

    # Search on the enum value table
    my $enumValueInfo = $g_enumValueTable->{$valueStr};
    if (!defined $enumValueInfo)
    {
        return undef
    }

    # Return the enum ID
    return $enumValueInfo->{enumId};
}


sub parseString
{
    my $valueStr = shift;

    # return all string    
    return $valueStr;
}


sub parseResource
{
    my $valueStr = shift;
    my $parser = shift;

    if (!defined $valueStr)
    {
        return undef;
    }

    if ($valueStr =~ /^$regInteger$/)
    {
        # ex. '123'
        return $valueStr;
    }
    else
    {
        # ex. '@STR_ID_HELLO'
        my $v = substr ($valueStr, 1);

        if (not exists $g_mappingTable->{$v})
        {
            outputErrorMessage($parser, "Resource id not found: '$v'");
            return undef;
        }
        
        return $g_mappingTable->{$v};
    }
}


sub parseVfxBool
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*(true)\s*$/i)
    {
        # ex. 'true'
        $value = 1;
    }
    elsif ($valueStr =~ /^\s*(false)\s*$/i)
    {
        # ex. 'false'
        $value = 0;
    }
    elsif ($valueStr =~ /^\s*[01]\s*$/)
    {
        # ex. '1', '0'
        $value = $1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxBool($value)\n" if $g_configDebug;
    
    return $value;
}


sub parseVfxFloat
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regFloat)\s*$/)
    {
        # ex. '123.4'
        $value = $1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxFloat($value)\n" if $g_configDebug;
    
    return $value;
}


sub parseVfxS32
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regInteger)\s*$/)
    {
        # ex. '123'
        $value = $1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxS32($value)\n" if $g_configDebug;
    
    return $value;
}

sub parseVfxU32
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regPosInteger)\s*$/)
    {
        # ex. '123'
        $value = $1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxU32($value)\n" if $g_configDebug;
    
    return $value;
}

sub parseVfxId
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regPosInteger)\s*$/)
    {
        # ex. '123'
        $value = $1;
    }
    elsif (($valueStr =~ /^\s*'([^']{1,4})'\s*$/) ||
          ($valueStr =~ /^\s*"([^"]{1,4})"\s*$/))
    {
        # ex. "'FOUR'" or '"FOUR"'
        my $parseStr = $1;
        my $v;
        while (1) {
            $v = ord($parseStr);
            last if ($v == 0);
            $value = ($value << 8) + $v;
            $parseStr = substr($parseStr, 1);
        }
    }
    elsif ($valueStr =~ /^\s*0x($regHexCh+)\s*$/)
    {
        # ex. '#123456'
        $value = oct '0x'.$1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxId($value)\n" if $g_configDebug;
    
    return $value;
}

sub parseVfxMsec
{
    my $valueStr = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regInteger)s\s*$/)
    {
        # ex. '123s'
        $value = $1 * 1000;
    }
    elsif ($valueStr =~ /^\s*($regInteger)(ms)?\s*$/)
    {
        # ex. '123ms', '123'
        $value = $1;
    }
    else
    {
        return undef;
    }

    print "\t\tVfxMSec($value)\n" if $g_configDebug;
    
    return $value;
}


sub parseVfxColor
{
    my $valueStr = shift;
    my $a = 255;
    my $r = 0;
    my $g = 0;
    my $b = 0;

    if ($valueStr =~ /^\s*#($regHexCh{6})\s*$/)
    {
        # ex. '#123456'
        $r = oct '0x'.substr($1, 0, 2);
        $g = oct '0x'.substr($1, 2, 2);
        $b = oct '0x'.substr($1, 4, 2);
    }
    elsif ($valueStr =~ /^\s*#($regHexCh{8})\s*$/)
    {
        # ex. '#12345678'
        $a = oct '0x'.substr($1, 0, 2);
        $r = oct '0x'.substr($1, 2, 2);
        $g = oct '0x'.substr($1, 4, 2);
        $b = oct '0x'.substr($1, 6, 2);
    }
    elsif (defined $g_colorInfo->{$valueStr})
    {
        # ex. 'white', 'black', etc...
        # see g_colorInfo for all color support
        $a = $g_colorInfo->{$valueStr}->{a};
        $r = $g_colorInfo->{$valueStr}->{r};
        $g = $g_colorInfo->{$valueStr}->{g};
        $b = $g_colorInfo->{$valueStr}->{b};
    }
    else 
    {
        return undef;
    }

    my $value = ($a << 24) + ($r << 16) + ($g << 8) + $b;

    print "\t\tVfxColor(".sprintf("0x%08x", $value).")\n" if $g_configDebug;
    
    return $value;
}


sub parseVfxPoint
{
    my $valueStr = shift;
    my ($x, $y) = (0, 0);
    
    if ($valueStr =~ /^\s*\(\s*($regInteger)\s*,\s*($regInteger)\s*\)\s*$/)
    {
        # ex. '(12, 34)'
        ($x, $y) = ($1, $2);        
    }
    else
    {
        return undef;
    }

    print "\t\tVfxPoint($x, $y)\n" if $g_configDebug;

    return { x => $x, y => $y };
}


sub parseVfxSize
{
    my $valueStr = shift;
    my ($width, $height) = (0, 0);
    
    if ($valueStr =~ /^\s*\(\s*($regInteger)\s*,\s*($regInteger)\s*\)\s*$/)
    {
        # ex. '(12, 34)'
        ($width, $height) = ($1, $2);
    }
    else
    {
        return undef;
    }

    print "\t\tVfxPoint($width, $height)\n" if $g_configDebug;

    return { width => $width, height => $height };
}


sub parseVfxRect
{
    my $valueStr = shift;
    my ($x, $y, $width, $height) = (0, 0, 0, 0);

    if ($valueStr =~ /^\s*\(\s*($regInteger)\s*,\s*($regInteger)\s*,\s*($regInteger)\s*,\s*($regInteger)\s*\)\s*$/)
    {
        # ex. '(12, 34, 56, 78)'
        ($x, $y, $width, $height) = ($1, $2, $3, $4);
    }
    else
    {
        return undef;
    }

    print "\t\tVfxRect($x, $y, $width, $height)\n" if $g_configDebug;

    return { x => $x, y => $y, width => $width, height => $height };
}


sub parseVfxFPoint
{
    my $valueStr = shift;
    my ($x, $y) = (0, 0);
    
    if ($valueStr =~ /^\s*\(\s*($regFloat)\s*,\s*($regFloat)\s*\)\s*$/)
    {
        # ex. '(12, 34)'
        ($x, $y) = ($1, $2);        
    }
    else
    {
        return undef;
    }

    print "\t\tVfxFPoint($x, $y)\n" if $g_configDebug;

    return { x => $x, y => $y };
}


sub parseVfxResId
{
    my $valueStr = shift;
    my $parser = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regInteger)\s*$/)
    {
        # ex. '123'
        $value = $1;
    }
    elsif ($valueStr =~ /^\s*(\@$regVarName)\s*$/)
    {
        # ex. '@STR_ID_HELLO'
        $value = parseResource($1, $parser);
        if(!defined $value)
        {
            return undef;
        }
    }
    else
    {
        return undef;
    }

    print "\t\tVfxResId($value)\n" if $g_configDebug;
    
    return $value;
}


sub parseVfxWString
{
    my $valueStr = shift;
    my $parser = shift;
    my $str = undef;
    my $resId = undef;

    if ($valueStr =~ /^\s*'([^']*)'\s*$/)
    {
        # ex. "'Hello World!'"
        $str = $1;
    }
    elsif ($valueStr =~ /^\s*"([^"]*)"\s*$/)
    {
        # ex. '"Hello World!"'
        $str = $1;
    }
    elsif ($valueStr =~ /^\s*($regInteger)\s*$/)
    {
        # ex. '123'
        $resId = $1;
    }
    elsif ($valueStr =~ /^\s*(\@$regVarName)\s*$/)
    {
        # ex. '@STR_ID_HELLO'
        $resId = parseResource($1, $parser);
        if(!defined $resId)
        {
            return undef;
        }
    }
    elsif ($valueStr =~ /^(.*)$/)
    {
        # ex. 'Hello World!'
        $str = $1;
    }
    else
    {
        return undef;
    }

    if (defined $str)
    {
        print "\t\tVfxWString('$str')\n" if $g_configDebug;
    }
    if (defined $resId)
    {
        print "\t\tVfxWString($resId)\n" if $g_configDebug;
    }
    
    return { str => $str, res_id => $resId};
}


sub parseVfxXmlIdSignal
{
    my $valueStr = shift;
    my $parser = shift;
    my $value = 0;

    if ($valueStr =~ /^\s*($regVarName)\s*$/)
    {
        # ex. 'clickHandler'

        # TODO: fix this
        my $rootClass = $parser->{objRefStack}->[3]->{className};
        
        # check if root object has this Slot
        if (exists $g_classTable->{$rootClass}->{slotTable}->{$1})
        {
            $value = $g_classTable->{$rootClass}->{slotTable}->{$1}->{slotId};
        }
        else
        {
            return undef;
        }
    }
    else
    {
        return undef;
    }

    print "\t\tVfxIdSignal($value)\n" if $g_configDebug;
    
    return $value;
}

sub parseVfxImageSrc
{
    my $valueStr = shift;
    my $parser = shift;
    my $value = undef;

    if ($valueStr =~ /^\s*($regResource)\s*$/)
    {
        # ex. "123" or "@IMG_GLOBAL_L1"
        $value = parseResource($1, $parser);
        if(!defined $value)
        {
            return undef;
        }
    }
    else
    {
        return undef;
    }
    
    print "\t\tVfxImageSrc($value)\n" if $g_configDebug;
    
    return $value;
}

sub parseVcpStateImage
{
    my $valueStr = shift;
    my $parser = shift;

    my $normalResId = undef;
    my $pressedResId = undef;
    my $disabledResId = undef;
    my $highlightResId = undef;
    
    if ($valueStr =~ /^\s*\(\s*($regResource)\s*\,\s*($regResource)\s*\,\s*($regResource)\s*\,\s*($regResource)\s*\)\s*$/)
    {
        # ex. "(0,0,0,0)" or "(@IMG_GLOBAL_L1, 0, @IMG_GLOBAL_L2, 0)"
        $normalResId    = parseResource($1, $parser);
        $pressedResId   = parseResource($2, $parser);
        $disabledResId  = parseResource($3, $parser);
        $highlightResId = parseResource($4, $parser);
        if(!defined $normalResId or !defined $pressedResId or !defined $disabledResId or !defined $highlightResId)
        {
            return undef;
        }
    }
    elsif ($valueStr =~ /^\s*($regResource)\s*$/)
    {
        # ex. "123" or "@IMG_GLOBAL_L1"
        $normalResId = parseResource($1, $parser);
        if(!defined $normalResId)
        {
            return undef;
        }
    }
    else
    {
        return undef;
    }
    
    if($g_configDebug)
    {
        my $debugmsg = (defined $normalResId ? $normalResId : '0').','.
                       (defined $pressedResId ? $pressedResId : '0').','.
                       (defined $disabledResId ? $disabledResId : '0').','.
                       (defined $highlightResId ? $highlightResId : '0');
        print "\t\tVcpStateImage($debugmsg)\n"
    }
    
    return { 
            normal => $normalResId, pressed => $pressedResId, 
            disabled => $disabledResId, highlight => $highlightResId
        };
}


sub parseAlignEnum
{
    my $valueStr = shift;
    my $parser = shift;

    if ($valueStr eq "none")
    {
        return 0;
    }
    elsif ($valueStr eq "side")
    {
        return 1;
    }
    elsif ($valueStr eq "middle")
    {
        return 2;
    }
    else
    {
        outputErrorMessage($parser, "Invalid align enum (use none, side, middle): '$valueStr'");
        return undef;
    }
}


sub parseVfxFrameAlignStruct
{
    my $valueStr = shift;
    my $parser = shift;

    my $modeLeft    = 0;
    my $modeTop     = 0;
    my $modeRight   = 0;
    my $modeBottom  = 0;

    if ($valueStr =~ /^\s*([a-z]+)\s+([a-z]+)\s+([a-z]+)\s+([a-z]+)\s*$/)
    {
        # ex. 'side side side side'
        $modeLeft = parseAlignEnum($1);
        return undef if !defined $modeLeft;
        $modeTop = parseAlignEnum($2);
        return undef if !defined $modeTop;
        $modeRight = parseAlignEnum($3);
        return undef if !defined $modeRight;
        $modeBottom = parseAlignEnum($4);
        return undef if !defined $modeBottom;
    }
    elsif ($valueStr =~ /^\s*(dock|center|top-dock|left-center)\s*$/)
    {
        # ex. alias such as 'dock'
        if ($1 eq 'dock')
        {
            $modeLeft = $modeTop = $modeRight = $modeBottom = parseAlignEnum('side');
        }
        elsif ($1 eq 'center')
        {
            $modeLeft = $modeTop = $modeRight = $modeBottom = parseAlignEnum('middle');
        }
        elsif ($1 eq 'top-dock')
        {
            $modeLeft = $modeTop = $modeRight = parseAlignEnum('side');
            $modeBottom = parseAlignEnum('none');
        }
        elsif ($1 eq 'left-center')
        {
            $modeLeft = parseAlignEnum('side');
            $modeTop = $modeBottom = parseAlignEnum('middle');
            $modeRight = parseAlignEnum('none');
        }
    }
    else
    {
        # ex. 'left:side, top:side'
        foreach $value (split(/,/, $valueStr))
        {
            if ($value =~ /^\s*(left|top|right|bottom)\s*\:(none|side|middle)\s*$/)    
            {
                $modeLeft = parseAlignEnum($2) if ($1 eq 'left');
                $modeTop = parseAlignEnum($2) if ($1 eq 'top');
                $modeRight = parseAlignEnum($2) if ($1 eq 'right');
                $modeBottom = parseAlignEnum($2) if ($1 eq 'bottom');
            }
            else
            {
                outputErrorMessage($parser, "Invalid align format: '$value'");
                return undef;
            }
        }        
    }

    print "\tVfxFrameAlignStruct($modeLeft, $modeTop, $modeRight, $modeBottom)\n" if $g_configDebug;
    
    return { 
            left => $modeLeft, top => $modeTop, 
            right => $modeRight, bottom => $modeBottom
        };
}


sub exportS32
{
    my $value = shift;

    return pack('i', $value);
}


sub exportU32
{
    my $value = shift;

    return pack('L', $value);
}


sub exportFloat
{
    my $value = shift;

    return pack('f', $value);
}


sub exportVfxPoint
{
    my $valueRef = shift;
    my $x = $valueRef->{x};
    my $y = $valueRef->{y};

    return pack('ii', $x, $y);
}


sub exportVfxSize
{
    my $valueRef = shift;
    my $width = $valueRef->{width};
    my $height = $valueRef->{height};

    return pack('ii', $width, $height);
}


sub exportVfxRect
{
    my $valueRef = shift;
    my $x = $valueRef->{x};
    my $y = $valueRef->{y};
    my $width = $valueRef->{width};
    my $height = $valueRef->{height};

    return pack('iiii', $x, $y, $width, $height);
}


sub exportVfxFPoint
{
    my $valueRef = shift;
    my $x = $valueRef->{x};
    my $y = $valueRef->{y};

    return pack('ff', $x, $y);
}


sub exportVfxResId
{
    my $value = shift;

    return pack('i', $value);
}


sub exportVfxWString
{
    my $value = shift;
    my $str     = $value->{str};
    my $resId   = $value->{res_id};

    if (defined $str)
    {
        my $len = length $str;
        my $ret = pack('i', 0x0002 | ($len << 16));
        $ret .= encode("UCS-2LE", $str);
        $ret .= encode("UCS-2LE", "\0") x (1 + (1 - $len % 2));
        return $ret;
    }
    elsif (defined $resId)
    {
        return pack('i', 0x0001 | ($resId << 16));
    }

    return pack('i', 0x0000);
}

sub exportVcpStateImage
{
    my $value = shift;
    my $normalId    = $value->{normal};
    my $pressedId   = $value->{pressed};
    my $disabledId  = $value->{disabled};
    my $highlgihtId = $value->{highlight};

    if (defined $normalId && !defined $pressedId && !defined $disabledId && !defined $highlgihtId)
    {
        return pack('i', 0x0001 | ($normalId << 16));
    }
    elsif (defined $normalId || defined $pressedId || defined $disabledId || defined $highlgihtId)
    {
        my $first = (defined $normalId ? $normalId : 0) | ((defined $pressedId ? $pressedId : 0) << 16);
        my $second = (defined $disabledId ? $disabledId : 0) | ((defined $highlgihtId ? $highlgihtId : 0) << 16);
            
        return pack('iii', 0x0002, $first, $second);
    }
    
    return pack('i', 0x0000);
}

sub exportVfxFrameAlignStruct
{
    my $value = shift;
    my $modeLeft    = $value->{left};
    my $modeTop     = $value->{top};
    my $modeRight   = $value->{right};
    my $modeBottom  = $value->{bottom};

    return pack('i', ($modeLeft) | ($modeTop<<8) | ($modeRight<<16) | ($modeBottom<<24));
}


# Primitive type table
my $g_typeTable = 
{
    '__String' =>
    {
        _value      => \&parseString
    },

    '__Enum' =>
    {
        _export     => \&exportS32,
        _value      => \&parseEnumValue
    },

    'VfxBool' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxBool
    },
    
    'VfxS32' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxS32
    },

    'VfxU32' =>
    {
        _export     => \&exportU32,
        _value      => \&parseVfxU32
    },

    'VfxId' =>
    {
        _export     => \&exportU32,
        _value      => \&parseVfxId
    },
    
    'VfxMsec' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxMsec
    },
    
    'VfxFloat' =>
    {
        _export     => \&exportFloat,
        _value      => \&parseVfxFloat
    },
    
    'VfxColor' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxColor
    },
    
    'VfxPoint' => 
    {
        _export     => \&exportVfxPoint,
        _value      => \&parseVfxPoint,
        x           => 'VfxS32',
        y           => 'VfxS32'
    },

    'VfxSize' =>
    {
        _export     => \&exportVfxSize,
        _value      => \&parseVfxSize,
        width       => 'VfxS32',
        height      => 'VfxS32'
    },
    
    'VfxRect' => 
    {
        _export     => \&exportVfxRect,
        _value      => \&parseVfxRect,
        x           => 'VfxS32',
        y           => 'VfxS32',
        width       => 'VfxS32',
        height      => 'VfxS32'
    },

    'VfxFPoint' => 
    {
        _export     => \&exportVfxFPoint,
        _value      => \&parseVfxFPoint,
        x           => 'VfxFloat',
        y           => 'VfxFloat',
    },

    'VfxResId' =>
    {
        _export     => \&exportVfxResId,
        _value      => \&parseVfxResId,
    },

    'VfxWString' =>
    {
        _export     => \&exportVfxWString,
        _value      => \&parseVfxWString,
        res_id      => 'VfxResId',
        str         => '__String'
    },

    'VfxXmlIdSignal' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxXmlIdSignal,
    },
    
    'VfxImageSrc' =>
    {
        _export     => \&exportS32,
        _value      => \&parseVfxImageSrc,
    },
    
    # kind of strange to support a vcp type?
    'VcpStateImage' =>
    {
        _export     => \&exportVcpStateImage,
        _value      => \&parseVcpStateImage,
    },

    'VfxFrameAlignStruct' =>
    {
        _export     => \&exportVfxFrameAlignStruct,
        _value      => \&parseVfxFrameAlignStruct,
    },

    'ObjName' =>
    {
        _export     => \&exportVfxWString,
        _value      => \&parseVfxWString,
    }
};


#############################################################################
#
# Functions
#
#############################################################################

sub dumpData
{
    my $data = shift;

    my $dumper = new Data::Dumper([$data]);
    $dumper->Indent(1);

    print $dumper->Dump;

    my $classId = 1;
}


sub loadMappingFile
{
    my $filename = shift;

    print "[Load mapping file: $filename]\n" if $g_configDebug;
    
    open FILE, "<$filename" or
        die "Error: Can not opern mapping file: $filename\n";
    &PrintDependency($filename);
    while (<FILE>)
    {
        chomp;

        my $line = $_;        
        if ($line =~ /^\s*($regVarName)\s*=\s*(\d+)$/)
        {
            $g_mappingTable->{$1} = $2;
        }
    }

    print "[Mapping Table]\n" if $g_configDebug;
    dumpData($g_mappingTable) if $g_configDebug;
}


sub loadResIdHeader
{
    my $filename = shift;

    print "[Load mapping header: $filename]\n" if $g_configDebug;
    
    open FILE, "<$filename" or
        die "Error: Can not oper mapping header: $filename\n";
    &PrintDependency($filename);
    while (<FILE>)
    {
        chomp;

        my $line = $_;        
        if ($line =~ /^\s*#define\s+($regVarName)\s+(\d+)\s*$/)
        {
            $g_mappingTable->{$1} = $2;
        }
    }

    print "[Mapping Header]\n" if $g_configDebug;
    dumpData($g_mappingTable) if $g_configDebug;
}


sub preprocessXmlFile
{
    my $outputFile = shift;
    my $inputFile = shift;
    
    print "[Pre-process export file: $inputFile]\n" if $g_configDebug;

    -e $inputFile or
        die "'$inputFile' does not exist.\n";

    my @args = (
        "../../../tools/python25/python", 
        "../../../tools/py/prexml.py",
        $inputFile,
        $outputFile
    );
    while(my $py = <../../../tools/py/*.py>)
    {
        &PrintDependency($py);
    }
    &PrintDependency($inputFile);

    system(@args) == 0 or 
        die "Error: system( @args )\nError: failed: $?";
}


sub postprocessExportFile
{
    my $command = shift;
    my $exportPath = shift;
    
    my @args = ( $command, $exportPath );
    
    system(@args) == 0 or
        die "Error: system( @args )\nError: failed: $?";
}


sub loadExportFile
{
    my $filename = shift;
    my $displayFilename = shift;
    
    $displayFilename = $filename if (!defined $displayFilename);

    #
    # Start
    #
    
    print "[Load export file: $displayFilename]\n" if $g_configDebug;

    my $xml = new XML::Simple;
    my $data = eval { $xml->XMLin($filename, forceArray => 1, KeyAttr => {}) }; 
    if($@)
    {
        $@ =~ s/at [^l].*?$//s;
        $@ = join("\nError:", split("\n", $@));
        die "\nERROR in '$displayFilename':$@\n";
    }

    #dumpData($data);

    #
    # Load Enums
    #

    # ID 0 reserved for unknown
    my $enumValueId = 1;

    for $enumItemData (@{$data->{'Enum'}})
    {
        my $enumTypeName = $enumItemData->{'name'};

        my $enumTypeInfo = 
        {
            name        =>  $enumTypeName
        };
        
        $g_enumTypeTable->{$enumTypeName} = $enumTypeInfo;
        
        for $enumValueData (@{$enumItemData->{'EnumValue'}})
        {
            my $enumValueName = $enumValueData->{'name'};
            
            my $enumValueInfo =
            {
                enumId      =>  $enumValueId,
                name        =>  $enumValueName,
                enumName    =>  $g_configEnumValueIdEnumPrefix.$enumValueName,
                type        =>  $enumTypeName
            };

            $g_enumValueTable->{$enumValueName} = $enumValueInfo;
            $g_enumValueArray->[$enumValueId]   = $enumValueInfo;
            $enumValueId++;
        }
    }

    print "[Enum Value Table]\n" if $g_configDebug;
    dumpData($g_enumTypeTable) if $g_configDebug;
    dumpData($g_enumValueTable) if $g_configDebug;

    #
    # Load Structs
    #

    # ID 0 reserved for unknown
    my $structId = 1;
    my $memberId = 1;
    for $structData (@{$data->{'Struct'}})
    {
        my $structName = $structData->{'name'};
        
        my $structInfo = 
        {
            structId    =>  $structId,
            name        =>  $structName,
            enumName    =>  $g_configStructIdEnumPrefix.$structName,
            memberTable =>  {}
        };
        
        $g_structTable->{$structName}   = $structInfo;
        $g_structArray->[$structId]     = $structInfo;
        $structId++;

        for $memberData (@{$structData->{'Member'}})
        {
            my $memberName = $memberData->{'name'};
            my $memberType  = $memberData->{type};

            my $memberInfo = 
            {
                memberId    => $memberId,
                name        => $memberName,
                enumName    => $g_configMemberIdEnumPrefix.$structName.'_'.$memberName,
                type        => $memberType,
                struct      => $structName                
            };
            
            $structInfo->{memberTable}->{$memberName} = $memberInfo;
            $g_memberArray->[$memberId] = $memberInfo;
            $memberId++;
        }
    }

    print "[Struct Table]\n" if $g_configDebug;
    dumpData($g_structTable) if $g_configDebug;

    #
    # Load Classes
    #

    # ID 0 reserved for unknown
    my $classId = 1;
    my $propertyId = 1;
    my $slotId = 1;
    for $classData (@{$data->{Class}})
    {
        my $className = $classData->{'name'};
        my $parentClass = $classData->{parent};
        my $isAbstract = exists $classData->{abstract} ? 1 : 0;
        my $headerName = exists $classData->{header} ? $classData->{header} : "";
        
        my $classInfo = 
        {
            classId     =>  $isAbstract ? 0 : $classId,
            name        =>  $className,
            enumName    =>  $g_configClassIdEnumPrefix.$className,
            isAbstract  =>  $isAbstract,
            parent      =>  $parentClass,
            header      =>  $headerName,
            propTable   =>  {}
        };
        
        $g_classTable->{$className} = $classInfo;
        if (!$isAbstract)
        {
            $g_classArray->[$classId] = $classInfo;
            $classId++;
        }

        for $propertyData (@{$classData->{'Property'}})
        {
            my $propertyName    = $propertyData->{'name'};
            my $propertyType    = $propertyData->{type};
            my $propertyMethod  = $propertyData->{method};

            # default method name is 'setXxx()'
            if (!defined $propertyMethod && $propertyName ne 'items')
            {
                $propertyMethod = 'set'.ucfirst($propertyName);
            }

            my $propertyInfo = 
            {
                propertyId  => $propertyId,
                propType    => 'property',
                name        => $propertyName,
                enumName    => $g_configPropertyIdEnumPrefix.$className.'_'.$propertyName,
                type        => $propertyType,
                class       => $className,
                method      => $propertyMethod
            };
            
            $classInfo->{propTable}->{$propertyName} = $propertyInfo;
            $g_propertyArray->[$propertyId] = $propertyInfo;
            $propertyId++;
        }

        for $propertyData (@{$classData->{'Handler'}})
        {
            my $propertyName    = $propertyData->{'name'};
            my $propertyType    = $propertyData->{type};

            my $propertyInfo = 
            {
                propertyId  => $propertyId,
                propType    => 'handler',
                name        => $propertyName,
                enumName    => $g_configPropertyIdEnumPrefix.$className.'_'.$propertyName,
                type        => $propertyType,
                class       => $className,
                method      => undef
            };
            
            $classInfo->{propTable}->{$propertyName} = $propertyInfo;
            $g_propertyArray->[$propertyId] = $propertyInfo;
            $propertyId++;
        }

        for $propertyData (@{$classData->{'Signal'}})
        {
            my $propertyName    = $propertyData->{'name'};
            my $propertyType    = $propertyData->{type};
            my $propertyMember  = $propertyData->{member};

            my $propertyInfo = 
            {
                propertyId  => $propertyId,
                propType    => 'signal',
                name        => $propertyName,
                enumName    => $g_configPropertyIdEnumPrefix.$className.'_'.$propertyName,
                type        => $propertyType,
                class       => $className,
                member      => $propertyMember
            };
            
            $classInfo->{propTable}->{$propertyName} = $propertyInfo;
            $g_propertyArray->[$propertyId] = $propertyInfo;
            $propertyId++;
        }

        for $slotData (@{$classData->{'Slot'}})
        {
            my $slotName    = $slotData->{'name'};
            my $slotType    = $slotData->{type};

            my $slotInfo = 
            {
                slotId      => $slotId,
                name        => $slotName,
                enumName    => $g_configSlotIdEnumPrefix.$className.'_'.$slotName,
                type        => $slotType,
                class       => $className
            };
            
            $classInfo->{slotTable}->{$slotName} = $slotInfo;
            $g_slotArray->[$slotId] = $slotInfo;
            $slotId++;
        }
    }

    print "[Class Table]\n" if $g_configDebug;
    dumpData($g_classTable) if $g_configDebug;
}


#############################################################################
#
# Export enum file
#
#############################################################################

sub exportEnumFile
{
    my $filename = shift;
    my $tempname = $filename.".tmp";

    print "[Export Enum Include File: $filename]\n" if $g_configDebug;
    
    open FILE, ">$tempname" or
        die "Error: Can not output temp definition file: $tempname\n";

    # Output Version
    print FILE "#define VFX_XML_VER_MAJOR ($g_configVersionMajor)\n";
    print FILE "#define VFX_XML_VER_MINOR ($g_configVersionMinor)\n";
    print FILE "\n\n";

    #
    # Output enum value ID enum
    #
    print FILE "enum $g_configEnumValueIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_enumValueArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        
        print FILE $g_configIndent.$enumName;
        print FILE ' = 0' if ($name eq $g_configEnumValueNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configEnumValueIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";

    
    #
    # Output struct ID enum
    #
    print FILE "enum $g_configStructIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_structArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        
        print FILE $g_configIndent.$enumName;        
        print FILE ' = 0' if ($name eq $g_configStructNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configStructIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";

    
    #
    # Output struct member ID enum
    #
    print FILE "enum $g_configMemberIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_memberArray})
    {
        my $name       = $info->{name};
        my $enumName   = $info->{enumName};
        
        print FILE $g_configIndent.$enumName;
        print FILE ' = 0' if ($name eq $g_configPropertyNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configMemberIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";

    
    #
    # Output class ID enum
    #
    print FILE "enum $g_configClassIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_classArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        my $isAbstract  = $info->{isAbstract};
        
        print FILE $g_configIndent.$enumName;        
        print FILE ' = 0' if ($name eq $g_configClassNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configClassIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";


    #
    # Output class property ID enum
    #
    print FILE "enum $g_configPropertyIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_propertyArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};

        print FILE $g_configIndent.$enumName;
        print FILE ' = 0' if ($name eq $g_configPropertyNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configPropertyIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";


    #
    # Output class slot ID enum
    #
    print FILE "enum $g_configSlotIdEnumName\n";
    print FILE "{\n";

    for $info (@{$g_slotArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        
        print FILE $g_configIndent.$enumName;
        print FILE ' = 0' if ($name eq $g_configSlotNameUnknown);
        print FILE ",\n";
    }

    print FILE $g_configIndent.$g_configSlotIdEnumPrefix."END_OF_ENUM\n";
    print FILE "};\n\n";
    
    close(FILE);
    
    #
    # compare temp file and original file
    #
    if(compare($tempname, $filename) != 0)
    {
        chmod 0777, $filename;
        copy($tempname, $filename) or die "Error: Can not overwrite definition file: $filename\n";
    }
    unlink($tempname);
}


#############################################################################
#
# Export table file
#
#############################################################################

sub exportTableFile
{
    my $filename = shift;
    my $tempname = $filename.".tmp";

    print "[Export Table Include File: $filename]\n" if $g_configDebug;
    
    open FILE, ">$tempname" or
        die "Error: Can not output temp table file: $tempname\n";

    #
    # Output includes
    #
    for $info (@{$g_classArray})
    {
        my $name        = $info->{name};
        my $headerName  = $info->{header};
        
        next if ($name eq $g_configClassNameUnknown) || ($headerName eq "");

        print FILE '#include "'.$headerName.'"'."\n";
    }
    print FILE "\n";


    #
    # Output enum value table
    #
    print FILE "VFX_XML_DEFINE_ENUM_VALUE_TABLE_BEGIN($g_configEnumValueTableName)\n";

    for $info (@{$g_enumValueArray})
    {
        my $name        = $info->{name};
        my $typeName    = $info->{type};
        my $enumName    = $info->{enumName};
        
        next if ($name eq $g_configEnumValueNameUnknown);

        print FILE 
            $g_configIndent.'VFX_XML_DEFINE_ENUM_VALUE('.
            $enumName.', '.
            $typeName.', '.
            $name.")\n";
    }

    print FILE "VFX_XML_DEFINE_ENUM_VALUE_TABLE_END();\n\n";


    #
    # Output struct table
    #
    print FILE "VFX_XML_DEFINE_STRUCT_TABLE_BEGIN($g_configStructTableName)\n";

    for $info (@{$g_structArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        
        next if ($name eq $g_configStructNameUnknown);

        print FILE 
            $g_configIndent.'VFX_XML_DEFINE_STRUCT('.
            $enumName.', '.
            $name.")\n";
    }

    print FILE "VFX_XML_DEFINE_STRUCT_TABLE_END();\n\n";


    #
    # Output struct member table
    #
    print FILE "VFX_XML_DEFINE_STRUCT_MEMBER_TABLE_BEGIN($g_configMemberTableName)\n";
            
    for $info (@{$g_memberArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        my $type        = $info->{type};
        my $struct      = $info->{struct};
        
        next if ($name eq $g_configMemberNameUnknown);

        print FILE 
            $g_configIndent.'VFX_XML_DEFINE_STRUCT_MEMBER('.
            $enumName.', '.
            $type.', '.
            $struct.', '.
            $name.")\n";
    }

    print FILE "VFX_XML_DEFINE_STRUCT_MEMBER_TABLE_END();\n\n";

    
    #
    # Output class table
    #
    print FILE "VFX_XML_DEFINE_CLASS_TABLE_BEGIN($g_configClassTableName)\n";

    for $info (@{$g_classArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        my $isAbstract  = $info->{isAbstract};

        next if ($name eq $g_configClassNameUnknown);
        
        print FILE 
            $g_configIndent.'VFX_XML_DEFINE_CLASS('.
            $enumName.', '.
            $name.")\n";
    }

    print FILE "VFX_XML_DEFINE_CLASS_TABLE_END();\n\n";


    #
    # Output property table
    #
    print FILE "VFX_XML_DEFINE_PROP_TABLE_BEGIN($g_configPropertyTableName)\n";
            
    for $info (@{$g_propertyArray})
    {
        my $propType    = $info->{propType};
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        my $type        = $info->{type};
        my $class       = $info->{class};
        my $method      = $info->{method};
        
        next if ($name eq $g_configPropertyNameUnknown);

        if ($propType eq 'handler')
        {
            my $defineMacro = 'VFX_XML_DEFINE_HANDLER_PROP';
            
            print FILE 
                $g_configIndent.$defineMacro.'('.
                $enumName.', '.
                $type.")\n";
        }
        elsif ($propType eq 'signal')
        {
            my $defineMacro = 'VFX_XML_DEFINE_SIGNAL_PROP';
            my $member = $info->{member};
            
            print FILE 
                $g_configIndent.$defineMacro.'('.
                $enumName.', '.
                $type.', '.
                $class.', '.
                $member.")\n";
        }
        elsif ($propType eq 'property')
        {
            my $defineMacro = undef;
            
            if (exists $g_typeTable->{$type})
            {
                $defineMacro = 'VFX_XML_DEFINE_TYPE_PROP';
            }
            elsif (exists $g_enumTypeTable->{$type})
            {
                $defineMacro = 'VFX_XML_DEFINE_ENUM_PROP'; 
            }
            elsif (exists $g_structTable->{$type})
            {
                $defineMacro = 'VFX_XML_DEFINE_STRUCT_PROP'; 
            }
            elsif (exists $g_classTable->{$type})
            {
                $defineMacro = 'VFX_XML_DEFINE_OBJECT_PROP'; 
            }
            else
            {
                die "Error: Unknown '$type' in export XML.\n";
            }
        
            my $memFunc = defined $method ?
                ('&'.$class.'::'.$method) :
                'NULL';

            print FILE 
                $g_configIndent.$defineMacro.'('.
                $enumName.', '.
                $type.', '.
                $memFunc.")\n";
        }
    }

    print FILE "VFX_XML_DEFINE_PROP_TABLE_END();\n\n";

    #
    # Output slot table
    #
    print FILE "VFX_XML_DEFINE_SLOT_TABLE_BEGIN($g_configSlotTableName)\n";
            
    for $info (@{$g_slotArray})
    {
        my $name        = $info->{name};
        my $enumName    = $info->{enumName};
        my $type        = $info->{type};
        my $class       = $info->{class};
        
        next if ($name eq $g_configSlotNameUnknown);

        my $defineMacro = 'VFX_XML_DEFINE_OBJECT_SLOT';

        my $memFunc = defined $name ?
            ('&'.$class.'::'.$name) :
            'NULL';

        print FILE 
            $g_configIndent.$defineMacro.'('.
            $enumName.', '.
            $type.', '.
            $memFunc.")\n";
    }

    print FILE "VFX_XML_DEFINE_SLOT_TABLE_END();\n\n";
    
    close(FILE);
    
    #
    # compare temp file and original file
    #
    if(compare($tempname, $filename) != 0)
    {
        chmod 0777, $filename;
        copy($tempname, $filename) or die "Error: Can not overwrite table file: $filename\n";
    }
    unlink($tempname);
}


sub findProperty
{
    my $className = shift;
    my $propName = shift;
    
    my $propInfo = undef;
    while (defined $className)
    {
        my $classInfo = $g_classTable->{$className};

        $propInfo = $classInfo->{propTable}->{$propName};

        last if defined $propInfo;

        $className = $classInfo->{parent};
    }

    return $propInfo;
}


sub outputErrorMessage
{
    my $parser = shift;
    my $message = shift;

    my $lineNum = $parser->current_line();
    my $lineCol = $parser->current_column();

    print STDERR "Error: at $g_configInputFile line $lineNum,col $lineCol: $message\n";
    $g_errorFlag = 1;
}


sub parseAttr
{
    my ($parser, $attrType, $attrValue) = @_;

    # Support primitive types and enum types
    if (!exists $g_typeTable->{$attrType} &&
        !exists $g_enumTypeTable->{$attrType})
    {
        outputErrorMessage($parser, "Type '$attrType' is not supportted.");
        return undef;
    }

    # If the type is a enum type, mapping to the general internal enum type
    $attrType = '__Enum' if exists $g_enumTypeTable->{$attrType};

    my $parserHandler = $g_typeTable->{$attrType}->{_value};
    if (!defined $parserHandler)
    {
        outputErrorMessage($parser, "Type '$attrType' is not supportted.");
        return undef;
    }
    
    my $value = &{$parserHandler}($attrValue, $parser);
    if (!defined $value)
    {
        outputErrorMessage($parser, "Format error in '$attrValue'");
        return undef;
    }

    return $value;
}


sub parseTypeAttrList
{
    my $parser = shift;
    my $className = shift;
    my $attrArrayRef = shift;
    my $valueAttrValue = shift;

    # Ouput property ID and data
    print "TYPE: $className\n" if $g_configDebug;

    # If there is an attribute 'value', use it
    if (defined $valueAttrValue)
    {
        print "\tvalue='$valueAttrValue'\n" if $g_configDebug;

        if (${$attrArrayRef} != -1)
        {
            outputErrorMessage($parser, "Use attribute 'value' only, other attribute will be ignored.");
        }

        return parseAttr($parser, $className, $valueAttrValue);
    }

    # Apply all attributes
    my $typeHandlerInfo = $g_typeTable->{$className};
    my $ret = {};
    for $attrRef (@{$attrArrayRef})
    {
        my $attrName  = $attrRef->{name};
        my $attrValue = $attrRef->{value};

        print "\t$attrName='$attrValue'\n" if $g_configDebug;

        my $attrType = $typeHandlerInfo->{$attrName};
        if (!defined $attrType)
        {
            outputErrorMessage($parser, "Tag '$className' has no attribute '$attrName'");
            next;
        }
        my $value = parseAttr($parser, $attrType, $attrValue);

        $ret->{$attrName} = $value;
    }
    return $ret;
}


sub parseStructAttrList
{
    my $parser = shift;
    my $className = shift;
    my $attrArrayRef = shift;

    my $structInfo = $g_structTable->{$className};
    
    # Ouput property ID and data
    print "STRUCT: $className\n" if $g_configDebug;
    
    my $ret = [];
    for $attrRef (@{$attrArrayRef})
    {
        my $attrName    = $attrRef->{name};
        my $attrValue   = $attrRef->{value};

        print "\t$attrName='$attrValue'\n" if $g_configDebug;

        my $memberInfo = $structInfo->{memberTable}->{$attrName};
        if (!defined $memberInfo)
        {
            outputErrorMessage($parser, "Tag '$className' has no attribute '$attrName'");
            next;
        }

        my $attrType = $memberInfo->{type};
        my $value = parseAttr($parser, $attrType, $attrValue);

        my $newObj = 
        {
            targetProperty => $attrName,
            className => $attrType,
            value => $value
        };
        push @{$ret}, $newObj;
    }
    return $ret;
}


sub parseObjectAttrList
{
    my $parser = shift;
    my $className = shift;
    my $attrArrayRef = shift;

    my $classInfo = $g_classTable->{$className};

    # This is a class 
    print "OBJ: $className\n" if $g_configDebug;

    my $ret = [];
    for $attrRef (@{$attrArrayRef})
    {
        my $attrName = $attrRef->{name};
        my $attrValue = $attrRef->{value};
        
        print "\t$attrName='$attrValue'\n" if $g_configDebug;

        my $propInfo = findProperty($className, $attrName);
        if (!defined $propInfo)
        {
            outputErrorMessage($parser, "Tag '$className' has no attribute '$attrName'");
            next;
        }

        my $attrType = $propInfo->{type};
        my $value = parseAttr($parser, $attrType, $attrValue);
        
        my $newObj = 
        {
            targetProperty => $attrName,
            className => $attrType,
            value => $value,
            propInfo => $propInfo
        };
        push @{$ret}, $newObj;
    }
    return $ret;
}


sub buildAttrArray
{
    my $attrArrayRef = [];
    my $specialAttrTableRef = {};
    while (@_)
    {
        my $arrtRef =
        {
            name    => shift,
            value   => shift
        };

        # Find special attributes
        if ($arrtRef->{name} eq 'prop')
        {
            $specialAttrTableRef->{prop} = $arrtRef->{value};
        }
        elsif ($arrtRef->{name} eq 'value')
        {
            $specialAttrTableRef->{value} = $arrtRef->{value};
        }
        else
        {
            push @{$attrArrayRef}, $arrtRef;
        }
    }

    return ($attrArrayRef, $specialAttrTableRef);
}


sub parseStartHandler
{
    my $parser = shift;
    my $elemName = shift;
    my ($attrArrayRef, $specialAttrTableRef) = buildAttrArray(@_);

    my $curObjRef = $parser->{objRefStack}->[-1]; # Get the top object of stack
    
    # There is a attribute 'prop', check it
    my $propAttrValue = $specialAttrTableRef->{'prop'};
    if (defined $propAttrValue)
    {
        if (!defined $curObjRef)
        {
            outputErrorMessage($parser, "Attribute 'prop' needs an object parent.");
            return;
        }
    }   
        
    my $newObjRef = 
    {
        className => $elemName,
        targetProperty => undef,
        value => undef
    };
    push @{$parser->{objRefStack}}, $newObjRef;

    if ($elemName eq "VenusXML")
    {
        if ($curObjRef->{className} ne "VenusXMLRoot") 
        {
            outputErrorMessage($parser, "Tag 'VenusXML' should be at 1st level");
            return;
        }
        push @{$curObjRef->{value}}, $newObjRef;
        return;
    }
    elsif ($elemName eq "Layout")
    {
        if ($curObjRef->{className} ne "VenusXML") 
        {
            outputErrorMessage($parser, "Tag 'Layout' should be at 2nd level");
            return;
        }

        for $attrRef (@{$attrArrayRef})
        {
            my $attrName  = $attrRef->{name};
            my $attrValue = $attrRef->{value};
            
            if($attrName eq "id")
            {
                $newObjRef->{resId} = $attrValue;
            }
        }
        if (!exists $newObjRef->{resId})
        {
            die "Error: Layout has no res id\n";
        }
        push @{$curObjRef->{value}}, $newObjRef;
        return;
    }

    if (!defined $g_configOutBinPath)
    {
        # if we only need layout id, no need to process following tag
        return;
    }        
    
    if (exists $g_typeTable->{$elemName} || 
        exists $g_enumTypeTable->{$elemName})
    {
        my $stackLevel = @{$parser->{objRefStack}};
        if ($stackLevel < 3) 
        {
            outputErrorMessage($parser, "Tag 'elemName' should be inside Tag 'Layout'");
            return;
        }
        
        # This is a primitive type or enum type
        if (!defined $propAttrValue)
        {
            outputErrorMessage($parser, "Tag '$elemName' needs attribute 'prop'.");
            return;
        }

        my $targetClassName = $curObjRef->{className};
        my $targetPropInfo = findProperty($targetClassName, $propAttrValue);
        if (!defined $targetPropInfo)
        {
            outputErrorMessage($parser, "Tag '$targetClassName' has no attribute '$propAttrValue'");
            return;
        }
        
        my $propType = $targetPropInfo->{type};
        if ($propType ne $elemName)
        {
            outputErrorMessage($parser, "'$elemName' should be assigned a '$propType'.");
            return;
        }

        $newObjRef->{targetProperty} = $propAttrValue;
        $newObjRef->{classType} = 'type';
        $newObjRef->{value} = parseTypeAttrList($parser, $elemName, $attrArrayRef, $specialAttrTableRef->{value});
        push @{$curObjRef->{value}}, $newObjRef;
    }
    elsif (exists $g_structTable->{$elemName})
    {
        my $stackLevel = @{$parser->{objRefStack}};
        if ($stackLevel < 3) 
        {
            outputErrorMessage($parser, "Tag 'elemName' should be inside Tag 'Layout'");
            return;
        }
        
        # This is a struct
        if (!defined $propAttrValue)
        {
            outputErrorMessage($parser, "Tag '$elemName' needs attribute 'prop'.");
            return;
        }

        my $targetClassName = $curObjRef->{className};
        my $targetPropInfo = findProperty($targetClassName, $propAttrValue);
        if (!defined $targetPropInfo)
        {
            outputErrorMessage($parser, "Tag '$targetClassName' has no attribute '$propAttrValue'");
            return;
        }
        
        my $propType = $targetPropInfo->{type};
        if ($propType ne $elemName)
        {
            outputErrorMessage($parser, "'$elemName' should be assigned a '$propType'.");
            return;
        }

        $newObjRef->{targetProperty} = $propAttrValue;
        $newObjRef->{classType} = 'struct';
        $newObjRef->{value} = parseStructAttrList($parser, $elemName, $attrArrayRef);
        $newObjRef->{propInfo} = $targetPropInfo;
        push @{$curObjRef->{value}}, $newObjRef;
    }
    elsif (exists $g_classTable->{$elemName})
    {
        my $stackLevel = @{$parser->{objRefStack}};
        if ($stackLevel < 3) 
        {
            outputErrorMessage($parser, "Tag '$elemName' should be inside Tag 'Layout'");
            return;
        }

        if ($g_classTable->{$elemName}->{isAbstract})
        {
            outputErrorMessage($parser, "Tag '$elemName' is an abstract class.");
            return;
        }
        
        # This is an object        
        $propAttrValue = 'items' unless defined $propAttrValue;
    
        my $targetClassName = $curObjRef->{className};
        my $targetPropInfo = findProperty($targetClassName, $propAttrValue);
        if (!defined $targetPropInfo && 
            $targetClassName ne 'VenusXMLRoot' &&
            $targetClassName ne 'Layout')
        {
            outputErrorMessage($parser, "Tag '$targetClassName' has no attribute '$propAttrValue'");
            return;
        }
        
        $newObjRef->{targetProperty} = $propAttrValue;
        $newObjRef->{classType} = 'object';
        $newObjRef->{value} = parseObjectAttrList($parser, $elemName, $attrArrayRef);
        $newObjRef->{propInfo} = $targetPropInfo;
        push @{$curObjRef->{value}}, $newObjRef;
    }
    else
    {
        # Unknown
        die "Error: Unknown element: $elemName\n";
    }
}


sub parseEndHandler
{
    my ($parser, $elemName) = @_;

    pop @{$parser->{objRefStack}};
}


sub parseCharHandler
{
    my ($parser, $elemName) = @_;
}


sub loadVenusXmlFile
{
    my $filename = shift;

    print "[Load Venus XML File: $filename]\n" if $g_configDebug;    

    my $rootObj =
    {
        className => 'VenusXMLRoot',
        classType => undef,
        targetProperty => undef,
        value => []
    };

    my $parser = new XML::Parser(
        ErrorContext => 1,
        Handlers =>
        {
            Start   => \&parseStartHandler,
            End     => \&parseEndHandler,
            Char    => \&parseCharHandler
        });
    $parser->{objRefStack} = [ $rootObj ];

    open INPUT, "<$filename" or
        die "Error: Can not open Venus XML file: $filename.\n";
    &PrintDependency($filename);
    eval { $parser->parse(*INPUT) };
    if($@)
    {
        $@ =~ s/at [^l].*?$//s;
        $@ = join("\nError:", split("\n", $@));
        die "\nERROR in '$filename':$@\n";
    }

    close INPUT;

    return $rootObj->{value}->[0];
}


sub genTypeData
{
    my ($outBufRef, $handlerId, $objRef) = @_;

    my $className = $objRef->{className};
    my $value = $objRef->{value};

    defined $value or
        die "Error: No value.\n";
    
    # If the type is a enum type, mapping to the general internal enum type
    $className = '__Enum' if exists $g_enumTypeTable->{$className};

    my $typeInfo = $g_typeTable->{$className};
    my $data = &{$typeInfo->{_export}}($value);

    # Output
    ${$outBufRef} .= pack('i', $handlerId);
    ${$outBufRef} .= $data;
}


sub genStructData
{
    my ($outBufRef, $handlerId, $objRef) = @_;

    my $className = $objRef->{className};
    my $structInfo = $g_structTable->{$className};

    # Output class ID
    my $structId = $structInfo->{structId};
    $handlerId += ($structId << 16);
    ${$outBufRef} .= pack('i', $handlerId);

    for $member (@{$objRef->{value}})
    {
        next unless defined $member;
        next unless defined $member->{value};

        my $memberName = $member->{targetProperty};
        
        my $memberInfo = $structInfo->{memberTable}->{$memberName};
        my $memberId = $memberInfo->{memberId};        

        genData($outBufRef, $memberId, $member);
    }

    # Output end of member list    
    ${$outBufRef} .= pack('i', 0);
}


sub sortByAttr
{
    sub getClassLevel
    {
        my $className = shift;
        my $classLevel = 0;
        while (defined $className)
        {
            $className = $g_classTable->{$className}->{parent};
            $classLevel = $classLevel + 1;
        }
        return $classLevel;
    }

    sub getOrderValue
    {
        my $propInfo = shift;
        
        if ($propInfo->{name} eq 'items')
        {
            return 9999*100000;
        }
        if ($propInfo->{name} eq 'alignParent')
        {
            return 9999*100000 + 1;
        }
        
        return getClassLevel($propInfo->{class})*100000 + $propInfo->{propertyId};
    }
    
    my $va = getOrderValue($a->{propInfo});
    my $vb = getOrderValue($b->{propInfo});

    return $va cmp $vb;
}


sub genClassData
{
    my ($outBufRef, $handlerId, $objRef) = @_;

    my $className = $objRef->{className};
    my $classInfo = $g_classTable->{$className};

    # Output class ID
    my $classId = $classInfo->{classId};
    $handlerId += ($classId << 16);
    ${$outBufRef} .= pack('i', $handlerId);

    for $property (sort sortByAttr @{$objRef->{value}})
    {
        next unless defined $property;
        next unless defined $property->{value};

        my $propId = $property->{propInfo}->{propertyId};

        # for property order debug
        #print "$property->{propInfo}->{name}:$propId\n";

        genData($outBufRef, $propId, $property);
    }

    # Output end of property list    
    ${$outBufRef} .= pack('i', 0);
}


sub genData
{
    my ($outBufRef, $handlerId, $objRef) = @_;

    defined $objRef or
        die "Error: Undefined object.\n";
    
    my $className = $objRef->{className};
    if (exists $g_typeTable->{$className} ||
        exists $g_enumTypeTable->{$className})
    {
        # This is a primitve type or enum type
        genTypeData($outBufRef, $handlerId, $objRef);
    }
    elsif (exists $g_structTable->{$className})
    {
        # This is a struct
        genStructData($outBufRef, $handlerId, $objRef);
    }
    elsif (exists $g_classTable->{$className})
    {
        # This is an object
        genClassData($outBufRef, $handlerId, $objRef);
    }
    else
    {
        die "Error: Unknown class name: $className\n";
    }        
}


sub genBinaryFromObject
{
    my $objRef = shift;

    # Generate file header
    my $outBuf = pack('a2c1c1', 'VX', $g_configVersionMajor, $g_configVersionMinor);

    my $propInfo = $g_classTable->{'VfxObject'}->{propTable}->{'items'};
    defined $propInfo or
        die "Error: Must export 'VfxObject' and property 'items'.\n";    
    my $propId = $propInfo->{propertyId};

    genClassData(\$outBuf, $propId, $objRef);

    return \$outBuf;
}


sub outputBinaryFile
{
    my $filename = shift;
    my $outBufRef = shift;

    print "[Output Venus XML binary file: $filename]\n" if $g_configDebug;
    
    open OUTPUT, ">$filename" or
        die "Error: Can not write file: $filename\n";
    binmode OUTPUT;

    print OUTPUT ${$outBufRef};

    close OUTPUT;
}


sub outputIncludeFile
{
    my $filename = shift;
    my $varName = shift;
    my $outBufRef = shift;

    print "[Output Venus XML C include file: $filename]\n" if $g_configDebug;
    
    open OUTPUT, ">$filename" or
        die "Error: Can not write file: $filename\n";

    print OUTPUT "const unsigned char ".$varName."[] =\n{\n";

    my $subBuf = "";
    my $pos = 0;
    my $len = length(${$outBufRef});
    while ($len >= $g_configOutputBytesPerLine)
    {
        print OUTPUT $g_configIndent;
        for (unpack("C*", substr(${$outBufRef}, $pos, $g_configOutputBytesPerLine)))
        {
            printf OUTPUT "0x%02x, ", $_;
        }
        print OUTPUT "\n";

        $len -= $g_configOutputBytesPerLine;
        $pos += $g_configOutputBytesPerLine;
    }

    if ($len > 0)
    {
        print OUTPUT $g_configIndent;
        for (unpack("C*", substr(${$outBufRef}, $pos, $len)))
        {
            printf OUTPUT "0x%02x, ", $_;
        }
        print OUTPUT "\n";
    }

    print OUTPUT "};\n";

    close OUTPUT;
}


sub outputLisFile
{
    my $filename = shift;
    my $listRef = shift;
    
    print "[Output LIS file: $filename]\n" if $g_configDebug;
    
    open OUTPUT, ">$filename" or
        die "Error: Can not write lis file: $filename\n";

    for $layout (@{$listRef})
    {
        print OUTPUT $layout->{resId}."\n";
    }

    close OUTPUT;
}


sub VERSION_MESSAGE
{
    my $FILE = shift;
    
    print $FILE "Venus XML Converter $g_configVersionMajor.$g_configVersionMinor\n";
}


sub HELP_MESSAGE
{
    my $FILE = shift;
    
    my $progName = basename($0);
    print $FILE "\nUsage:\n";
    print $FILE "\t$progName <options>\n";
    print $FILE "\noptions:\n";
    print $FILE "\t-d                           \tOuput debug message.\n";
    print $FILE "\t-e                           \tForce output export files.\n";
    print $FILE "\t-E <Command>                 \tPost-process after output export files.\n";
    print $FILE "\t-i <Venus XML file>          \t[IN]  XML file to be converted.\n";
    print $FILE "\t-x <Export XML file>         \t[IN]  Export XML file.\n";
    print $FILE "\t-t <Include table path>      \t[OUT] Export include table (*.i) path.\n";
    print $FILE "\t-o <Binary files path>       \t[OUT] Path of converted binary files.\n";
    print $FILE "\t-l <Venus XML IDs file>      \t[OUT] Table of XML ID\n";
    print $FILE "\t-m <Mapping table file>      \t[IN]  Mapping table of resource\n";
    print $FILE "\t-h <Resource ID header file> \t[IN]  Resource ID header file\n";
    print $FILE "\t-p                           \tDisable pre-processor.\n";
};


sub help
{
    VERSION_MESSAGE(*STDERR);
    HELP_MESSAGE(*STDERR);
}


#############################################################################
#
# Main
#
#############################################################################

# Change work dir to the script folder
chdir dirname($0);

# 
# Parse arguments
#
$Getopt::Std::STANDARD_HELP_VERSION = 1;
my %options = ();
if (!getopts('x:t:deE:i:o:l:m:h:p', \%options))
{
    help();
    exit -1;
}

$g_configDebug              = 1 if exists $options{d};
$g_configExport             = 1 if exists $options{e};
$g_configExportPostprocess  = $options{E};
$g_configPreprocess         = 0 if exists $options{p};
$g_configInputFile          = $options{i};
$g_configOutBinPath         = $options{o};
$g_configOutLisPath         = $options{l};
$g_configInMapPath          = $options{m};
$g_configResIdHeader        = $options{h};

$g_configTablePath = exists $options{t} ? 
    $options{t} :
    dirname($0);
    
$g_configExportFile = $options{x} if exists $options{x};

# Output tables or convert
if (!$g_configExport && !$g_configInputFile)
{
    help();
    exit -1;
}

$g_configInMapPath = undef if (defined $g_configResIdHeader);


#
# Start
#

my $tempExportFile = $g_configExportFile;

if ($g_configPreprocess)
{
    # Preprocess Export file
    $tempExportFile = $g_configExportFile.".tmp";
    preprocessXmlFile($tempExportFile, $g_configExportFile);
}

# Load Export file
loadExportFile($tempExportFile, $g_configExportFile);

if ($g_configPreprocess)
{
    # Remove temp file
    unlink($tempExportFile);
}

die "Error: There is error at $g_configExportFile" if $g_errorFlag != 0;


# Load Mapping files
if (defined $g_configInMapPath) 
{
    loadMappingFile($g_configInMapPath);
}

if (defined $g_configResIdHeader)
{
    loadResIdHeader($g_configResIdHeader);
}

die "Error: There is error" if $g_errorFlag != 0;


# Check if need to export
my $xmlStat = stat($g_configExportFile);
my $outStat = stat("$g_configTablePath/$g_configOutputDefFile");

if (!defined $outStat ||
    $xmlStat->mtime > $outStat->mtime - 1)
{
    print "Auto-update exported files.\n" if $g_configDebug;

    $g_configExport = 1;
}


# Export if needed
if ($g_configExport)
{
    exportEnumFile("$g_configTablePath/$g_configOutputDefFile");
    exportTableFile("$g_configTablePath/$g_configOutputTableFile");
    
    postprocessExportFile($g_configExportPostprocess, $g_configTablePath)
        if defined $g_configExportPostprocess;
}

die "Error: There is error" if $g_errorFlag != 0;

if (defined $g_configInputFile)
{
    my $objRef = loadVenusXmlFile($g_configInputFile);

    die "Error: There is error" if $g_errorFlag != 0;

    if ($g_configDebug)
    {
        for $layout (@{$objRef->{value}})
        {
            next unless defined $layout;
            next unless defined $layout->{value};
    
            print "[Object]\n";
            dumpData($layout);
        }
    }

    die "Error: There is error" if $g_errorFlag != 0;

    # Output binary files
    if (defined $g_configOutBinPath)
    {
        for $layout (@{$objRef->{value}})
        {
            my $outBufRef = genBinaryFromObject($layout->{value}->[0]);
            my $layoutName = $layout->{resId};
         
            outputBinaryFile("$g_configOutBinPath/$layoutName.bin", $outBufRef);
        }
    }
    
    die "Error: There is error" if $g_errorFlag != 0;

    # Output LIS file
    if (defined $g_configOutLisPath)
    {
        outputLisFile($g_configOutLisPath, $objRef->{value});
    }
    
    die "Error: There is error" if $g_errorFlag != 0;
} # if (defined $g_configInputFile)


sub PrintDependency
{
	my $file = shift;
	if (-e $file)
	{
		my $path = Win32::GetCwd() . "\\" . $file;
		$path =~ s/\//\\/g;
		print STDOUT "[Dependency] $path\n";
	}
}
