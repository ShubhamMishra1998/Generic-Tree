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

vector<int> RootToNodePath(Node *root,int data){
   if(root->data==data){
       vector<int> list;
       list.push_back(data);
       return list;
   }
   for(Node *child:root->children){
       vector<int> res=RootToNodePath(child,data);
       if(res.size()>0){
           res.push_back(root->data);
           return  res;
       }
   }
   vector<int> v1;
   return v1;
}
int main(){
    int n,node1,node2;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    cin>>node1>>node2;
    Node *root=createGenericTree(treeInfo,n);
    vector<int> path1=RootToNodePath(root,node1);
    vector<int> path2=RootToNodePath(root,node2);
    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());
    int n1=min(path1.size(),path2.size());
    int prev=0;
    for(int i=0;i<n1;i++){
        if(path1[i]!=path2[i])
        break;
        prev=path1[i];
    }
    
    cout<<prev;
}