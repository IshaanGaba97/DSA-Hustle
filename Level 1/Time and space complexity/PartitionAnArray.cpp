#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
  cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// i++ -> not unknown
// j++ -> smallers are behind after swap
// 0 - j-1 -> small
// j  - i-1 -> large
// j is the first of larger elements which is swapped with the smaller one

void partition(int arr[], int n, int pivot)
{
  // write your code
  int i = 0;
  int j = 0;
  while (i < n)
  {
    if (arr[i] > pivot)
    {
      i++;
    }
    else
    {
      swap(arr, i, j);
      i++;
      j++;
    }
  }
}

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{

  int n;
  cin >> n;

  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int pivot;
  cin >> pivot;

  partition(arr, n, pivot);
  print(arr, n);
}
