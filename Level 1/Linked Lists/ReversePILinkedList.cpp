#include<iostream>
#include <sstream> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    int sizee;
    
    LinkedList(){
        head=NULL;
        tail = NULL;
        sizee = 0;
    }

    void addLast(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;
        
        if(sizee==0){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail=temp;
        }
        sizee++;
    }
    int size(){
        return sizee;
    }
    void display(){
      for (Node* temp = head; temp != NULL; temp = temp->next) {
            cout<<temp->data<<" ";
        }  
        cout<<"\n";
    }
    void removeFirst() {
        if(head==NULL){
            cout<< "List is empty"<<"\n";
        }else if(sizee==1){
            head=NULL;
            tail=NULL;
            sizee--;
        }else{
            Node* ptr = head;
            head= ptr->next;
            ptr->next=NULL;
            ptr = NULL;
            sizee--;
        }
    }
    
    int getFirst() {
        if(head==NULL){
            cout<<"List is empty"<<"\n";
            return -1;
        }else{
           Node* ptr;
           ptr = head;
           return ptr->data;
        }
    }

    int getLast() {
           if(tail==NULL){
            cout<<"List is empty"<<"\n";
            return -1;
        }else{
           Node* ptr;
           ptr = tail;
           return ptr->data;
        } 
    }

    int getAt(int idx) {
        if(sizee==0){
            cout<<"List is empty"<<"\n";
            return -1;
        }else if(idx<0 || idx>=sizee){
            cout<<"Invalid arguments"<<"\n";
            return -1;
        }else{
            Node* ptr;
           ptr = head;
           int i =0;
           while(ptr!=NULL){
               if(i==idx){
                   return ptr->data;
               }
               ptr=ptr->next;
               i++;
           }
        }
    }
    
    
    void addFirst(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;
        
        if(sizee==0){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head= temp;
        }
        sizee++;
    }
    
    void addAt(int idx, int val) {
        if(idx<0 || idx>sizee){
            cout<<"Invalid arguments"<<"\n";
        }else if(idx==0){
            addFirst(val);
        }else if(idx==sizee){
            addLast(val);
        }else{
           Node* node = new Node();
           node->data = val;
           node->next = NULL;
           
           Node* temp = head;
           for(int i=0;i<idx-1;i++){
               temp = temp->next;
           }
           node->next = temp->next;
           temp->next = node;
           
           sizee++;
        }
    }
    void removeLast() {
            if(sizee==0){
                cout<<"List is empty"<<"\n";
            }else if(sizee==1){
                head=NULL;
                tail=NULL;
                sizee--;
            }else{
                Node*pre = NULL;
                Node*post;
                post=head;
                while(post->next!=NULL){
                    pre=post;
                    post=post->next;
                }
                tail=pre;
                tail->next=NULL;
                pre=NULL;
                post=NULL;
                sizee--;
            }
    }
    void removeAt(int idx) {
        if(idx<0 || idx>=sizee){
            cout<<"Invalid arguments"<<"\n";
        }else if(idx==0){
            removeFirst();
        }else if(idx==sizee-1){
            removeLast();
        }else{
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                    temp=temp->next;
                }
            
            temp->next = temp->next->next;
            sizee--;
        }
    }
    
    
   Node* getNodeAt(int idx){
            Node* temp = head;
            for(int i=0;i<idx;i++){
                    temp=temp->next;
                }
                return temp;
   } 
   
    void reversePI() {
        Node*  prev = NULL;
        Node*  curr = head;
        
        while(curr!=NULL){
            Node* nextToCurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextToCurr;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }
    
};

int main(){
    LinkedList list;
    string str;
    getline(cin,str);
   // cout<<"string"<<str<<"";
    while (str.compare("quit") != 0){
        istringstream ss(str);
        
        string a[3];
        string word;
        int i=0;
        while(ss>>word){
            a[i]=word;
            i++;
        }
       
        istringstream sv(a[1]);
        istringstream svv(a[2]);
        if(a[0].compare("addLast")==0){
            int val;
            sv>>val;
            list.addLast(val);
        }else if(a[0].compare("size")==0){
            int val=list.size();
            cout<<val<<"\n";
        }else if(a[0].compare("display")==0){
            list.display();
        }else if(a[0].compare("removeFirst")==0){
            list.removeFirst();
        }else if(a[0].compare("getFirst")==0){
            int val = list.getFirst();
            if(val !=-1){
                cout<<val<<"\n";
            }
        }else if(a[0].compare("getLast")==0){
            int val = list.getLast();
            if(val !=-1){
                cout<<val<<"\n";
            }
        }else if(a[0].compare("getAt")==0){
            int idx;
            sv>>idx;
            int val = list.getAt(idx);
            if(val !=-1){
                cout<<val<<"\n";
            }
        }else if(a[0].compare("addFirst")==0){
            int val;
            sv>>val;
            list.addFirst(val);
        }else if(a[0].compare("addAt")==0){
            int idx,val;
            sv>>idx;
            svv>>val;
            list.addAt(idx,val);
        }else if(a[0].compare("removeLast")==0){
            list.removeLast();
        }else if(a[0].compare("removeAt")==0){
            int idx;
            sv>>idx;
            list.removeAt(idx);
        }else if(a[0].compare("reversePI")==0){
            list.reversePI();
        }
        getline(cin,str);
    }
    
    return 0;
}