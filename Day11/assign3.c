#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int arr[2];

void sigint_handler(int sig)
{
    close(arr[1]);
	close(arr[0]);

	printf("SIGINT caught: %d\n", sig);
	_exit(0);
}

int main()
{
   int ret;
   char ch = 'A';

   ret = pipe(arr);
   if(ret < 0)
   {
		perror("pipe() failed");
		_exit(1);
	}
   
    struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;

	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0)
	{
		perror("sigaction() failed");
		_exit(1);
	}

   int count = 0;

   while(1)
   {
      write(arr[1], &ch, 1);
	  count++;
	  printf("bytes written: %d\n", count);
   }
   return 0;
}

