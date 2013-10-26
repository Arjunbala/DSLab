//Insertion Sort

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
 int a[100],n,key,j;
 cout<<"Enter the array size\n";
 cin>>n;
 cout<<"Enter the array elements\n";
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=1;i<n;i++)
 {
         key=a[i];
         j=i-1;
         while((j>=0)&&(a[j]>key))
         {
             a[j+1]=a[j];
             j--;
         }
         a[j+1]=key;
 }
 cout<<"Sorted array is: ";
 for(int i=0;i<n;i++)
 cout<<a[i]<<" ";
 getch();
 return 0;
}
