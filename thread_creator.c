#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 4096

int
thread_creator(void (*fn) (void *), void *arg)
{
  void *ptr = malloc(2 * PGSIZE); //?
  void *stack;

  if (ptr == 0)
  {
    return -1;
  }

  int mod = (uint)ptr % PGSIZE;
  if (mod == 0)
  {
    stack = ptr;
  }
  else
  {
    stack = ptr + (PGSIZE - mod);
  }

  int tid = thread_create((void*)stack);
  if (tid < 0)
  {
    printf(1, "thread_create failed !!\n");
  }
  else if (tid == 0)
  {
    (fn)(arg);
    free(stack);
    exit();
  }
   return tid;
   
  
  
}