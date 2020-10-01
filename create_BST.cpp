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
np root =NULL;
void insert(np temp, int x)
{
  if(temp==NULL)
  {
    root= new Node(x);
    return;
  }
  if(x<temp->data)
  {
    if(temp->left==NULL)
    {
    temp->left = new Node(x);
    return;
     }
     else
     insert(temp->left,x);
  }
  else
  {
    if(temp->right==NULL)
    {
      temp->right = new Node(x);
      return;
    }
    else
    insert(temp->right,x);
  }
}
np min_value(np node)
{
  np c_node = node;
  while(c_node && c_node->left!=NULL)
  c_node=c_node->left;
  return c_node;
}
np delete_value(np root,int x)
{
  if(root==NULL)
  return root;
  if(x < root->data)
  root->left = delete_value(root->left,x);
  else if(x > root->data)
  root->right =delete_value(root->right,x);
  else
  {
    if(root->left==NULL)
      {
         np temp = root->right;
         free(root);
         return temp;
      }
    else if(root->right==NULL)
    {
      np temp = root->left;
      free(root);
      return temp;
    }
    np temp = min_value(root->right);
    root->data=temp->data;
    root->right = delete_value(root->right,temp->data);
  }
  return root;
}
void inorder(np temp)
{
  if(temp==NULL)
  return;
  else
  {
  inorder(temp->left);
  cout<<" "<<temp->data;
  inorder(temp->right);
   }
}
void preorder(np temp)
{
  if(temp==NULL)
  return;
  else
  {
    cout<<" "<<temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}
void postorder(np temp)
{
  if(temp==NULL)
  return;
  else
  {
    postorder(temp->left);
    postorder(temp->right);
    cout<<" "<<temp->data;
  }
}
int main()
{
  //root= new Node(5);
  insert(root,8);
  insert(root,3);
  insert(root,10);
  insert(root,1);
  insert(root,6);
  insert(root,4);
  insert(root,7);
  insert(root,14);
  cout<<"Inorder: ";
  inorder(root);
  root = delete_value(root,4);
  cout<<"\n";
    inorder(root);
  // cout<<"Preorder: ";
  // preorder(root);
  // cout<<"\nPostorder:";
  // postorder(root);

  // cout<<root->data;

  return 0;
}
