//Heap Sort

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
 //Getting the unsorted array as input
 int a[100],n,c,root,temp;
 cout<<"Enter the array size\n";
 cin>>n;
 cout<<"Enter the array elements\n";
 for(int i=0;i<n;i++)
 cin>>a[i];

 //Creating max-heap
 for(int i=1;i<n;i++)
 {
    c=i;
    do
    {
        root = c/2;
        if(a[c]>a[root])
        {
           temp = a[c];
           a[c]=a[root];
           a[root]=temp;
        }
        c=root;
    }while(c!=0);
 }
 
 //Printing in ascending order by exchanging root with last element and then decrementing size of heap.
 for(int j=n-1;j>=0;--j)
 {
   temp = a[0];
   a[0]=a[j];
   a[j]=temp;
   root = 0;
   do
   {
        c = 2*root + 1;
        if((a[c+1]>a[c]) && (c<j-1))
        {
           c++;
        }
        if(a[c]>a[root]&& (c<j))
        {
          temp = a[c];
          a[c]=a[root];
          a[root]=temp;
        }
        root = c;
   }while(c<j);
 }
 cout<<"Sorted Array is: ";
 for(int i=0;i<n;i++)
 cout<<a[i]<<" ";
 getch();
 return 0;
}
