//Breadth First Search

#include<iostream>
#include<conio.h>
using namespace std;

int queue[20];
int front = -1;
int rear = -1;

void insert(char data)
{
     
}

int main()
{
    int n,n_rel;
    char node_rel;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    char nodes[n];
    int adj[n][n];
    char visited[n];
    int nos = 0;
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
    insert(nodes[0]);
    visited[nos++] = nodes[0];
    while(front != -1)
    {
     char ch = remove();
     for(i=0;i<n;i++)
     {
        if(remove == nodes[i])
        {
                  int pos = i;
        }
     }
     for(int j=0;j<n;j++)
     {
             if(adj[pos][j] == 1)
             {
                for(int k=0;k<nos;k++)
                {
                        if(visited[k] == nodes[j])
                        {
                            goto end;
                        }
                }
                visited[nos++] = nodes[j];
                insert(nodes[j]);
                end:
             }
     }
     }
     cout<<"Ans: ";
     for(int i=0;i<nos;i++)
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
