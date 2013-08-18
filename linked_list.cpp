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

void del_front()
{
     node *temp = (node*)malloc(sizeof(node));
      temp = head;
     head = temp->next;
     free(temp);
}

void del_back()
{
     
node *temp1;
temp1 = (node*)malloc(sizeof(node)); 
temp1 = head;                        
node *old_temp;                     
old_temp = (node*)malloc(sizeof(node));    
 
while(temp1->next!=NULL)            
{
      old_temp = temp1; 
      temp1 = temp1->next;       
}
old_temp->next = NULL;         
free(temp1);
}

void del_index()
{    int pos;
     node *temp1;
     temp1=(node*)malloc(sizeof(node));
     temp1=head;
      node *old;
     old=(node*)malloc(sizeof(node));
     old=temp1;
     cout<<"Enter the index to be deleted"<<"\n";
     cin>>pos;
     for( int i = 1 ; i < pos ; i++ )
{
      old= temp1;                    
      temp1 = temp1->next;                 
 
}

old->next = temp1->next;  
free(temp1);
     
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
     while(ch != 9)
     {
              cout<<"\n\n1.Insert at front\n";
              cout<<"2.Insert at back\n";
              cout<<"3.Inserting element at a position before particular index\n";
              cout<<"4.Inserting element at a position after particular index\n";
              cout<<"5.Delete from front\n";
              cout<<"6.Delete from back\n";
              cout<<"7.Delete element from particular index\n";
              cout<<"8.Display\n";
              cout<<"9.Exit\n";
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
                             del_front();
                             break;
                        case 6:
                             del_back();
                             break;
                        case 7:
                             del_index();
                             break;
                        case 8:
                             display();
                             break;
                        
                             
                        case 9: break;
                        default: cout<<"\nEnter a valid choice"<<endl;
              }
     }
     getch();
     return 0;
}
     
