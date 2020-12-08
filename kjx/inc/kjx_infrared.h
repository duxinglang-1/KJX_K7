/**********************************************************************************
*Filename:     kjx_infrared.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/04/29
*
***********************************************************************************/
#if !defined(KJX_INFRARED_H)
#define KJX_INFRARED_H

#if defined(__KJX_INFRARED__)


typedef enum 
{
    INFRARED_MENU_OBD   = 0 ,  
    INFRARED_MENU_DOG        , 
    //INFRARED_MENU_VOLUME     , 
    INFRARED_MENU_VIBR     , 
    INFRARED_MENU_MOVE     , 
    INFRARED_MENU_SPEED     , 
    INFRARED_MENU_MAX     
}kjx_infrared_menu_id;

extern BOOL disable_hand_free;
extern const unsigned char INFRARED_RIGHT_NO;
extern const unsigned char INFRARED_MENU_NO;
extern const unsigned char INFRARED_LEFT_NO;
extern const unsigned char INFRARED_BACK_NO;
extern U16 kjx_dog_flag;

extern void kjx_infrared_init(void);
#endif
#endif
