#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int data;
       node *next;
};

node *front = NULL;
node *rear = NULL;

void insert()
{
     int no;
     node *temp = new node;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     temp->data = no;
     temp->next = NULL;
     if(rear == NULL)
     {
             front = temp;
             rear = temp;
     }
     else
     {
         rear->next = temp;
         rear = rear->next;
         rear->next = NULL;
     }
}

void del()
{
     if(front == NULL)
     {
              cout<<"\nQueue is empty. Underflow condition\n";
     }
     else
     {
         node *temp = front;
         temp = temp->next;
         delete front;
         front = temp;
         if(front == NULL)
         {
                  rear = NULL;
         }
     }
}

void display()
{
     node *temp = front;
     if(temp == NULL)
     {
             cout<<"\nThe queue is empty\n";
     }
     else
     {
         cout<<"\nThe current queue is: ";
         while(temp != NULL)
         {
                    cout<<temp->data<<" ";
                    temp = temp->next;
         }
     }
}


int main()
{
    int ch;
    ch =1;
    while(ch != 4)
    {
             cout<<"\n\nMAIN MENU\n";
             cout<<"1.INSERT\n";
             cout<<"2.DELETE\n";
             cout<<"3.DISPLAY\n";
             cout<<"4.EXIT\n\n";
             cout<<"Enter your choice\n";
             cin>>ch;
             switch(ch)
             {
                       case 1:
                            insert();
                            break;
                       case 2:
                            del();
                            break;
                       case 3:
                            display();
                            break;
                       case 4:
                            break;
                       default: cout<<"\nEnter a proper choice\n";
             }
    }
    getch();
    return 0;
}
