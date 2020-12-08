/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    mmi_frm_key_routing.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   key routing mechanism
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "mmi_frm_gprot.h"
//#include "mmi_frm_prot.h"


//RHR Add
#include "mmi_frm_input_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
/*****************************************************************************
 * Global variables
 *****************************************************************************/
static  mmi_frm_translate_keyhandler_func_ptr g_translated_key_handler[MMI_FRM_TRANS_KEY_HANDLE_END] = {NULL};

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_app_translate_key_handler
 * DESCRIPTION
 *  This function is used to set translate key handler for applications.
 *  Currently, there are three layers for translate key handler,system layer,
 *  application layer and editor layer. Application layer and editor layer have
 *  the same translate key handler entry. So in fact we have tow level now.
 *  The invoke sequency is:
 *  if SYS == false
 *  then 
 *      if APP == false
        then traditional keyhandler
 *  or 
 *  if SYS== false
 *  then 
 *      if EDITOR == false
 *      then traditional keyhandler      
 *
 * PARAMETERS
 *  func_ptr      :[IN]   translate key handler that will be set
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_app_translate_key_handler(my_translate_key_handler);  
 * }
 * </code>
 *****************************************************************************/
void mmi_frm_set_app_translate_key_handler(mmi_frm_translate_keyhandler_func_ptr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, func_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_translate_key_handler
 * DESCRIPTION
 *  Currently, there are three layers for translate key handler,system layer,
 *  application layer and editor layer. application level and editor layer have
 *  the same translate key handler entry. So in fact we have tow level now.
 *  The invoke sequency is:
 *  if SYS == false
 *  then 
 *      if APP == false
        then traditional keyhandler
 *  or 
 *  if SYS== false
 *  then 
 *      if EDITOR == false
 *      then traditional keyhandler      
 *
 * PARAMETERS
 *  layer         :[IN]   translate key handler level which determine the invoke
 *                        sequency of the translate key handler
 *  func_ptr      :[IN]   translate key handler that will be set
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * //IME usage
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void some_input_method_proc()
 * {
 *     mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler);  
 * }
 * </code>
 *****************************************************************************/
void mmi_frm_set_translate_key_handler(mmi_frm_trans_key_handle_enum layer, mmi_frm_translate_keyhandler_func_ptr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(layer < MMI_FRM_TRANS_KEY_HANDLE_END);
    g_translated_key_handler[layer] = func_ptr;       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_app_translate_key_handler
 * DESCRIPTION
 *  Clear translate key handler for application layer.
 *  All translate key handler will be cleared when screen switch, so if application
 *  don't have special usage. It is not necessary to invoke this interface.
 *  we use func_ptr which application used when call mmi_frm_set_app_translate_key_handler
 *  as the parameters for futher extension.
 *  For example, we may support multi-translate key handler in the same layer
 *      mmi_frm_set_app_translate_key_handler(my_translate_key_handler1);
 *      mmi_frm_set_app_translate_key_handler(my_translate_key_handler2);
 *      we will has two translater key handler in application layer.
 *      when clear, we use the translate key handler to distinguish 
 *      which key handler should be cleared.
 *
 * PARAMETERS     
 *  func_ptr      :[IN] translate key handler application use it in mmi_frm_set_app_translate_key_handler
 * RETURNS
 *  MMI_TRUE, cleared successfully, MMI_FALSE, already changed by another one
 * EXAMPLE
 * <code>
 *
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_app_translate_key_handler(my_translate_key_handler);  
 * }
 *  
 * void some_function()
 * {
 *     mmi_frm_clear_app_translate_key_handler(my_translate_key_handler); 
 * }
 * </code>
 *****************************************************************************/
