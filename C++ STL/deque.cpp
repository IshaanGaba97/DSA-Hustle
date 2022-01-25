#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);

    for (int i : d)
    {
        cout << i << " ";
    }

    // d.pop_front();
    // d.pop_back();

    cout << endl;
    for (int i : d)
    {
        cout << i << " ";
    }

    cout << "front element -> " << d.front() << endl;
    cout << "back element -> " << d.back() << endl;

    cout << "empty or not ->" << d.empty() << endl;

    cout << "size before erase -> " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "size before erase -> " << d.size() << endl;

    for (int i : d)
    {
        cout << i << " ";
    }
}