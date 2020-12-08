#include "vfx_config.h"
#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_frame.h"
#include "vcp_list_menu.h"
#include "vfx_page.h"
#include "vfx_main_scr.h"
#include "vfx_string.h"
#include "vfx_draw_context.h"
#include "vfx_cpp_base.h"

#if  defined(__AFX_RT_TEST__) && defined(__COSMOS_MMI_PACKAGE__)
class VtstNmgr : public VfxApp
{
    VFX_DECLARE_CLASS(VtstNmgr);
// Override
public:
    virtual void onRun(void *args, VfxU32 argSize);
    VfxU32 getTestCaseCount(){return m_testCaseCount;}
    VfxU32 m_testCaseCount;
};


class VtstNmgrPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VtstNmgrPage);
// Override
public:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    virtual VfxU32 getCount() const 
	{
		VtstNmgr *nmgr = VFX_STATIC_CAST(getApp(), VtstNmgr*);
		return nmgr->getTestCaseCount();
	}
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
    }
private:
    void onItemTap(VcpListMenu *list, VfxU32 index);
    VcpListMenu *m_listMenu;
};

class VtstNmgrScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstNmgrScreen);
// Override
public:
    virtual void on1stReady();
};

class VtstNmgrTestCase
{
public:
    VfxWString name;
    void (* f)(void *);
};
#endif /* __AFX_RT_TEST__ */
