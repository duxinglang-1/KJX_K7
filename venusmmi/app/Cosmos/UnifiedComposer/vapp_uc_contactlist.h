#ifndef _VAPP_UC_CONTACTLIST_H
#define _VAPP_UC_CONTACTLIST_H

#include "mmi_features.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "..\Contact\ContactCore\vapp_contact_list.h"

class VappUcContactList:public VfxFrame,  public IVcpListMenuContentProvider
{
	 VFX_DECLARE_CLASS(VappUcContactList);
private:	

	VfxS32 m_hintlength;
	VfxWString m_hinttext;
	VcpListMenu* m_listmenu;
	ContactList *m_contactlist;
	VfxU32 m_alignField;
	VfxU8 m_contactlisttype;
	
protected:
	virtual void onInit();
public:

	enum
    {
		ENUM_VAPP_UC_CONTACTLIST_TYPE_NONE,
		ENUM_VAPP_UC_CONTACTLIST_TYPE_EMAIL,
		ENUM_VAPP_UC_CONTACTLIST_TYPE_PHBOOK,
		ENUM_VAPP_UC_CONTACTLIST_TYPE_TOTAL
	};

	VfxSignal1 <VfxU32> m_signalListUpdated;
    
    void setSearchString(const VfxWString& search);

    void setAlignField(VfxU32 alignField);

    void setGroup(VfxU32 groupId, VfxBool isEqual = VFX_TRUE);
	template <class _func_type>
	void setTappedHandler(VfxObject *obj, _func_type func)
	{
		this->m_listmenu->m_signalItemTapped.connect(obj, func);
	}
    
    void getList();

	ContactList *getContactList()
	{
		return m_contactlist;
	}

	VfxU8 getContactListType()
	{
		return m_contactlisttype;
	}

	// build list done
    void onListReady();

    // list changed
    void onListRefresh(ContactList* list, mmi_event_struct* evt);
		 
	VappUcContactList(VfxS32 len);
	VappUcContactList():m_hintlength(0),
                            m_listmenu(NULL),
                            m_contactlist(NULL)
	{
	}
	//virtual void setMenu(VcpListMenu *menu);
	virtual VfxBool getItemText(
		VfxU32 index,                    // [IN] the index of item
		VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		VfxWString &text,                // [OUT] the text resource
		VcpListMenuTextColorEnum &color  // [OUT] the text color
		);
	virtual VfxU32 getCount() const;
	virtual VfxBool getItemImage(
		VfxU32 index,                    
		VcpListMenuFieldEnum fieldType,  
		VfxImageSrc &image         
		) ;

	virtual VfxBool getItemTextFormat(
							VfxU32 index,                    // [IN] the index of item,
							VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
							VcpRichText &format        // [OUT] the text resource
						);	
	void updateHintList(VfxWChar *text);
	void onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex);
	VfxBool isMenuListActivated()
	{
		return (m_listmenu != NULL);
	}
};
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
#endif /* _VAPP_UC_CONTACTLIST_H */