#ifndef __SNS_SRV_FB_H__
#define __SNS_SRV_FB_H__

typedef struct srv_sns_fb_activity {
   struct srv_sns_fb_activity *next;
   srv_sns_user_struct user;
   srv_sns_activity_enum type;
   U8 act_id_len;   CHAR *act_id;
   U8 photo_id_len; CHAR *photo_id;
   U16 message_len; WCHAR *message;
   U16 link_len;    CHAR *link;
   U8 has_pic;
   U16 pic_len;     WCHAR *pic; /* local path of pic, empty if not yet downloaded */
   U32 timestamp;
   U32 blob_size; /* 12 */
   // ----------
   S16 photo_index; /* -1 if no photo */
   U16 like_count;
   U8 can_like;
   U8 user_likes;
   U16 comment_count;
   U8 can_comment;
} srv_sns_fb_activity_struct;

typedef struct srv_sns_fb_photo {
   struct srv_sns_fb_photo *next;
   U32 provider;
   U8 album_id_len;     CHAR *album_id;
   U8 user_id_len;      CHAR *user_id;
   U8 photo_id_len;     CHAR *photo_id;
   U16 description_len; WCHAR *description;
   U8 has_pic;
   U8 thumbnail_len;    WCHAR *thumbnail; /* local path of thumbnail, empty if not yet downloaded */
   U8 pic_len;          WCHAR *pic; /* url of the pic */
   U16 count; /* number of photos in the same album */
   U16 pos; /* the position of this photo in the album */
   U32 blob_size; /* 8 */
   // ----------
   U16 like_count;
   U8 can_like;
   U8 user_likes;
   U16 comment_count;
   U8 can_comment;
} srv_sns_fb_photo_struct;

/******************************************************************************
 * FUNCTION
 *    srv_sns_fb_like
 * DESCRIPTION
 *    like or unlike an object
 * PARAMETERS
 *    activity:  [IN]  the activity to like
 *                     like_count and user_likes should be updated if successful
 *    like:      [IN]  true to like, false to unlike
 *    cb:        [IN]  callback will be called to receive the requested data
 * RETURNS
 *    > 0 for request id
 *    < 0 for srv_sns_result
 ******************************************************************************/
S32 srv_sns_fb_like(
   srv_sns_object_enum        type,
   CHAR                       *obj_id,
   MMI_BOOL                   like,
   mmi_proc_func              done_cb, // EVT_ID_SRV_SNS_RESULT
   void                       *user_data
);

/******************************************************************************
 * FUNCTION
 *    srv_sns_fb_like_with_update
 * DESCRIPTION
 *    like or unlike an object
 * PARAMETERS
 *    list_id:   [IN]  the list 
 *    index:     [IN]  the index   
 *    like:      [IN]  true to like, false to unlike
 *    cb:        [IN]  callback will be called to receive the requested data
 * RETURNS
 *    > 0 for request id
 *    < 0 for srv_sns_result
 ******************************************************************************/
S32 srv_sns_fb_like_with_update(
   S32                        list_id,
   S16                        index,
   MMI_BOOL                   like,
   mmi_proc_func              done_cb, // EVT_ID_SRV_SNS_RESULT
   void                       *user_data
);;

/******************************************************************************
 * FUNCTION
 *    srv_sns_fb_write_wall
 * DESCRIPTION
 *    write on a friend's wall
 * PARAMETERS
 *    user_id:   [IN]  the id of the friend whose wall to write on
 *    message:   [IN]  the message to write on his/her wall
 *    cb:        [IN]  callback will be called to receive the requested data
 * RETURNS
 *    > 0 for request id
 *    < 0 for srv_sns_result
 ******************************************************************************/
S32 srv_sns_fb_write_wall(
   CHAR                     *user_id,
   WCHAR                    *message
);

#endif
