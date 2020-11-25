#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct proc {
  enum procstate state;        
  int pid;                     
  int priority;                
  int stime;
  int rtime;
  int iotime;
  int rabletime;
  char name[16];               
};

int
main(int argc, char *argv[]){
  struct proc ptable[NPROC];
  struct proc *p;
  int err;
  int yo = 1;

  if(getptable(NPROC * sizeof(struct proc), &ptable))
  {
    printf(1, "Error!");
    exit();
  }

  printf(1, "======================================================================================================================================================================================\n");
  printf(1, "PID\t\tPRIORITY\tSTATE\t\tr_time\tw_time\t\tn_run\tcur_q\tq0\tq1\tq2\tq3\tq4\n");
  printf(1, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
  for(p = ptable; p != &ptable[NPROC-1]; p++) {
        if (p->state == UNUSED) continue;

  if (p->pid == 1)
      printf(1, "%d",p->pid);
  else
      printf(1, "%d", p->pid);
    #ifdef PBS
      // printf(1,"in PBS\n");
      printf(1, "\t\t%d", p->priority);
    #else
    #ifdef MLFQ
      // printf(1,"in MLFQ\n");
      printf(1, "\t\t%d", p->priority);
    #else
      // printf(1,"in Default\n");
      printf(1, "\t\t60");
    #endif
    #endif

    switch(p->state){
    case UNUSED:
      printf(1,"\t\t%s", "UNUSED  ");
      break;
    case EMBRYO:
      printf(1,"\t\t%s", "EMBRYO  ");
      break;
    case SLEEPING:
      printf(1,"\t\t%s", "SLEEPING");
      break;
    case RUNNABLE:
      printf(1,"\t\t%s", "RUNNABLE");
      break;
    case RUNNING:
      printf(1,"\t\t%s", "RUNNING ");
      break;
    case ZOMBIE:
      printf(1,"\t\t%s", "ZOMBIE  ");
      break;
    default:
      printf(1, "\r");
      goto procList;
    }

    printf(1, "\t%d", p->rtime);
    printf(1, "\t%d", p->iotime);
    struct proc_stat pstat;
    int ans = getpinfo(&pstat, p->pid);
    printf(1, "\t\t%d", pstat.num_run);
    printf(1, "\t%d", pstat.current_queue);
    for(int i=0; i<5; i++)
      printf(1, "\t%d", pstat.ticks[i]);
    printf(1, "\n");


    // something useless
    procList:
      yo = yo;
  }
  printf(1, "======================================================================================================================================================================================\n");
  exit();
}