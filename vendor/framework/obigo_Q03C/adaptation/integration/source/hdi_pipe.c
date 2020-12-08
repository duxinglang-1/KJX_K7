/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   hdi_pipe.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating Obigo pipe APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "msf_def.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_cmmn.h"
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "msf_lib.h"
#include "msf_cfg.h"
#include "msm_int.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#include "msf_env.h"
#include "msf_log.h"

#include "kal_public_api.h"

#define MAX_NUM_PIPES                   16
#ifdef __OP01_3G__
#define PIPE_BUFSIZE                    2048    /*Use 2K pipe on CMCC TD projects.*/
#else
#define PIPE_BUFSIZE                    1024
#endif

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
#define MAX_NAME_PIPE_BIG_SIZE     (8192)
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#define PIPE_FLAG_CREATED               0x01
#define PIPE_FLAG_OPEN_READ             0x02
#define PIPE_FLAG_OPEN_WRITE            0x04
#define PIPE_FLAG_DELETED               0x08
#define PIPE_FLAG_POLLED_READ           0x10
#define PIPE_FLAG_POLLED_WRITE          0x20

#define PIPE_CLOSE                      0x00
#define PIPE_CLOSE_ERROR                0x01

#define PIPE_READ                       0x00
#define PIPE_PEAK                       0x01 
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
#define PIPE_FLAG_PIPE_BIG_SIZE         0x40
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
typedef struct name_pipe_st
{
    MSF_UINT8 flags;
    MSF_UINT8 isFull;	
    MSF_UINT8 readModule;
    MSF_UINT8 writeModule;
    char *name;
    char *buf;
    int readPos;
    int writePos;
    int error_code;

} name_pipe_struct;

static name_pipe_struct pipes[MAX_NUM_PIPES];

static name_pipe_struct empty_pipe_info = {0, 0, 0, 0, NULL, NULL, 0, 0, 0};
static kal_mutexid hdi_pipe_mutex;

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
static int big_pipes_available(void);
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  initPipe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void init_hdi_pipe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hdi_pipe_mutex == NULL)
    {
        hdi_pipe_mutex = kal_create_mutex((kal_char*) "hdi_pipe_mutex");
    }     
    for (i = 0; i < MAX_NUM_PIPES; i++)
    {
        pipes[i] = empty_pipe_info;
    }
}


/*****************************************************************************
 * FUNCTION
 *  find_pipe
 * DESCRIPTION
 *  To return pipe index with given pipe name.
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  index of pipe context.
 *****************************************************************************/
