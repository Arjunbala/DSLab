#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct node
{
       int no;
       node *left;
       node *right;
}*start,*ptr;

int carry = 0;



void add_no(int a, int b,int c)
{
 node *temp; 
 temp = new node;
 temp->no = ((a+b)%10)+c;
 if(start == NULL)
 {
       temp->left = NULL;
       temp->right = NULL;        
       start = temp;    
       ptr = start;
 }     
 else
 {
       temp->left = NULL;
       temp->right = ptr;
       ptr = temp;   
 }
    
}

void display()
{
     node *temp;
     temp = new node;
     temp = ptr;
     if(carry != 0)
              cout<<carry;
     while(temp != NULL)
     {
                cout<<temp->no;
                temp = temp->right;
     } 
}



int main()
{
    char n1[50],n2[50];
    cout<<"Enter number 1"<<"\n";
    cin>>n1;
    cout<<"Enter number 2"<<"\n";
    cin>>n2;
    int j=strlen(n2)-1;
    if(strlen(n1) == strlen(n2))
    {
     for(int i=strlen(n1)-1;i>=0;--i)
     {
    
      add_no(n1[i]-48,n2[j]-48,carry); 
      carry = (n1[i]+n2[j]-96)/10;   
      --j;   
      }
    }
    else if (strlen(n1)>strlen(n2))
    {
         j = strlen(n2)-1;
         for(int i=strlen(n1)-1;i>=0;--i)
     {
         if(j >= 0)
         {
                 add_no(n1[i]-48,n2[j]-48,carry); 
                 carry = (n1[i]+n2[j]-96)/10;   
                 --j;   
         }
         if(j < 0)
         {
                add_no(n1[i]-48,0,carry); 
                 carry = (n1[i]-48)/10;   
                 --j;   
         }
      }
    }
    else
    {
        j = strlen(n1)-1;
        for(int i=strlen(n2)-1;i>=0;--i)
     {
         if(j >= 0)
         {
                 add_no(n1[i]-48,n2[j]-48,carry); 
                 carry = (n1[i]+n2[j]-96)/10;   
                 --j;   
         }
         if(j < 0)
         {
                add_no(n2[i]-48,0,carry); 
                 carry = (n2[i]+0-48)/10;   
                 --j;   
         }
      } 
    }
    display();
    getch();
    return 0;
}
    
    
     
