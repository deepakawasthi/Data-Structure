#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;

void nextGreatestNearestElement(int n,int arr[]){
    int Nearest_Element = -1;
    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                cout<<"Next Nearest Greatest Element of "<<arr[i]<<" is : "<<arr[j]<<endl;
                break;
            }
        }
    }
}

void nextNearestGreatestElementByStack(int n,int arr[]){
    int nearestElement = -1,element;
    stack<int> *st = (stack<int>*) malloc(sizeof(int)*n);
    st->push(arr[0]);

    for(int i=1;i<n;i++){
        nearestElement = arr[i];
        if(!st->empty()){
            element = st->top();
            st->pop();
            while(nearestElement > element){
                cout<<"Next nearest greatest element of "<< element <<" is : " << nearestElement <<endl;
                if(st->empty())
                    break;
            }

            if(element > nearestElement){
                st->push(element);
            }
        }
        st->push(nearestElement);
    }


}

int main(){
int arr[] = {3,2,6,5,1,4,4,8,7};
//nextGreatestNearestElement(9,arr);

nextNearestGreatestElementByStack(9,arr);

return 0;
}
