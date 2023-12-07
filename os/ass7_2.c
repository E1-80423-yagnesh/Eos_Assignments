/*
ass 7.2  2. Create a thread to sort given array of "n" integers using bubble sort. Main thread should print the result after sorting is completed.

Hint: struct array { int *arr; int size; }
Pass struct address to thread function (via arg4 of pthread_create()).

*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define swap(a,b) {int t=a; a=b; b=t;}

typedef struct array{
	int *arr;
	int size;
}arr_t;
arr_t array;

void print(int arr[])
{
	for(int i=0; i<array.size; i++)
	{
		printf("%4d", arr[i]);
	}

	printf("\n");
}


void* array_sort(void *param) 
{
    printf("		Thread  START\n");
    int *arr = (int*)param;
	
	for(int j=0; j<array.size-1; j++)
	{
		for(int pos=0;pos<array.size-1-j ; pos++)
		{
			if(arr[pos] > arr[pos+1])
				swap(arr[pos], arr[pos+1]);
		}
	}
    printf("			Sorting Done...\n");
    printf("		Thread  END\n");
    pthread_exit(NULL);
}

int main() {
    int ret, *arr;

    
    printf("Enter the Number of elements : ");
    scanf("%d", &array.size);
    arr = (int *)malloc(array.size * sizeof(int));
    printf("Enter the Array Elements :\n");
    for(int i=0; i < array.size; i++)
    {
    	scanf("%d", &arr[i]);
    }
    printf("	%d Elements Added in the array\n\n", array.size);
    
    array.arr = arr;
   
    pthread_t th;
    ret = pthread_create(&th, NULL, array_sort, arr);
    printf("main: waiting for thread completion...\n\n");
    pthread_join(th, NULL); // calling threads waits for given thread
    printf("\nThe Sorted Array is :");
    print(arr);
    printf("\n");
    
    return 0;
}
