static int find_pipe(const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_NUM_PIPES; i++)
    {
        if ((pipes[i].name != NULL) && !msf_cmmn_strcmp_nc(pipes[i].name, name))
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  bytesAvailableRead
 * DESCRIPTION
 *  To return number of bytes avaiable for read.
 * PARAMETERS
 *  pipe        [?]     
 * RETURNS
 *  bytes available for read
 *****************************************************************************/
static int bytesAvailableRead(name_pipe_struct *pipe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 pipe_bufsize = PIPE_BUFSIZE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
    if(pipe->flags & PIPE_FLAG_PIPE_BIG_SIZE)
    {
        pipe_bufsize = MAX_NAME_PIPE_BIG_SIZE;
    }
#endif
#endif
    if(pipe->isFull)
    {
        return pipe_bufsize;
    }
    return (pipe->writePos + pipe_bufsize - pipe->readPos) % pipe_bufsize;
}


/*****************************************************************************
 * FUNCTION
 *  bytesAvailableWrite
 * DESCRIPTION
 *  To return number of bytes avaiable for write.
 * PARAMETERS
 *  pipe        [?]     
 * RETURNS
 *  bytes available for write
 *****************************************************************************/
static int bytesAvailableWrite(name_pipe_struct *pipe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 pipe_bufsize = PIPE_BUFSIZE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
    if(pipe->flags & PIPE_FLAG_PIPE_BIG_SIZE)
    {
        pipe_bufsize = MAX_NAME_PIPE_BIG_SIZE;
    }
#endif
#endif

    return pipe_bufsize - bytesAvailableRead(pipe);
}

/**********************************************************************
 * HDI Pipe functions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeCreate(MSF_UINT8 modId, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = -1, ret = 0;
    name_pipe_struct *pipe = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_BFA7F51ECAC059B67858F0D932567D4D, "MSF_PIPE_CREATE: modId=%d, name=%s\n", modId, name));
    
    //kal_take_mutex(hdi_pipe_mutex);
    if (!name)
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }
    
    pipe = (name_pipe_struct *)MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(name_pipe_struct));
    memset(pipe, 0, sizeof(name_pipe_struct));
    
    pipe->name = msf_cmmn_strdup(MSF_MODID_MSM, name);
    if (!pipe->name)
    {
        ret = HDI_PIPE_ERROR_RESOURCE_LIMIT;
        goto end;
    }
    pipe->buf = (char *)MSF_MEM_ALLOC(MSF_MODID_MSM, PIPE_BUFSIZE);
    if (!pipe->buf)
    {
        ret = HDI_PIPE_ERROR_RESOURCE_LIMIT;
        goto end;
    }
    memset(pipe->buf, 0, PIPE_BUFSIZE);
    pipe->readPos = 0;
    pipe->writePos = 0;
    pipe->flags = PIPE_FLAG_CREATED | PIPE_FLAG_OPEN_WRITE;
    pipe->writeModule = modId;
    pipe->readModule = 0xff;
    pipe->error_code = 0;
    pipe->isFull = 0;

    kal_take_mutex(hdi_pipe_mutex);
    if (find_pipe(name) >= 0)
    {
        ret = HDI_PIPE_ERROR_EXISTS;
    }
    else
    {
      for (i = 0; i < MAX_NUM_PIPES; i++)
      {
          if (pipes[i].flags == 0)
          {
              //pipe = &pipes[i];
              pipes[i] = *pipe;
              pipe->name = NULL;
              pipe->buf = NULL;
              ret = i;
              break;
          }
      }
    }
    kal_give_mutex(hdi_pipe_mutex);

    if (i == MAX_NUM_PIPES)
    {
        ret = HDI_PIPE_ERROR_RESOURCE_LIMIT;
    }

  end:
    //kal_give_mutex(hdi_pipe_mutex);
    if(pipe)
      {
        if(pipe->name)
          MSF_MEM_FREE(MSF_MODID_MSM, pipe->name);
        if(pipe->buf)
          MSF_MEM_FREE(MSF_MODID_MSM, pipe->buf);
        MSF_MEM_FREE(MSF_MODID_MSM, pipe);
      }
    return ret;
}

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
/*****************************************************************************
 * FUNCTION
 *  name_pipe_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p           [?]         
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void name_pipe_read(name_pipe_struct *pipe, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
MSF_UINT32 pipe_bufsize = PIPE_BUFSIZE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
    if(pipe->flags & PIPE_FLAG_PIPE_BIG_SIZE)
    {
        pipe_bufsize = MAX_NAME_PIPE_BIG_SIZE;
    }
#endif
#endif
    if (pipe->readPos + bufSize <= (MSF_UINT32)pipe_bufsize)
    {
        kal_mem_cpy((kal_uint8*) buf, &pipe->buf[pipe->readPos], bufSize);
    }
    else
    {
        long len = pipe_bufsize - pipe->readPos;

        kal_mem_cpy((kal_uint8*) buf, &pipe->buf[pipe->readPos], len);
        kal_mem_cpy((kal_uint8*) buf + len, pipe->buf, bufSize - len);
    }

    pipe->readPos = (pipe->readPos + bufSize) % pipe_bufsize;
    pipe->isFull = 0;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeOpenExtended
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeOpenExtended(MSF_UINT8 modId, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index, ret = 0;
    name_pipe_struct *pipe;
    kal_uint8 *buf = NULL, *temp = NULL;
	int occupy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(hdi_pipe_mutex);
    if (!name)
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }
    buf = (kal_uint8 *)MSF_MEM_ALLOC(MSF_MODID_MSM, MAX_NAME_PIPE_BIG_SIZE);
    /* check whether a pipe already exist with this name */
    if ((index = find_pipe(name)) == -1)
    {
        ret = HDI_PIPE_ERROR_NOT_FOUND;
        goto end;
    }
    
	pipe = &pipes[index];

    if (pipe->flags & PIPE_FLAG_OPEN_READ)
    {
        ret = HDI_PIPE_ERROR_IS_OPEN;
        goto end;
    }

    pipe->readModule = modId;
    pipe->flags |= PIPE_FLAG_OPEN_READ;

	if(big_pipes_available())
	{
		if(buf != NULL)
		{
			memset(buf, 0, MAX_NAME_PIPE_BIG_SIZE);
			occupy = bytesAvailableRead(pipe);
			name_pipe_read(pipe, buf, occupy);
			//MSF_MEM_FREE(MSF_MODID_MSM, pipe->buf);
			temp = (kal_uint8 *)pipe->buf;
			pipe->buf = (char*)buf;
			buf = temp;
			pipe->flags  |=  PIPE_FLAG_PIPE_BIG_SIZE;
			pipe->readPos = 0;
			pipe->writePos = occupy;
			pipe->isFull = 0;
		}	
	}
    ret = index + MAX_NUM_PIPES;

  end:
    kal_give_mutex(hdi_pipe_mutex);
    if(buf)
      MSF_MEM_FREE(MSF_MODID_MSM, buf);
    return ret;

}   /* end of HDIa_pipeOpenExtended */

