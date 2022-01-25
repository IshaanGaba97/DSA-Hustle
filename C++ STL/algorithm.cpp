#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);

    cout << "finding 4 -> " << binary_search(v.begin(), v.end(), 1) << endl;

    int a = 1;
    int b = 4;
    cout << "max" << max(a, b) << endl;
    cout << "min" << min(a, b) << endl;

    swap(a, b);
    cout << a << " " << b << endl;

    string s = "abcde";
    reverse(s.begin(), s.end());
    cout << s;

    rotate(v.begin(), v.begin() + 1, v.end());

    cout << endl;

    for (int i : v)
    {
        cout << i << " ";
    }

    sort(v.begin(), v.end());

    cout << "sorting ->" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
}
