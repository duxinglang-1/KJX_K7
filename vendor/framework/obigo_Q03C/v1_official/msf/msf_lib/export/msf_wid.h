/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_wid.h
 *
 * Created by Anders Hansson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_wid_h
#define _msf_wid_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif


/****************************************
 * Widget
 ****************************************/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define MSF_WIDGET_DEVICE_GET_PROPERTIES            gmms_HDIa_widgetDeviceGetProperties
#define MSF_WIDGET_SET_IN_FOCUS                     gmms_HDIa_widgetSetInFocus
#define MSF_WIDGET_HAS_FOCUS                        gmms_HDIa_widgetHasFocus
#define MSF_WIDGET_RELEASE                          gmms_HDIa_widgetRelease
#define MSF_WIDGET_RELEASE_ALL                      gmms_HDIa_widgetReleaseAll
#define MSF_WIDGET_COPY                             gmms_HDIa_widgetCopy
#define MSF_WIDGET_REMOVE                           gmms_HDIa_widgetRemove
#define MSF_WIDGET_ADD_ACTION                       gmms_HDIa_widgetAddAction
#define MSF_WIDGET_HANDLE_MSF_EVT                   gmms_HDIa_widgetHandleMsfEvt
#define MSF_WIDGET_SET_TITLE                        gmms_HDIa_widgetSetTitle
#define MSF_WIDGET_SET_BORDER                       gmms_HDIa_widgetSetBorder
#define MSF_WIDGET_SET_POSITION                     gmms_HDIa_widgetSetPosition
#define MSF_WIDGET_SET_SIZE                         gmms_HDIa_widgetSetSize
#define MSF_WIDGET_GET_POSITION                     gmms_HDIa_widgetGetPosition
#define MSF_WIDGET_GET_SIZE                         gmms_HDIa_widgetGetSize

#define MSF_WIDGET_SCREEN_CREATE                    gmms_HDIa_widgetScreenCreate
#define MSF_WIDGET_SCREEN_SET_NOTIFY                gmms_HDIa_widgetScreenSetNotify
#define MSF_WIDGET_SCREEN_ADD_WINDOW                gmms_HDIa_widgetScreenAddWindow
#define MSF_WIDGET_SCREEN_ACTIVE_WINDOW             gmms_HDIa_widgetScreenActiveWindow

#define MSF_WIDGET_WINDOW_ADD_GADGET                gmms_HDIa_widgetWindowAddGadget
#define MSF_WIDGET_WINDOW_SET_TICKER                gmms_HDIa_widgetWindowSetTicker
#define MSF_WIDGET_WINDOW_SET_PROPERTIES            gmms_HDIa_widgetWindowSetProperties
#define MSF_WIDGET_WINDOW_SPECIFIC_SIZE             gmms_HDIa_widgetWindowSpecificSize

#define MSF_WIDGET_PAINTBOX_CREATE                  gmms_HDIa_widgetPaintboxCreate
#define MSF_WIDGET_PAINTBOX_REDRAW_AREA             gmms_HDIa_widgetPaintboxRedrawArea
#define MSF_WIDGET_FORM_CREATE                      gmms_HDIa_widgetFormCreate

#define MSF_WIDGET_TEXT_SET_TEXT                    gmms_HDIa_widgetTextSetText
#define MSF_WIDGET_TEXT_MAX_SIZE                    gmms_HDIa_widgetTextMaxSize
#define MSF_WIDGET_TEXT_CLEAR                       gmms_HDIa_widgetTextClear
#define MSF_WIDGET_TEXT_SET_PROPERTY                gmms_HDIa_widgetTextSetProperty

#define MSF_WIDGET_EDITOR_CREATE                    gmms_HDIa_widgetEditorCreate
#define MSF_WIDGET_EDITOR_CREATE_CSS                gmms_HDIa_widgetEditorCreateCss

