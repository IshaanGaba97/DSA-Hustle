#include<iostream>
#include<vector>
#include<string>

using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string str) {
    if(str.size() == 0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch = str[0];
    string ros = str.substr(1);
    
    vector<string> rres = getKPC(ros);
    vector<string> mres;
    
    string codeforch = codes[ch -'0'];
    
    for(int i = 0; i < codeforch.size(); i++)
    {
        char chcode = codeforch[i];
        for(string rstr: rres)
        {
            mres.push_back(chcode + rstr);
        }
    }
    
    return mres;
}

int main()
{
    string str;
    cin >> str;
    vector<string> words = getKPC(str);
    int cnt = 0;

    cout << '[';
    for (string str : words){
        if (cnt != words.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}