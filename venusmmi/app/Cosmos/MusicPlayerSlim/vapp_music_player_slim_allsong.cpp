
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vapp_music_player_slim_allsong.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
#include "vapp_music_player_slim_util.h"
#include "vapp_screen_lock_gprot.h"

/***************************************************************************** 
 * VappMusicPlayerAllSongsPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerAllSongsPage", VappMusicPlayerAllSongsPage, VfxPage);

void VappMusicPlayerAllSongsPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_INIT); 
    VfxPage::onInit();
    m_screen= VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSlimScreen);
    if(!m_screen)
    {
        return;    
    }
    m_session = getMusicPlayerSession();
    if(!m_session)
    {
        return;
    }
    m_session->m_signalSessionEvt.connect(this, &VappMusicPlayerAllSongsPage::onSessionCallback);
    m_precount = getCount();

    //Ctreat Title bar
    initTitleBar(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG));
}
void VappMusicPlayerAllSongsPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_DEINIT);

    if(m_selectingState != NULL)
    {
        VFX_FREE_MEM(m_selectingState);
        m_selectingState = NULL;
    }
    if(m_PathArray)
    {
        VFX_FREE_MEM(m_PathArray);
        m_PathArray = NULL;
    }
    VfxPage::onDeinit();
}
void VappMusicPlayerAllSongsPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_ENTER, isBackward);
    m_isBackward = isBackward;

    //init UI when first enter
    if(!m_isBackward)
    {
        initListMenu();
        initToolbarByCount(VFX_FALSE);
    }
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
    if (!checkMemoryCardReady())
    {
        disableToolbar(VFX_TRUE);
    }
#endif
    if(m_precount == 0)
    {
        updateUI(VFX_FALSE, VFX_TRUE);
    }
}
void VappMusicPlayerAllSongsPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SLIM_ALLSONG_ON_ENTERED);

    //add song in onEntered to show waiticon
    if(m_PathArray)
    {
        m_screen->showWaitIcon();
        disableToolbar(VFX_TRUE);
        m_listMenu->setIsUnhittable(VFX_TRUE);
        addMusic();
    }
}
SessionActionEnum VappMusicPlayerAllSongsPage::getActionMode()
{
    SessionActionEnum action = m_session->getActionMode();
    return action;
}
VfxBool VappMusicPlayerAllSongsPage::getItemText(VfxU32 index,
                            VcpListMenuFieldEnum fieldType,
                            VfxWString & text,
                            VcpListMenuTextColorEnum & color)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (checkHighLight(index))
        {
            color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
        }
        else
        {
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }

       //get song title
       VfxS32 ret;     
       ret = m_session->getTitle(index, text);
       if(ret == MUSIC_RET_ERR_LIST_DAMAGE)
       {
           m_listMenu->stopScrolling();
       
           m_screen->popupConfirm(
            VFX_WSTR_RES(STR_GLOBAL_ERROR),
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VCP_POPUP_TYPE_FAILURE,
            VCP_CONFIRM_BUTTON_SET_OK,
            VCP_POPUP_BUTTON_TYPE_WARNING
            );
       }
       else if(ret != MUSIC_RET_OK)
       {
           text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG);
       } 
    }
    return VFX_TRUE;
}
VfxBool VappMusicPlayerAllSongsPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_DISCLOSURE_IMG:
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            break;
        }
        case VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG:
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
            return VFX_FALSE;
        }    
         case VCP_LIST_MENU_FIELD_ICON:
            {
                if (checkHighLight(index))
                {
                    image.setResId(IMG_ID_VAPP_MUSICPLY_LIST_PLAYING);
                }
                break;
            }              
        default:
            break;
    };
    return VFX_TRUE;
}
VfxBool VappMusicPlayerAllSongsPage::checkHighLight(VfxS32 index)
{
    VfxBool showIcon = VFX_FALSE;
    VfxS32 actIdx = m_session->getActiveIndex();

    if (index == actIdx)
    {
        showIcon = VFX_TRUE;
    }
    return showIcon;
}
VcpListMenuItemStateEnum VappMusicPlayerAllSongsPage::getItemState(VfxU32 index) const
{
     if (m_selectingState && m_selectingState[index])
     {
         return VCP_LIST_MENU_ITEM_STATE_SELECTED;
     }
     else
     {
         return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
     }
}
VfxBool VappMusicPlayerAllSongsPage::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    VcpListMenuCell *cell = m_listMenu->getCell(index);

    if (m_listMenu && cell)
    {
        if (checkHighLight(index))
        {
            frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT));

            return VFX_TRUE;
        }
        if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT));
        }
        else
        {
            frame->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
VfxBool VappMusicPlayerAllSongsPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{       
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
    if (!checkMemoryCardReady())
    {
        text.loadFromRes(STR_GLOBAL_INSERT_MEMORY_CARD);
        return VFX_TRUE;
    }
#endif
    VfxU32 count = getCount();
    SessionActionEnum action = getActionMode();

    //if in adding state not show no song text
    if(!count && action != SESSION_ACT_ADD)
    {
        text.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
    return VFX_TRUE;
}
void VappMusicPlayerAllSongsPage::onBack()
{ 
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_BACK, m_isMultiselect);

    if( m_isMultiselect)
    {
        onFuncDeleteStop();
        initAfterAddToolbar();
        return;
    }
    SessionActionEnum action = getActionMode();    
    if(action == SESSION_ACT_ADD )
    {
        m_AddPathNum = m_fmgrPathNum;
        m_session->addMusicCancel();
        return;
    }
    VfxPage::onBack();
}
VfxU32 VappMusicPlayerAllSongsPage::getCount() const
{
    VfxU32 count = m_session->getCount();
    return count;
}
VfxBool VappMusicPlayerAllSongsPage::onKeyInput(VfxKeyEvent &event)
{
    return VfxPage::onKeyInput(event);
}
void VappMusicPlayerAllSongsPage::initTitleBar(VfxWString str)
{
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    m_titleBar->setTitle(str);
    setTopBar(m_titleBar);
}
void VappMusicPlayerAllSongsPage::initListMenu()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_INIT_LIST_MENU);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    m_listMenu->setSize(getSize());
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_TRUE);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_TRUE);
    m_listMenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    //Assign highlight color to green
    VcpListMenuThemeStruct themeData = m_listMenu->getThemeData();
    themeData.highlightTextColor = VRT_COLOR_MAKE(255, 94, 149, 18);
    m_listMenu->setThemeData(themeData);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappMusicPlayerAllSongsPage::onListMenuItemTapped);
    m_listMenu->m_signalItemLongTapped.connect(this, &VappMusicPlayerAllSongsPage::onListMenuItemLongTapped);
}
void VappMusicPlayerAllSongsPage::initToolbarByCount(VfxBool isBackward)
{
    VfxU32 current_cnt = getCount();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_INIT_TOOLBAR_BY_COUNT, isBackward, current_cnt, m_precount);

    if(isBackward)
    {
        if(current_cnt)
        {
            if(m_precount == 0)
            {
                initAfterAddToolbar();    
            }
            else
            {
                //no need to update toolbar if unchange
            }
        }
        else
        {
            initAddToolbar();
        }
    }
    else
    {
        if(m_precount)
        {
            initAfterAddToolbar();    
        }
        else
        {
            initAddToolbar();
        }
    }
}
mmi_ret VappMusicPlayerAllSongsPage::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_PROC, evt->evt_id, 0, m_fmgrPathNum);

    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_FMGR_MEDIA_PICKER_RESULT:
        {
            //get file path from fmgr
            vcui_folder_selector_result_event_struct *fmgrEvt = (vcui_folder_selector_result_event_struct *)evt;
            if(fmgrEvt->result >0)
            {
                m_fmgrPathNum = vcui_fmgr_media_picker_get_picked_num(m_fsId);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_PROC, evt->evt_id, fmgrEvt->result, m_fmgrPathNum);
                VFX_ALLOC_MEM(m_PathArray, sizeof(vcui_fmgr_media_path_struct)*m_fmgrPathNum, this);
                vcui_fmgr_media_picker_get_picked_path(m_fsId, m_PathArray, m_fmgrPathNum);
                vcui_fmgr_media_picker_close(m_fsId);   
                return MMI_RET_OK;
            }
            else
            {
                //close fmgr cui if result error
                vcui_fmgr_media_picker_close(m_fsId);
            }
            break;
        }
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            return onProcPreLockRouting();
        } 
        default:
            break;
    }
    return VfxPage::onProc(evt);
}
void VappMusicPlayerAllSongsPage::setToolbar(VappMusicPlayerToolbarItemStruct *itemsStruct, VfxU32 itemNum)
{
    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->m_signalButtonTap.connect(this, &VappMusicPlayerAllSongsPage::eventHandler);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, toolbar, VFX_FALSE);
    for (VfxU32 i = 0; i < itemNum; i++)
    {
        toolbar->addItem(itemsStruct[i].id, itemsStruct[i].str, itemsStruct[i].iconResID);
    }
}
void VappMusicPlayerAllSongsPage::popupMenu(VfxWString str, VappMusicPlayerMenuPopupItemStruct *itemList, VfxU32 itemCount)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_POPUP_MENU);

    VFX_OBJ_CREATE(m_popupMenu, VcpMenuPopup, this);
    m_popupMenu->setTitle(str);
    m_popupMenu->setAutoDestory(VFX_TRUE);
    m_popupMenu->m_signalMenuCallback.connect(this, &VappMusicPlayerAllSongsPage::onMenuItemTapped);
    for (VfxU32 i = 0; i < itemCount; i++)
    {
        m_popupMenu->addItem(itemList[i].id, itemList[i].str);
    }
    m_popupMenu->show(VFX_TRUE);
}
void VappMusicPlayerAllSongsPage::popupConfirm(
                            VfxWString strHint, 
                            VfxWString strBtn, 
                            VcpPopupTypeEnum popupType, 
                            VcpConfirmPopupButtonSetEnum buttonSet, 
                            VcpPopupButtonTypeEnum buttonType)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_POPUP_CONFIRM);

    VFX_OBJ_CREATE(m_popupConfirm, VcpConfirmPopup, this);
    m_popupConfirm->setInfoType(popupType);
    m_popupConfirm->setText(strHint);
    m_popupConfirm->setButtonSet(buttonSet);
    if (buttonSet == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
    {
        m_popupConfirm->setCustomButton(strBtn , VFX_WSTR_RES(STR_GLOBAL_CANCEL), buttonType, VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    m_popupConfirm->show(VFX_TRUE);
    m_popupConfirm->m_signalButtonClicked.connect(this, &VappMusicPlayerAllSongsPage::eventHandler);
    m_popupConfirm->setAutoDestory(VFX_TRUE);
}
void VappMusicPlayerAllSongsPage::onMenuItemTapped(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    SessionActionEnum action = getActionMode();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_MENU_ITEM_TAPPED, action);

    if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        VfxId id = item->getId();
        switch (id)
        {
            case FUNC_ID_CM_REMOVE:
            {
                m_longTapComm.action = SESSION_ACT_DELETE;
                onFuncDelete(VFX_FALSE);
            }
                break;
            case FUNC_ID_CM_CANCEL:
            {
                popupMenuClose();
                break;      
            }
            default:
                break;
        };
    }
    m_popupMenu = NULL;
}
void VappMusicPlayerAllSongsPage::createFmgrCui()
{
    //lanuch FMGR cui Create E folder 
    VfxU8 drvCard = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
    VfxWString str;
    if (srv_fmgr_drv_is_accessible(drvCard) == MMI_TRUE)
    {
        str = VfxWString().format("%c:\\", drvCard);
    }
    FMGR_FILTER filter;
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter,FMGR_TYPE_FOLDER);
    srv_fmgr_types_filter_set_group(&filter, FMGR_GROUP_AUDIO);
    m_fsId = vcui_fmgr_media_picker_create(
               getApp()->getGroupId(), 
               /*(const WCHAR*)str.getBuf()*/(const WCHAR*)L"root", 
               &filter, 
               VCUI_FMGR_MEDIA_PICKER_STYLE_READ, 
               VCUI_FMGR_MEDIA_PICKER_OPT_FIXED_PATH_ON | VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_ALL);

    if (GRP_ID_INVALID == m_fsId)
    {  
        vcui_fmgr_media_picker_close(m_fsId);
    }
    vcui_fmgr_media_picker_run(m_fsId);
}
VfxBool VappMusicPlayerAllSongsPage::checkIsListMax()
{
    VfxU32 count = getCount();
    if(count == VAPP_MUSICPLY_MAX_SONG_NUM)
    {
        //show list full popup
        popupConfirm(
            VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG),
            VFX_WSTR_RES(STR_GLOBAL_OK),
            VCP_POPUP_TYPE_FAILURE,
            VCP_CONFIRM_BUTTON_SET_OK,
            VCP_POPUP_BUTTON_TYPE_WARNING
            );
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
void VappMusicPlayerAllSongsPage::eventHandler(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_EVENT_HANDLER, id);

    switch (id)
    {
        case FUNC_ID_TB_BTN_REMOVE:
        {
            pageMultiSelectOn();
            break;
        }
        case FUNC_ID_TB_BTN_ADD_SONGS:
        {
            if(!checkIsListMax())
            {
                createFmgrCui();
            }
            break;
        }
        //Confirm toolbar button handle
        case FUNC_ID_TB_BTN_OK:
        {
            m_listMenu->stopScrolling();
            onFuncDelete();
            break;
        }
        case FUNC_ID_TB_BTN_CANCEL:
        {
            //Multi select page with cancel button
            onFuncDeleteStop();
            initAfterAddToolbar();
            //updateUI(VFX_FALSE, VFX_TRUE);
            break;
        }
        case FUNC_ID_TB_BTN_SELECT_ALL:
        {
            if (isSelectAll())
            {
                deselectAll();
            }
            else
            {
                selectAll();
            }
            updateSelectingUI();        
            m_listMenu->updateAllControls();          
            break;
        }
        //Popup button handle
        case VCP_CONFIRM_POPUP_BUTTON_OK:
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            //deleting action
            if (SESSION_ACT_DELETE == m_longTapComm.action)
            {
                popupProgress(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVING));
                    //single delete
                if(m_session->getActiveIndex() == m_longTapComm.index)
                {
                    VfxWString info;
                    info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE);
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
                        popupProgressClose();
                }
                else
                {
                   del(m_longTapComm.index);
                }
            }
            else
            {
                if(m_selectingCount > 0)
                {
                    //multi delete
                   popupProgress(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVING));
                   delSelected();
                   disableToolbar(VFX_TRUE);

                }
            }            
            m_popupConfirm = NULL;
            break;
        }   
        case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        { 
            //single delete
            if(m_session->getActiveIndex() == m_longTapComm.index)
            {
                m_longTapComm.action = SESSION_ACT_NONE; 
            }
            m_popupConfirm = NULL;
            break;
        }
        default:
            break;
    };
}
void VappMusicPlayerAllSongsPage::onFuncDelete(VfxBool isMulti)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_FUNC_DELETE, isMulti);

    VfxWString strHint;
    VfxWString strBtn;
    if (isMulti)
    {
        VfxWString selectCount;
        selectCount.format("(%d)?", getSelectingCount());
        strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_HINT);
        strHint += selectCount;
    }
    else
    {
        strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_RMV_SONG);
    }
    strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);

    popupConfirm(
        strHint,
        strBtn,
        VCP_POPUP_TYPE_WARNING,
        VCP_CONFIRM_BUTTON_SET_USER_DEFINE,
        VCP_POPUP_BUTTON_TYPE_WARNING
        );
    m_popupMenu = NULL;
}
void VappMusicPlayerAllSongsPage::postProcFuncDeleteStop(VfxTimer *timer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_POST_PROC_FUNC_DELETE_STOP);

    VFX_OBJ_CLOSE(timer);
    onFuncDeleteStop();
    m_longTapComm.action = SESSION_ACT_NONE;
    initToolbarByCount(VFX_FALSE);
    disableToolbar(VFX_FALSE);
    updateUI(VFX_FALSE, VFX_TRUE);
}
void VappMusicPlayerAllSongsPage::onFuncDeleteStop()
{    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_FUNC_DELETE_STOP);

    pageMultiSelectOff();
    popupProgressClose();
}
void VappMusicPlayerAllSongsPage::popupMenuClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_POPUP_MENU_CLOSE);

    if (m_popupMenu)
    {
        m_popupMenu->exit(VFX_TRUE);
        m_popupMenu = NULL;
    }
}
void VappMusicPlayerAllSongsPage::popupProgress(VfxWString str)
{
    VFX_OBJ_CREATE(m_popupIndicator, VcpIndicatorPopup, this);
    m_popupIndicator->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_popupIndicator->setAutoDestory(VFX_TRUE);
    m_popupIndicator->m_signalCanceled.connect(this, &VappMusicPlayerAllSongsPage::onProgressCanceled);
    m_popupIndicator->setText(str);
    m_popupIndicator->show(VFX_TRUE);
    m_popupIndicator->setProgress(0.0f);
}
void VappMusicPlayerAllSongsPage::popupProgressClose()
{
    if (m_popupIndicator)
    {
        if (m_session->isBackLightOn())
        {
            m_popupIndicator->exit(VFX_TRUE);
        }
        else
        {
            m_popupIndicator->exit(VFX_FALSE);
        }
        m_popupIndicator = NULL;
    }
}
void VappMusicPlayerAllSongsPage::onProgressCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    SessionActionEnum action = getActionMode();
    if (m_popupIndicator)
    {
        m_popupIndicator = NULL;
    }
    if (1.0 != curr_progress)
    {
        if (SESSION_ACT_DELETE == action)
        {
            m_session->delCancel();
        }
    }
}
void VappMusicPlayerAllSongsPage::onMemoryCardChange(VfxBool isplugIn)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_MEMORY_CARD_CHANGE, isplugIn);
    if(!isplugIn)
    {
        initAddToolbar();
        disableToolbar(VFX_TRUE);
        //plug out multiselect set to false
        m_isMultiselect = VFX_FALSE;
    }
    else
    {
        pageMultiSelectOff();
    }
    m_listMenu->updateAllItems();
}
void VappMusicPlayerAllSongsPage::pageMultiSelectOn(VfxBool isAnim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_PAGE_MULTISELECT_ON);

    if(!m_listMenu)
    {
        return;
    }
    m_isMultiselect = VFX_TRUE;
    selectStart();
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, isAnim);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappMusicPlayerAllSongsPage::onItemSelectionStateChanged);
    m_listMenu->m_signalItemTapped.disconnect(this, &VappMusicPlayerAllSongsPage::onListMenuItemTapped);
    m_listMenu->m_signalItemLongTapped.disconnect(this, &VappMusicPlayerAllSongsPage::onListMenuItemLongTapped);

    //multiselect view tool bar 
    initMultiSelectToolbar();
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_TRUE);

    //chage title bar and tool bar state
    getToolBar()->setDisableItem(FUNC_ID_TB_BTN_OK, VFX_TRUE);
    getTitleBar()->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_REMOVE_ALLSONGS));
}
void VappMusicPlayerAllSongsPage::pageMultiSelectOff(VfxBool isAnim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_PAGE_MULTISELECT_OFF);

    if (!isSelectStart())
    {
        return;
    }
    selectEnd();
    m_isMultiselect = VFX_FALSE;
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, isAnim);
    m_listMenu->m_signalItemSelectionStateChanged.disconnect(this, &VappMusicPlayerAllSongsPage::onItemSelectionStateChanged);
    m_listMenu->m_signalItemTapped.connect(this, &VappMusicPlayerAllSongsPage::onListMenuItemTapped);
    m_listMenu->m_signalItemLongTapped.connect(this, &VappMusicPlayerAllSongsPage::onListMenuItemLongTapped);

    //chage title bar and tool bar state
    getTitleBar()->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG));
}
void VappMusicPlayerAllSongsPage::selectStart()
{
    m_isSelectStart = VFX_TRUE;
    m_selectingCount = 0;

    //Allocate memory to store select state
    if(NULL == m_selectingState)
    {
        VfxU32 count = getCount();
        if (count > 0)
        {
            if(m_selectingState != NULL)
            {
                VFX_FREE_MEM(m_selectingState);
                m_selectingState = NULL;
            }
            VFX_ALLOC_MEM(m_selectingState, sizeof(VfxBool)*count, this);
            kal_mem_set(m_selectingState, 0, sizeof(VfxBool)*count);
        }
    }
    m_session->delMultiSelectStart();
}
void VappMusicPlayerAllSongsPage::selectEnd()
{
    m_isSelectStart = VFX_FALSE;
    m_selectingCount = 0;
    if(m_selectingState != NULL)
    {
        VFX_FREE_MEM(m_selectingState);
        m_selectingState = NULL;
    }
    m_session->delMultiSelectEnd();
}
void VappMusicPlayerAllSongsPage::selectAll()
{
    setAllSelectingState(VFX_TRUE);
    m_session->delSelectAll();
}
void VappMusicPlayerAllSongsPage::deselectAll()
{
    setAllSelectingState(VFX_FALSE);
    m_session->delDeselectAll();
}
VfxBool VappMusicPlayerAllSongsPage::isSelectStart()
{
    return m_isSelectStart;
}
VfxBool VappMusicPlayerAllSongsPage::isSelectAll()
{
    VfxU32 count = getCount();
    return m_selectingCount == count;
}
VfxBool VappMusicPlayerAllSongsPage::isSelectNone()
{
    return m_selectingCount == 0;
}
VfxU32 VappMusicPlayerAllSongsPage::getSelectingCount()
{
    return m_selectingCount;
}
void VappMusicPlayerAllSongsPage::setSelectingState(VfxU32 idx, VfxBool isSelect)
{
    if (m_selectingState)
    {
        if (isSelect)
        {
            if (!m_selectingState[idx])
            {
                m_selectingCount++;
            }
        }
        else
        {
            if (m_selectingState[idx])
            {
                m_selectingCount--;
            }
        }
        m_selectingState[idx] = isSelect;
    }
}
void VappMusicPlayerAllSongsPage::setAllSelectingState(VfxBool isSelect)
{
    if (m_selectingState)
    {
        VfxU32 count = getCount();

        for (VfxU32 i = 0; i < count; i++)
        {
            m_selectingState[i] = isSelect;
        }

        m_selectingCount = isSelect ? count : 0;
    }
}
VfxBool VappMusicPlayerAllSongsPage::getSelectingState(VfxU32 idx)
{
    if (m_selectingState && idx < getCount())
    {
        return m_selectingState[idx];
    }
    return VFX_FALSE;
}
void VappMusicPlayerAllSongsPage::select(VfxU32 index)
{
    if (!getSelectingState(index))
    {
        setSelectingState(index, VFX_TRUE);
        m_session->delSelectItem(index);
    }
}
void VappMusicPlayerAllSongsPage::deselect(VfxU32 index)
{
    if (getSelectingState(index))
    {
        setSelectingState(index, VFX_FALSE);
        m_session->delDeselectItem(index);
    }
}
VfxBool VappMusicPlayerAllSongsPage::isSelected(VfxU32 index)
{
    return m_session->delIsSelectedItem(index);
}