#define MSF_WIDGET_CHOICE_SET_ELEMENT               gmms_HDIa_widgetChoiceSetElement
#ifdef MSF_CONFIG_TOOLTIP
#define MSF_WIDGET_CHOICE_SET_ELEMENT_TT            gmms_HDIa_widgetChoiceSetElementTT
#endif
#define MSF_WIDGET_CHOICE_REMOVE_ELEMENT            gmms_HDIa_widgetChoiceRemoveElement
#define MSF_WIDGET_CHOICE_GET_ELEM_STATE            gmms_HDIa_widgetChoiceGetElemState
#define MSF_WIDGET_CHOICE_SET_ELEM_STATE            gmms_HDIa_widgetChoiceSetElemState
#define MSF_WIDGET_CHOICE_ATTR_PROPERTY             gmms_HDIa_widgetChoiceAttrProperty
#define MSF_WIDGET_CHOICE_ELEM_PROPERTY             gmms_HDIa_widgetChoiceElemProperty
#define MSF_WIDGET_CHOICE_SIZE                      gmms_HDIa_widgetChoiceSize

#define MSF_WIDGET_MENU_CREATE                      gmms_HDIa_widgetMenuCreate
#define MSF_WIDGET_MENU_APP_CREATE                  gmms_HDIa_widgetMenuAppCreate

#define MSF_WIDGET_DIALOG_CREATE                    gmms_HDIa_widgetDialogCreate
#define MSF_WIDGET_DIALOG_SET_ATTR                  gmms_HDIa_widgetDialogSetAttr
#define MSF_WIDGET_DIALOG_ADD_INPUT                 gmms_HDIa_widgetDialogAddInput
#define MSF_WIDGET_DIALOG_REMOVE_INPUT              gmms_HDIa_widgetDialogRemoveInput
#define MSF_WIDGET_DIALOG_SET_INPUT_ATTR            gmms_HDIa_widgetDialogSetInputAttr

#define MSF_WIDGET_ACTION_CREATE                    gmms_HDIa_widgetActionCreate
#define MSF_WIDGET_ACTION_SET_ATTR                  gmms_HDIa_widgetActionSetAttr
#define MSF_WIDGET_ACTION_GET_ATTR                  gmms_HDIa_widgetActionGetAttr
#define MSF_WIDGET_ACTION_SET_PROPERTIES            gmms_HDIa_widgetActionSetProperties

#define MSF_WIDGET_GADGET_SET_PROPERTIES            gmms_HDIa_widgetGadgetSetProperties

#define MSF_WIDGET_STRING_GADGET_CREATE             gmms_HDIa_widgetStringGadgetCreate
#define MSF_WIDGET_STRING_GADGET_SET                gmms_HDIa_widgetStringGadgetSet

#define MSF_WIDGET_TEXT_INPUT_CREATE                gmms_HDIa_widgetTextInputCreate
#define MSF_WIDGET_TEXT_INPUT_CREATE_CSS            gmms_HDIa_widgetTextInputCreateCss

#define MSF_WIDGET_SELECTGROUP_CREATE               gmms_HDIa_widgetSelectgroupCreate

#define MSF_WIDGET_IMAGE_GADGET_CREATE              gmms_HDIa_widgetImageGadgetCreate
#define MSF_WIDGET_IMAGE_GADGET_SET                 gmms_HDIa_widgetImageGadgetSet

#define MSF_WIDGET_DATE_TIME_CREATE                 gmms_HDIa_widgetDateTimeCreate
#define MSF_WIDGET_DATE_TIME_SET_VALUES             gmms_HDIa_widgetDateTimeSetValues
#define MSF_WIDGET_DATE_TIME_GET_VALUES             gmms_HDIa_widgetDateTimeGetValues

#define MSF_WIDGET_BAR_CREATE                       gmms_HDIa_widgetBarCreate
#define MSF_WIDGET_BAR_GET_VALUES                   gmms_HDIa_widgetBarGetValues
#define MSF_WIDGET_BAR_SET_VALUES                   gmms_HDIa_widgetBarSetValues

