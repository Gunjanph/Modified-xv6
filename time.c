#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
	//pid_t 
	int pid;
	int a,b,status=0;	
	pid = fork();
	if (pid < 0)
	{
		printf(1, "Fork failed\n");
		exit();
	}
	else if (pid == 0)
	{	
		if(argc > 1)
		{
			int l = exec(argv[1], argv+1);
			if(l < 0)
			{
  				printf(1, "exec %s failed\n", argv[1]);
  				exit();
			}
  		}
  		else if(argc == 1)
  		{
  			exit();
  		}
  	}
	else
  		status = waitx(&a, &b);
 	printf(1, "Wait Time = %d\nRun Time = %d with Status = %d\n", a, b, status); 
 	exit();
}