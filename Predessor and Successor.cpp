#include<bits/stdc++.h>
using namespace std;
int predecessor;
int successor;
int flag;
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

void getPredessorAndSuccessor(Node *root,int data){
    if(flag==1){
        successor=root->data;
        flag++;
    }
    else if(root->data==data){
        flag=1;
    }
    else if(flag==0)
    predecessor=root->data;
    for(Node *child:root->children)
    getPredessorAndSuccessor(child,data);

}
int main(){
    int n,val;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    predecessor=INT_MAX;
    successor=INT_MAX;
    flag=0;
    Node *root=createGenericTree(treeInfo,n);
    cin>>val;
    getPredessorAndSuccessor(root,val);
    if(predecessor!=INT_MAX)
    cout<<"Predecessor = "<<predecessor<<endl;
    else
    cout<<"Predecessor = Not found"<<endl;
    if(successor!=INT_MAX)
    cout<<"Successor = "<<successor<<endl;
    else
    cout<<"Successor = Not found"<<endl;

}