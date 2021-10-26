#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void Display(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}

void countsort(vector<int> &arr, int ex)
{
    // write your code here
    vector<int> farr(10, 0);

    // frequency array
    for (int i = 0; i < arr.size(); i++)
    {
        int a = farr[arr[i] / ex % 10]++;
        farr.push_back(a);
    }

    // prefix sum array - cumulative
    for (int i = 1; i < farr.size(); i++)
    {
        farr[i] += farr[i - 1];
    }
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int pos = farr[arr[i] / ex % 10] - 1;
        ans[pos] = arr[i];
        farr[arr[i] / ex % 10]--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }
    cout << "After sorting on " << ex << " place -> ";
    Display(arr);
    cout << endl;
}

void radixSort(vector<int> &arr)
{
    // write your code here
    int maxi = (int)-1e9;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    for (int val : arr)
    {
        if (val > maxi)
        {
            maxi = val;
        }
    }
    int ex = 1;
    while (ex <= maxi)
    {
        countsort(arr, ex);
        ex = ex * 10;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr);
    Display(arr);
    return 0;
}