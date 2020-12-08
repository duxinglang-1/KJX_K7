#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VCUI_MUSIC_PLAYER" name="STR_ID_VCUI_MUSIC_PLAYER" type="venus">
    <MEMORY 
        heap="100*1024" 
        fg="$(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2" 
        inc="Cosmos\MusicPlayerSlim\vapp_music_player_slim_datatype.h" 
        />
        
    <STRING id="STR_ID_VCUI_MUSIC_PLAYER"/>     
</APP>

#endif __MMI_MUSIC_PLAYER_SLIM__

