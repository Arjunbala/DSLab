#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int c =0;
    for(int i=1;i<=3;i++)
    {
            for(int j=1;j<=i;j++)
            {
            for(int k=1;k<=i;k++)
               c = c+1;
               }
               }
cout<<c;
getch();
return 0;
}
