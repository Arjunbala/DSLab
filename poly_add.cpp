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
    for(int i=0;i<=d2;i++)
    {
            
            
                cout<<"Coefficient of x^"<<i<<": ";
                cin>>c2[i];
            
    }
    if(d1>d2)
    {
             for(int i=d2+1;i<=d1;i++)
                     c2[i] = 0;
             cout<<endl<<endl<<"Sum of polynomials is "<<endl;
             for(int i=d1;i>=0;--i)
             {       
                     if(i!=0)
                     {
                             cout<<c1[i]+c2[i]<<"x^"<<i<<" ";
                             cout<<"+ ";
                     }
                     else
                     {
                         cout<<c1[i]+c2[i]<<" ";
                     }
             }
                     
             
                  
    }
    
    if(d2>d1)
    {
             for(int i=d1+1;i<=d2;i++)
                     c1[i] = 0;
             cout<<endl<<endl<<"Sum of polynomials is "<<endl;
             for(int i=d2;i>=0;--i)
             {
                     if(i!=0)
                     { 
                             cout<<c1[i]+c2[i]<<"x^"<<i<<" ";
                             cout<<"+ ";
                     }
                     else
                         cout<<c1[i]+c2[i]<<" ";
             }
                     
             
                  
    }
    getch();
}
    
    
