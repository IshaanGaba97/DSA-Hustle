#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.length() == 0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch = s[0];
    string ros = s.substr(1);
    vector<string> rres = gss(ros);
    
    vector<string> mres;
    for(string rstr: rres)
    {
        mres.push_back("" + rstr);
    }
    for(string rstr: rres)
    {
        mres.push_back(ch + rstr);
    }
    return mres;
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}