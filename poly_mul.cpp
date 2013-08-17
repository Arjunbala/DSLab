#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int c1[100],c2[100],d1,d2,c[100];
    cout<<"Enter degree of equation 1"<<endl;
    cin>>d1;
    cout<<"Enter the coefficients of equation 1"<<endl;
    for(int i=0;i<=d1;i++)
    {
           
           
                cout<<"Coefficient of x^"<<i<<": ";
                cin>>c1[i];
            
    }
    cout<<"Enter degree of equation 2"<<endl;
    cin>>d2;
    cout<<"Enter the coefficients of equation 2"<<endl;
    for(int j=0;j<=d2;j++)
    {
            
            
                cout<<"Coefficient of x^"<<j<<": ";
                cin>>c2[j];
            
    }
    if(d1>d2)
    {
             for(int i=d2+1;i<=d1;i++)
                     c2[i] = 0;
    }
    if(d2>d1)
    {
             for(int i=d1+1;i<=d2;i++)
                     c1[i] = 0;
    }
    cout<<"\n Product is: ";
    for(int k=d1+d2;k>=0;--k)
    {
     int sum = 0; 
     for(int l=0;l<=d1;l++)
     {
             for(int m=0;m<=d2;m++)
             {
                     if(l+m == k)
                     {
                            sum = sum + (c1[l]*c2[m]);
                     }
             }
     } 
     c[k] = sum;
     if(sum !=0)
     { 
     if(k!=0)
     { 
        cout<<c[k]<<"x^"<<k<<"+ ";
     }
     else
     {
         cout<<c[k];   
     }
     }
    }
    
    getch();
}
