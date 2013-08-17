#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int stack[100],top = -1;
void push(int item)
{
     top = top + 1;
     stack[top] = item;
}

void pop()
{
    top = top - 1;
}


int main()
{
    int var =0, op = 0,flag = 0;
    char exp[100];
    cout<<"Enter the expression"<<"\n";
    gets(exp);
    for(int i=0;i<strlen(exp);i++)
    {
            if(isalnum(exp[i]))
            {
                     var++;
            }
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
            {
                     op++;
            }
    }
    
    if(var == op+1)
    {
           for(int j=0;j<strlen(exp);j++)
           {
               switch(exp[j])
               {
                     case '{': push(exp[j]);
                               break;
                     case '(': push(exp[j]);
                               break;
                     case '[': push(exp[j]);
                               break;
                     case '}': if(top == -1)
                               {
                                      flag = 1;
                                      break;
                               }
                               if(stack[top]=='{')
                                      pop();
                               else
                                      flag = 1;
                               break; 
                      case ']': if(top == -1)
                               {
                                      flag = 1;
                                      break;
                               }
                               if(stack[top]=='[')
                                      pop();
                               else
                                      flag = 1;
                               break; 
                      case ')': if(top == -1)
                               {
                                      flag = 1;
                                      break;
                               }
                               if(stack[top]=='(')
                                      pop();
                               else
                                      flag = 1;
                               break;           
                                      
               }
               if(flag == 1)
                       break;
           }
    }
    if(flag == 1)
            cout<<"\n"<<"Incorrect expression"<<endl;
    else
        cout<<"\n"<<"Correct expression "<<endl;
    getch();
}
                                
