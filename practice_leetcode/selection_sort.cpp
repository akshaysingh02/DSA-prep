#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{

    int imin;
    int min = 0;
    int temp;

    for (int i = 0; i < size-1; i++)
    {
        imin = i;
        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[imin]){
                imin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }

    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {5,6,0,4,9};

    // cout << "Enter 5 digits spaced out that you want to be sorted ";
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }

    selection_sort(arr, 5);
    return 0;
}