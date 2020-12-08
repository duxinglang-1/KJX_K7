#include "MMI_features.h"

#if (defined(__MMI_SOUND_RECORDER__) && !defined(__COSMOS_MMI_PACKAGE__))
#include "gdi_lcd_config.h"

#include "mmi_frm_gprot.h"
#include "GlobalConstants.h"
#include "FileMgr.h"

#include "SndrecResDef.h"
#include "SndrecDef.h"
#include "mmi_rp_app_soundrecorder_def.h"

/* ON/OFF Skin Mode MACRO define lie on screen size */
/*#if (((LCD_WIDTH == 128) && (LCD_HEIGHT == 128)) || ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160)))
    #ifdef __MMI_SNDREC_SKIN__
    #undef __MMI_SNDREC_SKIN__
    #endif*/
 /*   
#if (((LCD_WIDTH == 176) && (LCD_HEIGHT == 220)) || ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) || ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) || ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)))
    #ifndef __MMI_SNDREC_SKIN__
    #define __MMI_SNDREC_SKIN__
    #endif
#endif */
// baiwenlin 20130821  
#if ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220)||(LCD_WIDTH == 128) && (LCD_HEIGHT == 36))
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {28, 1}, {28, 28}, {1, 28}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {28, 1}, {28, 28}, {1, 28}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {28, 1}, {28, 28}, {1, 28}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {28, 1}, {28, 28}, {1, 28}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {28, 1}, {28, 28}, {1, 28}};
#endif /* __MMI_TOUCH_SCREEN__ */
const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 8, 176, 16,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        16, 127, 126, 18,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		25, 44, 127, 16,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        16, 147, 150, 14,   //time x, y, w, h
        /* ANIMATION IMG*/
        29, 42,
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
        19, 162,
        IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,        
        53, 162,
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        87, 162,
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        121, 162,
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        /* Touch Button area */
        125, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT/*0, 1, 2, 3*/
    }
};
#endif

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) || (LCD_WIDTH == 240) && (LCD_HEIGHT == 240))
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_stop_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
#else/*MMI_FTE_SUPPORT*/
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {45, 1}, {45, 45}, {1, 45}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {45, 1}, {45, 45}, {1, 45}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {45, 1}, {45, 45}, {1, 45}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {45, 1}, {45, 45}, {1, 45}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {45, 1}, {45, 45}, {1, 45}};
#endif/*MMI_FTE_SUPPORT*/
#endif /* __MMI_TOUCH_SCREEN__ */
const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
#ifdef __MMI_FTE_SUPPORT__
    /* Back Ground Img */
    //IMG_ID_SNDREC_FTE_BACKGROUND,    // bg img id
    
    /* LSK */
    IMG_ID_SNDREC_FTE_SKIN_LSK,    // LSK up image
    IMG_ID_SNDREC_FTE_SKIN_LSK_DOWN,
    //IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE,
    9, 289,    // LSK coordinate

    /* RSK */    
    IMG_ID_SNDREC_FTE_SKIN_RSK,
    IMG_ID_SNDREC_FTE_SKIN_RSK_DOWN,
    //IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE,
    199, 289,    // RSK coordinate

    /* Title */
    255, 255, 255,    // title text color
    0, 0, 0,         // title text border color
    0, 14, 240, 24,      // title x, y, w, h

    /* Name */
    255, 255, 255,        // name text color
    0, 0, 0,             // name text border color
    76, 128, 86, 27,    // filename x, y, w, h

    /* Time */
    255, 255, 255,    // time text color
    0, 0, 0,         // time text border color
    56, 156, 145, 18,   // time x, y, w, h

    /* ANIMATION IMG*/
    76, 36,
    IMG_ID_SNDREC_FTE_ANIMAL,    // animal iamge id

    /* REC Button */
    104, 221,     // rec button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_REC_UP,
    IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE,
    
#if defined(__MMI_OP02_LEMEI__)
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE,
#endif
    
    /* PLAY Button */
    104, 193,    // play button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP,
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE,

    /* PREV Button */
    59, 221,   // prev button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_PREV_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE,

    /* NEXT Button */
    149, 221,    // next button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE,

    /* Hilight Image */
    IMG_ID_SNDREC_FTE_HIGHLIGHT,

    /* LIST Button */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    263,36,
    IMG_ID_SNDREC_FTE_BUTTON_LIST_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE,
#endif

    /* STOP Button */
    104, 249,    // stop button area
    IMG_ID_SNDREC_FTE_BUTTON_STOP_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE,

    /* REC Sign */
    45, 159,    // rec sign coordinate
    IMG_ID_SNDREC_FTE_REC_SIGN,
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN,

    /* LINE */
