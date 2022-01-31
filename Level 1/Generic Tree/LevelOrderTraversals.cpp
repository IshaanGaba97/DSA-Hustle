#include<iostream>
#include<vector>
#include <stack>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>children;
};

void display(Node* node){
    string str = to_string(node->data) + " -> ";
    
    for(Node* child : node->children){
        str += to_string(child->data)+" , ";
    }
    str+= ".";
    cout<<str<<"\n";
    
    for(Node* child : node->children){
        display(child);
    }
}

int size(Node* node){
    int s = 0;
    
    for(Node* child : node->children){
        int cs = size(child);
        s = s + cs;
    }
    s = s + 1;
    return s;
}

//maximum = root, child 1, child 2, ...
int maximum(Node* node){
    int maxi = INT_MIN;
    for(Node* child : node->children){
        int cm = maximum(child);
        maxi = max(cm, maxi);
    }
    maxi = max(node->data, maxi);
    return maxi;
}


int height(Node* node){
    int ht = -1;               
    
    for(Node* child : node->children){
        int ch = height(child);
        ht = max(ht, ch);
    }
    ht = ht + 1;            
    return ht;
}

void traversals(Node* node){
    cout << "Node Pre " << node->data << endl;
    for(Node* child : node->children){
        cout << "Edge Pre " << node->data << "--"<< child->data<< endl;
        traversals(child);
        cout << "Edge Post " << node->data << "--"<< child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
}


//level order code
void levelOrder(Node* node){
    //rpa - remove print childrens add
    queue<Node*> q;
    q.push(node);
    
    while(q.size() > 0){
        node = q.front();
        q.pop();                              //remove
        cout << node->data << " ";            //print
        for(Node* child : node->children){    //child nodes push
            q.push(child);
        }
    }
    cout << ".";
}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    int* arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Node* root = NULL;
    stack<Node*> st ;
    
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node* t= new Node();
            t->data = arr[i];
            
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root = t;
            }
            st.push(t);
        }
    }
    levelOrder(root);
}