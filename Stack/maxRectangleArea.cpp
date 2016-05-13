#include<iostream>
#include<stack>
#include<stdlib.h>

//Write your own push,pop and top function for this

typedef struct StackData{
    int height;
    int index;
};


using namespace std;

int maxRectangleArea(int arr[],int n){
    int i,maxArea = 0, currentArea = 0,top = -1, left = -1;
    stack<StackData*> S = (stack<StackData*>) malloc(sizeof(StackData)*n);
    StackData *tempS = (StackData*) malloc(sizeof(StackData));

    for(i=0;i<n;i++){
        StackData *temp = (StackData*) malloc(sizeof(StackData));
        temp = (StackData *) S[top];
        while( (top >= 0) && (i == n || temp->height > arr[i]) ){
             tempS = S.top();
             S.pop();
            if(top > 0){
                left = tempS->index;
            }
            else{
                left = -1
            }

            currentArea = (i-left-1)* (S.top()->height)
            if(currentArea > maxArea)
                maxArea = currentArea;
        }
        if(i < n){
            top++;
            temp->height = arr[i];
            temp->index = i;
            S.push(temp);
        }
    }

    delete []S;
    return maxArea;
}

int main(){
    int a[] = {3,2,5,6,1,4,4};
    int area = maxRectangleArea(a,7);
    cout<<area<<endl;
return 0;
}