#ifdef __MMI_FTE_SUPPORT_SLIM__
    43, 177,
    IMG_ID_SNDREC_FTE_LINE,
#endif

    /* CROSS */
/*#ifdef __MMI_FTE_SUPPORT_SLIM__
    46, 190,
    IMG_ID_SNDREC_FTE_CROSS,
#endif */
    
    /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
    {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_stop_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */

    SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT

#else/*__MMI_FTE_SUPPORT__*/

		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 14, 240, 24,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        45, 178, 150, 22,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		45, 52, 150, 20,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        45, 200, 150, 18,   //time x, y, w, h
        /* ANIMATION IMG*/
        44, 76,  //45,53
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
		29, 239,
        IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,        
        74, 239,
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        121, 239,
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        168, 239,
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        /* Touch Button area */
        197, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
        
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT
    #endif/*__MMI_FTE_SUPPORT__*/
    }
};
#endif/*__MMI_SNDREC_SKIN__*/

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_stop_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
#else/*MMI_FTE_SUPPORT*/
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {27, 1}, {27, 27}, {1, 27}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {27, 1}, {27, 27}, {1, 27}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {27, 1}, {27, 27}, {1, 27}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {27, 1}, {27, 27}, {1, 27}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {27, 1}, {27, 27}, {1, 27}};
#endif/*MMI_FTE_SUPPORT*/
#endif /* __MMI_TOUCH_SCREEN__ */

const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
#ifdef __MMI_FTE_SUPPORT__
            /* Back Ground Img */
            //IMG_ID_SNDREC_FTE_BACKGROUND, //bg img id
            /* LSK */
            IMG_ID_SNDREC_FTE_SKIN_LSK,
             IMG_ID_SNDREC_FTE_SKIN_LSK_DOWN,
            //IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE,
            9, 367, // LSK coordinate
            IMG_ID_SNDREC_FTE_SKIN_RSK,
            IMG_ID_SNDREC_FTE_SKIN_RSK_DOWN,
            //IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE,
            199, 367, // RSK coordinat
            /* Title */
            255, 255, 255,    //title text color
            0, 0, 0,         //title text border color
            0, 14, 240, 24,      //title x, y, w, h
            /* state */
            //255, 255, 255,    //state text color
            //0, 0, 0,  //state text border color
            //56, 163, 150, 22,   //state x, y, w, h
            /* Name */
            255, 255, 255,    //name text color
            0, 0, 0,  //name text border color
            75, 172, 86, 20,    //filename x, y, w, h
        
            /* time */
            255, 255, 255,    //time text color
            0, 0, 0,  //time text border color
            58, 197, 135, 18,   //time x, y, w, h
        
        
            /* ANIMATION IMG*/
            75, 50,
            IMG_ID_SNDREC_FTE_ANIMAL, //animal iamge id
        
            /* Button */
            104, 276,  // rec button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_REC_UP,
            IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE,
            
    #if defined(__MMI_OP02_LEMEI__)
            IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE,
    #endif
            
        
            104, 248,  // play button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP,
            IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE,
        
            59, 276, //prev button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_PREV_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE,
        
            149, 276,  //next button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE,
        
            IMG_ID_SNDREC_FTE_HIGHLIGHT,

    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            263,36,
            IMG_ID_SNDREC_FTE_BUTTON_LIST_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE,
    #endif

            104, 304,  //stop button area
            IMG_ID_SNDREC_FTE_BUTTON_STOP_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE,
        
            48, 199,  // rec sign coordinate
            IMG_ID_SNDREC_FTE_REC_SIGN,
            IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN,
                
#ifdef __MMI_FTE_SUPPORT_SLIM__
                43, 227,
                IMG_ID_SNDREC_FTE_LINE,
#endif
        
