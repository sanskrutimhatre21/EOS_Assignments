#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
      int arr1[2], arr2[2], ret, num1, num2, res, ret1, ret2, s, r;

	  ret = pipe(arr1);
	  if(ret < 0)
	  {
	      perror("pipe() failed");
		  _exit(1);
	  }

	  ret = pipe(arr2);
	  if(ret < 0)
	  {
	      perror("pipe() failed");
		  _exit(1);
	  }

	  ret = fork();
	  if(ret == 0)
	  {
	      close(arr1[0]);
		  close(arr2[1]);

		  printf("Child Enter 2 Numbers: ");
		  scanf("%d %d",&num1, &num2);

		  ret1 = write(arr1[1], &num1, sizeof(num1));
		  ret2 = write(arr1[1], &num2, sizeof(num2));

		  printf("child: numbers written in pipe: %d byte\n",ret1);
		  printf("child: number written in pipe: %d byte\n",ret2);
		  
		  read(arr2[0], &res, sizeof(res));
		  printf("result: %d\n", res);

		  close(arr2[0]);
		  close(arr1[1]);
	   }
	   else
	   {
	        close(arr1[1]);
			close(arr2[0]);

			ret1 = read(arr1[0], &num1, sizeof(num1));
			ret2 = read(arr1[0], &num2, sizeof(num2));
            
			printf("parent : number read from pipe : %d bytes\n", ret1);
			printf("parent : number read from pipe : %d bytes\n", ret2);

			res = num1 + num2;

			ret = write(arr2[1], &res, sizeof(res));
			printf("parent : result sent: %d bytes\n", ret);

			close(arr2[1]);
			close(arr1[0]);
			waitpid(-1, &s, 0);

		}
		return 0;
}


