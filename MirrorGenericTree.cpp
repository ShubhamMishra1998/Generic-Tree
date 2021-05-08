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

void  MirrorGenericTree(Node *root){
  for(Node *child:root->children){
      MirrorGenericTree(child);
  }
  reverse(root->children.begin(),root->children.end());
  //return root;
}
void print(Node *root){
    cout<<root->data<<" -> ";
    for(Node *child:root->children)
    cout<<child->data<<", ";
    cout<<"."<<endl;
}
void printNodes(Node *root){
    print(root);
    for(Node *child:root->children){
        printNodes(child);
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
    printNodes(root);
    MirrorGenericTree(root);
    printNodes(root);
}