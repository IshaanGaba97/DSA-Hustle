#include <iostream>
#include <map>
#include <string>
using namespace std;
// map and set are o(logN) -> implement on BST
//  one key only point to one value only
// ordered maps ->
int main()
{
    map<int, string> m;

    m[1] = "scorpio";
    m[13] = "endeavour";
    m[2] = "fortuner";
    m.insert({5, "nexon"});
    for (auto i : m)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    cout << "finding 13 -> " << m.count(13) << endl;
    cout << "finding -13 -> " << m.count(-13) << endl;

    cout << "erase ->" << endl;
    m.erase(13); // only k
    for (auto i : m)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    // auto it = m.find(5);

    // for(int i = it; i!=m.end(); i++){
    //     cout << (*i).first << endl;
    // }
}