// Selection Sort

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
 int a[100],n,small,pos,temp;
 cout<<"Enter the array size\n";
 cin>>n;
 cout<<"Enter the array elements\n";
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=0;i<n;i++)
 {
         small = a[i];
         pos = i;
         for(int j=i+1;j<n;j++)
         {
                 if(a[j]<small)
                 {
                    pos = j;
                    small = a[j];
                 }
         }
         temp = a[i];
         a[i]=a[pos];
         a[pos]=temp;
 }
 cout<<"Sorted array is: ";
 for(int i=0;i<n;i++)
 cout<<a[i]<<" ";
 getch();
 return 0;
}
