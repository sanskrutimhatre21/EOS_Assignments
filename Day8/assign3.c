#include<unistd.h>
#include<stdio.h>

int main(){
    int ret, s, i;
	i =1;
	while(1){
	   ret = fork();
	   if(ret == 0)
	   {
	     printf("Hello\n");
		_exit(0);
		}
		else if(ret == -1)
		{
		     break;
	    }
		else
		{
            i++;
			printf("child count: %d\n",i);
		}
	}
	for(int j=1;j<=i;j++)
	{
	   wait(&s);
	}
	return 0;
}
		    
	

