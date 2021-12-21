#include <iostream>
#include <vector>

using namespace std;


int main() {

  int n;
  cin >> n;
  
  int ocb = 1;
  int ocs = 1;
  
  for(int i = 2; i <= n; i++){
      int ncb = ocs;
      int ncs = ocs + ocb;
      
      ocb = ncb;
      ocs = ncs;
  }
  long total = ocb + ocs;
  total = total * total;
  cout << total;
}