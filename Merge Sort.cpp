//Merge Sort

#include<iostream>
#include<conio.h>
using namespace std;

void merge(int la[],int ra[],int lsize,int rsize)
{
     cout<<"\nLEFT Array\n";
     for(int i=0;i<lsize;i++)
     {
             cout<<la[i]<<" ";
     }
     cout<<"\nRIGHT Array\n";
     for(int i=0;i<rsize;i++)
     {
             cout<<ra[i]<<" ";
     }
     int a[100],i,j,k;
     i=0;
     j=0;
     k=0;
     while((i<lsize)&&(j<rsize))
     {
         if(la[i]<ra[j])
         {
            a[k]=la[i];
            k++;
            i++;
         }
         else
         {
             a[k]=ra[j];
             k++;
             j++;
         }
     } 
     while(i < lsize)
     {
         a[k]=la[i];
         k++;
         i++;
     }
     while(j < rsize)
     {
        a[k]=ra[j];
        k++;
        j++;
     }
     cout<<"\nMERGED\n";
     for(int i=0;i<k;i++)
     {
             cout<<a[i]<<" ";
     }
}

void mergesort(int a[100],int n)
{
     if(n == 1)
     {
          return;
     }
     else
     {
         int lsize,rsize;
         lsize = n/2;
         rsize = n-lsize;
         int la[lsize],ra[rsize];
         cout<<"\nLA\n";
         for(int i=0;i<lsize;i++)
         {
                 la[i]=a[i];
                 cout<<la[i]<<" ";
         }
         cout<<"\nRA\n";
         for(int i=0;i<rsize;i++)
         {
                 ra[i]=a[lsize+i];
                 cout<<ra[i]<<" ";
         }
         mergesort(la,lsize);
         mergesort(ra,rsize);
         merge(la,ra,lsize,rsize);
     }
}

int main()
{
    int a[100],n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
    {
     cin>>a[i];       
    }
    mergesort(a,n);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
    getch();
    return 0;
}
