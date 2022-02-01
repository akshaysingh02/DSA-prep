// This is the working example of selection sort algorithm


#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}


int main(){
    int array[] = {3,6,3,54,68,568,94,231,8,12};
    int n = (sizeof(array)/sizeof(array[0]));
    selectionsort(array,n);
    for(int i = 0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}


/*here are some of the points about selection sort
Selection Sort
1. Comparison Based Algo
2. In Place ,so Space Complexity= O(1)
3. Time complexity O(n^2)
4. Offline Algo
5. Unstable Algo
6. Non-Recursive*/

//In-place algorithm is that algorithm in which we don't have to create new element to store the sorted one( which increases the space complexity)
//in In-place sorting is done inside the element only which results the constant space complexity of O(1)