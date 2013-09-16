#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int data;
       node *left;
       node *right;
}*root,*current,*prev;
root = NULL;
prev = NULL;
current = NULL;

void insert()
{
   node *temp = new node;
   int data;
   cout<<"Enter the number to be inserted\n";
   cin>>data;
   if(root == NULL)
   {
           temp->left = NULL;
           temp->right = NULL;
           root = temp;
           prev = temp;
   }  
   else
   {
       if(prev->left == NULL)
       {
                     
       }
   }
}

void main()
{
     insert();
     getch();
}
