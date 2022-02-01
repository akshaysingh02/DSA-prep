#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int k = 0;k<n-1;k++){
        int flag = 0;
        for(int i =0;i<n-k-1;i++){
            if(arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

int main(){
    int arr[] = {2,5,7,0,0,0,2,3};

    bubblesort(arr,8);

    for(int i = 0; i<8;i++){
        cout<<arr[i]<<" ";
    }
}