MMI_BOOL mmi_frm_clear_app_translate_key_handler(mmi_frm_translate_keyhandler_func_ptr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_clear_translate_key_handler(MMI_FRM_TRANS_KEY_APP, func_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_translate_key_handler
 * DESCRIPTION
 *  Clear translate key handler for specific layer.
 *  All translate key handler will be cleared when screen switch, so if user
 *  don't have special usage. It is not necessary to invoke this interface.
 *  we use func_ptr which user used when call mmi_frm_set_translate_key_handler
 *  as the parameters for futher extension.
 *  For example, we may support multi-translate key handler in the same layer in the future
 *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, my_translate_key_handler1);
 *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, my_translate_key_handler2);
 *      we will has two translater key handler in application layer.
 *      when clear, we use the translate key handler to distinguish 
 *      which key handler should be cleared.
 *
 * PARAMETERS
 *  layer         :[IN] translate key handler level which determine the invoke
 *                        sequency of the translate key handler 
 *  func_ptr      :[IN] translate key handler application use it in mmi_frm_set_app_translate_key_handler
 * RETURNS
 *  MMI_TRUE, cleared successfully, MMI_FALSE, already changed by another one
 * EXAMPLE
 * <code>
 *
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler);  
 * }
 *  
 * void some_function()
 * {
 *     mmi_frm_clear_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler); 
 * }
 * </code>
 *****************************************************************************/
MMI_BOOL mmi_frm_clear_translate_key_handler(mmi_frm_trans_key_handle_enum layer, mmi_frm_translate_keyhandler_func_ptr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Clear will be done when translate key handler is not set by some one others
     * if some others set it, we don't done this.
     * Case1: Now Edior has the same translate key handler entry with application
     *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, app_translate_key_handler)
     *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, ime_translate_handler);
     *      mmi_frm_clear_translate_key_handler(MMI_FRM_TRANS_KEY_APP, app_translate_key_handler);
     *      In this case translate key handler will not be cleared.
     * case2:
     *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, ime_translate_handler1);
     *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, ime_translate_handler2);
     *      mmi_frm_clear_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, ime_translate_handler1);
     *      In this case translate key handler will not be cleared.
     */
    if (func_ptr == g_translated_key_handler[layer])
    {
        mmi_frm_set_translate_key_handler(layer, NULL);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_translate_key_handler
 * DESCRIPTION
 *  Clear all translate key handler.
 *  Generally, this function is invoked when screen switch, the call stack is
 *  ExecuteCurrExitHandler->
 *  ClearInputEventHandler->
 *  ClearAllKeyHandler->
 *  mmi_frm_clear_all_translate_key_handler
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_translate_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_translated_key_handler, 0x00, sizeof(g_translated_key_handler));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dispatch_key_event
 * DESCRIPTION
 *  This function is used to invoke translate key handler according the following rule
 *  if SYS == false
 *  then  APP
 *  or
 *  if SYS == false
 *  then Editor
 *
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - don't need to call original key handler
 *  MMI_FALSE - need to call original key handler
 * EXAMPLE
 * <code>
 *
 * </code>
 *****************************************************************************/
MMI_BOOL mmi_frm_dispatch_key_event(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32      i;
    MMI_BOOL res = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /*
     * we call translate key handler in the order of
     *   if MMI_FRM_TRANS_KEY_SYS == false
     *   then MMI_FRM_TRANS_KEY_APP
     * or 
     *   if MMI_FRM_TRANS_KEY_SYS == false
     *   then MMI_FRM_TRANS_KEY_EDITOR
     */
    for (i = 0; i < MMI_FRM_TRANS_KEY_HANDLE_END; i++)
    {
        //MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_EXECUTE_TRANS_KEY_HDLR, i, g_translated_key_handler[i], mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
        if(g_translated_key_handler[i] != NULL)
        {
            res = (* g_translated_key_handler[i])(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
            if (res == MMI_TRUE)
            {
                break;
            }
        }
    }
    return res;
}


/*****************************************************************************
 * Unit Test
 *****************************************************************************/

#ifdef __MMI_FRM_TRANS_KEY_DEVELOPER_UT__
#define VERIFY_VAR_TABLE_LEN  (2)
static U32 verify_var[VERIFY_VAR_TABLE_LEN] = {0};
/*****************************************************************************
 * FUNCTION
 *  get_verify_var
 * DESCRIPTION
 *  get data from verify buffer by index
 *
 * PARAMETERS
 *  index    :[IN] verify buffer index
 * RETURNS
 *  data by index
 *****************************************************************************/
U32 get_verify_var(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index  < VERIFY_VAR_TABLE_LEN);
    return verify_var[index];
}


