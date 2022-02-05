#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int c = INT_MAX;
int flloor = INT_MIN;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

// travel and change
int msum = INT_MIN;
int msumnode = 0;

int subsumtree(Node *node)
{
    // Write your code here
    int sum = 0;
    for (Node *child : node->children)
    {
        int csum = subsumtree(child);
        sum += csum;
    }
    sum += node->data;

    if (sum > msum)
    {
        msumnode = node->data; // calculate something else
        msum = sum;
    }
    return sum; // return something else
}

int main()
{

    int n;
    cin >> n;
    // int arr[n];
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Node *root = construct(arr, n);
    subsumtree(root);
    cout << msumnode << "@" << msum << endl;
}