void VappMusicPlayerAllSongsPage::del(VfxU32 index)
{
    m_session->delMusic(index);
}
void VappMusicPlayerAllSongsPage::delSelected()
{
    m_session->delSelectedMusic();
}
void VappMusicPlayerAllSongsPage::delCancel()
{
    return m_session->delCancel();
}
void VappMusicPlayerAllSongsPage::onItemSelectionStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{ 
    VfxU32 idx = index;

    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        select(idx);
    }
    else
    {
        deselect(idx);
    }
    updateSelectingUI();
}
void VappMusicPlayerAllSongsPage::updateSelectingUI()
{
    VcpToolBar *bar = getToolBar();
    if (bar)
    {
        bar->setDisableItem(FUNC_ID_TB_BTN_OK, isSelectNone());

        if (isSelectAll())
        {
            bar->changeItem(FUNC_ID_TB_BTN_SELECT_ALL, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_UNSELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        }
        else
        {
            bar->changeItem(FUNC_ID_TB_BTN_SELECT_ALL,  VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        }
    }
}
void VappMusicPlayerAllSongsPage::initAddToolbar()
{
    VappMusicPlayerToolbarItemStruct items[1];
    items[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD;
    items[0].id = FUNC_ID_TB_BTN_ADD_SONGS;
    items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD);
    setToolbar(items, 1);
}
void VappMusicPlayerAllSongsPage::initMultiSelectToolbar()
{
    VappMusicPlayerToolbarItemStruct items[3];
    items[0].id = FUNC_ID_TB_BTN_SELECT_ALL;
    items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL);
    items[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
    items[1].id = FUNC_ID_TB_BTN_OK;
    items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
    items[1].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
    items[2].id = FUNC_ID_TB_BTN_CANCEL;
    items[2].str.loadFromRes(STR_GLOBAL_CANCEL);
    items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
    setToolbar(items, 3);
}
void VappMusicPlayerAllSongsPage::initAfterAddToolbar()
{
    VappMusicPlayerToolbarItemStruct items[2];
    items[0].id = FUNC_ID_TB_BTN_ADD_SONGS;
    items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD);
    items[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD;
    items[1].id = FUNC_ID_TB_BTN_REMOVE;
    items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
    items[1].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
    setToolbar(items, 2);
}
void VappMusicPlayerAllSongsPage::onListMenuItemTapped(VcpListMenu *sender, VfxU32 index)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_LISTMENU_ITEM_TAPPED);

    if (m_listMenu && (m_listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION))
    {
        return;
    }
    if(isMakingCall())
    {
        VfxWString info;
        info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
        return;
    }
    //Go to now playing screen and play
    m_screen->popPage();
    m_session->startPlay(index);
}
void VappMusicPlayerAllSongsPage::onListMenuItemLongTapped(VcpListMenu *sender, VfxU32 index)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_LISTMENU_ITEM_LONG_TAPPED);

    VfxWString title;
    VcpListMenuTextColorEnum color;
    getItemText(index, VCP_LIST_MENU_FIELD_TEXT, title, color);
    m_longTapComm.index = index;

    //popup longtap remove menu
    VappMusicPlayerMenuPopupItemStruct itemList[2];
    itemList[0].id = FUNC_ID_CM_REMOVE;
    itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
    itemList[1].id = FUNC_ID_CM_CANCEL;
    itemList[1].str.loadFromRes(STR_GLOBAL_CANCEL);
    popupMenu(title, itemList, 2);
}
VcpToolBar* VappMusicPlayerAllSongsPage::getToolBar()
{
    return static_cast<VcpToolBar*>(VfxPage::getBar(VFX_PAGE_BAR_LOCATION_BOTTOM));
}
VcpTitleBar* VappMusicPlayerAllSongsPage::getTitleBar()
{
    return static_cast<VcpTitleBar*>(VfxPage::getBar(VFX_PAGE_BAR_LOCATION_TOP));
}
void VappMusicPlayerAllSongsPage::disableToolbar(VfxBool isDisable)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_DISABLE_TOOL_BAR);
    VcpToolBar *bar = getToolBar();
    VfxBool isReady;
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
    isReady = checkMemoryCardReady();
