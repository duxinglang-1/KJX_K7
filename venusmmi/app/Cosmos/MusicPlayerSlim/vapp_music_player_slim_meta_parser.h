
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSPLY_SLIM_META_PARSER_H__
#define __VAPP_MUSPLY_SLIM_META_PARSER_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_slim_datatype.h"
extern "C" 
{
#include "meta_tag_api.h"
};

/* max length of each meta info */
#define META_INFO_MAX_LEN            (META_TAG_FRAME_MAX_LEN)
/* artist info structure */
typedef struct
{
    UI_character_type artist[META_INFO_MAX_LEN + 1];    /* artist name */
}artist_info_struct;

/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerMetaParser class
 *****************************************************************************/

class VappMusicPlayerMetaParser : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerMetaParser);
	
private:
	// parser handle
	U32 m_parserHdlr;

	// parser buffer pointer
	VfxU8 *m_parserBuffer;

	// image buffer to store resize image for display
	void *m_infoBuffer;

	// image buffer to store resize image for display
	void *m_imageBuffer;

public:
    // constructor
	VappMusicPlayerMetaParser():
	 m_parserHdlr(0),
	 m_parserBuffer(NULL),
	 m_infoBuffer(NULL),
 	 m_imageBuffer(NULL)
	 {};

public:
    // init
    virtual void onInit();

    // deinit
    virtual void onDeinit();

public:
    // parse file before get info
    VfxBool parseFile(VfxWString &filePath);

    // get meta info, the memory is allocate from FG buffer
    artist_info_struct* getAudioInfo(void);

    // get album cover, the memory is allocate from FG buffer
    VfxBool getCover(VfxS32 dest_width, VfxS32 dest_height, VfxImageBuffer &imgBuf, VfxBool noBG = VFX_TRUE);

};

#endif /*   __VAPP_MUSPLY_SLIM_META_PARSER_H__   */

#endif //__MMI_MUSIC_PLAYER_SLIM__
