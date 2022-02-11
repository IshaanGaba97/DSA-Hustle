#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

// complexity - O(n*n)
int diameter1(Node *node)
{
  if (node == NULL)
  {
    return 0;
  }
  // max distance between two nodes on lhs
  int ld = diameter1(node->left);
  // max distance between two nodes on rhs
  int rd = diameter1(node->right);
  // max distance between left deepest and right deepest
  int f = height(node->left) + height(node->right) + 2;
  // final dia is max of above three
  int dia = max(f, max(ld, rd));
  return dia;
}

// for dia and height in one function
class diaPair
{
public:
  int dia;
  int ht;
};

// complexity - O(n) - effective
diaPair diameter2(Node *node)
{
  if (node == nullptr)
  {
    diaPair bp; // basePair
    bp.ht = -1;
    bp.dia = 0;
    return bp;
  }
  diaPair lp = diameter2(node->left); // return dia and height
  diaPair rp = diameter2(node->right);

  diaPair mp;                    // maxPiar
  mp.ht = max(lp.ht, rp.ht) + 1; // maxHeight

  int fes = lp.ht + rp.ht + 2;            // farthestOnEitherSide
  mp.dia = max(fes, max(lp.dia, rp.dia)); // maxDia
  return mp;                              // return both dia and height
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

  // int dia = 0;
  // dia = diameter1(root);
  // cout<<dia;

  diaPair p = diameter2(root);
  cout << p.dia << endl;
}