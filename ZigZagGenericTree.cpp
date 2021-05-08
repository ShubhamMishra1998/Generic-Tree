#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*> children;
    Node(int val){
       data=val;
    }
};
Node *createGenericTree(vector<int> &treeInfo,int n){
    stack<Node*> st;
    Node *root=new Node(-1);
    for(int i=0;i<n;i++){
        if(treeInfo[i]==-1)
        st.pop();
        else{
            Node *temp=new Node(treeInfo[i]);
            if(!st.empty()){
               st.top()->children.push_back(temp);
            }else{
                root=temp;
            }
            st.push(temp);

        }
    }
    return root;
}

void ZigZagLineWise(Node *root){
   stack<Node*> st1,st2;
   st1.push(root);
   while(st1.size()>0||st2.size()>0){
       
       while(st1.size()>0){
           Node *temp=st1.top();
           st1.pop();
           cout<<temp->data<<' ';
           for(int i=0;i<temp->children.size();i++)
           st2.push(temp->children[i]);
       }
       cout<<endl;
       while(st2.size()>0){
           Node *temp=st2.top();
           st2.pop();
           cout<<temp->data<<' ';
           for(int i=temp->children.size()-1;i>=0;i--)
           st1.push(temp->children[i]);
       }
       cout<<endl;
       
   }
}
int main(){
    int n;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    Node *root=createGenericTree(treeInfo,n);
    ZigZagLineWise(root);
}