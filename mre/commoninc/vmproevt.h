#ifndef	_VM_PRO_EVT_
#define _VM_PRO_EVT_

#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


/**
 * 进程管理器处理按键事件的消息。 
 * 
 * @param[in]					vmKeyCode 按键的键值。
 * @param[in]					vmKeyEvent 按键的事件。
 * @return					是否有进程处理该事件。
 * @retval					TRUE 有进程处理了该事件。
 * @retval					FALSE 没有进程处理该事件。
 */
VMINT vm_pmng_deal_key_event(VMINT vmKeyCode, VMINT vmKeyEvent);

/**
 * 进程管理器处理笔触事件的消息。
 * 
 * @param[in]					vmPenEvent 笔触事件。
 * @param[in]					x X坐标值。
 * @param[in]					y Y坐标值。
 * @return					是否有进程处理该事件。
 * @retval					TRUE 有进程处理了该事件。
 * @retval					FALSE 没有进程处理该事件。
 */
VMINT vm_pmng_deal_pen_event(VMINT vmPenEvent, VMINT x, VMINT y);

/**
 * 进程管理器处理拔T卡的事件。
 *  
 * @param[out]				被退出的进程个数。
 * @return					还在运行的进程个数。
 */
VMUINT vm_pmng_deal_card_plug_out_event(VMUINT* exitProcessNum);

#ifdef __cplusplus
}
#endif 
#endif

#endif
