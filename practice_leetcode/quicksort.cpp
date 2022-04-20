#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int *arr, int start, int end){
    int pindex = start;
    int pivot = arr[end];

    for(int i = start; i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex],arr[end]);
    return pindex;
}

int randompartition(int* arr,int start, int end){
    srand(time(0));
    // int random = offset + (rand() % range);
    int pivot_index = start + (rand() % end);
    swap(arr[pivot_index],arr[end]);
    return partition(arr, start , end);
}


void quicksort(int *arr, int start, int end){
    if(start>=end) return;
    int pindex = randompartition(arr,start,end);

    quicksort(arr, start , pindex-1);
    quicksort(arr, pindex+1 , end);

}

int main(){
    int arr[]= {7,-110,33,0,1,2,1,0,69};

    quicksort(arr, 0 , 8);

    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}