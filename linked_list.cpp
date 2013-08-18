#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int data;
       node *next;
};

node *head = (node*)malloc(sizeof(node));
node *list;

void insert_front()
{
     int no;
     node *temp = (node*)malloc(sizeof(node));
     cout<<"\nEnter the number"<<"\n";
     cin>>no;
     temp->data = no;
     temp->next = list;
     list = temp;
     head = list;
}

void insert_back()
{
     int no;
     node *temp;
     cout<<"\nEnter the number"<<"\n";
     cin>>no;
     temp = head;
     if(temp != NULL)
     {
             while(temp != NULL)
                        temp = temp->next;
     }
     
     temp = (node*)malloc(sizeof(node));
     temp->data = no;
     temp->next = NULL;
     list=list->next;
     list->next=temp;
     
}

void insert_pos_before()
{
     int pos,no,flag;
     flag =0;
     node *temp,*ins;
     cout<<"\nEnter the number"<<"\n";
     cin>>no;
     cout<<"Enter the index"<<"\n";
     cin>>pos;
     ins = (node*)malloc(sizeof(node));
     ins->data = no;
     temp = head;
     for(int i=0;i<pos-1;i++)
     {
             if(temp == NULL)
                 flag=1;
             else
                 temp = temp->next;
     }
    
     if(flag == 1)
        cout<<"Incorrect index"<<"\n";
     else
     {
         node *l = temp;
         l = l->next;
        temp->next = ins;
        ins->next = l;
        list = ins; 
     }
}

void insert_pos_after()
{
     int pos,no,flag;
     flag =0;
     node *temp,*ins;
     cout<<"\nEnter the number"<<"\n";
     cin>>no;
     cout<<"Enter the index"<<"\n";
     cin>>pos;
     ins = (node*)malloc(sizeof(node));
     ins->data = no;
     temp = head;
     for(int i=0;i<pos;i++)
     {
             if(temp == NULL)
                 flag=1;
             else
                 temp = temp->next;
     }
    
     if(flag == 1)
        cout<<"Incorrect index"<<"\n";
     else
     {
         node *l = temp;
         l = l->next;
        temp->next = ins;
        ins->next = l;
        list = ins; 
     }
}
     

void display()
{
     cout<<"\n";
     node *temp1 = (node*)malloc(sizeof(node));
     temp1 = head;
     while(temp1 != NULL)
     {
                 cout<<temp1->data<<" ";
                 temp1 = temp1->next;
     }
}

int main()
{
     int ch=1;
     head = list;
     while(ch != 6)
     {
              cout<<"\n\n1.Insert at front\n";
              cout<<"2.Insert at back\n";
              cout<<"3.Inserting element at a position before particular index\n";
              cout<<"4.Inserting element at a position after particular index\n";
              cout<<"5.Display\n";
              cout<<"6.Exit\n";
              cout<<"Enter your choice: ";
              cin>>ch;
              switch(ch)
              {
                        case 1:
                             insert_front();
                             break;
                        case 2:
                             insert_back();
                             break;
                        case 3:
                             insert_pos_before();
                             break;
                        case 4:
                             insert_pos_after();
                             break;
                        case 5:
                             display();
                             break;
                        
                             
                        case 6: break;
                        default: cout<<"\nEnter a valid choice"<<endl;
              }
     }
     getch();
     return 0;
}
     
