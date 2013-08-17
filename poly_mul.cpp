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
    for(int k=0;k<=d1+d2;k++)
    {
     for(int l=0;l<=d1;l++)
     {
             
     }    
    }
    getch();
}