#define MSF_WIDGET_HOLD_DRAW                        gmms_HDIa_widgetHoldDraw
#define MSF_WIDGET_PERFORM_DRAW                     gmms_HDIa_widgetPerformDraw 
#define MSF_WIDGET_DRAW_LINE                        gmms_HDIa_widgetDrawLine
#define MSF_WIDGET_DRAW_RECT                        gmms_HDIa_widgetDrawRect
#define MSF_WIDGET_DRAW_ICON                        gmms_HDIa_widgetDrawIcon
#define MSF_WIDGET_DRAW_ARC                         gmms_HDIa_widgetDrawArc
#define MSF_WIDGET_DRAW_STRING                      gmms_HDIa_widgetDrawString
#define MSF_WIDGET_DRAW_POLYGON                     gmms_HDIa_widgetDrawPolygon
#define MSF_WIDGET_DRAW_IMAGE                       gmms_HDIa_widgetDrawImage


#define MSF_WIDGET_STYLE_CREATE                     gmms_HDIa_widgetStyleCreate
#define MSF_WIDGET_GET_BRUSH                        gmms_HDIa_widgetGetBrush
#define MSF_WIDGET_SET_COLOR                        gmms_HDIa_widgetSetColor
#define MSF_WIDGET_SET_BACK_GROUND_COLOR            gmms_HDIa_widgetSetBackGroundColor
#define MSF_WIDGET_SET_LINE_STYLE                   gmms_HDIa_widgetSetLineStyle
#define MSF_WIDGET_SET_TEXT_PROPERTY                gmms_HDIa_widgetSetTextProperty
#define MSF_WIDGET_SET_BACK_GROUND                  gmms_HDIa_widgetSetBackGround
#define MSF_WIDGET_SET_FORE_GROUND                  gmms_HDIa_widgetSetForeGround
#define MSF_WIDGET_SET_FONT                         gmms_HDIa_widgetSetFont
#define MSF_WIDGET_FONT_GET_FAMILY                  gmms_HDIa_widgetFontGetFamily
#define MSF_WIDGET_GET_COLOR                        gmms_HDIa_widgetGetColor
#define MSF_WIDGET_GET_BACK_GROUND_COLOR            gmms_HDIa_widgetGetBackGroundColor
#define MSF_WIDGET_GET_FONT                         gmms_HDIa_widgetGetFont
#define MSF_WIDGET_GET_STYLE                        gmms_HDIa_widgetGetStyle
#define MSF_WIDGET_GET_TEXT_PROPERTY                gmms_HDIa_widgetGetTextProperty
#define MSF_WIDGET_GET_PATTERN                      gmms_HDIa_widgetGetPattern
#define MSF_WIDGET_GET_ICON_SIZE                    gmms_HDIa_widgetGetIconSize
#define MSF_WIDGET_GET_STRING_SIZE                  gmms_HDIa_widgetGetStringSize
#define MSF_WIDGET_GET_CHAR_SIZE                    gmms_HDIa_widgetGetCharSize
#define MSF_WIDGET_GET_VISIBLE_STRING               gmms_HDIa_widgetGetVisibleString
#define MSF_WIDGET_SET_MARQUEE                      gmms_HDIa_widgetSetMarquee

#define MSF_WIDGET_STRING_CREATE                    gmms_HDIa_widgetStringCreate
#define MSF_WIDGET_STRING_GET_PREDEFINED            gmms_HDIa_widgetStringGetPredefined
#define MSF_WIDGET_STRING_CREATE_TEXT               gmms_HDIa_widgetStringCreateText
#define MSF_WIDGET_STRING_GET_LENGTH                gmms_HDIa_widgetStringGetLength
#define MSF_WIDGET_STRING_GET_DATA                  gmms_HDIa_widgetStringGetData
#define MSF_WIDGET_STRING_COMPARE                   gmms_HDIa_widgetStringCompare
#define MSF_WIDGET_STRING_GET_VISIBLE               gmms_HDIa_widgetStringGetVisible
#define MSF_WIDGET_FONT_GET_VALUES                  gmms_HDIa_widgetFontGetValues
#define MSF_WIDGET_STRING_GET_SUB_SIZE              gmms_HDIa_widgetStringGetSubSize

#define MSF_WIDGET_ICON_CREATE                      gmms_HDIa_widgetIconCreate

