#include<iostream>
#include<conio.h>
using namespace std;

const int size = 10;
int stack[size];
int top = -1;

void push(int item)
{
     if(top == size)
     {
            cout<<"\n Stack is full. Overflow condition"<<"\n";
     }
     
     else
     {      
            top = top + 1;
            stack[top] = item;
     }
     
 
}

void pop()
{
     if(top == -1)
     {
            cout<<"\n Stack is empty. Underflow condition"<<"\n";
     }
     else
     {
         top = top - 1;
     }
         
}

void display()
{
     cout<<"\n";
     for(int i=top;i>=0;--i)
             cout<<stack[i]<<"\n";
     
}



int main()
{
    int choice,item;
    choice =1;
    while(choice!=4)
    {
                    cout<<"MAIN MENU"<<"\n";
                    cout<<"1.push()"<<"\n";
                    cout<<"2.pop()"<<"\n";
                    cout<<"3.display()"<<"\n";
                    cout<<"4.Exit"<<"\n";
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    switch(choice)
                    {
                                  case 1: 
                                       cout<<"\n Enter the item to be inserted"<<"\n";
                                       cin>>item;
                                       push(item);
                                       break;
                                  case 2:
                                       pop();
                                       break;
                                  case 3:
                                       display();
                                       break;
                                  case 4:
                                       break;
                                  default:
                                          cout<<"\n Enter a correct choice"<<"\n";
                    }
                    
    }
    getch();
}
                                          
                                  
                                  
                    
    
                    
    
