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
node *temp1;
cout<<"Enter the number to be inserted\n";
cin>>no;                         
temp1=(node*)malloc(sizeof(node));  
temp1 = head;                  
while(temp1->next!=NULL) 
      temp1 = temp1->next;
node *temp;                           
temp = (node*)malloc(sizeof(node));  
temp->data = no;                   
temp->next = NULL;                  
temp1->next = temp;                  
     
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

void no_nodes()
{
     int n=0;
     if(head == NULL)
             cout<<"No nodes \n";
     else
     {
         node *temp;
         temp =(node*)malloc(sizeof(node));
         temp = head;
         while(temp->next !=NULL)
         { 
             n++;
             temp = temp->next;
         }   
         n=n+1;
         cout<<"Number of nodes is "<<n<<"\n";
     }
}

void split()
{
     int pos,i;
     cout<<"Enter the position where you want to split\n";
     cin>>pos;
     node *list1 = (node*)malloc(sizeof(node));
     node *list2 = (node*)malloc(sizeof(node));
     node *temp1 = (node*)malloc(sizeof(node));
     node *head1 = (node*)malloc(sizeof(node));
     node *head2 = (node*)malloc(sizeof(node));
     head1 = list1;
     head2 = list2;
     temp1 = head;
     i=0;
     while(temp1 != NULL)
     {
       if(i<=pos)
       {
                 cout<<i;
                  
                 list1 = list1->next;
                 node *temp;                           
                 temp = (node*)malloc(sizeof(node));  
                 temp->data = temp1->data;                   
                 temp->next = NULL;                  
                 list1->next = temp; 
       }
       else
       {
           
                 list2 = list1->next;
                 node *temp;                           
                 temp = (node*)malloc(sizeof(node));  
                 temp->data = temp1->data;                   
                 temp->next = NULL;                  
                 list2->next = temp; 
       }
        i=i+1;                       
        temp1 = temp1->next;
     }     
     cout<<"\n";
     node *temp5 = (node*)malloc(sizeof(node));
     temp5 = head1;
     while(temp5 != NULL)
     {
                 cout<<temp5->data<<" ";
                 temp5 = temp5->next;
     }
     cout<<"\n";
     node *temp6 = (node*)malloc(sizeof(node));
     temp6 = head2;
     while(temp6 != NULL)
     {
                 cout<<temp6->data<<" ";
                 temp6 = temp6->next;
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
     while(ch != 11)
     {
              cout<<"\n\n1.Insert at front\n";
              cout<<"2.Insert at back\n";
              cout<<"3.Inserting element at a position before particular index\n";
              cout<<"4.Inserting element at a position after particular index\n";
              cout<<"5.Delete from front\n";
              cout<<"6.Delete from back\n";
              cout<<"7.Delete element from particular index\n";
              cout<<"8.Number of nodes\n";
              cout<<"9.Split\n";
              cout<<"10.Display\n";
              cout<<"11.Exit\n";
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
                             no_nodes();
                             break;
                        case 9:
                             split();
                             break;
                        
                        case 10:
                             display();
                             break;     
                        case 11: break;
                        default: cout<<"\nEnter a valid choice"<<endl;
              }
     }
     getch();
     return 0;
}
     