/*****************************************************************************
 * FUNCTION
 *  big_pipes_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int big_pipes_available()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    for (i = 0; i < MAX_NUM_PIPES; i++)
    {
		if( (pipes[i].name != NULL) && (pipes[i].flags & PIPE_FLAG_PIPE_BIG_SIZE))
        {
			count++;
        }
    }	
	if (count >= MAX_NUM_BIG_PIPES)
	{
		return 0;
	}
	return 1;
	
}
#endif
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeOpen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeOpen(MSF_UINT8 modId, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index, ret = 0;
    name_pipe_struct *pipe;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_A30E6E0491C4CD644B0595519AC5076C, "MSF_PIPE_OPEN: modId=%d, name=%s\n", modId, name));
    
    kal_take_mutex(hdi_pipe_mutex);
    if (!name)
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }

    if ((index = find_pipe(name)) == -1)
    {
        ret = HDI_PIPE_ERROR_NOT_FOUND;
        goto end;
    }

    pipe = &pipes[index];

    if (pipe->flags & PIPE_FLAG_OPEN_READ)
    {
        ret = HDI_PIPE_ERROR_IS_OPEN;
        goto end;
    }

    pipe->readModule = modId;
    pipe->flags |= PIPE_FLAG_OPEN_READ;

    ret = index + MAX_NUM_PIPES;

  end:
    kal_give_mutex(hdi_pipe_mutex);
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeClose(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_F9B67BE56250013B3A730A05F7842C17, "MSF_PIPE_CLOSE: handle=%d\n", handle));
	return gmms_HDIa_pipeCloseExt(handle,PIPE_CLOSE);
   
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeCloseExt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  error_code      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeCloseExt(int handle,int errormode)
{
int i=handle, ret = 0;
    name_pipe_struct *pipe;
    MSF_UINT8 pipe_closed_notify = FALSE, closed_notify_module = 0xff;
    int pipe_id = -1;
	  char *pname = NULL, *pbuf = NULL;
	  MSF_UINT8 flag=PIPE_FLAG_OPEN_WRITE;
	  MSF_UINT8 flaga=PIPE_FLAG_OPEN_READ|PIPE_FLAG_POLLED_READ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    kal_take_mutex(hdi_pipe_mutex);
    if (handle >= MAX_NUM_PIPES)
    {
        i = handle - MAX_NUM_PIPES;
		 flag =PIPE_FLAG_OPEN_READ;
		 flaga=PIPE_FLAG_OPEN_WRITE|PIPE_FLAG_POLLED_WRITE|PIPE_FLAG_DELETED;
	}
        if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
            !(pipes[i].flags & flag))
        {
            ret = HDI_PIPE_ERROR_BAD_HANDLE;
            goto end;
        }
        pipe = &pipes[i];

	if(errormode==PIPE_CLOSE_ERROR)
    	pipe->error_code = HDI_PIPE_ERROR_CLOSED_ERROR;
	pipe->flags &= ~flag;
	if ((pipe->flags & flaga)==flaga)
        {          
            pipe_closed_notify = TRUE;
			if(flag==PIPE_FLAG_OPEN_READ)
			{
            closed_notify_module = pipe->writeModule;
            pipe_id = i;
            pipe->flags &= ~PIPE_FLAG_POLLED_WRITE;
        }
    else
    {
            closed_notify_module = pipe->readModule;
            pipe_id = i + MAX_NUM_PIPES;            
            pipe->flags &= ~PIPE_FLAG_POLLED_READ;
        }
    }

    /* Remove the pipe if both ends are closed */
    if ((pipe->flags & PIPE_FLAG_DELETED) &&
        !(pipe->flags & PIPE_FLAG_OPEN_READ) && !(pipe->flags & PIPE_FLAG_OPEN_WRITE))
    {
        //MSF_MEM_FREE(MSF_MODID_MSM, pipe->name);
		pname = pipe->name;
        pipe->name = NULL;
        //MSF_MEM_FREE(MSF_MODID_MSM, pipe->buf);
		pbuf = pipe->buf;
        pipe->buf = NULL;
        pipe->flags = 0;
        pipe->isFull = 0;
    }

