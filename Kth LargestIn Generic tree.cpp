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

void getKthLargest(Node *root,priority_queue<int,vector<int>,greater<int>> &pq,int k){
    if(pq.size()<k)
    pq.push(root->data);
    else{
        if(root->data>pq.top()){
            pq.pop();
            pq.push(root->data);
        }
    }
    for(Node *child:root->children)
    getKthLargest(child,pq,k);
}

int main(){
    int n,k;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    Node *root=createGenericTree(treeInfo,n);
    cin>>k;
   priority_queue<int,vector<int>,greater<int>> pq;
    getKthLargest(root,pq,k);
    cout<<pq.top();
    
}