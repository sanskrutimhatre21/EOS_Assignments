#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int arr[10] = {14,24,35,65,75,45,20,80,48,67};

pthread_mutex_t s;

void* selection_sort(void *param)
{
     int *arr;
	 int temp = 0;
	 arr = (int*)param;
	 int array_size = 10;
	 int i = 0;
	 int j = 0;
	 int min_index = 0;
	 for(i = 0;i<array_size;i++)
	 {
	     min_index = i;
		 for(j = i+1;j<array_size;j++)
		 {
		     if(arr[min_index] > arr[j])
			   min_index = j;
		 }
		 temp = arr[i];
		 arr[i] = arr[min_index];
		 arr[min_index] = temp;
	 }
}

int main()
{
   int ret = 0;
   pthread_t th;

   ret = pthread_create(&th,NULL,selection_sort,arr);
   if(ret < 0)
   {
      printf("thread failed()\n");
   }

   pthread_join(th, NULL);
   for(int i = 0;i<10;i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\r\n");
   return 0;
}

