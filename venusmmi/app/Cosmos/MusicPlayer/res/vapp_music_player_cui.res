#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VCUI_MUSIC_PLAYER" name="STR_ID_VCUI_MUSIC_PLAYER" type="venus">
    <MEMORY 
        heap="100*1024" 
        extra_base="base(SRV_MDI_AUDPLY)" 
        fg="$(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2" 
        inc="Cosmos\MusicPlayer\vapp_music_player_datatype.h" 
        />
        
    <STRING id="STR_ID_VCUI_MUSIC_PLAYER"/>     
</APP>

#endif __COSMOS_MUSICPLY_COVER_FLOW__