#else
    isReady = VFX_TRUE;
#endif    
    if(isReady)
    {
        if (bar)
        {
            bar->setDisableItem(FUNC_ID_TB_BTN_SELECT_ALL, isDisable);  
            bar->setDisableItem(FUNC_ID_TB_BTN_ADD_SONGS, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_REMOVE, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_OK, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_CANCEL, isDisable);
        }
    }
    else
    {
        if (bar)
        {
            bar->setDisableItem(FUNC_ID_TB_BTN_ADD_SONGS, VFX_TRUE);
        }
    }
}
void VappMusicPlayerAllSongsPage::onSessionCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_ON_SESSION_CALLBACK, cb_event, result, ca_para_2);

    SessionActionEnum action = getActionMode();
    switch (cb_event)
    {      
        case MUSIC_CB_OPEN:
        {
            if (MUSIC_RET_OK == result)
            {
                m_precount = m_session->getCount();
                pageMultiSelectOff();
                initToolbarByCount(VFX_FALSE);
                updateUI(VFX_TRUE, VFX_TRUE);
            }
            else if(MUSIC_RET_ASYNC == result)
            {
                if(checkMemoryCardReady())
                {
                    m_screen->showWaitIcon();
                }
            }
            else if(MUSIC_RET_MEMORY_FULL == result)
            {
                //show open fail popup
                m_screen->popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MEMORY_FULL),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );            
            }
            else if(MUSIC_RET_MSDC_NOTEXIST == result)
            {          
                //show open fail popup           
            }
            else
            {
                //show open fail popup
                m_screen->popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_OPEN_LIST),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );            
            }
            break;
        }
        case MUSIC_CB_ADD:
        {
            if (MUSIC_RET_OK == result)
            {
                if(m_AddPathNum == m_fmgrPathNum)
                {
                    //add done 
                    initToolbarByCount(VFX_TRUE);
                    updateUI(VFX_TRUE, VFX_TRUE);
                    addDoneProc();
                }
                else
                {
                    //add next path
                    addMusic();
                }
            }
            else if(MUSIC_RET_LIST_FULL == result)
            {
                //hide wait icon
                updateUI(VFX_TRUE, VFX_TRUE);
                initToolbarByCount(VFX_TRUE);
                //show list full popup
                popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );
                addDoneProc();
            }
            else if(MUSIC_RET_MEMORY_FULL == result)
            {
                //hide wait icon
                updateUI(VFX_TRUE, VFX_TRUE);
                //show memory full popup
                popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MEMORY_FULL),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );
                addDoneProc();
            }
            else
            {
                //hide wait icon
                updateUI(VFX_TRUE, VFX_TRUE);
                addDoneProc();
            }
            break;            
        }
        case MUSIC_CB_SONG_SWITCHED:
        {
            //update highlight index
            updateUI(VFX_TRUE, VFX_TRUE);
            break;
        }
        case MUSIC_CB_DELETE_ACTIVE:
        {
            //delete active song popup error
            VfxWString info;
            info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
            onFuncDeleteStop();
            initToolbarByCount(VFX_FALSE);
            updateUI(VFX_FALSE, VFX_TRUE);
        }
        case MUSIC_CB_DELETE:
        {
            if (MUSIC_RET_OK == result)
            {
                if (m_popupIndicator)
                {
                    m_popupIndicator->setProgress(1);
                    m_popupIndicator->setIsDisabled(VFX_TRUE);
                }
            }
            //delete done
            if (SESSION_ACT_NONE == action)
            {
                VfxTimer *timer;
                VFX_OBJ_CREATE(timer, VfxTimer, this);
                timer->setStartDelay(VCP_PROGRESS_INDICATOR_PATTERN_MOTION_TIME);
                timer->m_signalTick.connect(this, &VappMusicPlayerAllSongsPage::postProcFuncDeleteStop);
                timer->start();
                m_precount = getCount();
            }
            break;            
        }
        
        case MUSIC_CB_DELETE_PROGRESS:
        {
            if (m_popupIndicator)
            {
                m_popupIndicator->setProgress(VfxFloat(ca_para_2)/100.0f);
            }

            break;            
        }
        case MUSIC_CB_MSDC_PLUG_IN:
        {
            closeAllSongPopup();
            break;
        }
        case MUSIC_CB_MSDC_PLUG_OUT:
        {
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
            closeAllSongPopup();
            onMemoryCardChange(VFX_FALSE);
            if (GRP_ID_INVALID != m_fsId)
            {  
                vcui_fmgr_media_picker_close(m_fsId);
            }
#else
            //to update highlight index
            m_listMenu->updateAllItems();
#endif
            break;
        }
        default:
            break;
    }

}

