#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[100],i,j,k;
    k=0;
    cout<<"Generating twin primes between 1 and 100"<<"\n";
    for(i=1;i<=100;i++)
    {
                       int f=0;
                       for(j=1;j<=i;j++)
                       {
                                        if(i%j==0)
                                        f = f+1;
                       }
                       if(f==2)
                       {
                               a[k]=i;
                               k++;
                       }
    }
    for(i=0;i<k;i++)
    {
                    for(j=0;j<k;j++)
                    {
                                    if(a[j] - a[i] == 2)
                                    cout<<"("<<a[i]<<","<<a[j]<<")"<<"\n";
                    }
    }
    getch();
}
