#include "types.h"
#include "user.h"

int findRable();

int
main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf(1, "Please enter correct number of arguments.\n");
		exit();
	}
	int i;
	int n;
	int j = 0;
	int k;
	int rabletime=0;
	int rtime;
	int iotime;
	int sums[3][3];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sums[i][j] = 0;
	n = atoi(argv[1]);
	int pid;
	for (i = 0; i < n; i++) {
		j = i % 3;
		pid = fork();
		if (pid == 0) {
			j = (getpid() - 4) % 3; 
			switch(j) {
				case 0:
					for (double z = 0; z < 100000.0; z+= 0.01){
				         double x =  x + 6.52 * 23.56;
					}
					break;
				case 1:
					for (k = 0; k < 100; k++){
						for (j = 0; j < 1000000; j++){}
						yield();
					}
					break;
				case 2:
					for(k = 0; k < 100; k++){
						sleep(1);
					}
					break;
			}
			exit();
		}
		continue; 
	}
	for (i = 0; i < n; i++) {
		pid = waitx(&iotime, &rtime);
		rabletime = findRable();
		int res = (pid - 4) % 3;
		switch(res) {
			case 0: 
				printf(1, "CPU-bound, pid: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, rtime, iotime, rabletime + rtime + iotime);
				sums[0][0] += rabletime;
				sums[0][1] += rtime;
				sums[0][2] += iotime;
				break;
			case 1: 
				printf(1, "Short Tasks, pid: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, rtime, iotime, rabletime + rtime + iotime);
				sums[1][0] += rabletime;
				sums[1][1] += rtime;
				sums[1][2] += iotime;
				break;
			case 2: 
				printf(1, "I/O bound, pid: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, rtime, iotime, rabletime + rtime + iotime);
				sums[2][0] += rabletime;
				sums[2][1] += rtime;
				sums[2][2] += iotime;
				break;
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sums[i][j] /= n;
	printf(1, "\n\nCPU bound:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[0][1], sums[0][2], sums[0][0] + sums[0][1] + sums[0][2]);
	printf(1, "Short Tasks:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[1][1], sums[1][2], sums[1][0] + sums[1][1] + sums[1][2]);
	printf(1, "I/O bound:\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sums[2][1], sums[2][2], sums[2][0] + sums[2][1] + sums[2][2]);
	exit();
}