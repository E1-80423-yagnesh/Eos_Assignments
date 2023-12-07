/*
1. Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 10
#define swap(a,b) {int t=a; a=b; b=t;}

void print(int arr[])
{
	for(int i=0; i<SIZE; i++)
	{
		printf("%4d", arr[i]);
	}

	printf("\n");
}


void* array_sort(void *param) 
{
    printf("Thread  START\n");
    int *arr = (int*)param;
    
    for(int i=0; i<SIZE; i++)
	{
		for(int j=i; j<SIZE; j++)
		{
			if(arr[j] < arr[i])
				swap(arr[j], arr[i]);
		}
	} 
    printf("Thread  END\n");
    pthread_exit(NULL);
}

int main() {
    int ret, arr[SIZE];
    
    printf("Enter the Array Elements :\n");
    for(int i=0; i < SIZE; i++)
    {
    	scanf("%d", &arr[i]);
    }
    printf("Adding elements done\n\n");
    
    
    int *result;
    pthread_t th;
    ret = pthread_create(&th, NULL, array_sort, arr);
    printf("main: waiting for thread completion...\n\n");
    pthread_join(th, NULL); // calling threads waits for given thread
    printf("The Sorted Array is :");
    print(arr);
    printf("\n");
    
    return 0;
}
