void VappMusicPlayerAllSongsPage::updateUI(VfxBool isHide, VfxBool isUpdate)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_UPDATE_UI);

    if(isHide)
    {
        m_screen->hideWaitIcon();
    }

    if(isUpdate)
    {
        m_listMenu->updateAllItems();
    }
}
void VappMusicPlayerAllSongsPage::addMusic()
{
    S32 temp;
    for (; m_AddPathNum< m_fmgrPathNum; m_AddPathNum++)
    {
        VfxWString path;
        temp = m_AddPathNum;
        path.loadFromMem(m_PathArray[m_AddPathNum].path);
        
        //add folder is async need to update num in session callback        
        if(m_PathArray[m_AddPathNum].isFolder)
        {
            m_session->addMusicFromFolder(path);
            if(++temp == m_fmgrPathNum)
            {
                VFX_FREE_MEM(m_PathArray);
                m_PathArray = NULL;
                m_precount = m_session->getCount();
            }
        }
        else
        {
            //add song is sync direct update num
            VfxS32 result = MUSIC_RET_OK;
            result = m_session->addMusic(path);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_ALLSONG_PAGE_ADDMUSIC, result);
            if(result == MUSIC_RET_OK || result == MUSIC_RET_UNSUPPORTED_FILE)
            {
            if(++temp == m_fmgrPathNum)
            {
                initToolbarByCount(VFX_TRUE);
                updateUI(VFX_TRUE, VFX_TRUE);
                VFX_FREE_MEM(m_PathArray);
                m_PathArray = NULL;
                    addDoneProc();
                    
                    //show unsupported file type popup when add one file
                    if(result == MUSIC_RET_UNSUPPORTED_FILE && 1 == m_fmgrPathNum)
                    {
                        popupConfirm(
                                VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNSUPPORTED_FILE_TYPE),
                            VFX_WSTR_RES(STR_GLOBAL_OK),
                            VCP_POPUP_TYPE_FAILURE,
                            VCP_CONFIRM_BUTTON_SET_OK,
                            VCP_POPUP_BUTTON_TYPE_WARNING
                            );
                    }
                break;
            }
        }
            else
            {
                //hide wait icon
                updateUI(VFX_TRUE, VFX_FALSE);
                addDoneProc();
                if(MUSIC_RET_LIST_FULL == result)
                {
                //show list full popup
                popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );
            }
            else if(MUSIC_RET_MEMORY_FULL == result)
                {
                //show memory full popup
                popupConfirm(
                        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MEMORY_FULL),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );
            }
            else
            {
                    //show error full popup
                popupConfirm(
                        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_OPEN_LIST),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );
                }
                if(m_PathArray)
                {
                    VFX_FREE_MEM(m_PathArray);
                    m_PathArray = NULL;
                }
                break;
            }
        }
    }

}