/*#ifdef __MMI_FTE_SUPPORT_SLIM__
        48, 244,
        IMG_ID_SNDREC_FTE_CROSS,
#endif */
            
    /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
    {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_stop_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        
    SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT

#else/*__MMI_FTE_SUPPORT__*/

		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 35, 240, 20,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        18, 247, 204, 22,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		45, 78, 160, 22,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        18, 274, 150, 22,   //time x, y, w, h
        /* ANIMATION IMG*/
        21, 120,  //45,53
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
		24, 317,
        IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,        
        78, 317,
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        134, 317,
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        189, 317,
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        197, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
        /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT        
#endif/*MMI_FTE_SUPPORT*/
    }
};
#endif

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
static const mmi_sndrec_point_struct mmi_sndrec_stop_pen[] = {{1, 1}, {39, 1}, {39, 29}, {1, 29}};
#else/*MMI_FTE_SUPPORT*/
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {23, 1}, {23, 23}, {1, 23}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {23, 1}, {23, 23}, {1, 23}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {23, 1}, {23, 23}, {1, 23}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {23, 1}, {23, 23}, {1, 23}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {23, 1}, {23, 23}, {1, 23}};
#endif/*MMI_FTE_SUPPORT*/
#endif /* __MMI_TOUCH_SCREEN__ */
const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
    #ifdef __MMI_FTE_SUPPORT__
            /* Back Ground Img */
            //IMG_ID_SNDREC_FTE_BACKGROUND, //bg img id
            /* LSK */
            IMG_ID_SNDREC_FTE_SKIN_LSK,
            IMG_ID_SNDREC_FTE_SKIN_LSK_DOWN,
            //IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE,
            9, 210, // LSK coordinate
            IMG_ID_SNDREC_FTE_SKIN_RSK,
            IMG_ID_SNDREC_FTE_SKIN_RSK_DOWN,
            //IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE,
            282, 210, // RSK coordinat
            /* Title */
            255, 255, 255,    //title text color
            0, 0, 0,         //title text border color
            0, 14, 240, 24,      //title x, y, w, h
            /* state */
            //255, 255, 255,    //state text color
            //0, 0, 0,  //state text border color
            //56, 163, 150, 22,   //state x, y, w, h
            /* Name */
            255, 255, 255,    //name text color
            0, 0, 0,  //name text border color
            183, 39, 118, 20,    //filename x, y, w, h
        
            /* time */
            255, 255, 255,    //time text color
            0, 0, 0,  //time text border color
            190, 62, 120, 18,   //time x, y, w, h        
        
            /* ANIMATION IMG*/
            38, 52,
            IMG_ID_SNDREC_FTE_ANIMAL, //animal iamge id
        
            /* Button */
            226, 136,  // rec button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_REC_UP,
            IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE,
            
        #if defined(__MMI_OP02_LEMEI__)
            IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE,
        #endif
        
            226, 108,  // play button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP,
            IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE,
        
            181, 136, //prev button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_PREV_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE,
        
            271, 136,  //next button coordinate
            IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE,
        
            IMG_ID_SNDREC_FTE_HIGHLIGHT,

        #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            263,36,
            IMG_ID_SNDREC_FTE_BUTTON_LIST_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE,
        #endif
        
            226, 164,  //stop button area
            IMG_ID_SNDREC_FTE_BUTTON_STOP_UP,
            //IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE,
        
            179, 64,  // rec sign coordinate
            IMG_ID_SNDREC_FTE_REC_SIGN,
            IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN,
                
        #ifdef __MMI_FTE_SUPPORT_SLIM__
            176, 92,
            IMG_ID_SNDREC_FTE_LINE,
        #endif
	        
        /*#ifdef __MMI_FTE_SUPPORT_SLIM__
            168, 103,
            IMG_ID_SNDREC_FTE_CROSS,
        #endif */
    
    /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
    {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_stop_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
    SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT

#else/*__MMI_FTE_SUPPORT__*/
		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 8, 320, 22,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        29, 125, 262, 22,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		29, 47, 262, 20,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        29, 148, 150, 18,   //time x, y, w, h
        /* ANIMATION IMG*/
		25, 66,  //45,53
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
    #if defined(LOW_COST_SUPPORT)
		38, 174,
		#else
		38, 184,
		#endif
		IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,
        #if defined(LOW_COST_SUPPORT)
        82, 174,
        #else
        82, 184,
        #endif
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        #if defined(LOW_COST_SUPPORT)
        127, 174,
        #else
        127, 184,
        #endif
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        #if defined(LOW_COST_SUPPORT)
        173, 174,
        #else
        173, 184,
        #endif
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        /* Touch Button area */
        197, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT            
#endif/*MMI_FTE_SUPPORT*/          
    }
};
#endif

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_stop_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
#else/*MMI_FTE_SUPPORT*/
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};

