
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_ALLSONG_H__
#define __VAPP_MUSIC_PLAYER_ALLSONG_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_app.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"
#include "vapp_music_player_slim_datatype.h"
#include "vfx_mc_include.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_dataDef.h"
#include "vapp_fmgr_cui_gprot.h"

typedef struct
{
    VfxId id;
    VfxWString str;
    VfxResId iconResID;
}VappMusicPlayerToolbarItemStruct;

typedef struct
{
    VfxId id;
    VfxWString str;
}VappMusicPlayerMenuPopupItemStruct;

typedef struct
{
    SessionActionEnum action;
    VfxU32 index;
}VappMusicPlayerLongTapCommStruct;


/***************************************************************************** 
 * Music Player UI componet: Music player sub page class
 *****************************************************************************/
 
class VappMusicPlayerListMenu;
class VappMusicPlayerAppSlim;
class VappMusicPlayerSlimScreen;

class VappMusicPlayerAllSongsPage : public VfxPage , public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMusicPlayerAllSongsPage);
    
private:
        
    VcpTitleBar *m_titleBar;
    
    VcpListMenu *m_listMenu;
    
    VappMusicPlayerAppSlim *m_app;

    VappMusicPlayerSlimScreen *m_screen;
    
    PageIDEnum m_pageID;

    VcpMenuPopup *m_popupMenu;

    VfxBool m_isMultiselect;

    VcpConfirmPopup *m_popupConfirm;

    VcpIndicatorPopup *m_popupIndicator;

    VappMusicPlayerSession *m_session;

    VappMusicPlayerLongTapCommStruct m_longTapComm;
    
    VfxBool *m_selectingState;
    
    VfxU32 m_selectingCount;
    
    VfxBool m_isSelectStart;

	//fmgr cui id
    mmi_id m_fsId;

	//file path array get from fmgr
	vcui_fmgr_media_path_struct *m_PathArray;
	
	S32 m_fmgrPathNum;
	
	S32 m_AddPathNum;
	
    // the isBack flag in onEnter() function
    VfxBool m_isBackward;

	VfxU32 m_precount;

public:
    VappMusicPlayerAllSongsPage():
        m_titleBar(NULL),
        m_listMenu(NULL),
        m_app(NULL),
        m_screen(NULL),
        m_pageID(PAGE_ID_NONE),
        m_popupMenu(NULL),
        m_isMultiselect(VFX_FALSE),
        m_popupConfirm(NULL),
        m_popupIndicator(VFX_FALSE),
        m_session(NULL), 
        m_selectingState(NULL),
        m_selectingCount(0),
        m_isSelectStart(NULL),
        m_fsId(GRP_ID_INVALID),
        m_PathArray(NULL),
        m_fmgrPathNum(0),
        m_AddPathNum(0),
        m_isBackward(VFX_FALSE),
        m_precount(0)
        {};

protected:
	
	//VfxPage virtual function
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onBack();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);  

	//list menu virtual function
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType, VfxWString & text,VcpListMenuTextColorEnum & color);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame);
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
    
public:
    void initTitleBar(VfxWString str);
    VcpToolBar* getToolBar();
	VcpTitleBar* getTitleBar();
    SessionActionEnum getActionMode();
    void initListMenu();
    void initToolbarByCount(VfxBool isBackward);
    void setToolbar(VappMusicPlayerToolbarItemStruct *itemsStruct, VfxU32 itemNum);
    void popupMenu(VfxWString str, VappMusicPlayerMenuPopupItemStruct *itemList, VfxU32 itemCount);
    void popupConfirm(VfxWString strHint, VfxWString strBtn, VcpPopupTypeEnum popupType, VcpConfirmPopupButtonSetEnum buttonSet, VcpPopupButtonTypeEnum buttonType);
    void onMenuItemTapped(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void createFmgrCui();
    VfxBool checkIsListMax();
    void eventHandler(VfxObject* sender, VfxId id);
    void onFuncDelete(VfxBool isMulti = VFX_TRUE);
    void postProcFuncDeleteStop(VfxTimer *timer);
    void onFuncDeleteStop();
    void popupMenuClose();
    void popupProgress(VfxWString str);
    void popupProgressClose();
    void onProgressCanceled(VfxObject* obj, VfxFloat curr_progress);
    void initMultiSelectToolbar();
    void initAddToolbar();
    void initAfterAddToolbar();
    void onListMenuItemTapped(VcpListMenu *sender, VfxU32 index);
    void onListMenuItemLongTapped(VcpListMenu *sender, VfxU32 index);
	void onMemoryCardChange(VfxBool isplugIn);
    void pageMultiSelectOn(VfxBool isAnim = VFX_TRUE);
    void pageMultiSelectOff(VfxBool isAnim = VFX_TRUE);
    void disableToolbar(VfxBool isDisable);
    void onItemSelectionStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void updateSelectingUI();
    void onSessionCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    void selectStart();
    void selectEnd();
    void setSelectingState(VfxU32 idx, VfxBool isSelect);
    void selectAll();
    void deselectAll();
    void setAllSelectingState(VfxBool isSelect);
    void select(VfxU32 index);
    void deselect(VfxU32 index);
    void del(VfxU32 index);
    void delSelected();
    void delCancel();
    VfxBool isSelectStart();
    VfxBool isSelectAll();
    VfxBool isSelectNone();
    VfxBool getSelectingState(VfxU32 idx);
    VfxBool isSelected(VfxU32 index);
    VfxBool checkHighLight(VfxS32 index);
    VfxU32 getSelectingCount();
	void updateUI(VfxBool isHide, VfxBool isUpdate);
	void addMusic();
	mmi_ret onProcPreLockRouting();
	VfxBool closeAllSongPopup(VfxBool isClose = VFX_TRUE);
	void popupConfirmClose();
	void addDoneProc();

};

#endif //__VAPP_MUSIC_PLAYER_ALLSONG_H__
#endif /*__MMI_MUSIC_PLAYER_SLIM__*/
