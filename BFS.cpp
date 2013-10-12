//Breadth First Search

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int n,n_rel;
    char node_rel;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    char nodes[n];
    int adj[n][n];
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
