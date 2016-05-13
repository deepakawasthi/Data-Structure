#include<stdio.h>
#include<conio.h>

int  LinearSearch(int arr[],int len,int item){
    int pos=-1,i=0;
    for(i=0;i<len;i++){
        if(arr[i] == item){
            pos = i;
            break;
        }
    }
    return pos;
}

void BubbleSort(int arr[],int len){
    int i,j,temp;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-i-1;j++){
            if(arr[j] > arr[j+1]){ //swap these
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectionSort(int arr[],int len){
    int i,j,temp,min=32767,min_index;
    for(i=0;i<len-1;i++){
        for(j=i;j<len;j++){
            if(arr[j] < min){
                min = arr[j];
                min_index=j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;

        min=32767;
    }

}

void InsertionSort(int arr[],int len){
    int i,j,temp;
    temp = arr[0];
    for(i=1;i<len;i++){
        temp=arr[i];
        j=i-1;
        while(arr[j] > temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void ShellSort(){

}

void CountingSort(){

}

void RadixSort(){

}

void mergeSort(int arr[],int len){

}


int BinarySearch(int arr[],int len,int item){
    int mid,low,high,pos=-1;
    low=0;
    high=len-1;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] > item)
            high = mid-1;
        else if(arr[mid] < item)
            low = mid+1;
        else{
            pos = mid;
            break;
        }
    }
return mid;
}

int main(){
    int lRetPos=-1,item,i;
    int arr[] = {5,1,19,14,17,31,9,03,13,45,-2,4,-35,9,81};//5,1,19,14,17,31,9,03,
    printf("Original Array :\n");
    for(i=0;i<15;i++)
        printf("%d ",arr[i]);
    printf("\n");

    item = 03;
    lRetPos = LinearSearch(arr,15,item);
    if(lRetPos != -1)
        printf("Item : %d found at position : %d\n",item,lRetPos);
    else
        printf("Item : %d is not found.\n",item);

    //BubbleSort(arr,15);
    //SelectionSort(arr,15);
    InsertionSort(arr,15);
    printf("Sorted Array :\n");
    for(i=0;i<15;i++)
        printf("%d ",arr[i]);
    printf("\n");


    item = 19;
    lRetPos = BinarySearch(arr,15,item);
    if(lRetPos != -1)
        printf("Item : %d found at position : %d\n",item,lRetPos);
    else
        printf("Item : %d is not found.\n",item);


getchar();
return 0;
}
