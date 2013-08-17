#include<iostream>
#include<conio.h>
using namespace std;
const int size = 10;
int queue[size];
int front = -1,rear = -1;


void insert(int data)
{
     if(((front == 0)&&(rear == size-1))||(rear == front-1))
              cout<<"Queue is full"<<endl;
     else
     {
         if(front == -1)
         {
                  front = 0;
                  rear = 0;
         }
         else if (rear == size - 1)
              rear =0;
         else
             rear++;
         queue[rear] = data;
     }
}

void delet()
{
     if(front == -1)
              cout<<"Queue is empty"<<endl;
     else
     {
         if(front == rear)
         {
                  front = -1;
                  rear = -1;
         }
         else if(front == size-1)
            front = 0;
         else
             front++;
     }  
}

void display()
{
     if(front == -1)
              cout<<"Queue is empty"<<endl;
     else
     {
         if(front<=rear)
         {
                        for(int i=front;i<=rear;i++)
                                cout<<queue[i]<<" ";
         }
         else
         {
             for(int i=front;i<size;i++)
                  cout<<queue[i]<<" ";
             for(int j=0;j<=rear;j++)
                  cout<<queue[j]<<" ";
         }
     }
}


int main()
{
     int choice,data;
     choice = 1;
     while(choice!=4)
     {
                     cout<<"MAIN MENU"<<endl;
                     cout<<"1.insert()"<<endl;
                     cout<<"2.delete()"<<endl;
                     cout<<"3.display()"<<endl;
                     cout<<"4.quit"<<endl;
                     cout<<"Enter your choice"<<endl;
                     cin>>choice;
                     switch(choice)
                     {
                                   case 1: cout<<"Enter the data to be inserted to be inserted"<<endl;
                                           cin>>data;
                                           insert(data);
                                           break;
                                   case 2: delet();
                                           break;
                                   case 3: display();
                                           break;
                                   case 4: break;
                                   default: cout<<"Enter a correct choice"<<endl;
                     }
                                   getch();
      }
      return 0;
 }
                                        

     
