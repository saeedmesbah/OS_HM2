#include "types.h"
#include "stat.h"
#include "user.h"

int Base = 0;
int Limit = 10;

// void child2(void *args){

//     if (Base > Limit)
//     {
//         printf(1, "Base and Limit error !!\n");
//         exit();
//     }
//     else if (Base == Limit)
//     {
//         printf(1, "%d => -1\n", thread_id());   
//         exit();
//     }
//     else{
//         Base++;
//         printf(1, "%d => 0, Base = %d\n", thread_id(), Base);

//         int tid = thread_creator(&child2, args);

//         printf(1, "1111111111\n", thread_id());

//         thread_join(tid);
//         exit();
//     }

//     printf(1, "222222\n", thread_id());

    
// }

void child(void *args){

    if (Base == Limit)
    {
        printf(1, "%d => -1\n", thread_id());   
        exit();
    }
    Base++;
    printf(1, "%d => 0, Base = %d\n", thread_id(), Base);

    exit();
    
}


int main(void)
{
    int argument = 0x0F01;
    printf(1, "Base = %d, Limit = %d\n", Base, Limit);
    // int pid = fork();

    // if (pid < 0)
    // {
    //     printf(1, "fork failed !!\n");
    // }
    // // // sleep(100);
    // else if (pid == 0)
    // {
    //     child((void *)&argument);
    // }
    // else
    // {
    //     wait();
    // }
    int i;
    for (i = Base; i <= Limit; i++)
    {
        int tid = thread_creator(&child, (void *)&argument);
        thread_join(tid);

    }
    
    
    
    // printf(1, "tid: %d\n", tid);
    
    exit();

}