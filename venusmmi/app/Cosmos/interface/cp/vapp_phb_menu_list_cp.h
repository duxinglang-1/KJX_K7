#ifndef __VAPP_PHB_MENU_LIST_CP_H__
#define __VAPP_PHB_MENU_LIST_CP_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"
#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vcp_async_image_frame.h"
#endif /*__SOCIAL_NETWORK_SUPPORT__*/ 

#ifdef __SOCIAL_NETWORK_SUPPORT__
/* List menu cell - used in VcpListMenu/VcpGroupListMenu */
class VappPhbPhotoBorderFrame : public VcpPhotoBorderFrame
{
    VFX_DECLARE_CLASS(VappPhbPhotoBorderFrame);

public:
    VfxFrame *getContentFrame()
    {
        return getImageFrame();
    }

    void setContentFrame(VfxFrame *content)
    {
        setImageFrame(content);
    }
};
#endif /*__SOCIAL_NETWORK_SUPPORT__*/ 

// VappPhbListMenuItemBase class declaration
class VappPhbListMenuItemBase : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappPhbListMenuItemBase);

// Enum
public:
    enum {
    #if defined(__MMI_MAINLCD_240X320__)
        DEFAULT_GAPS      = 10,
        // multi text
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 11,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 10,
        // single text
        TEXT_LEFT_GAPS    = 0,
        TEXT_RIGHT_GAPS   = 8,
        // image
        IMG_LEFT_GAPS     = 8,
        IMG_RIGHT_GAPS    = 9,
        IMG_MAX_WIDTH     = 45,
        IMG_MAX_HEIGHT    = 45,
        ICON_WIDTH        = 24,
        ICON_HEIGHT       = 24,
        ICON_RIGHT_GAPS   = 8,
        ICON_LEFT_GAPS    = 9,
        IMG_WIDTH         = 45,
        IMG_HEIGHT        = 45,
        ICON_TOP_GAPS     = 7,
        ICON_BOTTOM_GAPS  = 7
    #elif defined (__MMI_MAINLCD_240X400__)
        DEFAULT_GAPS      = 10,
        // multi text
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 11,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 10,
        // single text
        TEXT_LEFT_GAPS    = 0,
        TEXT_RIGHT_GAPS   = 8,
        // image
        IMG_LEFT_GAPS     = 8,
        IMG_RIGHT_GAPS    = 9,
        IMG_MAX_WIDTH     = 45,
        IMG_MAX_HEIGHT    = 45,
        ICON_WIDTH        = 24,
        ICON_HEIGHT       = 24,
        ICON_RIGHT_GAPS   = 8,
        ICON_LEFT_GAPS    = 9,
        IMG_WIDTH         = 45,
        IMG_HEIGHT        = 45,
        ICON_TOP_GAPS     = 7,
        ICON_BOTTOM_GAPS  = 7
    #elif defined(__MMI_MAINLCD_320X480__)
        DEFAULT_GAPS      = 10,
        // multi text
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 10,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 9,
        // single text
        TEXT_LEFT_GAPS    = 0,
        TEXT_RIGHT_GAPS   = 8,
        // image
        IMG_LEFT_GAPS     = 8,
        IMG_RIGHT_GAPS    = 9,
        IMG_MAX_WIDTH     = 45,
        IMG_MAX_HEIGHT    = 45,
        ICON_WIDTH        = 24,
        ICON_HEIGHT       = 24,
        ICON_RIGHT_GAPS   = 8,
        ICON_LEFT_GAPS    = 9,
        IMG_WIDTH         = 45,
        IMG_HEIGHT        = 45,
        ICON_TOP_GAPS     = 7,
        ICON_BOTTOM_GAPS  = 7
    #elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_GAPS      = 10,
        // multi text
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 14,
        TEXT1_TOP_GAPS    = 13,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 14,
        TEXT2_BOTTOM_GAPS = 13,
        // single text
        TEXT_LEFT_GAPS    = 0,
        TEXT_RIGHT_GAPS   = 14,
        // image
        IMG_LEFT_GAPS     = 14,
        IMG_RIGHT_GAPS    = 16,
        IMG_MAX_WIDTH     = 60,
        IMG_MAX_HEIGHT    = 60,
        ICON_WIDTH        = 32,
        ICON_HEIGHT       = 32,
        ICON_RIGHT_GAPS   = 14,
        ICON_LEFT_GAPS    = 16,
        IMG_WIDTH         = 60,
        IMG_HEIGHT        = 60,
        ICON_TOP_GAPS     = 13,
        ICON_BOTTOM_GAPS  = 13
     #else
        DEFAULT_GAPS      = 10,
        // multi text
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 14,
        TEXT1_TOP_GAPS    = 13,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 14,
        TEXT2_BOTTOM_GAPS = 13,
        // single text
        TEXT_LEFT_GAPS    = 0,
        TEXT_RIGHT_GAPS   = 14,
        // image
        IMG_LEFT_GAPS     = 14,
        IMG_RIGHT_GAPS    = 16,
        IMG_MAX_WIDTH     = 60,
        IMG_MAX_HEIGHT    = 60,
        ICON_WIDTH        = 32,
        ICON_HEIGHT       = 32,
        ICON_RIGHT_GAPS   = 14,
        ICON_LEFT_GAPS    = 16,
        IMG_WIDTH         = 60,
        IMG_HEIGHT        = 60,
        ICON_TOP_GAPS     = 13,
        ICON_BOTTOM_GAPS  = 13
    #endif
    };

    enum ListModeEnum
    {
        VCP_LIST_MENU_CELL_STYLE_SNS, // single text & small icon at top
        VCP_LIST_MENU_CELL_STYLE_MSG, // multi text & small icon at top
        VCP_LIST_MENU_CELL_STYLE_TOTAL
    };

// Constructor / Destructor
public:
    // Default constructor
    VappPhbListMenuItemBase(ListModeEnum listMode = VCP_LIST_MENU_CELL_STYLE_SNS);

// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void);
    virtual void onUpdateTextFrameStyle(VcpListMenuFieldEnum fieldType, VfxTextFrame *frame);
    virtual void onUpdateTextViewStyle(VcpListMenuFieldEnum fieldType, VcpTextView *frame);

#ifdef __SOCIAL_NETWORK_SUPPORT__
    void setAsyncImgContent(const VfxWString &imagePath);

    static void *memAllocator(VfxU32 size, void *userData);

    static void memDeallocator(void *mem, void *userData);
#endif /*__SOCIAL_NETWORK_SUPPORT__*/

// Implementation
public:
    // Set list mode
    void setListMode(ListModeEnum listMode);

// Variable
private:
    // List mode
    ListModeEnum m_listMode;

    // Image frame
#ifdef __SOCIAL_NETWORK_SUPPORT__
    VappPhbPhotoBorderFrame *m_imageFrame;
    VcpAsyncImageFrame *m_asyncFrame;
    VfxWString m_asyncImgPath;
#else
    VcpPhotoBorderFrame *m_imageFrame;
#endif /*__SOCIAL_NETWORK_SUPPORT__*/

    // Text frame
    VfxFrame *m_textFrame;
    VfxFrame *m_subText;

    // Icon frame
    VfxImageFrame *m_iconFrame;
};

#endif /*__VAPP_PHB_MENU_LIST_CP_H__ */

