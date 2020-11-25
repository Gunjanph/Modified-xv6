# Modified-xv6
To run the code in xv6, check README
## Task 1

### waitx() syscall:
	
- ALl the necessary files edited to declare a system call (sysproc.c, usys.S, etc.)
- The function of the syscall is declared in proc.c under function int waitx().
- It is mostly the same as wait syscall with the only differences being that it takes 2 arguments and the wtime and rtime are updated inside waitx using extra definitions of the in the proc structure in proc.h as rtime(running), iotime(sleeping), stime(start), rabletime(runnable), etime(end).
- Test program is named waitx.c and can be run with command waitx.
- Alternativly any command can be tested with time.c:
```
$ time <command>
```

### ps:

- ALl the necessary files edited to declare a system call getpinfo(sysproc.c, usys.S, etc.)
- The function of the syscall is declared in proc.c under function int waitx().
- In proc.c, the function searches for the element with given pid(second argument) and populates the proc_stat element given(first argument) using the extra definitions of the in the proc structure in proc.h as numrun, current_queue, ticks[].
- If pid given is 0, the calling process pid is taken.
- The proc_stat structure is declared in getpinfo.h.
- Alternativly any program can be tested with ps.c
```
ps
```

## Task 2

- A macro is added to Makefile as SCHEDULER which is used to define the type of scheduler with which xv6 should run.
- The rtime(running), iotime(sleeping), stime(start), rabletime(runnable), etime(end) are appropriately initialized in allocproc function in proc.c.
- The rtime(running), iotime(sleeping), stime(start), rabletime(runnable) are updated each tick based on the state of the process, for every process, in the incrementTimes function(also in proc.c).

### set_priority() syscall:
	
- ALl the necessary files edited to declare a system call (sysproc.c, usys.S, etc.)
- The function of the syscall is declared in proc.c under function int set_priority().
- It takes 2 arguments and the new priority and pid are updated inside set_priority using yield function as priority given pid is changed to given priority.
- Test program is named setPiority.c and can be run with command setPriority.
```
  $ setPriority <new_priority> <pid>
```  
### Schedular

#### FCFS:
	
- Context switch part is same as round robin, the only difference being that the loop iterates through ptable to find leastP (i.e. process with least stime), and that process is selected to run. [Only RUNNABLE processes]

#### PBS:
	
- Priority scheduling works on process priority, an int that is declared in the modified proc structure in proc.h.
- All processes are initialized with priority 10, except init and sh (with priority 1).
- Context switch part is same as round robin, the only difference being that the loop iterates through ptable to find maxP (i.e. process with maximum priority), and that process is selected to run. [Only RUNNABLE processes]

#### MLFQ:
	
- Dynamic Multilevel Queue scheduling works on the same (int) priority as in PBS, it's just used in a different way. In this, priority indicates the number of the current queue process is in.
- The context switch part is (mostly) same as round robin. The only difference is that the tickcounter is reset before context switch so as to indicate that the process was preemted as it had used up it's time quantum.
- Where process ticks are updated, (in the function incrementTimes()) tickcounter is also incremented for the process, and if the tickcounter becomes greater than to the time quantum allocated, priority is lowered (arithmetically incrementing it).
- When scheduler is executed, it takes up a RUNNABLE process from the highest priority queue (and if no such process is available, it goes looking for a process in lower queues) in the function bestProcess.
- index1, index2, index3, index4, index5 are respective indexes of current process in respective queues.
- Intra queue, the selection process is round-robin. 

### Sample

- It is a benchmark program that is used for comparing the performances of different scheduling algorithms.
```
$ sample <number>
```
