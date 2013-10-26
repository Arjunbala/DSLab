// Shell Sort

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int a[100],n,key,j;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
    {
     cin>>a[i];       
    }
    int count = n/2;
    while(count >= 1)
    {
       for(int i=count;i<n;i+=count)
       {
          key = a[i];
          j = i-count;
          while((j>=0)&&(a[j]>key))
          {
             a[j+count]=a[j];
             j=j-count;
          }     
          a[j+count]=key;
       }
       count --;
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
    getch();
    return 0;
}
