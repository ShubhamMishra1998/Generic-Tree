#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  vector<Node*> children;
};
Node *Insert(vector<int> &v1,int n)
{
  Node *root=NULL;
  stack<Node*> st;
  for(int i=0;i<n;i++)
  {
    if(st.empty())
    {
      Node *temp=new Node();
      temp->data=v1[i];
      st.push(temp);
      root=temp;
    }
    else if(v1[i]==-1)
    st.pop();
    else
    {
      Node *temp=new Node();
      temp->data=v1[i];
      st.top()->children.push_back(temp);
      st.push(temp);
    }
  }
  return root;
}
void print(Node *root)
{
  if(!root)return;
  cout<<root->data<<"  ";
  for(int i=0;i<root->children.size();i++)
  cout<<root->children[i]->data<<' ';
  cout<<endl;

  for(int i=0;i<root->children.size();i++)
  print(root->children[i]);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    vector<int> v1;
    int x,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>x;
      v1.push_back(x);
    }
    Node *root=NULL;
    root=Insert(v1,v1.size());
    print(root);

  }
}
