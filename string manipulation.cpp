#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{
    int choice = 1;
    while(choice!=11)
    {
                     clrscr();
                     cout<<"MAIN MENU"<<"\n";
                     cout<<"1.strlen()"<<"\n";
                     cout<<"2.strncat()"<<"\n";
                     cout<<"3.strncmp()"<<"\n";
                     cout<<"4.strcmpi()"<<"\n";
                     cout<<"5.strchr()"<<"\n";
                     cout<<"6.strstr()"<<"\n";
                     cout<<"7.strspm()"<<"\n";
                     cout<<"8.strcspm()"<<"\n";
                     cout<<"9.strncmpi()"<<"\n";
                     cout<<"10.strrchr()"<<"\n";
                     cout<<"11.Exit"<<"\n";
                     cout<<"Enter your choice"<<"\n";
                     cin>>choice;
                     switch(choice)
                     {
                                   case 1:
                                        strlen();
                                        break;
                                   case 2:
                                        strncat();
                                        break;
                                   case 3:
                                        strncmp();
                                        break;
                                   case 4:
                                        strcmpi();
                                        break;
                                   case 5:
                                        strchr();
                                        break;
                                   case 6:
                                        strstr();
                                        break;
                                   case 7:
                                        strspm();
                                        break;
                                   case 8:
                                        strcspm();
                                        break;
                                   case 9:
                                        strncmpi();
                                        break;
                                   case 10:
                                        strrchr();
                                        break;
                                   case 11:
                                        goto end;
                                   default:
                                        cout<<"Enter a valid choice"<<"\n";
                                        break;
                     }
                     getch();
    }
    getch();
}
                                         
                                   
