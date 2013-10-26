//Depth First Search

#include<iostream>
#include<conio.h>
using namespace std;

char stack[20];
int top = -1;

void push(char data)
{
     top = top + 1;
     stack[top] = data;
}

char pop()
{
     top = top - 1;
     return(stack[top+1]);
}

int main()
{
    int n,n_rel,pos;
    char node_rel;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    char nodes[n];
    int adj[n][n];
    char visited[n];
    int nos = -1;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            adj[i][j]=0;
            
    }
    cout<<"\nEnter the nodes\n";
    for(int i=0;i<n;i++)
    {
            cin>>nodes[i];
    }
    for(int i=0;i<n;i++)
    {
            cout<<"\n\nEnter number of nodes related to "<<nodes[i]<<"\n";
            cin>>n_rel;
            for(int j=1;j<=n_rel;j++)
            {
                    cout<<"\nEnter node "<<j<<" related to "<<nodes[i]<<"\n";
                    cin>>node_rel;
                    for(int k=0;k<n;k++)
                    {
                            if(nodes[k] == node_rel)
                            {
                                adj[i][k] = 1;
                            }
                    }
            }
    }
    push(nodes[0]);
    nos = nos + 1;
    visited[nos] = nodes[0];
    while(top != -1)
    {
     char ch = pop();
     for(int i=0;i<n;i++)
     {
        if(ch == nodes[i])
        {
                   pos = i;
        }
     }
     for(int j=0;j<n;j++)
     {
             if(adj[pos][j] == 1)
             {
                for(int k=0;k<=nos;k++)
                {
                        if(visited[k] == nodes[j])
                        {
                            goto end;
                        }
                }
                nos = nos + 1;
                visited[nos] = nodes[j];
                push(nodes[j]);
                end:continue;
             }
     }
     }
     cout<<"\n\nAns: ";
     for(int i=0;i<=nos;i++)
     cout<<visited[i]<<" ";
    cout<<"\n\nAdjagency matrix is \n";
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
            cout<<"\n";
    }
    getch();
    return 0;
}
