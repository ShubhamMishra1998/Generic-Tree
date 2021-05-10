#include<bits/stdc++.h>
using namespace std;
int Ceil=0;
int Floor=0;
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

void getCeilAndFloor(Node *root,int data){
    if(root->data>data){
        Ceil=min(Ceil,root->data);
    }
    if(root->data<data){
        Floor=max(Floor,root->data);
    }
    for(Node *child:root->children)
    getCeilAndFloor(child,data);

}
int main(){
    int n,val;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    Node *root=createGenericTree(treeInfo,n);
    cin>>val;
    Ceil=INT_MAX;
    Floor=INT_MIN;
    getCeilAndFloor(root,val);
    cout<<"CEIL = "<<Ceil<<endl;
    cout<<"FLOOR = "<<Floor<<endl;
}