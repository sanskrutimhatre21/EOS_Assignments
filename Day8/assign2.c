#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main() {

int ret1, ret2, ret3, i, s1, s2, s3;
   ret1 = fork();
   if(ret1 == 0)
   {
       ret2 = fork();
	
    	if(ret2 == 0)
    	{   
	       ret3 = fork();
            
		   if(ret3 == 0)
		   {
		      
		      for(int i=0;i<5;i++)
			  {
			       printf("child3 - %d\n",i);
				   sleep(1);
				 }
				 _exit(0);
			}
			
		      for(int i=0;i<5;i++)
			  {
			       printf("child2 - %d\n",i);
				   sleep(2);
			  }
				 waitpid(ret3,&s3,0);
				 _exit(0);
			}

		     for(int i=0;i<5;i++)
			  {
			       printf("child1- %d\n",i);
				   sleep(1);
				 }
				 waitpid(ret2,&s2,0);

				 _exit(0);
			}
			waitpid(ret1,&s1,0);
			return 0;

       	}
