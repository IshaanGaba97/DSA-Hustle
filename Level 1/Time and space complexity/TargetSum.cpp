#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void input(vector<int>& arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cin >> arr[i];
  }
}
void targetSumPair(vector<int>& arr, int target)
{
  //write your code here
  sort(arr.begin(), arr.end());
  int li = 0;
  int ri = arr.size() - 1;
  while(li < ri){
      if(arr[li] + arr[ri] < target){
          li++;
      }
      else if(arr[li] + arr[ri] > target){
          ri--;
      }
      else{
          cout << arr[li] << ", " << arr[ri] << endl;
          li++;
          ri--;
      }
  }
}
int main()
{
  int n, target;
  cin >> n;
  vector<int> vec(n);
  input(vec);
  cin >> target;
  targetSumPair(vec, target);
  return 0;
}