end:
    kal_give_mutex(hdi_pipe_mutex);
    
    if(pipe_closed_notify)
      {	if(errormode==PIPE_CLOSE_ERROR)
			HDIc_pipeNotify(closed_notify_module, pipe_id, HDI_PIPE_EVENT_CLOSED_ERROR);
		else
        HDIc_pipeNotify(closed_notify_module, pipe_id, HDI_PIPE_EVENT_CLOSED);
      }
	if(pname)
		MSF_MEM_FREE(MSF_MODID_MSM, pname);
	if(pbuf)
		MSF_MEM_FREE(MSF_MODID_MSM, pbuf);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeCloseError
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  error_code      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeCloseError(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_69EE56D60529F49B1DEC4338C97067FD, "MSF_PIPE_CLOSE_ERROR: handle=%d\n", handle));
    
    return gmms_HDIa_pipeCloseExt(handle,PIPE_CLOSE_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeDelete(const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = -1, ret = 0;
    name_pipe_struct pipe = empty_pipe_info;
    MSF_UINT8 close_notify = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_04DA5052AF46AF1E8A9E84AC1F0ABDA9, "MSF_PIPE_DELETE: name=%s\n", name));

    kal_take_mutex(hdi_pipe_mutex);
    if ((name == NULL) || (strlen(name) == 0))
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }

    if ((i = find_pipe(name)) == -1)
    {
        ret = HDI_PIPE_ERROR_NOT_FOUND;
        goto end;
    }

    pipe = pipes[i];

    if (pipes[i].flags & PIPE_FLAG_CREATED)
    {
        //MSF_MEM_FREE(MSF_MODID_MSM, pipe->name);
        pipes[i].name = NULL;
        pipes[i].flags |= PIPE_FLAG_DELETED;

        if ((pipes[i].flags & PIPE_FLAG_OPEN_WRITE) &&
            (pipes[i].flags & PIPE_FLAG_POLLED_WRITE) && !(pipes[i].flags & PIPE_FLAG_OPEN_READ))
        {
            //HDIc_pipeNotify(pipes[i].writeModule, i, HDI_PIPE_EVENT_CLOSED);
            close_notify = TRUE;
            pipes[i].flags &= ~PIPE_FLAG_POLLED_WRITE;
        }

        /* Remove, if both ends are closed */
        if (!(pipes[i].flags & PIPE_FLAG_OPEN_READ) && !(pipes[i].flags & PIPE_FLAG_OPEN_WRITE))
        {
            //MSF_MEM_FREE(MSF_MODID_MSM, pipes[i].buf);
            pipes[i].buf = NULL;
            pipes[i].flags = 0;
        }
        else
          {
            pipe.buf = NULL;
          }
    }

  end:
    kal_give_mutex(hdi_pipe_mutex);
    if(i != -1)
      {
        MSF_MEM_FREE(MSF_MODID_MSM, pipe.name);
        if(close_notify)
          {
            HDIc_pipeNotify(pipe.writeModule, i, HDI_PIPE_EVENT_CLOSED);
          }
        if(pipe.buf)
          {
            MSF_MEM_FREE(MSF_MODID_MSM, pipe.buf);
          }
      }
    return ret;

}

