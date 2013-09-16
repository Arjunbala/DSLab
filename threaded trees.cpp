// in-threaded trees

#include<iostream>
#include<conio.h>

enum boolean
{
     not_threaded = 0;
     threaded = 1;
};

struct node 
{
       int data;
       node *left;
       node *right;
       enum boolean isleft;
       enum boolean isright;
};

node *head = NULL;

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
         head->data = -9999;
             
     }
}

void main()
{
     int ch =1;
     while(ch != 3)
     {
              cout<<"1.Insert\n";
              cout<<"2.Display\n";
              cout<<"3.Exit\n";
              cout<<"Enter your choice\n";
              cin>>ch;
              switch(ch)
              {
                        case 1: insert(head);
                                break;
                        case 2: display(head);
                                break;
                        case 3: break;
                        default: cout<<"Enter a valid choice \n";
              }
     }
     getch();
}

