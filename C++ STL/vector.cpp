#include <iostream>
#include <vector>

using namespace std;

// stl vector is a dynamic array it doubles it size when exceded
int main()
{
    vector<int> v;
    vector<int> v1(5, 1);
    vector<int> v2(v1); // copies all elements to v2

    cout << "capacity -> " << v.capacity() << endl; // space assigned to the vector
    v.push_back(1);
    cout << "capacity -> " << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity -> " << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity -> " << v.capacity() << endl;

    cout << "size -> " << v.size() << endl; // no. of elements in vector

    cout << "element at index 2 -> " << v.at(2) << endl;

    cout << "element at front ->" << v.front() << endl;
    cout << "element at back ->" << v.back() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    v.pop_back();
    cout << "after pop back -" << endl;

    for (int i : v)
    {
        cout << v[i] << endl;
    }

    cout << "before clear size ->" << v.size() << endl;
    v.clear(); // it only make size = 0 but not capacity
    cout << "after clear size ->" << v.size() << endl;

    for (int i : v1)
    {
        cout << v1[i] << endl;
    }

    for (int i : v2)
    {
        cout << v2[i] << endl;
    }
}