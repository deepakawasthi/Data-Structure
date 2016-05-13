#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int left,right,pivot,i;    // pivot
    left=low;
    right=high;
    pivot=arr[low];
    while(left<right){
        while(arr[left] <= pivot)
            left++;
        while(arr[right] > pivot)
            right--;
        if(left<right)
            swap(&arr[left],&arr[right]);
    }
    arr[low] = arr[right];
    arr[right]=pivot;
    return right;
}

void quickSort(int *ar,int low,int high) {
    int i;
    if (low < high)
    {
        int pi = partition(ar,low, high);

        quickSort(ar, low, pi - 1);
        quickSort(ar, pi + 1, high);
    }
}
int main(void) {
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) {
      scanf("%d", &ar[i]);
   }

   quickSort(ar,0,ar_size-1);
  // for(i=0;i<ar_size;i++)
    //   printf("%d ",ar[i]);
   return 0;
}
