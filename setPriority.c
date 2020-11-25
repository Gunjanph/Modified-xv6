#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"

// enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// struct proc {
//   enum procstate state;        
//   int pid;                     
//   int priority;                
//   int stime;
//   int rtime;
//   int iotime;
//   int rabletime;
//   char name[16];               
// };

int main(int argc, char *argv[])
{
  // struct proc ptable[NPROC];
  // struct proc *p ;
  int value,pid;
  char *type;

  if (argc < 3 || argc > 3) 
  {
      printf(2, "Usage: setPriority [priority] [pid]\n" );
      exit();
  }
  value = (int)atoi(argv[1]);
  pid = (int)atoi(argv[2]);
  // printf(1,"in nice\n");
  // if(getptable(NPROC * sizeof(struct proc), &ptable))
  // {
  //   printf(1, "Error!");
  //   exit();
  // }

  // for(p = ptable; p < &ptable[NPROC]; p++){   
  //   if(pid==p->pid)
  //   {
    // #ifdef MLFQ
    //   if (value < 1 || value > 3) {
    //       printf(2, "Invalid priority (1-3)!\n" );
    //       exit();
    //   }
    // #else
    //   if (value < 1 || value > 20) {
    //       printf(2, "Invalid priority (1-20)!\n" );
    //       exit();
    //   }
    // #endif
      // printf(1,"ifelse\n");
    
    int jugad= value*1000+pid;

    set_priority(jugad,pid);

    printf(1,"Priority of %d set to %d\n",pid,value);
    // break;
  //   // }
  // }
  exit();
}