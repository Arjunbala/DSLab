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

void insert_begin()
{
     node *temp = new node;
     int no;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     temp->data = no;
     if(front == NULL)
     {
              temp->next = NULL;
              front = temp;
              rear = temp;
     }
     else
     {
         temp->next = front;
         front = temp;
     }
}

void insert_end()
{
     node *temp = new node;
     int no;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     temp->data = no;
     temp->next = NULL;
     if(rear == NULL)
     {
             rear = temp;
             front = temp;
     }
     else
     {
         rear->next=temp;
         rear = temp;
     }
}

void del_begin()
{
     node *temp = front;
     if(temp == NULL)
             cout<<"\nList is empty\n";
     else 
     {
          temp = temp->next;
          delete front;
          front = temp;
     }
}

void del_end()
{
     node *temp = front;
     node *prev = new node;
     if(temp == NULL)
             cout<<"\nList is empty\n";
     else
     {
         while(temp != rear)
         { 
         prev = temp;
         temp = temp->next;
         }
         delete temp;
         rear = prev;
         rear->next = NULL;
     }
}

void insert_after_index()
{
     node *temp = front;
     node *prev = new node;
     node *ins = new node;
     int index,no,i=0;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     cout<<"\nEnter the position after which it is to be inserted\n";
     cin>>index;
     ins->data = no;
     while(i != index)
     {
             prev = temp;
             temp = temp->next;
             if(prev == NULL)
             {
                     cout<<"\nIndex out of bounds\n";
                     return;
             }
             i++;
     }
     if(temp != NULL)
     {
      prev->next = ins;
      ins->next = temp;
     }
     else
     {
         prev->next = ins;
         ins->next = NULL;
     }
}

void insert_before_index()
{
}

void display()
{
     node *temp = front;
     if(temp == NULL)
     {
             cout<<"\nThe list is empty\n";
     }
     else
     {
         cout<<"\nThe current list is: ";
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
    while(ch != 10)
    {
             cout<<"\n\nMAIN MENU\n";
             cout<<"1.INSERT IN BEGINNING\n";
             cout<<"2.INSERT IN END\n";
             cout<<"3.INSERT AFTER POSITION\n";
             cout<<"4.INSERT BEFORE POSITION\n";
             cout<<"5.DELETE FROM BEGINNING\n";
             cout<<"6.DELETE FROM END\n";
             cout<<"7.DELETE PARTICULAR INDEX\n";
             cout<<"8.NUMBER OF NODES\n";
             cout<<"9.DISPLAY\n";
             cout<<"10.EXIT\n\n";
             cout<<"Enter your choice\n";
             cin>>ch;
             switch(ch)
             {
                       case 1:
                            insert_begin();
                            break;
                       case 2:
                            insert_end();
                            break;
                       case 3:
                            insert_after_index();
                            break;
                       case 4:
                            //insert_before_index();
                            break;
                       case 5:
                            del_begin();
                            break;
                       case 6:
                            del_end();
                            break;
                       case 7:
                            //delete_index();
                            break;
                       case 8:
                            //number_nodes();
                            break;
                       case 9:
                            display();
                            break;
                       case 10:
                            break;
                       default: cout<<"\nEnter a proper choice\n";
             }
    }
    getch();
    return 0;
}

