#include "types.h"
#include "stat.h"
#include "user.h"

int stack[4096] __attribute__ ((aligned (4096)));
int x = 0;

int main(void)
{
    int tid = thread_create(stack);

    if (tid < 0)
    {
        printf(1, "thread_create failed !!\n");
    }
    else if (tid == 0)
    {
        for (;;)
        {
            x++;
            sleep(100);
        }
        
    }
    else
    {
        for (;;)
        {
            printf(1, "x: %d\n", x);
            sleep(100);
        }

    }
    exit();

}