mmi_ret VappMusicPlayerAllSongsPage::onProcPreLockRouting()
{
    SessionActionEnum action = getActionMode();

    if (m_popupIndicator) 
    {
        //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_PRE_LOCK_ROUTING_1, action);
        return MMI_RET_ERR;
    }
    else
    {
        //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_PRE_LOCK_ROUTING_3, action);
        return MMI_RET_OK;
    }
}

VfxBool VappMusicPlayerAllSongsPage::closeAllSongPopup(VfxBool isClose)
{
    VfxBool closePopup = VFX_FALSE;
    if (m_popupIndicator)
    {
        if (!isClose)
        {
            m_popupIndicator = NULL;
        }
        popupProgressClose();
        onProgressCanceled(NULL, 0);
        onFuncDeleteStop();
        closePopup = VFX_TRUE;
    }

    if (m_popupConfirm)
    {
        if (!isClose)
        {
            m_popupConfirm = NULL;
        }
        popupConfirmClose();
        eventHandler(NULL, VCP_CONFIRM_POPUP_BUTTON_CANCEL);
        //eventHandler(NULL, VCP_CONFIRM_POPUP_BUTTON_USER_2);

        closePopup = VFX_TRUE;
    }

    if (m_popupMenu)
    {
        popupMenuClose();

        closePopup = VFX_TRUE;
    }
    if(m_screen)
    {
        m_screen->popupConfirmClose();
    }
    return closePopup;
}

void VappMusicPlayerAllSongsPage::popupConfirmClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_CONFIRM_CLOSE);

    if (m_popupConfirm)
    {
            m_popupConfirm->exit(VFX_TRUE);
        m_popupConfirm = NULL;
    }
}
void VappMusicPlayerAllSongsPage::addDoneProc()
{
    m_AddPathNum = 0;
    m_precount = getCount();
    disableToolbar(VFX_FALSE);
    m_listMenu->setIsUnhittable(VFX_FALSE);
}

#endif /*__MMI_MUSIC_PLAYER_SLIM__*/

