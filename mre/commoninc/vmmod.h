/***********************************************************************
  * 模块管理器必须实现的函数，这些函数提供了管理模块
  * 生命周期的功能。在MRE里的所有模块都将有三个状态。
  * 这三个状态分别对应:
  *
  * (1) INIT_STATE
  * 在MRE还没有启动的时候各个模块处于该状态。在该状态下
  * 各个模块提供的服务是可选择的。MRE中的各个功能模块可
  * 以不提供任何服务，也可以选择提供部分或全部的服务。
  * 但如果提供服务各个模块在本状态下应该不依赖于
  * 其它模块的实现，因为在INITAL_STATE下，其它模块提供的
  * 服务是没有保证的。
  *
  * (2) RUNNING_STATE
  * 在系统处于INIT_STATE下，在模块收到EVT_MOD_INIT消息后，模块就
  * 应该过渡到RUNNING_STATE下，或是在模块处于FREEZING_STATE下时，
  * 收到EVT_MOD_ACTIVE消息，那么模块也会处于RUNNING_STATE
  * 状态下。在该状态下，MRE内部的模块应该提供全部的服务功能。
  *
  * (3) FREEZING_STATE
  * 在模块收到了EVT_MOD_ACTIVE消息，MRE模块就应该切换到FREEZING_STATE
  * 状态，在该状态下模块对外提供的服务是不确定的，不被保证的。
  * 应用程序在收到MRE发出的INACTIVE消息后不应该再调用MRE任何模块提供
  * 的任何服务。因为在应用程序收到该消息后，所有的模块都已处在
  * FREEZING_STATE下了。直到模块收到EVT_MOD_ACTIVE后所有模块就过渡到
  * RUNNING_STATE状态或收到EVT_MOD_RELEASE消息后，模块就过渡到INIT_STATE状态
  * 下了。
  *
  * copyright vogins.co
  * version 1.2.0
  *
  **********************************************************************/

#ifndef MODULE_H
#define MODULE_H
  #include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  * MRE各个模块的生命周期事件。
  */
typedef enum {EVT_MOD_INIT = 1, EVT_MOD_ACTIVE, EVT_MOD_INACTIVE, EVT_MOD_RELEASE} MRE_MOD_LIFECIRCLE_EVT;

/*
  * 各个模块处理函数的类型。
  */
typedef VMINT (*MOD_EVT_PROCESS)(MRE_MOD_LIFECIRCLE_EVT);

/*
  * 注册模块成功。
  */
#define REG_MRE_MODULE_SUCCESS						0

/*
  * 超过了系统所能接受的最大的模块数目。
  */
#define OVERFLOW_MAX_MODULE_NUM_ERROR			1

/*
  * 模块的名称和已经注册到系统的模块名称相同。
  */
#define MRE_MODULE_NAME_CONFLICT_ERROR			2

/*
  * 模块的名称没有指定的错误。
  */
#define MRE_MODULE_NAME_NOT_EXISTS_ERROR			3

/**
 * 注册一个MRE模块。MRE中的每个模块都应该调用这个函数把自己注册到系统中。
 * 在进入MRE的主函数前，MRE管理器会按模块注册的顺序依次把模块的生命周期
 * 事件通知各个模块。当前的模块处理函数的返回值只有在模块处理EVT_MOD_INIT
 * 的时才有效，返回0，表示成功处理了该生命周期消息，否则返回错误码。当
 * 有一个模块在处理EVT_MOD_INIT的时候返回错误，那么模块管理器则会发送给已
 * 进入RUNNING_STATE状态的模块EVT_MOD_RELEASE消息，并且退出MRE系统。
 * 
 * 
 * @param name			模块的名称，该模块名称必须是指定的模块名称与已经注册的模块名称相同，
 *						那么函数将会返回，判定是大小写敏感的。并且模块名称必须
 *						是有值的，也就是说strlen(name)  > 0 必须是TRUE。
 * @param process			模块注册到模块管理器上的模块生命周期上的处理函数。		
 *
 * @return
 */
VMINT _vm_reg_module(VMSTR name, MOD_EVT_PROCESS process);

/**
 * 注册所有的模块。
 */
VMINT _vm_reg_modules(void);

/**
 * 模块所处的状态类型。
 */
typedef enum {
	MOD_STATUS_SHUTDOWN,
	MOD_STATUS_RUNNING,
	MOD_STATUS_PAUSE
} MRE_MOD_STATUS;

/**
 * 得到模块所处的状态。
 */
MRE_MOD_STATUS _vm_get_status(void);

/**
  * 通知模块管理器内的模块生命周期事件。
  * 
  * 
  * @param event			需要通知到模块的生命周期事件。
  * 
  */
VMINT _vm_notify_modules(MRE_MOD_LIFECIRCLE_EVT event);


/**
  * 初始化模块管理所用到的资源，必须在调用_vm_setup_modules函数
  * 前调用。
  */
void _vm_initizlize_module_manager(void);

/**
  * 清理模块管理所用到的资源，必须在调用_vm_cleanup_modules函数后
  * 调用。
  */
void _vm_destory_module_manager(void);

#ifdef __cplusplus
}
#endif

#endif
#endif

