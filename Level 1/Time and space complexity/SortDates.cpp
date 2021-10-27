#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
void countSort(vector<string> &arr, int div, int mod, int range)
{
    vector<int> farr(range, 0);
    vector<string> ans(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        int b = std::stoi(arr[i]);
        int a = farr[b / div % mod]++;
        farr.push_back(a);
    }

    for (int i = 1; i < farr.size(); i++)
    {
        farr[i] += farr[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int b = std::stoi(arr[i]);
        int pos = farr[b / div % mod] - 1;
        ans[pos] = arr[i];
        farr[b / div % mod]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }
}

void sortDates(vector<string> &arr)
{
    countSort(arr, 1000000, 100, 32);
    countSort(arr, 10000, 100, 13);
    countSort(arr, 1, 10000, 2501);
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    input(arr);
    sortDates(arr);
    print(arr);
    return 0;
}