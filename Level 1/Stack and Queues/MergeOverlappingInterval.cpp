#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

void mergeOverlappingIntervals(vector<vector<int>> &arr)
{

    // write your code here
    sort(arr.begin(), arr.end(), compare);
    stack<vector<int>> st;
    st.push(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        //   0 -> starting tim
        //   1 -> ending time
        vector<int> cm = arr[i];
        vector<int> lm = st.top();

        if (lm[1] >= cm[0])
        {
            // overlap
            st.pop();
            vector<int> merge = {lm[0], max(lm[1], cm[1])};
            st.push(merge);
        }
        else
        {
            // not overlap
            st.push(cm);
        }
    }

    // reverse printing

    stack<vector<int>> newSt;
    while (st.size() > 0)
    {
        newSt.push(st.top());
        st.pop();
    }

    // print newSt
    while (newSt.size() > 0)
    {
        vector<int> fm = newSt.top();
        newSt.pop();

        cout << fm[0] << " " << fm[1] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    mergeOverlappingIntervals(arr);
}