long gmms_HDIa_pipe_ext(int handle, void *buf, long bufSize,int mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = handle - MAX_NUM_PIPES;
    name_pipe_struct *pipe;
    int ret;
    MSF_UINT32 pipe_bufsize = PIPE_BUFSIZE;
    MSF_UINT8 notify_write = FALSE, notify_module = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_80396DBD6FAFA31EA4954F47773BAA14, "MSF_PIPE_READ: handle=%d\n", handle));

    kal_take_mutex(hdi_pipe_mutex);
    if (buf == NULL || bufSize < 0)
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }

    if (bufSize == 0)
    {
        ret = 0;
        goto end;
    }

    if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
        !(pipes[i].flags & PIPE_FLAG_OPEN_READ))
    {
        ret = HDI_PIPE_ERROR_BAD_HANDLE;
        goto end;
    }

    pipe = &pipes[i];

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
    if(pipe->flags & PIPE_FLAG_PIPE_BIG_SIZE)
    {
        pipe_bufsize = MAX_NAME_PIPE_BIG_SIZE;
    }
#endif
#endif

    ret = bytesAvailableRead(pipe);

    if (ret == 0)
    {
        if (pipe->flags & PIPE_FLAG_OPEN_WRITE)
        {
            ret = HDI_PIPE_ERROR_DELAYED;
        }
        else
        {
            ret = (pipe->error_code != 0) ? pipe->error_code : HDI_PIPE_ERROR_CLOSED;
        }
        goto end;
    }


    if (ret > bufSize)
    {
        ret = bufSize;
    }

    if (pipe->readPos + ret <= (MSF_UINT32)pipe_bufsize)
    {
        kal_mem_cpy((kal_uint8*) buf, &pipe->buf[pipe->readPos], ret);
    }
    else
    {
        long len = pipe_bufsize - pipe->readPos;

        kal_mem_cpy((kal_uint8*) buf, &pipe->buf[pipe->readPos], len);
        kal_mem_cpy((kal_uint8*) buf + len, pipe->buf, ret - len);
    }
	if(mode==PIPE_READ)
	{
    pipe->readPos = (pipe->readPos + ret) % pipe_bufsize;
    pipe->isFull = 0;

    if (pipe->flags & PIPE_FLAG_POLLED_WRITE)
    {
        //HDIc_pipeNotify(pipe->writeModule, i, HDI_PIPE_EVENT_WRITE);
        notify_write = TRUE;
        notify_module = pipe->writeModule;
        pipe->flags &= ~PIPE_FLAG_POLLED_WRITE;
    }
	}

  end:
    kal_give_mutex(hdi_pipe_mutex);
    if(notify_write && mode==PIPE_READ)
      {
        HDIc_pipeNotify(notify_module, i, HDI_PIPE_EVENT_WRITE);
      }
    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeRead
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_pipeRead(int handle, void *buf, long bufSize)
{

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_80396DBD6FAFA31EA4954F47773BAA14, "MSF_PIPE_READ: handle=%d\n", handle));

	return gmms_HDIa_pipe_ext(handle,buf,bufSize,PIPE_READ);
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipePeek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_pipePeek(int handle, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_328344E98F63F7BB537736EEE23948B1, "MSF_PIPE_PEEK: handle=%d\n", handle));

	return gmms_HDIa_pipe_ext(handle,buf,bufSize,PIPE_PEAK);
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeWrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_pipeWrite(int handle, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = handle, ret = 0;
    name_pipe_struct *pipe;
    MSF_UINT32 pipe_bufsize = PIPE_BUFSIZE;
    MSF_UINT8 notify_read = FALSE, notify_module = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_7DC57448C85C00E84A7F18DF169CF89B, "MSF_PIPE_WRITE: handle=%d, bufSize=%d\n", handle, bufSize));

    kal_take_mutex(hdi_pipe_mutex);
    if ((buf == NULL) || (bufSize < 0))
    {
        ret = HDI_PIPE_ERROR_INVALID_PARAM;
        goto end;
    }

    if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
        !(pipes[i].flags & PIPE_FLAG_OPEN_WRITE))
    {
        ret = HDI_PIPE_ERROR_BAD_HANDLE;
        goto end;
    }

    pipe = &pipes[i];

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_DOWNLOAD_SPEEDUP
    if(pipe->flags & PIPE_FLAG_PIPE_BIG_SIZE)
    {
        pipe_bufsize = MAX_NAME_PIPE_BIG_SIZE;
    }
