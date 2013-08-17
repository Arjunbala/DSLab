#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{
    int a[3],i,j,odd,even;
    cout<<"Printing numbers..."<<"\n";
    for(i=100;i<=150;i++)
    {
                         odd=0;
                         even=0;
                         a[0] = i/100;
                         a[1] = (i/10)%10;
                         a[2] = (i%100)%10; 
                         for(j=0;j<3;j++)
                         {
                                         if(a[j]%2==0)
                                         even++;
                                         else
                                         odd++;
                         }
                         if(((even%2)==0)&&((odd%2)==1))
                         cout<<i<<" "; 
                         
    }
    getch();
    return 0;
}
    
