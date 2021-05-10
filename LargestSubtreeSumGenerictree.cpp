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

int findLargestSumSubtree(Node *root,int &node,int &Sum){
    int sum=0;
    for(Node *child:root->children){
        sum+=findLargestSumSubtree(child,node,Sum);
    }
    sum+=root->data;
    if(sum>Sum){
        Sum=sum;
        node=root->data;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> treeInfo(n);
    for(int i=0;i<n;i++){
        cin>>treeInfo[i];
    }
    Node *root=createGenericTree(treeInfo,n);
    int node,sum=INT_MIN;
    findLargestSumSubtree(root,node,sum);
    cout<<node<<"@"<<sum;
    
}