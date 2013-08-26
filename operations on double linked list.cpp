#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int data;
       node *left;
       node *right;
};

node *front = NULL;
node *rear = NULL;

node *frontsplit1 = NULL;
node *frontsplit2 = NULL;
node *frontmerge = NULL;
node *rearsplit1 = NULL;
node *rearsplit2 = NULL;
node *rearmerge = NULL;

void insert_begin()
{
     int no;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     node *temp = new node;
     temp->data = no;
     if(front == NULL)
     {
              temp->left = NULL;
              temp->right = NULL;
              front = temp;
              rear = temp;
     }
     else
     {
         temp->right = front;
         temp->left = NULL;
         front = temp;
     }
}

void insert_end()
{
     int no;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     node *temp = new node;
     temp->data = no;
     if(rear == NULL)
     {
             temp->left = NULL;
             temp->right = NULL;
             front = temp;
             rear = temp;
     }
     else
     {
         temp->left = rear;
         temp->right = NULL;
         rear->right = temp;
         rear = temp;
     }
}

void insert_after_index()
{
     int no,pos;
     cout<<"\nEnter the number to be inserted\n";
     cin>>no;
     cout<<"\nEnter the position after which it is to be inserted\n";
     cin>>pos;
     int i=0;
     node *temp = front;
     node *prev = front;
     node *ins = new node;
     ins->data = no;
     while(i != pos)
     {
             prev = temp;
             temp = temp->right;
             if(prev == NULL)
             {
                     cout<<"\nIndex out of bounds\n";
                     return;
             }
             i++;
     }
     if(temp == NULL)
     {
             rear->right = ins;
             ins->right = NULL;
             rear = ins;
     }
     else
     {
         ins->right = temp;
         prev->right = ins;
     }
}

void insert_before_index()
{
     int no,pos,i=0;
     cout<<"\nEnter the element to be inserted\n";
     cin>>no;
     cout<<"\nEnter the position before which it is to be inserted\n";
     cin>>pos;
     node *temp = front;
     node *prev = front;
     node *ins = new node;
     ins->data = no;
     if(pos == 1)
     cout<<"\nIndex out of bounds\n";
     else
     {
         while(i != pos-1)
         {
                 prev = temp;
                 temp = temp->right;
                 if(temp == NULL)
                 {
                         cout<<"\nIndex out of bounds\n";
                         return;
                 }
                 i++;
         }
         if(temp != NULL)
         {
          ins->right = temp;
          prev->right = ins;
         }
     }
}

void del_begin()
{
     node *temp = front;
     if(temp == NULL)
     {
             cout<<"\nList is empty\n";
     }
     else
     {
         temp = temp->right;
         delete front;
         front = temp;
     }
}

void del_end()
{
     node *temp = front;
     node *prev = temp;
     while(temp->right != NULL)
     {
          prev = temp;
          temp = temp->right;
     }
     delete temp;
     prev->right = NULL;
     rear = prev;
}

void delete_before_index()
{
     int pos,i=0;
     cout<<"\nEnter the position before which you wish to delete\n";
     cin>>pos;
     node *temp = front;
     node *prev = front;
     node *del = new node;
     if(pos == 1)
     {
            cout<<"\nIndex out of bounds\n";
            return;
     }
     else
     {
      while(i != pos-2)
      {
       prev = temp;
       temp = temp->right;
       if(prev == NULL)
       {
               cout<<"\nIndex out of bounds\n";
               return;
       }     
       i++; 
      }
      del = temp;
      temp = temp->right;
      delete del;
      prev->right = temp;
     }
}

void delete_after_index()
{
     int pos,i=0;
     node *temp = front;
     node *prev = front;
     node *del = new node;
     cout<<"\nEnter the position after which you wish to delete\n";
     cin>>pos;
     while(i != pos)
     {
             prev = temp;
             temp = temp->right;
             if(temp == NULL)
             {
                     cout<<"\nIndex out of bounds\n";
                     return;
             }
             i++;
     }
     del = temp;
     temp = temp->right;
     delete del;
     prev->right = temp;
}

void number_nodes()
{
     int i=0;
     node *temp = front;
     if(temp == NULL)
     {
             cout<<"\nThe number of nodes = 0\n";
             return;
     }
     while(temp != NULL)
     {
                temp = temp->right;
                i++;
     } 
     cout<<"\nThe number of nodes = "<<i<<"\n";
}

