#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}
static vector<int> path;
bool find(Node *node, int data)
{
    if (node == NULL)       
    {
        return false;
    }

    if (node->data == data)                   
    {
        path.push_back(node->data);        //add the node in path
        return true;
    }

    bool filc = find(node->left, data);    //left child return true and path then add node->data in path
    if (filc)
    {
        path.push_back(node->data);    
        return true;
    }

    bool firc = find(node->right, data);     //right child return true and path then add node->data in path
    if (firc)
    {
        path.push_back(node->data);
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }

    Node *root = constructTree(arr);
    int data;
    cin >> data;
    bool found = find(root, data);
    found == 1 ? cout << "true" << endl : cout << "false" << endl;
    cout << "[";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}