#endif
#endif

    if (!(pipe->flags & PIPE_FLAG_OPEN_READ) && (pipe->flags & PIPE_FLAG_DELETED))
    {
        if (pipe->error_code == 0)
        {
            ret = HDI_PIPE_ERROR_CLOSED;
            goto end;
        }
        else
        {
            /* pipe closed with HDIa_pipeCloseError */
            ret = pipe->error_code;
            goto end;
        }
    }

    if (bufSize == 0)
    {
        ret = 0;
        goto end;
    }

    ret = bytesAvailableWrite(pipe);

    if(ret == 0)
    {
        ret = HDI_PIPE_ERROR_DELAYED;
        goto end;
    }

    if (ret > bufSize)
    {
        ret = bufSize;
    }

    if (pipe->writePos + ret < (MSF_UINT32)pipe_bufsize)
    {
        kal_mem_cpy(&pipe->buf[pipe->writePos], (kal_uint8*) buf, ret);
    }
    else
    {
        long len = pipe_bufsize - pipe->writePos;

        kal_mem_cpy(&pipe->buf[pipe->writePos], (kal_uint8*) buf, len);
        kal_mem_cpy(pipe->buf, (kal_uint8*) buf + len, ret - len);
    }

    pipe->writePos = (pipe->writePos + ret) % pipe_bufsize;
    if(pipe->writePos == pipe->readPos)
    {
        pipe->isFull = 1;
    }

    if (pipe->flags & PIPE_FLAG_POLLED_READ)
    {
        //HDIc_pipeNotify(pipe->readModule, i + MAX_NUM_PIPES, HDI_PIPE_EVENT_READ);
        notify_read = TRUE;
        notify_module = pipe->readModule;
        pipe->flags &= ~PIPE_FLAG_POLLED_READ;
    }

  end:
    kal_give_mutex(hdi_pipe_mutex);
    if(notify_read)
      {
        HDIc_pipeNotify(notify_module, i + MAX_NUM_PIPES, HDI_PIPE_EVENT_READ);
      }
        return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipePoll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipePoll(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 0;
    name_pipe_struct *pipe;
    MSF_UINT8 notify = FALSE;
    MSF_UINT8 notify_module = 0xff;
    int notify_handle = -1, notify_event = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_AE53AF401E2F39536DF66C1EC2027517, "MSF_PIPE_POLL: handle=%d\n", handle));

    kal_take_mutex(hdi_pipe_mutex);
    if (handle >= MAX_NUM_PIPES)
    {
        /* It is a READ handle */
        i = handle - MAX_NUM_PIPES;
        if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
            !(pipes[i].flags & PIPE_FLAG_OPEN_READ))
        {
            ret = HDI_PIPE_ERROR_BAD_HANDLE;
            goto end;
        }

        pipe = &pipes[i];

        if (bytesAvailableRead(pipe) > 0)
        {
            //HDIc_pipeNotify(pipe->readModule, handle, HDI_PIPE_EVENT_READ);
            notify = TRUE;
            notify_module = pipe->readModule;
            notify_handle = handle;
            notify_event = HDI_PIPE_EVENT_READ;
            pipe->flags &= ~PIPE_FLAG_POLLED_READ;
        }
        else if (!(pipe->flags & PIPE_FLAG_OPEN_WRITE))
        {
            //HDIc_pipeNotify(pipe->readModule, handle, HDI_PIPE_EVENT_CLOSED);
            notify = TRUE;
            notify_module = pipe->readModule;
            notify_handle = handle;
            notify_event = HDI_PIPE_EVENT_CLOSED;            
            pipe->flags &= ~PIPE_FLAG_POLLED_READ;
        }
        else
        {
            pipe->flags |= PIPE_FLAG_POLLED_READ;
        }
    }
    else
    {
        /* It is a WRITE handle */
        i = handle;
        if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
            !(pipes[i].flags & PIPE_FLAG_OPEN_WRITE))
        {
            ret = HDI_PIPE_ERROR_BAD_HANDLE;
            goto end;
        }

        pipe = &pipes[i];

        if (bytesAvailableWrite(pipe) > 0)
        {
            //HDIc_pipeNotify(pipe->writeModule, handle, HDI_PIPE_EVENT_WRITE);
            notify = TRUE;
            notify_module = pipe->writeModule;
            notify_handle = handle;
            notify_event = HDI_PIPE_EVENT_WRITE;             
            pipe->flags &= ~PIPE_FLAG_POLLED_WRITE;
        }
        else if (!(pipe->flags & PIPE_FLAG_OPEN_READ) && (pipe->flags & PIPE_FLAG_DELETED))
        {
            //HDIc_pipeNotify(pipe->readModule, handle, HDI_PIPE_EVENT_CLOSED);
            notify = TRUE;
            notify_module = pipe->readModule;
            notify_handle = handle;
            notify_event = HDI_PIPE_EVENT_CLOSED;            
            pipe->flags &= ~PIPE_FLAG_POLLED_WRITE;
        }
        else
        {
            pipe->flags |= PIPE_FLAG_POLLED_WRITE;
        }
    }

  end:
    kal_give_mutex(hdi_pipe_mutex);
    if(notify)
      {
        HDIc_pipeNotify(notify_module, notify_handle, notify_event);
      }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  isOpen          [OUT]         
 *  available       [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_pipeStatus(int handle, int *isOpen, long *available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i=handle, ret = 0;
    name_pipe_struct *pipe;
	MSF_UINT8 flag=PIPE_FLAG_OPEN_WRITE;
	MSF_UINT8 flaga=PIPE_FLAG_OPEN_READ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_05670BFD304D6CF85C68AD3F4A79ADD2, "MSF_PIPE_STATUS: handle=%d\n", handle));

    kal_take_mutex(hdi_pipe_mutex);
    if (handle >= MAX_NUM_PIPES)
	{	i=handle - MAX_NUM_PIPES;
		flag=PIPE_FLAG_OPEN_READ;
		flaga=PIPE_FLAG_OPEN_WRITE;
	}

        if ((i < 0) || (i >= MAX_NUM_PIPES) || !(pipes[i].flags & PIPE_FLAG_CREATED) ||
				!(pipes[i].flags & flag))
        {
            ret = HDI_PIPE_ERROR_BAD_HANDLE;
            goto end;
        }

        pipe = &pipes[i];

        if (isOpen)
        {
		*isOpen = (pipe->flags & flaga) > 0;
        }
        if (available)
        {
		if(flag==PIPE_FLAG_OPEN_READ)
            *available = bytesAvailableRead(pipe);
    else
			*available = bytesAvailableWrite(pipe);
        }


  end:
    kal_give_mutex(hdi_pipe_mutex);
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_pipeCloseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_pipeCloseAll(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    name_pipe_struct *pipe;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_PIPE_08D2DF048FBDD9EE5CCDADB2974CF4D6, "MSF_PIPE_CLOSE_ALL: modId=%d\n", modId));

    for (i = 0; i < MAX_NUM_PIPES; i++)
    {
        pipe = &pipes[i];
        if (pipe->readModule == modId)
        {
            gmms_HDIa_pipeClose(i + MAX_NUM_PIPES);
            gmms_HDIa_pipeDelete(pipe->name);
        }    

        if (pipe->writeModule == modId)
        {
            gmms_HDIa_pipeClose(i);
            gmms_HDIa_pipeDelete(pipe->name);
        }
    }
}

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeDeleteByHandle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeDeleteByHandle(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h;
    name_pipe_struct *pipe = NULL;
    MSF_UINT32 flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= MAX_NUM_PIPES)
    {
        h = handle - MAX_NUM_PIPES;
        flag = PIPE_FLAG_OPEN_READ;
    }
    else
    {
        h = handle;
        flag = PIPE_FLAG_OPEN_WRITE;
    }

    if ((h < 0) || (h >= MAX_NUM_PIPES) || !(pipes[h].flags & PIPE_FLAG_CREATED) ||
        !(pipes[h].flags & flag))
    {
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    pipe = &pipes[h];

    pipe->flags &= ~flag;
    
    return gmms_HDIa_pipeDelete(pipe->name);
}
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