#define MSF_WIDGET_IMAGE_CREATE                     gmms_HDIa_widgetImageCreate
#define MSF_WIDGET_IMAGE_NEXT_PART                  gmms_HDIa_widgetImageNextPart
#define MSF_WIDGET_IMAGE_CREATE_ICON                gmms_HDIa_widgetImageCreateIcon
#define MSF_WIDGET_IMAGE_CREATE_RESOURCE            gmms_HDIa_widgetImageCreateResource
#define MSF_WIDGET_IMAGE_CREATE_EMPTY               gmms_HDIa_widgetImageCreateEmpty
#define MSF_WIDGET_IMAGE_CREATE_FRAME               gmms_HDIa_widgetImageCreateFrame
#define MSF_WIDGET_IMAGE_CREATE_FORMAT              gmms_HDIa_widgetImageCreateFormat
#define MSF_WIDGET_IMAGE_GET_PREDEFINED             gmms_HDIa_widgetImageGetPredefined

#define MSF_WIDGET_SOUND_CREATE                     gmms_HDIa_widgetSoundCreate
#define MSF_WIDGET_SOUND_NEXT_PART                  gmms_HDIa_widgetSoundNextPart
#define MSF_WIDGET_SOUND_CREATE_RESOURCE            gmms_HDIa_widgetSoundCreateResource
#define MSF_WIDGET_SOUND_PLAY                       gmms_HDIa_widgetSoundPlay
#define MSF_WIDGET_SOUND_PLAY_PREDEFINED            gmms_HDIa_widgetSoundPlayPredefined
#define MSF_WIDGET_SOUND_STOP                       gmms_HDIa_widgetSoundStop
#define MSF_WIDGET_SOUND_CREATE_FORMAT              gmms_HDIa_widgetSoundCreateFormat
#define MSF_WIDGET_SOUND_GET_PREDEFINED             gmms_HDIa_widgetSoundGetPredefined

#define MSF_WIDGET_SET_ACCESS_KEY                   gmms_HDIa_widgetSetAccessKey
#define MSF_WIDGET_REMOVE_ACCESS_KEY                gmms_HDIa_widgetRemoveAccessKey 

#define MSF_WIDGET_MOVE_CREATE                      gmms_HDIa_widgetMoveCreate
#define MSF_WIDGET_ROTATION_CREATE                  gmms_HDIa_widgetRotationCreate
#define MSF_WIDGET_COLOR_ANIM_CREATE                gmms_HDIa_widgetColorAnimCreate
#define MSF_WIDGET_ADD_ANIMATION                    gmms_HDIa_widgetAddAnimation
#define MSF_WIDGET_SET_DECORATION                   gmms_HDIa_widgetSetDecoration
#define MSF_WIDGET_MSF_EVENT_2_UTF8                 gmms_HDIa_widgetMsfEvent2Utf8
#else
#define MSF_WIDGET_DEVICE_GET_PROPERTIES            HDIa_widgetDeviceGetProperties
#define MSF_WIDGET_SET_IN_FOCUS                     HDIa_widgetSetInFocus
#define MSF_WIDGET_HAS_FOCUS                        HDIa_widgetHasFocus
#define MSF_WIDGET_RELEASE                          HDIa_widgetRelease
#define MSF_WIDGET_RELEASE_ALL                      HDIa_widgetReleaseAll
#define MSF_WIDGET_COPY                             HDIa_widgetCopy
#define MSF_WIDGET_REMOVE                           HDIa_widgetRemove
#define MSF_WIDGET_ADD_ACTION                       HDIa_widgetAddAction
#define MSF_WIDGET_HANDLE_MSF_EVT                   HDIa_widgetHandleMsfEvt
#define MSF_WIDGET_SET_TITLE                        HDIa_widgetSetTitle
#define MSF_WIDGET_SET_BORDER                       HDIa_widgetSetBorder
#define MSF_WIDGET_SET_POSITION                     HDIa_widgetSetPosition
#define MSF_WIDGET_SET_SIZE                         HDIa_widgetSetSize
#define MSF_WIDGET_GET_POSITION                     HDIa_widgetGetPosition
#define MSF_WIDGET_GET_SIZE                         HDIa_widgetGetSize

