#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int x)
  {
    data=x;
    left=NULL;
    right=NULL;
  }
};
typedef struct Node* np;
np root = NULL;
void Insert(np temp,int x)
{
  if(temp==NULL)
  {
      root=new Node(x);
      return;
  }

  if(x<temp->data)
  {
    if(temp->left==NULL)
    {
    temp->left=new Node(x);
    return;
    }
    else
    Insert(temp->left,x);
  }
  else
  {
    if(temp->right==NULL)
    {
      temp->right= new Node(x);
      return;
    }
    else
    Insert(temp->right,x);
  }
}
np find_min(np node)
{
  np c_node=node;
  while(c_node && c_node->left!=NULL)
  c_node=c_node->left;
  return c_node;
}
np delete_value(np root,int x)
{
  if(root==NULL)
  return root;
  if(x<root->data)
    root->left = delete_value(root->left,x);
  else if(x>root->data)
    root->right = delete_value(root->right,x);
  else
  {
    if(root->left==NULL)
    {
      np temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL)
    {
      np temp=root->left;
      free(root);
      return temp;
    }
    np temp=find_min(root->right);
    root->data=temp->data;
    root->right=delete_value(root->right,temp->data);
  }
  return root;
}
bool search_elemnt(np temp,int val)
{
  if(temp==NULL)
  return false;
  if(val==temp->data)
  return true;
  if(val<temp->data)
   return search_elemnt(temp->left,val);
  else
  return search_elemnt(temp->right,val);
}
void Inorder(np temp)
{
  if(temp==NULL)
  return;
  else
  {
    Inorder(temp->left);
    cout<<" "<<temp->data;
    Inorder(temp->right);
  }
}
void leve_order(np temp)
{
  if(temp==NULL)
  return;
  queue<np> q;
  q.push(temp);
  while(!q.empty())
  {
    np node =q.front();
    cout<<" "<<node->data;
    q.pop();
    if(node->left!=NULL)
    q.push(node->left);
    if(node->right!=NULL)
    q.push(node->right);
  }
}
int Height_of_bst(np temp)
{
  if(temp==NULL)
  return 0;
  else
  {
    int l=Height_of_bst(temp->left);
    int r=Height_of_bst(temp->right);
    if(l>r)
    return l+1;
    else
    return r+1;
  }
}
int main()
{
  Insert(root,8);
  Insert(root,3);
  Insert(root,10);
  Insert(root,1);
  Insert(root,6);
  Insert(root,4);
  Insert(root,7);
  Insert(root,14);
  cout<<"Inorder: ";
  Inorder(root);
  cout<<"\nHeight of tree:"<<Height_of_bst(root);
  //cout<<"\nLevel order traversal:";
  //leve_order(root);
  //if(search_elemnt(root,23))
  //cout<<"\nfound";
  //else
//  cout<<"\nNot found";
  //root=delete_value(root,6);
  //cout<<"\nInorder:";
  //Inorder(root);
  return 0;
}
