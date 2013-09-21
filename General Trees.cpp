#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct node
{
       char data;
       node *left;
       node *right;
       int level;
};

node *stack[100];
node *head = new node;
int top = -1;

void push(node *temp)
{
 top = top + 1;
 stack[top] = temp;     
}

node* pop()
{
 top = top - 1;
 return(stack[top+1]);     
}

int main()
{
    int ch = 1;
    int level;
    char data;
    head->data='\0';
    head->left = NULL;
    head->right = head;
    head->level = 0;
    node *pred;
    node *temp;
    push(head);
    while(ch != 2)
    {
             cout<<"Do you wish to insert?\n";
             cin>>ch;
             switch(ch)
             {
                       case 1: cout<<"Enter data in format: level character\n";
                               cin>>level>>data;
                               temp = new node;
                               temp->left = NULL;
                               temp->right = NULL;
                               temp->data = data;
                               temp->level = level;
                               pred = pop();
                               if(level > pred->level)
                               {
                                        pred->left = temp;
                               }
                               else
                               {
                                   while(pred->level > level)
                                   {
                                      pred = pop();
                                      if(pred->level < level)
                                      {
                                         cout<<"Mixed Level Numbers\n";
                                         exit(1);
                                      }
                                   }
                                   pred->right = temp;
                                   node *remove = pop();
                                   push(temp);
                               }
                               break;
                       case 2: cout<<"Going to results..\n\n";
             }
    }
    //display(root);
}