#define MSF_WIDGET_SCREEN_CREATE                    HDIa_widgetScreenCreate
#define MSF_WIDGET_SCREEN_SET_NOTIFY                HDIa_widgetScreenSetNotify
#define MSF_WIDGET_SCREEN_ADD_WINDOW                HDIa_widgetScreenAddWindow
#define MSF_WIDGET_SCREEN_ACTIVE_WINDOW             HDIa_widgetScreenActiveWindow

#define MSF_WIDGET_WINDOW_ADD_GADGET                HDIa_widgetWindowAddGadget
#define MSF_WIDGET_WINDOW_SET_TICKER                HDIa_widgetWindowSetTicker
#define MSF_WIDGET_WINDOW_SET_PROPERTIES            HDIa_widgetWindowSetProperties
#define MSF_WIDGET_WINDOW_SPECIFIC_SIZE             HDIa_widgetWindowSpecificSize

#define MSF_WIDGET_PAINTBOX_CREATE                  HDIa_widgetPaintboxCreate
#define MSF_WIDGET_PAINTBOX_REDRAW_AREA             HDIa_widgetPaintboxRedrawArea
#define MSF_WIDGET_FORM_CREATE                      HDIa_widgetFormCreate

#define MSF_WIDGET_TEXT_SET_TEXT                    HDIa_widgetTextSetText
#define MSF_WIDGET_TEXT_MAX_SIZE                    HDIa_widgetTextMaxSize
#define MSF_WIDGET_TEXT_CLEAR                       HDIa_widgetTextClear
#define MSF_WIDGET_TEXT_SET_PROPERTY                HDIa_widgetTextSetProperty

#define MSF_WIDGET_EDITOR_CREATE                    HDIa_widgetEditorCreate
#define MSF_WIDGET_EDITOR_CREATE_CSS                HDIa_widgetEditorCreateCss

#define MSF_WIDGET_CHOICE_SET_ELEMENT               HDIa_widgetChoiceSetElement
#ifdef MSF_CONFIG_TOOLTIP
#define MSF_WIDGET_CHOICE_SET_ELEMENT_TT            HDIa_widgetChoiceSetElementTT
#endif
#define MSF_WIDGET_CHOICE_REMOVE_ELEMENT            HDIa_widgetChoiceRemoveElement
#define MSF_WIDGET_CHOICE_GET_ELEM_STATE            HDIa_widgetChoiceGetElemState
#define MSF_WIDGET_CHOICE_SET_ELEM_STATE            HDIa_widgetChoiceSetElemState
#define MSF_WIDGET_CHOICE_ATTR_PROPERTY             HDIa_widgetChoiceAttrProperty
#define MSF_WIDGET_CHOICE_ELEM_PROPERTY             HDIa_widgetChoiceElemProperty
#define MSF_WIDGET_CHOICE_SIZE                      HDIa_widgetChoiceSize

#ifdef OBIGO_Q03C_MMS_V01
#define MSF_WIDGET_MENU_CREATE                      HDIa_widgetMenuCreate
#endif /* OBIGO_Q03C_MMS_V01 */
#define MSF_WIDGET_MENU_APP_CREATE                  HDIa_widgetMenuAppCreate

#define MSF_WIDGET_DIALOG_CREATE                    HDIa_widgetDialogCreateWithType
#define MSF_WIDGET_DIALOG_SET_ATTR                  HDIa_widgetDialogSetAttr
#define MSF_WIDGET_DIALOG_ADD_INPUT                 HDIa_widgetDialogAddInput
#define MSF_WIDGET_DIALOG_REMOVE_INPUT              HDIa_widgetDialogRemoveInput
#define MSF_WIDGET_DIALOG_SET_INPUT_ATTR            HDIa_widgetDialogSetInputAttr

#define MSF_WIDGET_ACTION_CREATE                    HDIa_widgetActionCreate
#define MSF_WIDGET_ACTION_SET_ATTR                  HDIa_widgetActionSetAttr
#define MSF_WIDGET_ACTION_GET_ATTR                  HDIa_widgetActionGetAttr
#define MSF_WIDGET_ACTION_SET_PROPERTIES            HDIa_widgetActionSetProperties

#define MSF_WIDGET_GADGET_SET_PROPERTIES            HDIa_widgetGadgetSetProperties

