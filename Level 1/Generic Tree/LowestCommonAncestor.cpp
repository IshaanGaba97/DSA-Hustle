#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
    }
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";

    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << "\n";

    for (Node *child : node->children)
    {
        display(child);
    }
}

vector<int> nodeToRootPath(Node *node, int data)
{
    if (node->data == data)
    {
        vector<int> v;
        v.push_back(node->data);
        return v;
    }

    for (Node *child : node->children)
    { // ptc - path till child
        vector<int> ptc = nodeToRootPath(child, data);
        if (ptc.size() > 0)
        {
            ptc.push_back(node->data);
            return ptc;
        }
    }

    vector<int> v;
    return v;
}

int lca(Node *node, int data1, int data2)
{
    vector<int> p1 = nodeToRootPath(node, data1);
    vector<int> p2 = nodeToRootPath(node, data2);

    int i = p1.size() - 1;
    int j = p2.size() - 1;
    while (i >= 0 && j >= 0 && p1[i] == p2[j])          //comparing paths to find common ancestor
    {
        i--;
        j--;
    }
    i++;                                               //to get last same ancestor
    j++;
    return p1[i];
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
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

    int data1;
    cin >> data1;
    int data2;
    cin >> data2;

    int Lca = lca(root, data1, data2);
    cout << Lca << endl;
}