#ifndef _MMI_EBOOKPROT_H
#define _MMI_EBOOKPROT_H

#include "fs_type.h"
#include "wgui_inputs.h"
#include "MMIDataType.h"
#include "Conversions.h"
#include "EbookGprot.h"
#include "ebrsrvgprot.h"
#include "PixcomFontEngine.h"
#include "gui_inputs.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
    
/* nfo file related */
#define     EBR_EBOOK_SEARCH_NFO_STR            "*.nf?"
#define     EBR_TXT_EBOOK_NFO_FILE_EXT          "nf2"

/* line_index file related */
#define     EBR_TXT_EBOOK_LARGE_FONT_LINE_FILE_EXT  "ltl"
#define     EBR_TXT_EBOOK_MEDIUM_FONT_LINE_FILE_EXT "ltm"
#define     EBR_TXT_EBOOK_SMALL_FONT_LINE_FILE_EXT  "lts"

/* source file realted */
#define     EBR_FILE_TYPE_TXT                "TXT"

/* temp file related */
#define     TXT_TEMP_EXT_STR                 ".txz"
#define     EBR_EBOOK_TXZ                    "txz"

/* converting related */
#define     CHARACTERS_IN_ONE_LINE                  (MAX_NUM_OF_CHAR_FOR_EACH_LINE / 2)  
#define     EBOOK_RECURSIVE_SHORT_TIMER_DURATION    10
#define     EBOOK_RECURSIVE_LONG_TIMER_DURATION     2000
#define     GUI_LINE_INFO_STRUCT_BUFFER_LENGTH      2048
#define     LINE_INFO_CACHE_LENGTH                  1024
#define     HALF_LINE_INFO_CACHE_LENGTH             512

/* search related */
#define MMI_EBR_HIGHLIGHT_STRING_FLAG 0x01
/* this flag identifies if it is the first time to search user input string
 * eg: use "find" option, must set this flag */
#define MMI_EBR_FIND_NEXT_FIRST_FLAG 0x02
#define MMI_EBR_SEARCH_FOUND_FLAG 0x04
/* when cannot find the searched string, this flag identifies whether the algo has searched the last record */
#define MMI_EBR_LAST_RECORD_FLAG 0x08 
#define MMI_EBR_SET_SEARCH_STRING_FLAG(search_string_flag, mask) ((search_string_flag) |= (mask))
#define MMI_EBR_RESET_SEARCH_STRING_FLAG(search_string_flag, mask) ((search_string_flag) &= ~(mask))
#define MMI_EBR_CHECK_SEARCH_STRING_FLAG_IS_SET(search_string_flag, mask) ((search_string_flag) & (mask))
#define EBR_FRM_SEARCH_BREAK_TIMER    10

/* others */
#define EBOOK_REFRESH_BOOKSHELF_TIMER_DURATION        100
#define EBOOK_IMEI_NUM                                16
#define EBOOK_CHECK_SUM_ACK                           0
#define EBOOK_MAX_OPEN_BOOK                           1
#define EBOOK_MAX_BOOKSHELF                           1
#define EBR_MAX_OVER_THE_RECORD_BORDER                2

#define EBOOK_DATA_OFFSET_BYTE_LEN                    4

#define EBOOK_SRC_BUFFER_OVER_SIZE ((MAX_NUM_OF_CHAR_FOR_EACH_LINE + 2) > (SRV_EBR_MAX_SEARCH_STRING_LENGTH * 2) ? \
                                    (MAX_NUM_OF_CHAR_FOR_EACH_LINE + 2) : (SRV_EBR_MAX_SEARCH_STRING_LENGTH * 2))
                                   
#if ((MAX_NUM_OF_CHAR_FOR_EACH_LINE / 6 * GUI_MAX_VISIBLE_LINE) > (EBR_RECORD_SIZE_MAX + EBOOK_SRC_BUFFER_OVER_SIZE))
#define EBOOK_SRC_BUFFER_SIZE (MAX_NUM_OF_CHAR_FOR_EACH_LINE / 6 * GUI_MAX_VISIBLE_LINE)
#else
#define EBOOK_SRC_BUFFER_SIZE (EBR_RECORD_SIZE_MAX + EBOOK_SRC_BUFFER_OVER_SIZE)
#endif

