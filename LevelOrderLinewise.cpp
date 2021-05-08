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

void levelOrderLineWise(Node *root){
   queue<Node*> q1;
   q1.push(root);
   while(!q1.empty()){
       int c=q1.size();
       while(c--){
       Node *temp=q1.front();
       q1.pop();
       cout<<temp->data<<' ';
       for(Node *x:temp->children)
       q1.push(x);
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
    levelOrderLineWise(root);
}