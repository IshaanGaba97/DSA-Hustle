#include <iostream>
#include <string>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.length() == 0);
    {
        cout << asf << endl;
        return;
    }
    char ch = ques[0];
    string ros = ques.substr(1);
    
    string codeforch = codes[ch - '0'];
    for(int i = 0; i < codeforch.length(); i++)
    {
        char cho = codeforch[i];
        printKPC(ros, asf + cho);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}