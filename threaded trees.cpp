// in-threaded trees
using namespace std;


#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>
#include<deque>
#include<sstream>
#include<math.h>

enum status
{
      structural = 0,threaded
};

struct node 
{
       int data;
       node *left;
       node *right;
       enum status isleft;
       enum status isright;
};

node *phead = NULL;

void insert(node *head)
{
     int no;
     cout<<"Enter the number to be inserted\n";
     cin>>no;
     node *ins = new node;
     ins->data = no;
     ins->isleft = threaded;
     ins->isright = threaded;
     if(head == NULL) // tree empty in this case
     {
         node *s = new node;    
         s->data = 0;
         s->left = ins;
         s->right = head;
         s->isleft = structural;
         s->isright = structural;
         ins->left = s;
         ins->right = s;
         phead = s;
         return;
     }
     else
     {
         node *p = head->left;
         while(p != head)
         {
          if(no < p->data)
          {
               if(p->isleft == structural)
               {
                            p = p->left;
               }
               else if(p->isleft == threaded)
               {
                    ins->left = p->left;
                    p->left = ins;
                    p->isleft = structural;
                    ins->right = p;
                    return;
               }
          }
          else if(no > p->data)
          {
               if(p->isright == structural)
               {
                  p = p->right;
               }
               else if (p->isright == threaded)
               {
                    ins->right = p->right;
                    p->right = ins;
                    p->isright = structural;
                    ins->left = p;
                    return;
               }
          }
         }
     }
}




void tree_disp(node *p)
{

     if(p->isleft == structural)
     {
                  tree_disp(p->left);
     }
     cout<<p->data<<" ";
     if(p->isright == structural)
     {
                   tree_disp(p->right);
     } 
}

void display(node *head)
{
     if(head == NULL)
     {
             cout<<"Tree is empty\n";
             return;
     }
     else
     {
         cout<<"\n\nCurrent tree: ";
         node *p = head->left;
         tree_disp(p);
     }
}

int main()
{
     int ch =1;
     while(ch != 3)
     {
              cout<<"\n\n";
              cout<<"1.Insert\n";
              cout<<"2.Display\n";
              cout<<"3.Exit\n";
              cout<<"Enter your choice\n";
              cin>>ch;
              switch(ch)
              {
                        case 1: insert(phead);
                                break;
                        case 2: display(phead);
                                break;
                        case 3: break;
                        default: cout<<"Enter a valid choice \n";
              }
     }
     getch();
     return 0;
}

