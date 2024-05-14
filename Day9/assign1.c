#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main()
{
    int signum, pid, ret;

    printf("Enter signum: ");
	scanf("%d", &signum);

	printf("Enter pid: ");
	scanf("%d", &pid);
    
	ret = kill(pid, signum);

	if(ret == 0)
	{
	   printf("Success\n");
	}
	else
	{
	   printf("Failed\n");
	}
	return 0;
}
 
