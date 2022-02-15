#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


Node* construct(vector<int> & arr){
    Node* root=new Node(arr[0]);
    pair<Node*,int> p={root,1};

    stack<pair<Node*,int>> st;
    st.push(p);

    int idx=1;
    while(!st.empty()){
       
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*,int> rp={st.top().first->right,1};
                st.push(rp);
            } else {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else {
            st.pop();
        }

    }
    return root;
}

// int ans;
// int lca(Node* node, int d1, int d2){

// if(d1 < node->data && d2 < node->data){
//     return lca(node->left, d1, d2);
// } else if(d1 > node->data && d2 > node->data){
//     return lca(node->right, d1, d2);
// } else {
//     return node->data;
// }

// }


int lca(Node* node, int d1, int d2){
    if(d1<node->data && d2<node->data){
        return lca(node->left,d1,d2);
    }else if(d1>node->data && d2>node->data){
        return lca(node->right,d1,d2);
    }else{
        return node->data;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x=="n"){
            arr[i]=-1;

        }
        else{
            arr[i]=stoi(x);
        }
    }
    int d1,d2;
    cin >> d1 >> d2;
    Node* root = construct(arr);
    int res =  lca(root,d1,d2);
    cout<<res<<"\n";
    return 0;
    
}