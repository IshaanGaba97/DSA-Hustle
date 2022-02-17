#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() 
  {
  string str;
  cin >> str;
  unordered_map<char, int> hm;
  
  for(int i = 0; i < str.length(); i++){
      char ch = str[i];
      hm[str[i]]++;
  }
  int maxCount = 0;
  char ch;
  
  for(auto x : hm){
      if(maxCount < x.second){
          maxCount = x.second;
          ch = x.first;
      }
  }
  cout << ch;
}