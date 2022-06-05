// #include <iostream>
// using namespace std;
 
// int _mergeSort(int arr[], int temp[], int left, int right);
// int merge(int arr[], int temp[], int left, int mid,
//           int right);
 

// int mergeSort(int arr[], int array_size)
// {
//     int temp[array_size];
//     return _mergeSort(arr, temp, 0, array_size - 1);
// }
 

// int _mergeSort(int arr[], int temp[], int left, int right)
// {
//     int mid, inv_count = 0;
//     if (right > left) {

//         mid = (right + left) / 2;
 

//         inv_count += _mergeSort(arr, temp, left, mid);
//         inv_count += _mergeSort(arr, temp, mid + 1, right);
 

//         inv_count += merge(arr, temp, left, mid + 1, right);
//     }
//     return inv_count;
// }
 
// int merge(int arr[], int temp[], int left, int mid,
//           int right)
// {
//     int i, j, k;
//     int inv_count = 0;
 
//     i = left; /* i is index for left subarray*/
//     j = mid; /* j is index for right subarray*/
//     k = left; /* k is index for resultant merged subarray*/
//     while ((i <= mid - 1) && (j <= right)) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         }
//         else {
//             temp[k++] = arr[j++];
 
//             inv_count = inv_count + (mid - i);
//         }
//     }
 
//     /* Copy the remaining elements of left subarray
// (if there are any) to temp*/
//     while (i <= mid - 1)
//         temp[k++] = arr[i++];
 

//     while (j <= right)
//         temp[k++] = arr[j++];
 

//     for (i = left; i <= right; i++)
//         arr[i] = temp[i];
 
//     return inv_count;
// }
 
// // Driver code
// int main()
// {
//     int arr[] = { 1, 20, 6, 4, 5 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int ans = mergeSort(arr, n);
//     cout << " Number of inversions are " << ans << endl;
//     return 0;
// }


//The below code is pass address of ans variable to get the number of inversions.
#include <iostream>
#include <vector>
using namespace std;

void mergearray(int left[], int right[], int arr[], int nL, int nR, int &ans){
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
            ans = ans + (nL - i);
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

void mergeSort(int arr[], int n, int &ans)
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

    mergeSort(left, mid, ans);
    mergeSort(right, n - mid, ans);
    mergearray(left,right,arr,mid,n-mid,ans);
}

int main()
{
    int arr[] = {2,5,1,3,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = 0;
    mergeSort(arr, size, ans);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<endl<<"Number of inversions are: "<<ans<<endl;
}
