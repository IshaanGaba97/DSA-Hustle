#include<iostream>
#include<vector>
#include<stack>
#include <ctype.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;
 
  // write your code here
  stack<int> st;
  vector<int> nge(n);
  st.push(n-1);
  nge[n-1] = n;
  for(int i = n - 2; i >= 0; i--){
      //-a+
      while(st.size() > 0 && arr[i] > arr[st.top()]){     
          st.pop();              //pop all greaters
      }
      if(st.size() == 0){        // no next greater
          nge[i] = n;
      }else{
          nge[i] = st.top();
      }
      st.push(i);
  }
  int j = 0;
  for(int i = 0; i <= n - k; i++){
      if(j < i){
          j = i;
      }
      while(nge[j] < i + k){
          j = nge[j];
      }
      cout << arr[j] << endl;
  }
}