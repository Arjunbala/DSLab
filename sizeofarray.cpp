#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<sizeof(a);
    cout<<a[n];
    getch();
    return 0;
}
