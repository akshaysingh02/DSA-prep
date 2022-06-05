/*
This algorithm fall under the Divide and conquer alogrithm (its my my fist divide and 
conquer algo🤯)
The bubble sort, selection sort and insertion sort algorithms are all slow and 
have the average and worst time complexity of O(n^2),
Now we will talk about the Merge sort algo, it has the worst case Time complexity 
of O(nlogn) which is a lot better.

In this algorithm we divide the array into two parts, left and right using recursion and
sort the left and right sub array and then merge the sorted array into the main array 
which will result in the fully sorted array
*/

#include <iostream>
#include <vector>
using namespace std;

void mergearray(int left[], int right[], int arr[], int nL, int nR){
    // int sizeofleft = nL;
    // int sizeofright = nR;
    int i = 0,j = 0,k = 0;
    while(i<nL && j<nR){
        if(left[i]<=right[j]){
            arr[k]  =left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
        while(j<nR){
            arr[k] = right[j];
            j++;
            k++;
        }
        while(i<nL){
            arr[k] = left[i];
            i++;
            k++;
        }
}

void mergeSort(int arr[], int n)
{
    int mid = n / 2;
    if (n < 2) return;
    int left[mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    int right[n - mid];
    for (int j = mid; j < n; j++)
    {
        right[j - mid] = arr[j];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    mergearray(left,right,arr,mid,n-mid);
}

int main()
{
    int arr[] = {1,20,6,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// Few features of Merge sort:
// 1) divide and conquer.
// 2) Recursive.
// 3) Stable.
// 4) Not In-place(i.e. space complexity is not constant or O(1)).
// space: O(n) and time: O(nlogn)

// stable algorithm is that algo which preserves the initial state of the occurence of the element, if in the sorting the element have the other same element with the same value
// then the elements are arranged according to the arrangement in the unsorted list