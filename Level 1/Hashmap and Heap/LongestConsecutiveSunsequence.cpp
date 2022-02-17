#include<map>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void longestConsecutive(vector<int> &num) {
    
    unordered_map<int, bool> mp;
    
    for(int i = 0; i < num.size(); i++){
        mp[num[i]] = true;
    }
    
    for(int i = 0; i < num.size(); i++){
        if(mp.find(num[i] - 1) != mp.end()){
            mp[num[i]] = false;
        }
    }
    
    int msp = 0;           //maximum starting point
    int ml = 0;            //maximum length
    
    for(int val : num){
        if(mp[val] == true){
            int tsp = val;         //temporary
            int tl = 1;   
            while(mp.find(tsp + tl) != mp.end()){
                tl++;
            }
            if(tl > ml){
                ml = tl;
                msp = tsp;
            }
        }
    }
    
    for(int i = 0; i < ml; i++){
        cout << msp+i << endl;
    }
}
int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
    longestConsecutive(arr);

  return 0;
}