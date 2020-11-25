#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main()
{
	int pid;
	int status=0, a, b;	
	pid = fork();
	if (pid == 0)
  	{	
  		sleep(200);
  		exit();
    }
  	else
 	{
    	status = waitx(&a, &b);
 	}
 	printf(1, "Wait Time = %d and Run Time = %d with Status %d\n", a, b, status); 
 	exit();
}