void split()
{
     int pos,i=0;
     cout<<"\nEnter the position where you wish to split\n";
     cin>>pos;
     node *temp = front;
     node *front1 = NULL;
     node *rear1 = NULL;
     node *front2 = NULL;
     node *rear2 = NULL;
     while(i != pos)
     {
      if(front1 == NULL)
      {
       node *ptr = new node;
       ptr->data = temp->data;
       ptr->right = NULL;
       ptr->left = NULL;
       front1 = ptr;      
       rear1 = ptr;   
      }       
      else
      {
         node *ptr = new node;
         ptr->data = temp->data;
         ptr->right = NULL;
         rear1->right = ptr;
         rear1 = ptr;
      }
      temp = temp->right;
      i++;
     }
     while(temp != NULL)
     {
       if(front2 == NULL)
      {
       node *ptr = new node;
       ptr->data = temp->data;
       ptr->right = NULL;
       ptr->left = NULL;
       front2 = ptr;      
       rear2 = ptr;   
      }       
      else
      {
         node *ptr = new node;
         ptr->data = temp->data;
         ptr->right = NULL;
         rear2->right = ptr;
         rear2 = ptr;
      }   
      temp = temp->right;      
     }
     node *temp1 = front1;
     node *temp2 = front2;
     if(front1 == NULL)
     {
              cout<<"\nThe list is empty\n";
     }
     else
     {
         cout<<"\nThe current list is: ";
         while(temp1 != NULL)
         {
                    cout<<temp1->data<<" ";
                    temp1 = temp1->right;
         }
                    
     }
     if(front2 == NULL)
     {
              cout<<"\nThe list is empty\n";
     }
     else
     {
         cout<<"\nThe current list is: ";
         while(temp2 != NULL)
         {
                    cout<<temp2->data<<" ";
                    temp2 = temp2->right;
         }
                    
     }
     frontsplit1 = front1;
     frontsplit2 = front2;
}

void merge()
{
     node *temp = frontsplit1;
     while(temp != NULL)
     {
                 if(frontmerge == NULL)
                 {
                               node *ptr = new node;
                               ptr->data = temp->data;
                               ptr->left = NULL;
                               ptr->right = NULL;
                               frontmerge = ptr;
                               rearmerge = ptr;
                 }
                 else
                 {
                     node *ptr = new node;
                     ptr->data = temp->data;
                     ptr->right = NULL;
                     rearmerge->right = ptr;
                     rearmerge = ptr;
                 }
                 temp = temp->right;
     }
     temp = frontsplit2;
     while(temp != NULL)
     {
                 if(frontmerge == NULL)
                 {
                               node *ptr = new node;
                               ptr->data = temp->data;
                               ptr->left = NULL;
                               ptr->right = NULL;
                               frontmerge = ptr;
                               rearmerge = ptr;
                 }
                 else
                 {
                     node *ptr = new node;
                     ptr->data = temp->data;
                     ptr->right = NULL;
                     rearmerge->right = ptr;
                     rearmerge = ptr;
                 }
                 temp = temp->right;
     }
     node *tempdisp = front;
     if(front == NULL)
     {
              cout<<"\nThe list is empty\n";
     }
     else
     {
         cout<<"\nThe merged list is: ";
         while(tempdisp != NULL)
         {
                    cout<<tempdisp->data<<" ";
                    tempdisp = tempdisp->right;
         }
                    
     }
}

void display()
{
     node *temp = front;
     if(front == NULL)
     {
              cout<<"\nThe list is empty\n";
     }
     else
     {
         cout<<"\nThe current list is: ";
         while(temp != NULL)
         {
                    cout<<temp->data<<" ";
                    temp = temp->right;
         }
                    
     }
}

int main()
{
    int ch;
    ch =1;
    while(ch != 13)
    {
             cout<<"\n\nMAIN MENU\n";
             cout<<"1.INSERT IN BEGINNING\n";
             cout<<"2.INSERT IN END\n";
             cout<<"3.INSERT AFTER POSITION\n";
             cout<<"4.INSERT BEFORE POSITION\n";
             cout<<"5.DELETE FROM BEGINNING\n";
             cout<<"6.DELETE FROM END\n";
             cout<<"7.DELETE BEFORE PARTICULAR POSITION\n";
             cout<<"8.DELETE AFTER PARTICULAR POSITION \n";
             cout<<"9.NUMBER OF NODES\n";
             cout<<"10.SPLIT THE LIST BASED ON INDEX\n";
             cout<<"11.MERGE THE LIST BACK\n";
             cout<<"12.DISPLAY\n";
             cout<<"13.EXIT\n\n";
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
                            insert_before_index();
                            break;
                       case 5:
                            del_begin();
                            break;
                       case 6:
                            del_end();
                            break;
                       case 7:
                            delete_before_index();
                            break;
                       case 8:
                            delete_after_index();
                            break;
                       case 9:
                            number_nodes();
                            break;
                       case 10:
                            split();
                            break;
                       case 11:
                            merge();
                            break;
                       case 12:
                            display();
                            break;
                       case 13:
                            break;
                       default: cout<<"\nEnter a proper choice\n";
             }
    }
    getch();
    return 0;
}




