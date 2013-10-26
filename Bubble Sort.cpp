//Bubble Sort

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
 int a[100],n,t;
 cout<<"Enter the array size\n";
 cin>>n;
 cout<<"Enter the array elements\n";
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=0;i<n-1;i++)
 {
    for(int j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
           t = a[j];
           a[j]=a[j+1];
           a[j+1]=t;
        }                   
    }
 }
 cout<<"Sorted array is: ";
 for(int i=0;i<n;i++)
 cout<<a[i]<<" ";
 getch();
 return 0;
}