#define MSF_WIDGET_STRING_GADGET_CREATE             HDIa_widgetStringGadgetCreate
#define MSF_WIDGET_STRING_GADGET_SET                HDIa_widgetStringGadgetSet

#define MSF_WIDGET_TEXT_INPUT_CREATE                HDIa_widgetTextInputCreate
#define MSF_WIDGET_TEXT_INPUT_CREATE_CSS            HDIa_widgetTextInputCreateCss

#define MSF_WIDGET_SELECTGROUP_CREATE               HDIa_widgetSelectgroupCreate

#define MSF_WIDGET_IMAGE_GADGET_CREATE              HDIa_widgetImageGadgetCreate
#define MSF_WIDGET_IMAGE_GADGET_SET                 HDIa_widgetImageGadgetSet

#define MSF_WIDGET_DATE_TIME_CREATE                 HDIa_widgetDateTimeCreate
#define MSF_WIDGET_DATE_TIME_SET_VALUES             HDIa_widgetDateTimeSetValues
#define MSF_WIDGET_DATE_TIME_GET_VALUES             HDIa_widgetDateTimeGetValues

#define MSF_WIDGET_BAR_CREATE                       HDIa_widgetBarCreate
#define MSF_WIDGET_BAR_GET_VALUES                   HDIa_widgetBarGetValues
#define MSF_WIDGET_BAR_SET_VALUES                   HDIa_widgetBarSetValues

#define MSF_WIDGET_HOLD_DRAW                        HDIa_widgetHoldDraw
#define MSF_WIDGET_PERFORM_DRAW                     HDIa_widgetPerformDraw 
#define MSF_WIDGET_DRAW_LINE                        HDIa_widgetDrawLine
#define MSF_WIDGET_DRAW_RECT                        HDIa_widgetDrawRect
#define MSF_WIDGET_DRAW_ICON                        HDIa_widgetDrawIcon
#define MSF_WIDGET_DRAW_ARC                         HDIa_widgetDrawArc
#define MSF_WIDGET_DRAW_STRING                      HDIa_widgetDrawString
#define MSF_WIDGET_DRAW_POLYGON                     HDIa_widgetDrawPolygon
#define MSF_WIDGET_DRAW_IMAGE                       HDIa_widgetDrawImage


#define MSF_WIDGET_STYLE_CREATE                     HDIa_widgetStyleCreate
#define MSF_WIDGET_GET_BRUSH                        HDIa_widgetGetBrush
#define MSF_WIDGET_SET_COLOR                        HDIa_widgetSetColor
#define MSF_WIDGET_SET_BACK_GROUND_COLOR            HDIa_widgetSetBackGroundColor
#define MSF_WIDGET_SET_LINE_STYLE                   HDIa_widgetSetLineStyle
#define MSF_WIDGET_SET_TEXT_PROPERTY                HDIa_widgetSetTextProperty
#define MSF_WIDGET_SET_BACK_GROUND                  HDIa_widgetSetBackGround
#define MSF_WIDGET_SET_FORE_GROUND                  HDIa_widgetSetForeGround
#define MSF_WIDGET_SET_FONT                         HDIa_widgetSetFont
#define MSF_WIDGET_FONT_GET_FAMILY                  HDIa_widgetFontGetFamily
#define MSF_WIDGET_GET_COLOR                        HDIa_widgetGetColor
#define MSF_WIDGET_GET_BACK_GROUND_COLOR            HDIa_widgetGetBackGroundColor
#define MSF_WIDGET_GET_FONT                         HDIa_widgetGetFont
#define MSF_WIDGET_GET_STYLE                        HDIa_widgetGetStyle
#define MSF_WIDGET_GET_TEXT_PROPERTY                HDIa_widgetGetTextProperty
#define MSF_WIDGET_GET_PATTERN                      HDIa_widgetGetPattern
#define MSF_WIDGET_GET_ICON_SIZE                    HDIa_widgetGetIconSize
#define MSF_WIDGET_GET_STRING_SIZE                  HDIa_widgetGetStringSize
#define MSF_WIDGET_GET_CHAR_SIZE                    HDIa_widgetGetCharSize
#define MSF_WIDGET_GET_VISIBLE_STRING               HDIa_widgetGetVisibleString
#define MSF_WIDGET_SET_MARQUEE                      HDIa_widgetSetMarquee

