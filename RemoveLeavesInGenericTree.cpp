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

void removeLeaves(Node *root){
    for(int i=root->children.size()-1;i>=0;i--){
      Node *child=root->children[i];
      if(child->children.size()==0)
      root->children.erase(root->children.begin()+i);
  }
  for(Node *child:root->children){
      removeLeaves(child);
  }
  
}
void print(Node *root){
    cout<<root->data<<" -> ";
    for(Node *child:root->children)
    cout<<child->data<<", ";
    cout<<"."<<endl;
}
void printNodes(Node *root){
    //cout<<root->children.size()<<' ';
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
    removeLeaves(root);
    printNodes(root);
}