/*****************************************************************************
 * FUNCTION
 *  clear_verify_var_buff
 * DESCRIPTION
 *  clear verify buffer
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_verify_var_buff()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(verify_var, 0x00, sizeof(verify_var));
}


/*****************************************************************************
 * FUNCTION
 *  write_verify_var
 * DESCRIPTION
 *  write verify data to verify data buffer
 *   init  [0] [0]
 *   write_verify_var(0x55)  [0x55] [0]
 *   write_verify_var(0x66)  [0x55] [0x66]
 *   write_verify_var(0x77)  Assert
 *   we can use this buffer to see translate key handler is called or not
 *   and the calling sequence.
 *
 * PARAMETERS
 *   data     :[IN]  data to write
 * RETURNS
 *  void
 *****************************************************************************/
void write_verify_var(U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VERIFY_VAR_TABLE_LEN; i++)
    {
        if (verify_var[i] ==  0)
        {
            verify_var[i] = data;
            return;
        }
    }
    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_translate_key_handler
 * DESCRIPTION
 *  get translate key handler, this function is used to do developer unit test
 * PARAMETERS
 *  layer         :[IN]   translate key handler level which determine the invoke
 *                        sequency of the translate key handler      
 * RETURNS
 *  translate key handler of specific layer
 *****************************************************************************/
mmi_frm_translate_keyhandler_func_ptr mmi_frm_get_translate_key_handler(mmi_frm_trans_key_handle_enum layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((layer >= MMI_FRM_TRANS_KEY_SYS) && (layer < MMI_FRM_TRANS_KEY_HANDLE_END));
    return g_translated_key_handler[layer];
}


