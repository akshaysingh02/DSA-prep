//This is the iterative approach for the binary search
#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int x){
    //These are the two pointers pointing to start and end of the array
    int start = 0;
    int end = n-1;

    while(start<=end){
        //initializing mid like that might cause an overflow
        //to avoid that overflow use mid = end + (start-end)/2
        int mid = (start+end)/2;
        if (arr[mid] == x){
            return mid;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        else if(arr[mid]<x){
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[10] = {2,3,53,65,77,89,96,112,200,696};

    int x = BinarySearch(arr,10,2);
    if(x>0){
        cout<<"found at the index number: "<<x<<endl;
    }
    else if(x==-1){
        cout<<"Element not found in the array"<<endl;

    }
}

//Next will be recursive approach