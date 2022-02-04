#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

static int c = INT_MAX;
static int flloor = INT_MIN;

void cnf(Node *node, int data)
{
    if (node->data > data)
    {
        if (node->data < c)
        {
            c = node->data;
        }
    }

    if (node->data < data)
    {
        if (node->data > flloor)
        {
            flloor = node->data;
        }
    }
    for (Node *child : node->children)
    {
        cnf(child, data);
    }
}

int kthlarge(Node *node, int k)
{
    int factor = INT_MAX;

    for (int i = 0; i < k; i++)
    {                      // kth largest from kth
        cnf(node, factor); // will return floor
        factor = flloor;   // next floor of factor
        flloor = INT_MIN;
    }
    return factor;
}

int main()
{

    int n;
    cin >> n;
    int* arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
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
            Node *t = new Node();
            t->data = arr[i];

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
    int k;
    cin >> k;
    int kthlrg = kthlarge(root, k);
    cout << kthlrg;
}