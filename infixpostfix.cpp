#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int top = -1;
char stack[100];
void push(char item)
{
     top = top + 1;
     stack[top] = item;
}

char pop()
{
    top = top - 1;
    return stack[top+1];
}

int main()
{
    char infix[100],postfix[100];
    cout<<"Enter the infix expression \n";
    gets(infix);
    infix[strlen(infix)]=')';
    push('(');
    int j=0;
    for(int i=0;i<strlen(infix);i++)
    {
            if(isalnum(infix[i]))
            {
                 postfix[j] = infix[i];
                 j++;
            }
            if(infix[i] == '(')
                 push('(');
            if(infix[i] == '+' || infix[i] == '-')
            {
                 while(stack[top]=='*'||stack[top]=='/'||stack[top]=='^'||stack[top]=='-'||stack[top]=='+')
                        {
                            postfix[j] = pop();
                            j++;
                        }
                 push(infix[i]);
            }
            if(infix[i] == '*' || infix[i] == '/')
            {
                 while(stack[top]=='*'||stack[top]=='/'||stack[top]=='^')
                        {
                           postfix[j] = pop();
                           j++;
                        }
                 push(infix[i]);
            }
            
            if(infix[i] == '^')
            {
                        while(stack[top] == '^')
                            {
                               postfix[j] = pop();
                                j++;
                            }
                        push(infix[i]);
            }
            if(infix[i] == ')')
            {
                        while(stack[top] != '(')
                            {
                               postfix[j] = pop();
                               j++;
                            }
                        char temp = pop();
            }
                            
    }
    cout<<"\nPostfix expression is \n";
    for(int k=0;k<j;k++)
            cout<<postfix[k];
    
    getch();
}
    
    
