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

int calculateDiameter(Node *root,int &diameter){
    int dch=-1,sdch=-1;
    for(Node *child:root->children){
        int ht=calculateDiameter(child,diameter);
        if(ht>dch){
            sdch=dch;
            dch=ht;
        }else if(ht>sdch){
            sdch=ht;
        }
    }
    int cand=dch+sdch+2;
    if(cand>diameter)
    diameter=cand;
    return dch+1;
}
int main(){
    int n;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    Node *root=createGenericTree(treeInfo,n);
    int diameter=0;
    calculateDiameter(root,diameter);
    cout<<diameter;
}