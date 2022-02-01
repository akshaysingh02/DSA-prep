#include <iostream>
using namespace std;

void merge(int arr[],int left[],int right[],int nL,int nR){
    int i = 0,j=0,k=0;
    while(i<nL && j<nR){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<nL){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<nR){
        arr[k] = right[j];
        j++;
        k++;
    }
}

//try to make merge sort quicker by using only one for loop while assinging value to left and right array
void mergesort(int arr[],int n){
    if(n < 2) return;
    int mid = n/2;
    int  left[mid];
    for(int i = 0; i < mid;i++){
        left[i] = arr[i];
    }
    int right[n-mid];
    for(int j = mid;j<n;j++){
        right[j-mid] = arr[j];
    }

    mergesort(left, mid);
    mergesort(right, n-mid);
    merge(arr,left,right,mid,n-mid);
}

int main(){
    int arr[]={7,2,5,0,12,8,0,1,1,4};

    mergesort(arr,10);
    for(int i = 0; i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}