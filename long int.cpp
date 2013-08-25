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
 temp->no = ((a+b+c)%10);
 carry = (a+b+c)/10;
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
     cout<<"The sum is: ";
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
    int i=strlen(n1)-1;
    while((i>=0)||(j>=0))
    {
     if((i>=0)&&(j>=0))
     add_no(n1[i]-48,n2[j]-48,carry);
     else if((i>=0)&&(j<=0))
     add_no(n1[i]-48,0,carry);
     else if((j>=0)&&(i<=0))
     add_no(0,n2[j]-48,carry);
     
     --i;
     --j;
     
    }
    display();
    getch();
    return 0;
}
     
