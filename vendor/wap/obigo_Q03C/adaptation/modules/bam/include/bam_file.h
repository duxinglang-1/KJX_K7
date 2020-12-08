#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_file.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code for managing the fle access.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_file.h
 *
 * Description:
 *
 *
 */


#ifndef _bam_file_h

#define _bam_file_h
#include "bam_cfg.h"

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define BAM_FILE_BLOCK_HEADER_SIZE  3


typedef void (*bam_file_op_callback_t)();
typedef void (*bam_file_init_callback_t)(int idx, int eof, void* block, int size);

/*
 * This function initializes file stuff.
 *
 * Parameters:
 *
 * RETURN           : void
 */
void
bam_file_start (void);

/*
 * This function initializes a db file, if no file is found a new file is created
 * with the size initial_size. If a file exist the file is read and handle is 
 * initialized. If the available bytes in a db is less than an allocate request
 * the file grows with size_increment bytes until max_size is reached. If the 
 * defrag_limit is specified to be less than max_size the file is defragmented 
 * when the file reaches this size.
 *
 * Parameters:
 *
 * file             : DB file path. folders in path must exist.
 * handle           : Pointer to handle struct. A new struct is allocated.
 * max_size         : Max file size.
 * initial_size     : The initial file size.
 * defragment_limit : The DB is defragmented when this limit is reached.
 * size_increment   : the number of bytes the file shall grow in each step.
 *
 * Note! max_size must be a multiple of size_increment.
 *
 * RETURN           : void
 */
void
bam_file_init (char* file, 
               void **handle, 
               int max_size, 
               int initial_size, 
               int defragment_limit, 
               int size_increment,
               bam_file_init_callback_t callback);

/*
 * This function closes and deallocates the resources used by the db
 * specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 *
 * RETURN           : void
 */
void
bam_file_close (void *handle);
 
/*
 * This function reads a block of bytes from the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * block_index      : Index of block to read.
 * callback         : function to return the read block to.
 *
 * RETURN           : void
 */
void
bam_file_read_block (void *handle, int block_index, bam_file_op_callback_t callback);

/*
 * This function writes a block of bytes to the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * block            : Pointer to block of bytes to write to DB. 
 * size             : Size of block to write.
 * callback         : Called when the write is finished
 *
 * NOTE!: It is not allowed to allocate blocks larger than the size_increment parameter
 *
 * RETURN           : index to the written block
 */
int
bam_file_write_block (void *handle, unsigned char* block, int size, bam_file_op_callback_t callback);

/*
 * This function deletes a block from the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * index            : Index of block to be deleted.
 * callback         : Called when the delete is finished
 *
 * RETURN           : void
 */
void
bam_file_delete_block (void *handle, int index, bam_file_op_callback_t callback);

/*
 * This function performs one file task. if there are mor pending tasks the function
 * will send a signal to it self to continue with the next task. If a file operation was
 * delayed this function should be called when the select notification arrives.
 *
 * Parameters:
 *
 *
 * RETURN           : void
 */
void
bam_file_execute_file_task (void);

#endif

#endif
#endif /* _bam_file_h */ 


#endif /*OBIGO_Q03C_BROWSER*/
