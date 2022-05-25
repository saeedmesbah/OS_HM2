#include "types.h"
#include "stat.h"
#include "user.h"

void child(void *args){
    printf(1, "tid: %d\n", thread_id());
    printf(1, "Argument: %d\n", *(int*) args);
}

int main(void)
{
    int argument = 0x0F01;
    int tid = thread_creator(&child, (void*)&argument);

    if (tid < 0)
    {
        printf(1, "thread_create failed !!\n");
    }
    // sleep(100);
    thread_join(tid);
    
    printf(1, "tid: %d\n", tid);
    
    exit();

}