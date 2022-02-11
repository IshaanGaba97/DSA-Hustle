#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:
    int data = 0;
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

// Display function
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

// Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bstPair
{
public:
    bool isBST;
    int mini;
    int maxi;
};

bstPair *Bst(Node *node)
{
    if (node == NULL)
    {
        bstPair *bp = new bstPair();
        bp->mini = INT_MAX;
        bp->maxi = INT_MIN;
        bp->isBST = true;
        return bp;
    }

    bstPair *lp = Bst(node->left);
    bstPair *rp = Bst(node->right);
    bstPair *mp = new bstPair();
    if (lp->isBST && rp->isBST && (node->data >= lp->maxi && node->data <= rp->mini))
    {
        mp->isBST = true;
    }
    else
    {
        mp->isBST = false;
    }
    mp->mini = min(node->data, min(rp->mini, lp->mini));
    mp->maxi = max(node->data, max(rp->maxi, lp->maxi));
    return mp;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(tmp);
        }
    }

    Node *root = constructTree(arr);

    bstPair *r = Bst(root);
    if (r->isBST == 1)
        cout << "true";
    else
        cout << "false";
}