#include <iostream>
#include <vector>

using namespace std;


int main() {

  int n;
  cin >> n;
  
  int oczeroes = 1;
  int ocones = 1;
  
  for(int i = 2; i <= n; i++){
      int nczeroes = ocones;
      int ncones = oczeroes + ocones;
      
      ocones = ncones;
      oczeroes = nczeroes;
  }
  cout << ocones + oczeroes;
}