#include <iostream>
#include<string>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &arr)
{
    int j = 0;              // 0 to j-1 is 0s area
    int i = 0;              // j to i-1 is 1s area
    int k = arr.size() - 1; // k+1 to end is 2s area
    // i to k is unknown
    while (i <= k)
    {
        if (arr[i] == 0)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else
        {
            swap(arr, i, k);
            k--;
        }
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012(A);
    print(A);
    return 0;
}