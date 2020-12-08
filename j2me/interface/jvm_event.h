#ifndef __JVM_EVENT_H__
#define __JVM_EVENT_H__

void jvm_event_mutex_lock(void);
void jvm_event_mutex_unlock(void);

#define JVM_EVENT_LOCK  jvm_event_mutex_lock
#define JVM_EVENT_UNLOCK    jvm_event_mutex_unlock

#endif /* __JVM_EVENT_H__ */