/*****************************************************************************
 * FUNCTION
 *  developer_ut_set_app_translate_key_handler
 * DESCRIPTION
 *  This function is used to test set app translate key handler 
 *  Test Method: set then get, they should be same.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_set_app_translate_key_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_translate_keyhandler_func_ptr set_value = (mmi_frm_translate_keyhandler_func_ptr)20090409;
    mmi_frm_translate_keyhandler_func_ptr get_value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_app_translate_key_handler(set_value);
    get_value = mmi_frm_get_translate_key_handler(MMI_FRM_TRANS_KEY_APP);
    MMI_ASSERT(set_value == get_value);
}


/*****************************************************************************
 * FUNCTION
 *  developer_ut_set_translate_key_handler
 * DESCRIPTION
 *  This function is used to test set translate key handler
 *  Test Method: set then get, they should be same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_set_translate_key_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_translate_keyhandler_func_ptr set_value = (mmi_frm_translate_keyhandler_func_ptr)20090409;
    mmi_frm_translate_keyhandler_func_ptr get_value = NULL;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_FRM_TRANS_KEY_SYS; i < MMI_FRM_TRANS_KEY_HANDLE_END; i++)
    {
        mmi_frm_set_translate_key_handler(i, (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i * 1000));
        get_value = mmi_frm_get_translate_key_handler(i);
        MMI_ASSERT(((U32)set_value + i * 1000) == (U32)get_value);
    }
}

/*****************************************************************************
 * FUNCTION
 *  developer_ut_clear_app_translate_key_handler
 * DESCRIPTION
 *  This function is used to test clear app translate key handler
 *  Test Method:
 *     case 1: set hdlr1, clear hdlr1, cleared successfully
 *     case 2: set hdlr1, change set hdlr2, clear hdlr1, not clear, keep hdlr2
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_clear_app_translate_key_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_translate_keyhandler_func_ptr set_value = (mmi_frm_translate_keyhandler_func_ptr)20090409;
    MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * case 1: set hdlr1, clear hdlr1, cleared successfully
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = set_value;
    res = mmi_frm_clear_app_translate_key_handler(set_value);
    MMI_ASSERT(g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] == NULL);
    MMI_ASSERT(res == MMI_TRUE);

    /*
     * case 2: set hdlr1, change set hdlr2, clear hdlr1, not clear, keep hdlr2
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = set_value;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_EDITOR] =  (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + 1000);
    res = mmi_frm_clear_app_translate_key_handler(set_value);
    MMI_ASSERT((U32)g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] == ((U32)set_value + (U32)1000));
    MMI_ASSERT(res == MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  developer_ut_clear_translate_key_handler
 * DESCRIPTION
 *  This function is used to test clear translate key handler
 *     case 1: set hdlr1, clear hdlr1, cleared successfully
 *     case 2: set hdlr1, change set hdlr2, clear hdlr1, not clear, keep hdlr2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_clear_translate_key_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_translate_keyhandler_func_ptr set_value = (mmi_frm_translate_keyhandler_func_ptr)20090409;
    MMI_BOOL res;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_FRM_TRANS_KEY_SYS; i < MMI_FRM_TRANS_KEY_HANDLE_END; i++)
    {
        /*
         * case 1: set hdlr1, clear hdlr1, cleared successfully
         */        
        g_translated_key_handler[i] = (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i);
        res = mmi_frm_clear_translate_key_handler(i, (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i));
        MMI_ASSERT(g_translated_key_handler[i] == NULL);
        MMI_ASSERT(res == MMI_TRUE);

        /*
         * case 2: set hdlr1, change set hdlr2, clear hdlr1, not clear, keep hdlr2
         */
        g_translated_key_handler[i] = (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i);
        g_translated_key_handler[i] =  (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i + 0xFF);
        res = mmi_frm_clear_translate_key_handler(i, (mmi_frm_translate_keyhandler_func_ptr)((U32)set_value + i));
        MMI_ASSERT((U32)g_translated_key_handler[i] == ((U32)set_value + i + 0xFF));
        MMI_ASSERT(res == MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  developer_ut_clear_all_translate_key_handler
 * DESCRIPTION
 *  This function is used to test clear all translate key handler
 *  Test Method:
 *      All translate key handler should be NULL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_clear_all_translate_key_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_translate_keyhandler_func_ptr set_value = (mmi_frm_translate_keyhandler_func_ptr)20090409;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_translated_key_handler, 0x55, sizeof(g_translated_key_handler));
    mmi_frm_clear_all_translate_key_handler();
    for (i = MMI_FRM_TRANS_KEY_SYS; i < MMI_FRM_TRANS_KEY_HANDLE_END; i++)
    {
        MMI_ASSERT(g_translated_key_handler[i] == NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  my_translate_key_handler1
 * DESCRIPTION
 *  translate key handler
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - stop key routing
 *  MMI_FALSE - continue key routing
 *****************************************************************************/
MMI_BOOL my_translate_key_handler1(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_verify_var((U32)my_translate_key_handler1);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  my_translate_key_handler2
 * DESCRIPTION
 *  translate key handler
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - stop key routing
 *  MMI_FALSE - continue key routing
 *****************************************************************************/
MMI_BOOL my_translate_key_handler2(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_verify_var((U32)my_translate_key_handler2);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  my_translate_key_handler3
 * DESCRIPTION
 *  translate key handler
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - stop key routing
 *  MMI_FALSE - continue key routing
 *****************************************************************************/
MMI_BOOL my_translate_key_handler3(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_verify_var((U32)my_translate_key_handler3);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  my_translate_key_handler4
 * DESCRIPTION
 *  translate key handler
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - stop key routing
 *  MMI_FALSE - continue key routing
 *****************************************************************************/
MMI_BOOL my_translate_key_handler4(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_verify_var((U32)my_translate_key_handler4);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  developer_ut_mmi_frm_dispatch_key_event
 * DESCRIPTION
 *  This function is used to test mmi_frm_dispatch_key_event
 *  Test Method
 *      case 1: All translate key handler are NULL, MMI_FALSE will be got
 *      case 2: SYS = NULL, APP = translate 2, return false
 *              translate 2 will be called, MMI_FALSE will be got
 *      case 3: SYS = NULL, APP = translate 4, return false
 *              translate 4 will be called, MMI_TRUE will be got
 *      case 4: SYS = translate 1, return false, APP = NULL
 *              translate 1 will be called, MMI_FALSE will be got
 *      case 5: SYS = translate 3, return true, APP = NULL
 *              translate 3 will be called, MMI_TRUE will be got
 *      case 6: SYS = translate 1, return false, APP = translate 2, return false
 *              translate 1 will be called, then translate 2 will be called,
 *              then MMI_FALSE will be got
 *      case 7: SYS = translate 1, return false, APP = translate 4, return true
 *              translate 1 will be called, then translate 2 will be called,
 *              then MMI_TRUE will be got
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void developer_ut_mmi_frm_dispatch_key_event()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * case 1: All translate key handler are NULL, MMI_FALSE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = NULL;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = NULL;
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(res == MMI_FALSE);

    /*
     * case 2: SYS = NULL, APP = translate 2, return false
     *   translate 2 will be called, MMI_FALSE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = NULL;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = my_translate_key_handler2;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler2);
    MMI_ASSERT(get_verify_var(1) == 0);
    MMI_ASSERT(res == MMI_FALSE);

    /*
     * case 3: SYS = NULL, APP = translate 4, return false
     * translate 4 will be called, MMI_TRUE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = NULL;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = my_translate_key_handler4;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler4);
    MMI_ASSERT(get_verify_var(1) == 0);
    MMI_ASSERT(res == MMI_TRUE);

    /*
     * case 4: SYS = translate 1, return false, APP = NULL
     *  translate 1 will be called, MMI_FALSE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = my_translate_key_handler1;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = NULL;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler1);
    MMI_ASSERT(get_verify_var(1) == 0);
    MMI_ASSERT(res == MMI_FALSE);

    /*
     * case 5 SYS = translate 3, return true, APP = NULL
     * translate 3 will be called, MMI_TRUE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = my_translate_key_handler3;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = NULL;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler3);
    MMI_ASSERT(res == MMI_TRUE);

    /*
     * case 6 SYS = translate 1, return false, APP = translate 2, return false
     * translate 1 will be called, then translate 2 will be called,
     * then MMI_FALSE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = my_translate_key_handler1;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = my_translate_key_handler2;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler1);
    MMI_ASSERT(get_verify_var(1) == (U32)my_translate_key_handler2);
    MMI_ASSERT(res == MMI_FALSE);

    /*
     * case 7 SYS = translate 1, return false, APP = translate 4, return true
     * translate 1 will be called, then translate 2 will be called,
     * then MMI_TRUE will be got
     */
    g_translated_key_handler[MMI_FRM_TRANS_KEY_SYS] = my_translate_key_handler1;
    g_translated_key_handler[MMI_FRM_TRANS_KEY_APP] = my_translate_key_handler4;
    clear_verify_var_buff();
    res = mmi_frm_dispatch_key_event(KEY_1, KEY_EVENT_DOWN, 0, 0);
    MMI_ASSERT(get_verify_var(0) == (U32)my_translate_key_handler1);
    MMI_ASSERT(get_verify_var(1) == (U32)my_translate_key_handler4);
    MMI_ASSERT(res == MMI_TRUE);
}

void developer_ut_key_routing()
{
    developer_ut_set_app_translate_key_handler();
    developer_ut_set_translate_key_handler();
    developer_ut_clear_app_translate_key_handler();
    developer_ut_clear_translate_key_handler();
    developer_ut_clear_all_translate_key_handler();
    developer_ut_mmi_frm_dispatch_key_event();
}
#endif /* __MMI_FRM_TRANS_KEY_DEVELOPER_UT__ */
 

