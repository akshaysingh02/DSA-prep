// This is the working example of bubble sort algo

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main() 
{
    int arr[] = {2, 3, 11, 1, 0, -2, 1, 6};
    bubbleSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}

//It is In place algorithm
//It is stable sorting algorithm
//best case time complexity : O(n)
//average and worst will be: O(n^2)