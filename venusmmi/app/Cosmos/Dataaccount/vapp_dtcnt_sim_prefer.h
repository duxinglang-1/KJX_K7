/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_dtcnt_sim_prefer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define the class to select sim prefer
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_DTCNT_SIM_PREFER_H__
#define __VAPP_DTCNT_SIM_PREFER_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt.h"
extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
}
#include "mmi_res_range_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_DTCNT_SIM_PREFER_CLOSE = VAPP_DTCNT_SIM_PREFER + 1,
    EVT_ID_DTCNT_SIM_PREFER_SIM1,
    EVT_ID_DTCNT_SIM_PREFER_SIM2,
    EVT_ID_DTCNT_SIM_PREFER_SIM3,
    EVT_ID_DTCNT_SIM_PREFER_SIM4,
    EVT_ID_DTCNT_SIM_PREFER_END
} vapp_dtcnt_sim_prefer_enum;


/***************************************************************************** 
 * Class VappDtcntSimPreferPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for select sim prefer.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSimPreferPage : public VfxPageHandler, public IVcpListMenuContentProvider
{

public:
    VappDtcntSimPreferPage() : 
        m_menu(NULL),
        m_simType(SRV_DTCNT_SIM_TYPE_NONE),
        m_indicatorPopupPtr(NULL)
    {
    }
    virtual ~VappDtcntSimPreferPage() {}

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const ;

// override
public:
    virtual void onPageInit(VfxPageEx *page);
// method
public:
    VfxBool isAnyAccountInUse();
    VfxWString getSimName(VfxU32 simIndex);
    void AccountInUseNum(VfxU32 &num);
    void showAcctInUseConfirm();
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif
#ifdef __MMI_PNS__
    static mmi_ret updatePage(mmi_event_struct *evt);
#endif

// signal
protected:
    void onListItemTapped(
        VcpListMenu *sender, // Sender
        VfxU32 index        // List item index
    ) ;

    void onNotChangedConfirm(
        VfxObject* sender,     // sender 
        VfxId id          // id
    ) ;

private:
    VcpListMenu *m_menu;
    srv_dtcnt_sim_type_enum m_simType;
    VfxWeakPtr <VcpIndicatorPopup> m_indicatorPopupPtr;
};


/***************************************************************************** 
 * Class VappDtcntSimPreferApp
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Sim Prefer App Class.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSimPreferApp : public VfxCui, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappDtcntSimPreferApp);
// Construtor / Destructor
public:
    VappDtcntSimPreferApp() {};
    virtual ~VappDtcntSimPreferApp() {};

protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onScr1stReady(VfxMainScrEx *scr);

};


/***************************************************************************** 
 * Class VappDtcntSimPreferCell
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Sim Prefer Cell.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSimPreferCell: public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappDtcntSimPreferCell);

public:
    virtual void onInit();
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    void updateCell();
    static mmi_ret staticSimPreferProc(mmi_event_struct *evt);
    static VfxBool isSimPreferCellHideHdlr(); // need to hide the cell when sim card num less than 2
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif
};

#endif
#endif /* __VAPP_DTCNT_SIM_PREFER_H__ */
