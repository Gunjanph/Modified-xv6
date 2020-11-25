#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  unsigned int ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  unsigned int xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

  // Added sys_waitx call to load parameters and calling waitx    
int sys_waitx(void)   
{   
  int *wtime;   
  int *rtime;   
      
  if(argptr(0, (char**)&wtime, sizeof(int)) < 0)
    return -1;    
  if(argptr(1, (char**)&rtime, sizeof(int)) < 0)
    return -1;    
  return waitx(wtime, rtime);
}

// copy elements from the kernel ptable to the user space
extern struct proc * getptable_proc(void);

int sys_getptable(void){
  int size;
  char *buf;
  char *s;
  struct proc *p = '\0';

  if (argint(0, &size) <0){
    return -1;
  }
  if (argptr(1, &buf,size) <0){
    return -1;
  }

  s = buf;
  p = getptable_proc();

  while(buf + size > s && p->state != UNUSED){
    *(int *)s = p->state;
    s+=4;
    *(int *)s = p->pid;
    s+=4;
    *(int *)s = p->priority;
    s+=4;
    *(int *)s = p->stime;
    s+=4;
    *(int *)s = p->rtime;
    s+=4;
    *(int *)s = p->iotime;
    s+=4;
    *(int *)s = p->rabletime;
    s+=4;
    memmove(s,p->name,16);
    s+=16;
    p++;
  }
  return 0;
}

int
sys_getppid(void)
{
  return myproc()->parent->pid;
}

// change priority of a specific process
extern int set_priority(int, int);

int
sys_set_priority(void)
{
  int pr;
  int pid;
  if(argint(0, &pr) < 0)
    return -1;
  if(argint(0, &pid) < 0)
    return -1;

  return set_priority(pr, pid);
}

int sys_yield(void) {
  yield();
  return 0;
}

// void* malloc(unsigned int);

int sys_getpinfo(void)   
{
  struct proc_stat *prInfo;
  int pid;
  if(argptr(0, (void*)&prInfo, sizeof(struct proc_stat)) < 0)    
    return -1;
  if(argint(1, &pid) < 0)    
    return -1;

  return getpinfo(prInfo, pid);
}

int sys_findRable(void)
{
  return findRable();
}