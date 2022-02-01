//Given a limited range array contains both positive and non-positive numbers, i.e., elements are in the range from -MAX to +MAX. Our task is to search if some number is present in the array or not in O(1) time.

//Since range is limited, we can use index mapping (or trivial hashing). We use values as the index in a big array. Therefore we can search and insert elements in O(1) time.

#include <iostream>
using namespace std;

#define MAX 1000

bool has[MAX + 1][2];

bool search(int x)
{
    if (x >= 0)
    {
        if (has[x][0] == 1)
            return true;
        else
            return false;
    }

    x = abs(x);
    if (has[x][1] == 1)
        return true;

    return false;
}

void insert(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            has[arr[i]][0] = 1;
        }
        else
            has[abs(arr[i])][1] = 1;
    }
}

int main()
{
    int arr[] = {1, 9, -34, 4, 2, 1, -9, 10, 4};
    int n = sizeof(arr) / sizeof(arr[1]);

    insert(arr, n);

    int x;
    cout << "Konsa number chahiye batao :";
    cin >> x;

    if (search(x) == true)
        cout << "Number hai array mai" << endl;

    else if (search(x) == false)
        cout << "Nhi mila Number" << endl;

    return 0;
}
