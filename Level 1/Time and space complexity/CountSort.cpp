#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void countsort(vector<int>& arr, int max, int min) {
  int range = max - min + 1;
  vector<int> farr(range,0);
  
  // frequency array
  for(int i = 0; i < arr.size(); i++){
      int idx = arr[i] - min;
    int a = farr[idx]++;
    farr.push_back(a);
  }
  
  //prefix sum array - cumulative 
  for(int i = 1; i < farr.size(); i++)
  {
      farr[i] = farr[i] + farr[i-1];
  }
      vector<int> ans(arr.size(), 0);
      for(int i = arr.size() - 1; i >= 0; i--){
      int val = arr[i];
      int pos = farr[val - min];
      int idx = pos - 1;
      ans[idx] = val;
      
      farr[val - min]--;
      }
  for(int i = 0; i < arr.size(); i++)
  {
      arr[i] = ans[i];
  }
}

void Display(vector<int>& arr) {
  for (int ele : arr) {
    cout << ele << endl;
  }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }
  int maxi = (int)-1e9;
  int mini = (int)1e9;
  
  for (int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
    maxi = max(maxi, arr[i]);
  }

  countsort(arr, maxi, mini);
  Display(arr);

}