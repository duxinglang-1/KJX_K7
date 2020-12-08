#include "MMI_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_MOT" name="STR_SRV_MOT">

    <MEMORY
        inc="MotSrvGprot.h"
        base="SRV_MOT_TOTAL_MEM_SIZE"
        fg="total(SRV_MDI_VDOPLY_INFO)"
    />

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SRV_MOT_CAT_ACTION_ADVENTURE"/>
    <STRING id="STR_ID_SRV_MOT_CAT_ROMANCE_ETHICS"/>
    <STRING id="STR_ID_SRV_MOT_CAT_COMEDY_HUMOR"/>
    <STRING id="STR_ID_SRV_MOT_CAT_TV_DRAMA"/>
    <STRING id="STR_ID_SRV_MOT_CAT_ANIMATION_SCIFI"/>
    <STRING id="STR_ID_SRV_MOT_CAT_THRILLER_MYSTERY"/>
    <STRING id="STR_ID_SRV_MOT_CAT_MUSIC_PERFORMANCE"/>
    <STRING id="STR_ID_SRV_MOT_CAT_DOCUMENTARY"/>
    <STRING id="STR_ID_SRV_MOT_CAT_OTHERS"/>
    <STRING id="STR_ID_SRV_MOT_CAT_RECENT_PLAY"/>
    <STRING id="STR_ID_SRV_MOT_CAT_ALL"/>
    <STRING id="STR_ID_SRV_MOT_DEFAULT_UNNAMED"/>
    <STRING id="STR_ID_SRV_MOT_DEFAULT_UNKNOWN"/>
    <STRING id="STR_ID_SRV_MOT_DEFAULT_NO_DETAILS"/>
    <STRING id="STR_ID_SRV_MOT_UNKNOWN_ERR"/>
    <STRING id="STR_ID_SRV_MOT_FS_ERR"/>
    <STRING id="STR_ID_SRV_MOT_DB_CANNOT_OPEN"/>
    <STRING id="STR_ID_SRV_MOT_DB_FREESPACE_NOT_ENOUGH"/>
</APP>
