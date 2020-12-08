#ifndef __SNS_SRV_TWT_H__
#define __SNS_SRV_TWT_H__

typedef struct srv_sns_twt_activity {
   struct srv_sns_twt_activity *next;
   srv_sns_user_struct user;
   srv_sns_activity_enum type;
   U8 act_id_len;   CHAR *act_id;
   U8 photo_id_len; CHAR *photo_id;
   U16 message_len; WCHAR *message;
   U16 link_len;    CHAR *link;
   U8 has_pic;
   U16 pic_len;     WCHAR *pic; /* local path of pic, empty if not yet downloaded */
   U32 timestamp;
   U32 blob_size; /* 8 */
   // ----------
   U8 can_favorite; /* always return 1 for now */
   U8 favorited; /* whether the user has favorited this tweet */
   U8 can_retweet; /* 1 if the original poster is not the current user */
   U8 retweeted; /* whether the user has retweeted this tweet */
   U16 retweet_count; /* the number of total retweets for this tweet */
} srv_sns_twt_activity_struct;

void srv_sns_twt_fill_can_retweet(srv_sns_twt_activity_struct *activity);

S32 srv_sns_twt_favorite(
   CHAR           *act_id,
   MMI_BOOL       favorite,
   mmi_proc_func  done_cb, // EVT_ID_SRV_SNS_RESULT
   void           *user_data
);

S32 srv_sns_twt_reply_to_status(
   CHAR           *act_id,
   WCHAR          *message
);

S32 srv_sns_twt_retweet(
   CHAR           *act_id
);

S32 srv_sns_twt_retweet_with_update(
   S32            list_id, 
   S16            index,
   mmi_proc_func  done_cb, 
   void           *user_data
);

#endif
