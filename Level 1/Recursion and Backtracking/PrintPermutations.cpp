#include <iostream>
#include <string>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str == "")
    {
        cout << asf << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string qlpart = str.substr(0,i);
        string qrpart = str.substr(i+1);
        string ros = qlpart + qrpart;
        printPermutations(ros, asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
}