#define EBOOK_DEST_BUFFER_SIZE (EBOOK_SRC_BUFFER_SIZE * 2)

//#define EBOOK_DEBUG_ERROR_ASSERT

typedef enum
{
    MMI_EBR_FRM_FILE_TYPE_TXT = 1,
    MMI_EBR_FRM_FILE_TYPE_TOTAL
} mmi_ebr_frm_file_type_enum;

typedef enum
{
    MMI_EBR_FRM_OP_RESULT_SUCCESS,
    MMI_EBR_FRM_OP_RESULT_FAILURE,
    MMI_EBR_FRM_OP_RESULT_BLOCKING,
    MMI_EBR_FRM_OP_RESULT_FILE_TYPE_NOT_SUPPORTED,
    MMI_EBR_FRM_OP_RESULT_FILE_EMPTY,
    MMI_EBR_FRM_OP_RESULT_MEMORY_NOT_ENOUGH,
    MMI_EBR_FRM_OP_RESULT_TOTAL
} mmi_ebr_frm_op_result_enum;

typedef enum
{
    MMI_EBR_APP_SEARCH_RESULT_INVALID = 0,
    MMI_EBR_APP_SEARCH_RESULT_NOT_COMPLETE,
    MMI_EBR_APP_SEARCH_RESULT_SUCCESS,
    MMI_EBR_APP_SEARCH_RESULT_FAIL,
    MMI_EBR_APP_SEARCH_RESULT_TOTAL
} mmi_ebr_app_search_result_enum;

typedef enum
{
    MMI_EBR_FRM_BOOKSHELF_STATE_IDLE = 0,
    MMI_EBR_FRM_BOOKSHELF_STATE_REFRESH,
    MMI_EBR_FRM_BOOKSHELF_STATE_TOTAL
}mmi_ebr_frm_bookshelf_state_enum;

typedef enum
{
    MMI_EBR_FRM_BOOK_STATE_IDLE = 0,
    MMI_EBR_FRM_BOOK_STATE_LOAD_DATA,
    MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD,
    MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX,
    MMI_EBR_FRM_BOOK_STATE_TOTAL
}mmi_ebr_frm_book_state_enum;

typedef struct
{
    S32 book_id;
    FS_HANDLE file_hnd;
    S32 record_id;
    S32 record_offset;
    srv_ebr_search_type_enum search_type;
}mmi_ebr_frm_search_struct;