#endif/*MMI_FTE_SUPPORT*/
#endif /* __MMI_TOUCH_SCREEN__ */
const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
#ifdef __MMI_FTE_SUPPORT__
    /* Back Ground Img */
    //IMG_ID_SNDREC_FTE_BACKGROUND,    // bg img id
    
    /* LSK */
    IMG_ID_SNDREC_FTE_SKIN_LSK,
    IMG_ID_SNDREC_FTE_SKIN_LSK_DOWN,
    //IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE,
    11,436,    // LSK coordinate

    /* RSK */
    IMG_ID_SNDREC_FTE_SKIN_RSK,
    IMG_ID_SNDREC_FTE_SKIN_RSK_DOWN,
    //IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE,
    267,436,    // RSK coordinate

    /* Title */
    255, 255, 255,        // title text color
    0, 0, 0,              // title text border color
    0, 14, 240, 24,      // title x, y, w, h

    /* Name */
    255, 255, 255,        // name text color
    0, 0, 0,              // name text border color
    85, 215, 150, 20,    // filename x, y, w, h

    /* Time */
    255, 255, 255,        //time text color
    0, 0, 0,             //time text border color
    100, 243, 180, 18,   // time x, y, w, h

    /* ANIMATION IMG*/
    88, 53,
    IMG_ID_SNDREC_FTE_ANIMAL,    // animal iamge id

    /* REC Button */
    139,332,    // rec button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_REC_UP,
    IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE,

    #if defined(__MMI_OP02_LEMEI__)
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE,
    #endif

    /* PLAY Button */
    139,290,    // play button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP,
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE,

    /* PREV Button */
    72, 332,    // prev button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_PREV_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE,

    /* NEXT Button */
    206, 332,    // next button coordinate
    IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE,

    /* Hilight Image */
    IMG_ID_SNDREC_FTE_HIGHLIGHT,

    /* List Up Button */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    263,36,
    IMG_ID_SNDREC_FTE_BUTTON_LIST_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE,
#endif

    /* Stop Button */
    139, 374,
    IMG_ID_SNDREC_FTE_BUTTON_STOP_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE,

    /* Rec Sign */
    85, 243,
    IMG_ID_SNDREC_FTE_REC_SIGN,
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN,

#ifdef __MMI_FTE_SUPPORT_SLIM__
    47,270,
    IMG_ID_SNDREC_FTE_LINE,
#endif
    
/*#ifdef __MMI_FTE_SUPPORT_SLIM__
        56, 286,
        IMG_ID_SNDREC_FTE_CROSS,
#endif */
    
    /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
    {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_stop_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */

    SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT

#else/*__MMI_FTE_SUPPORT__*/

		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 30, 320, 24,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        26, 290, 200, 26,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		0, 80, 320, 27,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        22, 328, 290, 26,   //time x, y, w, h
        /* ANIMATION IMG*/
		26, 120,  //45,53
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
		0, 368,
		IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,
        80, 368,
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        160, 368,
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        240, 368,
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        197, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
        
        /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT            
#endif/*MMI_FTE_SUPPORT*/    
    }
};
#endif

#elif ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) ) || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) )
#ifdef __MMI_SNDREC_SKIN__
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
static const mmi_sndrec_point_struct mmi_sndrec_stop_pen[] = {{1, 1}, {52, 1}, {52, 43}, {1, 43}};
#else/*MMI_FTE_SUPPORT*/
static const mmi_sndrec_point_struct mmi_sndrec_record_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_play_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_prev_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_next_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};
static const mmi_sndrec_point_struct mmi_sndrec_list_pen[] = {{1, 1}, {60, 1}, {60, 60}, {1, 60}};

