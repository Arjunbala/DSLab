#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int data;
       node *next;
};

node *top = NULL;

void push()
{
     node *temp = new node;
     int no;
     cout<<"\nEnter the number to be pushed\n";
     cin>>no;
     temp->data=no;
     temp->next = top;
     top = temp;
     
}

void pop()
{
     if(top == NULL)
            cout<<"\nThe stack is empty. Underflow condition\n";
     else
     {
         node *temp = top;
         temp = temp->next;
         delete top;
         top = temp;
     }
}

void display()
{
     node *temp = new node;
     temp = top;
     if(temp == NULL)
     {
             cout<<"\nThe stack is empty\n";
     }
     else
     {
     cout<<"\nThe contents of the stack are:\n";
     while(temp != NULL)
     {
                cout<<temp->data<<"\n";
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
             cout<<"\nMAIN MENU\n";
             cout<<"1.PUSH\n";
             cout<<"2.POP\n";
             cout<<"3.DISPLAY\n";
             cout<<"4.EXIT\n\n";
             cout<<"Enter your choice\n";
             cin>>ch;
             switch(ch)
             {
                       case 1:
                            push();
                            break;
                       case 2:
                            pop();
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
