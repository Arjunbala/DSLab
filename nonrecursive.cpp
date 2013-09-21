#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
     char data;
     node *left;
     node *right;
};
node *root = new node;

node *stack[100];
int top = -1;

void push(node *temp)
{
     top = top + 1;
     stack[top] = temp;
}

node* pop()
{
      if(top == -1)
      {
       top = -1;
       return NULL;
      }
      else
      top = top - 1;
     return stack[top+1];
}

node* peep()
{
      return stack[top];
}

void preorder()
{
     if(root == NULL)
     {
             cout<<"Tree is empty\n";
             return;
     }
     else
     {
         cout<<"Preorder: ";
         push(root);
         while(top > -1)
         {
                   node *temp = pop();
                   while(temp != NULL)
                   {
                        cout<<temp->data<<" ";
                        if(temp->right != NULL)
                        {
                             push(temp->right);          
                        }      
                        temp = temp->left;
                   }
         }
     }
}

void postorder()
{
     cout<<"\n";
     if(root == NULL)
     {
             cout<<"Tree is empty\n";
             return;
     }
     else
     {
          cout<<"Postorder: ";
         node *temp = root;
         top = -1;
         while(1)
         {
                 while(temp != NULL)
                 {
                            if(temp->right != NULL)
                               push(temp->right);
                            push(temp);
                            temp = temp->left;
                 }
                 temp = pop();
                 if((temp->right != NULL)&&(temp->right == peep()))
                 {
                                 node *remove = pop();
                                 push(temp);
                                 temp = temp->right;
                 }
                 else
                 {
                     cout<<temp->data<<" ";
                     temp = NULL;
                     if(top == -1)
                        return;
                 }
                 
         }
     }
}

void inorder()
{
     cout<<"\n";
     if(root == NULL)
     {
             cout<<"Tree is empty\n";
             return ;
     }
     else
     {
          cout<<"Inorder: ";
         top = -1;
         node *current = root;
         while(1)
         {
         if(current != NULL)
         {
            push(current);
            current = current->left;
         }
     
         if((current == NULL)&&(top > -1))                      
         {
          current = pop();
          cout<<current->data<<" ";
         current = current->right;
         }
         else if ((current == NULL)&&(top == -1))
         {
              return;
         }
         }
     }
}

node* add_node(char info)
{
      node *temp = new node;
      temp->data = info;
      temp->left = NULL;
      temp->right = NULL;
      return temp;
}

int main()
{
    root->data = '*';
    root->left = add_node('+');
    root->right = add_node('*');
    (root->left)->left = add_node('a');
    (root->left)->right = add_node('-');
    (root->right)->left = add_node('e');
    (root->right)->right = add_node('+');
    ((root->left)->right)->left = add_node('-');
    ((root->left)->right)->right = add_node('d');
    (((root->left)->right)->left)->left = add_node('b');
    (((root->left)->right)->left)->right = add_node('c');
    ((root->right)->right)->left = add_node('f');
    ((root->right)->right)->right = add_node('g');
    preorder();
    postorder();
    inorder();
    getch();
    return 0;
}