#endif/*MMI_FTE_SUPPORT*/
#endif /* __MMI_TOUCH_SCREEN__ */
const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[] = 
{
    {
#ifdef __MMI_FTE_SUPPORT__
    /* Back Ground Img */
    //IMG_ID_SNDREC_FTE_BACKGROUND, //bg img id
    /* LSK */
    IMG_ID_SNDREC_FTE_SKIN_LSK,
    //IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE,
    11,436,
    IMG_ID_SNDREC_FTE_SKIN_RSK,
    //IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE,
    269,436,
    /* Title */
    255, 255, 255,    //title text color
    0, 0, 0,         //title text border color
    0, 14, 240, 24,      //title x, y, w, h
    /* state */
    //255, 255, 255,    //state text color
    //0, 0, 0,  //state text border color
    //56, 163, 150, 22,   //state x, y, w, h
    /* Name */
    255, 255, 255,    //name text color
    0, 0, 0,  //name text border color
    75, 223, 150, 20,    //filename x, y, w, h
    /* time */
    255, 255, 255,    //time text color
    0, 0, 0,  //time text border color
    62, 256, 187, 18,   //time x, y, w, h
    /* ANIMATION IMG*/
    63, 55,  //45,53
    IMG_ID_SNDREC_FTE_ANIMAL, //animal iamge id
    /* Button */
    132, 372,
    IMG_ID_SNDREC_FTE_BUTTON_REC_UP,
    IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE,
    #if defined(__MMI_OP02_LEMEI__)
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE,
    #endif
    45, 372,
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP,
    IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE,
    49, 305,
    IMG_ID_SNDREC_FTE_BUTTON_PREV_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE,
    220, 305,
    IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE,
    IMG_ID_SNDREC_FTE_HIGHLIGHT,
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    263,36,
    IMG_ID_SNDREC_FTE_BUTTON_LIST_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE,
#endif
    224,372,
    IMG_ID_SNDREC_FTE_BUTTON_STOP_UP,
    //IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE,
    50,257,
    IMG_ID_SNDREC_FTE_REC_SIGN,
    IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN,
#ifdef __MMI_FTE_SUPPORT_SLIM__
    5,302,
    IMG_ID_SNDREC_FTE_LINE,
#endif
    
    /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
    {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_list_pen, 4},
    {(const mmi_sndrec_point_struct*) mmi_sndrec_stop_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
    SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT

#else/*__MMI_FTE_SUPPORT__*/

		/* Back Ground Img */
		IMG_ID_SNDREC_BACKGROUND, //bg img id
		/* LSK */
		255, 255, 255,  //lsk text color
		0, 0, 0,  //lsk text border color
		/* RSK */
		255, 255, 255,  //rsk text color
		0, 0, 0,  //rsk text border color
        /* Title */
		255, 255, 255,    //title text color
        0, 0, 0,         //title text border color
        0, 30, 320, 24,      //title x, y, w, h
        /* state */
        255, 255, 255,    //state text color
        0, 0, 0,  //state text border color
        26, 290, 200, 26,   //state x, y, w, h
        /* Name */
		255, 255, 255,    //name text color
		0, 0, 0,  //name text border color
		0, 80, 320, 27,    //filename x, y, w, h
        /* time */
        255, 255, 255,    //time text color
        0, 0, 0,  //time text border color
        22, 328, 290, 26,   //time x, y, w, h
        /* ANIMATION IMG*/
		26, 120,  //45,53
        IMG_ID_SNDREC_ANIMAL, //animal iamge id
        /* Button */
		0, 368,
		IMG_ID_SNDREC_BUTTON_REC_UP,
        IMG_ID_SNDREC_BUTTON_REC_DN,
        IMG_ID_SNDREC_BUTTON_REC_P_UP,
        IMG_ID_SNDREC_BUTTON_REC_P_DN,
        IMG_ID_SNDREC_BUTTON_REC_DISABLE,
        IMG_ID_SNDREC_BUTTON_STOP_P_UP,
        IMG_ID_SNDREC_BUTTON_STOP_P_DOWN,
        80, 368,
        IMG_ID_SNDREC_BUTTON_PLAY_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_P_UP,
        IMG_ID_SNDREC_BUTTON_PLAY_P_DN,
        IMG_ID_SNDREC_BUTTON_PLAY_DISABLE,
        160, 368,
        IMG_ID_SNDREC_BUTTON_PREV_UP,
        IMG_ID_SNDREC_BUTTON_PREV_DN,
        IMG_ID_SNDREC_BUTTON_PREV_DISABLE,
        240, 368,
        IMG_ID_SNDREC_BUTTON_NEXT_UP,
        IMG_ID_SNDREC_BUTTON_NEXT_DN,
        IMG_ID_SNDREC_BUTTON_NEXT_DISABLE,
        197, 25,
        IMG_ID_SNDREC_BUTTON_LIST_UP,
        IMG_ID_SNDREC_BUTTON_LIST_DN,
        IMG_ID_SNDREC_BUTTON_LIST_DISABLE,
        
        /* Touch Button area */
#ifdef __MMI_TOUCH_SCREEN__
        {(const mmi_sndrec_point_struct*) mmi_sndrec_record_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_play_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_prev_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
        {(const mmi_sndrec_point_struct*) mmi_sndrec_next_pen, 4},
#endif /* __MMI_TOUCH_SCREEN__ */
        SNDREC_MAIN_REC, SNDREC_MAIN_PLAY, SNDREC_MAIN_PREV, SNDREC_MAIN_NEXT            
#endif/*MMI_FTE_SUPPORT*/    
    }
};
#endif

#endif 

#endif  /* defined(__MMI_SOUND_RECORDER__) */
