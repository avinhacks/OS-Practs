#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void asc(int *a, int sz);
void desc(int *a, int sz);

int main()
{
  int arr[10];
  int i, size;
 
  pid_t pid;

  printf("\nEnter size of array: ");
  scanf("%d", &size);

  printf("\nEnter %d elements: \n",size);
  for(i=0; i<size; i++)
  {
    scanf("%d", &arr[i]);
  }

  pid = fork();

  if(pid == 0) 
    desc(arr, size);
  else
  {
    wait(NULL);
    asc(arr, size);
  }
 
  return 0;
}

void asc(int *a,int sz)
{
   int i, j;
   int temp;
  
   for(i=0; i<sz; i++) 
   {
    for(j=0; j<sz-i; j++)
    {
        if(a[j]>=a[j+1])
        {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;   
        }
    }
   }
   printf("\nSorted array in ascending order is:\n");
   for(i=0; i<sz; i++)
   {
    printf("%d\t", a[i]) ;
   }
}

void desc(int *a, int sz)
{
   int i, j;
   int temp;
  
   for(i=0; i<sz; i++) 
   {
    for(j=0; j<sz; j++)
    {
        if(a[j]<=a[j+1])
        {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;   
        }
    }
   }
   printf("\nSorted array in descending order is:\n");
   for(i=0; i<sz; i++)
   {
    printf("%d\t", a[i]) ;
   }
}
