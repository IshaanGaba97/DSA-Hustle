#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>
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

Node *construct(vector<int> &arr)
{
  Node *root = new Node(arr[0]);
  pair<Node *, int> p = {root, 1};

  stack<pair<Node *, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty())
  {
    if (st.top().second == 1)
    {
      st.top().second++;
      if (arr[idx] != -1)
      {
        st.top().first->left = new Node(arr[idx]);
        pair<Node *, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else
      {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2)
    {
      st.top().second++;
      if (arr[idx] != -1)
      {
        st.top().first->right = new Node(arr[idx]);
        pair<Node *, int> rp = {st.top().first->right, 1};
        st.push(rp);
      }
      else
      {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else
    {
      st.pop();
    }
  }
  return root;
}

void iterativePrePostInTraversal(Node *node)
{
  // write your code here
  stack<Pair *> st;
  Pair *rtp = new Pair(node, 1);
  st.push(rtp);

  string pre = "";
  string in = "";
  string post = "";
  while (st.size() > 0)
  {
    Pair *peek = st.top();
    if (peek->state == 1)
    { // pre print, s++, left
      pre += to_string(peek->node->data) + " ";
      peek->state++;

      if (peek->node->left != NULL)
      {
        Pair *lp = new Pair(peek->node->left, 1);
        st.push(lp);
      }
    }
    else if (peek->state == 2)
    { // in print, s++, right
      in += to_string(peek->node->data) + " ";
      peek->state++;

      if (peek->node->right != NULL)
      {
        Pair *rp = new Pair(peek->node->right, 1);
        st.push(rp);
      }
    }
    else
    { // post print, pop
      post += to_string(peek->node->data) + " ";
      st.pop();
    }
  }
  cout << pre << "\n"
       << in << "\n"
       << post << "\n";
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
  Node *root = construct(arr);
  iterativePrePostInTraversal(root);
}