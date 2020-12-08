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

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_p2v_shell.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Shell plutommi to venus adaption layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "app_mem.h"
#include "ShellAppGprot.h"

#ifdef __cplusplus
}
#endif

#include "vfx_context.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vrt_datatype.h"
#include "vfx_screen.h"
#include "vapp_shell_panel.h"
#include "vadp_app_trc.h"
#include "vapp_shell_scr.h"
#include "vadp_p2v_shell.h"


/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    VappShellScr *c;
    VfxContext *first_node;
} vadp_p2v_shell_context_struct;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static vadp_p2v_shell_context_struct shell_cnxt = {NULL, NULL};
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
static VfxU8 shell_mem[MAX_SHELL_MEM_SIZE];
#else
static VfxU8 *shell_mem = NULL;
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
 
/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_shell_vrt_cache_mem_alloc
 * DESCRIPTION
 *  allocate vrt cache memory
 *  buffer.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU8 *vadp_p2v_shell_vrt_cache_mem_alloc(VfxU32 size)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (size > MAX_SHELL_VRT_CACHE_SIZE)
    {
        // exceed max size
        return NULL;
    }
        
    return (VfxU8 *) applib_mem_screen_alloc((kal_uint32)size);
#else /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    return NULL;
#endif /* !__MMI_VUI_SHELL_MULTI_PAGE__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_shell_vrt_cache_mem_free
 * DESCRIPTION
 *  free vrt cache memory
 *  buffer.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vadp_p2v_shell_vrt_cache_mem_free(VfxU8 *mem_ptr)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (mem_ptr != NULL)
    {
        applib_mem_screen_free((kal_uint8 *)mem_ptr);
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_init
 * DESCRIPTION
 *  This function is used to init shell app
 *  buffer.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vadp_p2v_shell_vapp_init(void)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell_cnxt.first_node == NULL)
    {
        memset((kal_uint8 *)shell_mem, 0, sizeof(shell_mem));
        
        VFX_OBJ_CREATE(shell_cnxt.first_node, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
        shell_cnxt.first_node->assignPool((VfxU8 *)shell_mem, MAX_SHELL_MEM_SIZE);
        VFX_OBJ_CREATE_EX(shell_cnxt.c, VappShellScr, shell_cnxt.first_node, ());
    }

    VFX_ASSERT(shell_cnxt.c != NULL);
    
    shell_cnxt.c->entry(shell_cnxt.first_node, (VfxScreen *)shell_cnxt.c);
#else /* __MMI_VUI_SHELL_MULTI_PAGE__ */
if (shell_cnxt.first_node == NULL)
   {
       if (shell_mem != NULL)
       {
           applib_mem_screen_free(shell_mem);
           shell_mem = NULL;
       }
       shell_mem = (VfxU8 *) applib_mem_screen_alloc(MAX_SHELL_MEM_SIZE);
       if (shell_mem)
       {
           memset((kal_uint8 *)shell_mem, 0, MAX_SHELL_MEM_SIZE);
           VFX_OBJ_CREATE(shell_cnxt.first_node, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
           shell_cnxt.first_node->assignPool((VfxU8 *)shell_mem, MAX_SHELL_MEM_SIZE);
           VFX_OBJ_CREATE_EX(shell_cnxt.c, VappShellScr, shell_cnxt.first_node, ());
       }
   }

   VFX_ASSERT(shell_cnxt.c != NULL);
   
   shell_cnxt.c->entry(shell_cnxt.first_node, (VfxScreen *)shell_cnxt.c);
#endif /* !__MMI_VUI_SHELL_MULTI_PAGE__ */
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vadp_p2v_shell_close_app(void)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell_cnxt.c != NULL)
    {
        shell_cnxt.c->closeScreen(VFX_TRUE);
        VFX_OBJ_CLOSE(shell_cnxt.c);
        VFX_OBJ_CLOSE(shell_cnxt.first_node);
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vadp_p2v_shell_vapp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (shell_cnxt.c != NULL)
    {
        shell_cnxt.c->exit();
        shell_cnxt.c->closeScreen(VFX_FALSE);
    }
#else /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    shell_cnxt.c->exit();
    shell_cnxt.c->closeScreen(VFX_TRUE);
    //VFX_OBJ_CLOSE(shell_cnxt.c);
    VFX_OBJ_CLOSE(shell_cnxt.first_node);
    
    /* free memory */
    if (shell_mem != NULL)
    {
        applib_mem_screen_free(shell_mem);
        shell_mem = NULL;
    }
#endif /* !__MMI_VUI_SHELL_MULTI_PAGE__ */

    return;
}

#endif /* __MMI_VUI_SHELL_APP__ */

