// This is the working example of insertion sort algo

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0;i<n;i++){
        int value = arr[i];
        int hole = i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole = hole-1;
        }
        arr[hole] = value;
    }
}


int main(){
    int arr[] = {4,23,-65,2,112,2345,-987,5,0,5};

    insertionSort(arr,10);

    for(int i = 0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}


/*In best case the time complexity will be O(n) when the array is fully sorted which
is highly impractical and happens only in rare cases.
In the worst case the time complexity will be O(n^2) when the array is in the 
reverse order.
The time complexity is O(n^2) but still it has less operation than the selection and bubble sort
and considered better than both of those algorithms.
MyCodeSchool is the best thing everrrr.
*/