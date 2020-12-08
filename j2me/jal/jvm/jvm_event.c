#include "kal_release.h"
#include "jvm_event.h"

volatile int jvm_event_mutex_cnt = 0;
volatile module_type jvm_event_mutex_tid = MOD_NIL;

extern kal_mutexid g_jam_vm_event_mutex;

/*****************************************************************************
 * FUNCTION
 *  jvm_event_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_event_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_get_active_module_id() != jvm_event_mutex_tid)
    {
        while (jvm_event_mutex_cnt > 0)
            kal_sleep_task(1);
        kal_take_mutex(g_jam_vm_event_mutex);
        jvm_event_mutex_tid = kal_get_active_module_id();
    }
    ++jvm_event_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_event_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_event_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_event_mutex_tid == kal_get_active_module_id());

    --jvm_event_mutex_cnt;

    if (jvm_event_mutex_cnt == 0)
    {
        jvm_event_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_vm_event_mutex);
    }
}