typedef struct
{
    char file_name[(SRV_EBR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];   
    U8 temp_encoding_file_format;
    U8 imei_value[EBOOK_IMEI_NUM]; /* record the imei related value */

    /* stop converting when close a book and continue converting when open next time */
    MMI_BOOL convert_complete;
    MMI_BOOL temp_file_exist;
    U32 total_records_num;
    U32 current_record_id;
    U32 source_file_convert_offset;
    U32 temp_file_convert_offset;
    U32 index_file_convert_offset; 
    U32 over_the_record_border;
    U8 tempArray[EBR_MAX_OVER_THE_RECORD_BORDER];
    U32 remain_unconverted_characters;
    S16 left_chars[CHARACTERS_IN_ONE_LINE];
    U32 total_converted_characters; 
    
    FS_DOSDateTime last_modify_time;   
    U32 book_size; /* source file size */
    U32 temp_book_size;
    srv_ebr_book_bookmark_struct book_marks[SRV_EBR_MAX_BOOKMARK_NUMBER];
    mmi_ebr_frm_book_state_enum open_state;

    S32 font_size;
    S32 total_line_num; /* total line number in current font */
//    S32 total_line_num_in_font_size_large; /* total line number in font size large */
//    S32 total_line_num_in_font_size_medium; /* total line number in font size medium */
//    S32 total_line_num_in_font_size_small; /* total line number in font size small */
    S32 start_line;
    S32 end_line;
    S32 start_line_offset; 
    U32 final_check; /* the checksum which is used to check the whole nfo file */
} mmi_ebr_frm_book_struct;

typedef struct
{
    MMI_BOOL in_use;
    CHAR path_name[SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH];
    srv_ebr_bookshelf_setting setting;
    mmi_ebr_frm_bookshelf_state_enum state;
    FS_HANDLE refresh_handle;
    void (*refresh_complete_handler)(srv_ebr_bookshelf_refresh_result_struct *); /* the callback function when refresh bookshelf complete */
}mmi_ebr_frm_bookshelf_context;

typedef enum
{
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_IDLE = 0,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_SRC_OPEN,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_OPEN,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_CREAT,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_OPEN,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_CREAT,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_OPEN,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_CREAT,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_DONE,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_ABORT,
    MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TOTAL
}mmi_ebr_frm_async_book_open_state_enum;

typedef struct
{
    MMI_BOOL in_use;
    S32 num_records;
    CHAR book_name[(SRV_EBR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    CHAR book_full_path_name[SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH]; 
    mmi_ebr_frm_book_state_enum state;
    mmi_ebr_frm_book_struct nfo_book_struct;
    S32 current_file_offset;
    S32 current_record_id;
    S32 total_line_num; /* the total numbers of the line */
    void (*open_book_handler)(srv_ebr_open_book_enum, void *); /* the callback function when opening the book */
    MMI_BOOL temp_file_exist;
    MMI_BOOL continue_convert;
    MMI_BOOL index_continue;
    mmi_ebr_frm_file_type_enum file_type;
    
    /* generating line_index file related variables */
    MMI_BOOL current_converting_status; /* identify whetherthe ebook app is using source file to generate the line_index file */
    S32 convert_line_offset; /* identify the last convert line's offset */

    kal_int64 src_file_hnd; /* the file handle of source file */
    kal_int64 convert_temp_file_hnd; /* the file handle of temp file when converting */
    kal_int64 convert_line_file_hnd; /* the file handle of line file when converting */
    kal_int64 async_nfo_file_handle;  
 
    S32 remain_unconverted_characters; /* the left unconverted characters */
    S32 total_characters_in_start_buffer; /* the original number of characters in g_curr_book_cntx_p->dest_buffer buffer */ 
    S32 total_converted_characters; /* the total converted characters */
    srv_ebr_book_convert_speed_enum convert_speed;

    U32 over_the_record_border;
    U8 tempArray[EBR_MAX_OVER_THE_RECORD_BORDER];

    /* the src_buffer has two functions:
     * 1) it stores the data which in source file
     * 2) when in converting state, it stores the temp data which displays in screen */
    U8 src_buffer[EBOOK_SRC_BUFFER_SIZE];
    U8 dest_buffer[EBOOK_DEST_BUFFER_SIZE];

    S32 line_cache_start; /* identify the first line in g_line_info_cache */
    S32 line_cache_end; /* identify the last line in g_line_info_cache */
    S32 first_record_id; /* the first record id in dest_buffer */
    gui_line_info_struct line_info_cache[LINE_INFO_CACHE_LENGTH]; /* the buffer which is used to store line info */
    gui_line_info_struct gui_line_info_struct_buffer[GUI_LINE_INFO_STRUCT_BUFFER_LENGTH / sizeof(gui_line_info_struct)];

    S32 load_data_current_record_id; /* this variable is used in load data into buffer */
    S32 load_data_next_record_id; /* this variable is used in load data into buffer */
    S32 load_data_current_page_id; /* this variable is used in load data into buffer */
    S32 load_data_total_page_num; /* this variable is used in load data into buffer */
    S32 load_data_load_page_count; /* this variable is used in load data into buffer */

    U32 search_string_flag;    
    CHAR last_search_string_input[(SRV_EBR_MAX_SEARCH_STRING_LENGTH + 1) * ENCODING_LENGTH];
    /* This member identifies this "find" operation starts from which record. If this file doesnot contain
    the searched string, use this member to justify whether the whole file has been searched. So keep away
    from dead-loop */
    S32 last_search_line; /* identify the last search line */
    /* search string related members */
    void *search_arg; /* identify the search related argument */
    void (*search_complete_hdlr)(srv_ebr_book_search_result *);
    fs_job_id job_id;
    mmi_ebr_frm_async_book_open_state_enum async_book_open_state;
}mmi_ebr_frm_book_context;

extern mmi_ebr_frm_bookshelf_context g_ebr_frm_bookshelf_context_array[];
extern mmi_ebr_frm_book_context g_ebr_frm_book_context_array[];

#define EBOOK_FRM_SEND_MSG_TO_MMI(msgid, req)  {          \
    ilm_struct *ilm_send = allocate_ilm(MOD_MMI);            \
    ilm_send->msg_id = (msgid);                              \
    ilm_send->peer_buff_ptr = NULL;                          \
    ilm_send->local_para_ptr = (local_para_struct*)(req);    \
    ilm_send->src_mod_id = MOD_MMI;                          \
    ilm_send->dest_mod_id = MOD_MMI;                         \
    ilm_send->sap_id = 0;                                    \
    msg_send_ext_queue(ilm_send);}

/* bookshelf related */
extern void mmi_ebr_frm_bookshelf_init(void);
extern S32 mmi_ebr_frm_get_first_available_bookshelf_id(void);
extern mmi_ebr_frm_bookshelf_context *mmi_ebr_frm_get_bookshelf_context(S32 bookshelf_id);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_refresh_book_operation(CHAR *book_path, CHAR *nfo_file_name);
extern void mmi_ebr_frm_refresh_bookshelf_timeout_handler(void *arg);

/* book related */
extern void mmi_ebr_frm_book_init(void);
extern S32 mmi_ebr_frm_get_first_available_book_id(void);
extern MMI_BOOL mmi_ebr_frm_compare_book_last_modify_time(FS_DOSDateTime *book_last_modify_time, FS_DOSDateTime *nfo_file_record_time);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_is_empty_file(S32 book_id, FS_HANDLE file_hnd, mmi_ebr_frm_file_type_enum type, MMI_BOOL *is_empty);
extern S32 mmi_ebr_frm_get_number_of_records(U32 book_size, U32 record_size);
extern S32 mmi_ebr_frm_get_record_context(S32 book_id, FS_HANDLE file_hnd, S32 record_id, mmi_ebr_frm_file_type_enum file_type, U8 *buffer, S32 *p_content_size);
extern int mmi_ebr_frm_convert_record(S32 book_id, FS_HANDLE file_hnd, FS_HANDLE new_file_hnd, S32 record_id, mmi_ebr_frm_file_type_enum file_type);
extern MMI_BOOL mmi_ebr_frm_check_temp_file_exist(S32 book_id);
extern S32 mmi_ebr_frm_get_record_size_txt(S32 book_id, S32 rec_num);
extern void mmi_ebr_frm_start_decompression(U8 *decompressed_buffer, U8 *compressed_buffer, U32 *size);
extern MMI_BOOL mmi_ebr_frm_bm_search(S16 *text, S16 *pat, S32 *start_pos,U32 size);
extern mmi_ebr_frm_book_context *mmi_ebr_frm_get_book_context(S32 book_id);
extern void mmi_ebr_frm_get_line_file_name(CHAR *ebook_name, CHAR *line_file_name, WGUI_FONT_SIZE font_size);
extern void mmi_ebr_frm_get_temp_file_name(CHAR *ebook_name, CHAR *temp_file_name);
extern void mmi_ebr_frm_get_nfo_file_name(CHAR *ebook_name, CHAR *nfo_file_name);
extern MMI_BOOL mmi_ebr_frm_convert_context_into_line(S32 book_id, S32 *remain_unconverted_characters, MMI_BOOL *end_flag, S32 *p_fs_error);
extern MMI_BOOL mmi_ebr_frm_init_line_info_cache(S32 book_id, S32 start_line, S32 *start_line_offset);
extern void mmi_ebr_frm_set_line_info_catch_id(S32 book_id, S32 cache_start);
extern MMI_BOOL mmi_ebr_frm_get_data_len(S32 book_id, S32 start_line, S32 end_line, S32 *p_total_offset_from_file_header, S32 *p_data_len, S32 *p_fs_error);
extern MMI_BOOL mmi_ebr_frm_get_data_context(S32 book_id, U8 **buffer, S32 total_offset_from_file_head, S32 p_data_len, S32 *p_fs_error);
extern MMI_BOOL mmi_ebr_frm_get_searched_string_start_line(S32 book_id, S32 total_offset, S32 search_string_len, S32 *start_line, S32 *start_line_offset);
extern void mmi_ebr_frm_bm_get_searched_string_offset(S32 book_id, S32 start_id, S32 end_id, S32 total_offset, S32 *start_line, S32 *start_line_offset);
extern void mmi_ebr_frm_reset_line_base_data(S32 book_id);
extern void *mmi_ebr_frm_malloc_memory(S32 size);
extern void mmi_ebr_frm_free_memory(void **arg);
extern void mmi_ebr_frm_free_file_handles(S32 book_id);
extern void mmi_ebr_frm_delete_line_index_file(S32 book_id);
extern MMI_BOOL mmi_ebr_frm_reset_nfo_line_element(S32 book_id);
extern MMI_BOOL mmi_ebr_frm_guess_book_charset(S32 book_id, FS_HANDLE file_hnd, mmi_ebr_frm_file_type_enum file_type, mmi_chset_enum *book_charset);
extern void mmi_ebr_frm_change_imei_value(U8 *imei_value, S32 count);
extern mmi_ebr_app_search_result_enum mmi_ebr_frm_search_string_in_record(S32 book_id, FS_HANDLE file_hnd, S32 record_id, S32 *record_offset, srv_ebr_search_type_enum search_type, char *search_string);   
extern void mmi_ebr_frm_search_timeout_handler(void *arg);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index(S32 book_id, S32 *p_fs_error);
extern void mmi_ebr_frm_convert_record_and_line_index_fsm(void *arg);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_convert_record(S32 book_id, S32 *p_fs_error);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_generate_line_index(S32 book_id, S32 *p_fs_error);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_load_data(S32 book_id, S32 *p_fs_error);
extern MMI_BOOL mmi_ebr_frm_book_is_in_converting_state(S32 book_id);
extern MMI_BOOL mmi_ebr_frm_check_convert_context_into_line_loop(void);
extern srv_ebr_book_open_error_enum mmi_ebr_frm_error_to_srv_error(mmi_ebr_frm_op_result_enum op_error);
extern srv_ebr_op_result_enum mmi_ebr_frm_op_result_to_srv_result(mmi_ebr_frm_op_result_enum op_result);

// async fs new API
extern MMI_BOOL mmi_ebr_frm_async_save_settings_in_nfo_file(S32 book_id, S32 *p_fs_error);
extern void mmi_ebr_frm_free_async_file_handles(S32 book_id);
extern kal_int32 mmi_ebr_frm_async_refresh_file_callback(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data);
extern kal_int32 mmi_ebr_frm_async_open_fsm(fs_job_id job_id, kal_int64 result, fs_async_callback_data_struct *data);
extern MMI_BOOL mmi_ebr_frm_async_check_nfo_vaild(S32 book_id);
extern void mmi_ebr_frm_delete_temp_file(S32 book_id);
mmi_ebr_frm_op_result_enum mmi_ebr_frm_open_source_file(S32 book_id);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_nfo_file(S32 book_id);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_temp_file(S32 book_id, kal_int32 flag);
extern mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_index_file(S32 book_id, kal_int32 flag);
extern kal_int32 mmi_ebr_frm_async_delete(const kal_wchar* filename);

#endif /* _MMI_EBOOKPROT_H */ 