#define MSF_WIDGET_STRING_CREATE                    HDIa_widgetStringCreate
#define MSF_WIDGET_STRING_GET_PREDEFINED            HDIa_widgetStringGetPredefined
#define MSF_WIDGET_STRING_CREATE_TEXT               HDIa_widgetStringCreateText
#define MSF_WIDGET_STRING_GET_LENGTH                HDIa_widgetStringGetLength
#define MSF_WIDGET_STRING_GET_DATA                  HDIa_widgetStringGetData
#define MSF_WIDGET_STRING_COMPARE                   HDIa_widgetStringCompare
#define MSF_WIDGET_STRING_GET_VISIBLE               HDIa_widgetStringGetVisible
#define MSF_WIDGET_FONT_GET_VALUES                  HDIa_widgetFontGetValues
#define MSF_WIDGET_STRING_GET_SUB_SIZE              HDIa_widgetStringGetSubSize

#define MSF_WIDGET_ICON_CREATE                      HDIa_widgetIconCreate

#define MSF_WIDGET_IMAGE_CREATE                     HDIa_widgetImageCreate
#define MSF_WIDGET_IMAGE_NEXT_PART                  HDIa_widgetImageNextPart
#define MSF_WIDGET_IMAGE_CREATE_ICON                HDIa_widgetImageCreateIcon
#define MSF_WIDGET_IMAGE_CREATE_RESOURCE            HDIa_widgetImageCreateResource
#define MSF_WIDGET_IMAGE_CREATE_EMPTY               HDIa_widgetImageCreateEmpty
#define MSF_WIDGET_IMAGE_CREATE_FRAME               HDIa_widgetImageCreateFrame
#define MSF_WIDGET_IMAGE_CREATE_FORMAT              HDIa_widgetImageCreateFormat
#define MSF_WIDGET_IMAGE_GET_PREDEFINED             HDIa_widgetImageGetPredefined

#ifdef WIDGET_SUPPORT_SOUND
#define MSF_WIDGET_SOUND_CREATE                     HDIa_widgetSoundCreate
#define MSF_WIDGET_SOUND_NEXT_PART                  HDIa_widgetSoundNextPart
#define MSF_WIDGET_SOUND_CREATE_RESOURCE            HDIa_widgetSoundCreateResource
#define MSF_WIDGET_SOUND_PLAY                       HDIa_widgetSoundPlay

#define MSF_WIDGET_SOUND_STOP                       HDIa_widgetSoundStop
#define MSF_WIDGET_SOUND_CREATE_FORMAT              HDIa_widgetSoundCreateFormat
#define MSF_WIDGET_SOUND_GET_PREDEFINED             HDIa_widgetSoundGetPredefined
#endif /* WIDGET_SUPPORT_SOUND */
#define MSF_WIDGET_SOUND_PLAY_PREDEFINED            HDIa_widgetSoundPlayPredefined
#define MSF_WIDGET_SET_ACCESS_KEY                   HDIa_widgetSetAccessKey
#define MSF_WIDGET_REMOVE_ACCESS_KEY                HDIa_widgetRemoveAccessKey 

#define MSF_WIDGET_MOVE_CREATE                      HDIa_widgetMoveCreate
#define MSF_WIDGET_ROTATION_CREATE                  HDIa_widgetRotationCreate
#define MSF_WIDGET_COLOR_ANIM_CREATE                HDIa_widgetColorAnimCreate
#define MSF_WIDGET_ADD_ANIMATION                    HDIa_widgetAddAnimation
#define MSF_WIDGET_SET_DECORATION                   HDIa_widgetSetDecoration
#define MSF_WIDGET_MSF_EVENT_2_UTF8                 HDIa_widgetMsfEvent2Utf8

#define HDIa_widgetDialogCreate(modId, dialogText, type, timeoutTime, propertyMask, defaultStyle) \
            HDIa_widgetDialogCreateWithType(modId, dialogText, type, propertyMask, defaultStyle) 

#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

#endif
