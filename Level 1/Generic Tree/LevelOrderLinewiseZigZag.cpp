#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
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

void levelOrder(Node* node){
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

void levelorderlinewise(Node* node){
    queue<Node*> mq;
    mq.push(node);
    queue<Node*> cq;
    queue<Node*> q;
    while(mq.size() > 0){
        node = mq.front();
        mq.pop();
        cout << node->data << " ";
        
        for(Node* child : node->children){
            cq.push(child);
        }
        if(mq.size() == 0){
            mq = cq;
            cq = q;
            cout << endl;
        }
    }
}

//zigzag
void levelorderlinewiseZZ(Node* node){
    //stack will store the children in same order as parents and when popped out the order is unique
    stack<Node*> ms;   
    ms.push(node);
    stack<Node*> cs;
    stack<Node*> s;
    int level = 1;
    while(ms.size() > 0){
        node = ms.top();
        ms.pop();
        cout << node->data << " ";
        if(level%2 == 1){
            for(int i = 0; i < node->children.size(); i++){
                Node* child = node->children[i];
                cs.push(child);
            }
        } else {
            for(int i = node->children.size() - 1; i >= 0; i--){
                Node* child = node->children[i];
                cs.push(child);
            }
        }
        if(ms.size() == 0){
            ms = cs;
            cs = s;
            level++;
            cout << endl;
        }
    }
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
    levelorderlinewiseZZ(root);
}