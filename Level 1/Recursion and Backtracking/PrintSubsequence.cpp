#include <iostream>
#include<string>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = ques[0];
    string roq = ques.substr(1);
    printSS(roq, ans + ch);
    printSS(roq, ans + "");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}