/* Program to find a single root by Bisection method */ 
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
      float a,b,e,check1,check2,n,m,check3;
      /*User customised function should be entered prior to calculation */
      /* Current function is 0.65x^5 - 9x^4 +45.4x^3 - 88x^2 +82.3x -26 */
      printf("Enter the intervals \n");
      printf("Enter left interval(a) \n");
      scanf("%f",&a);
      printf("Enter right interval(b) \n");
      scanf("%f",&b);
      printf("Enter maximum permissible error (in percentage) \n");
      scanf("%f",&e);
      check1 = (0.65*a*a*a*a*a) - (9*a*a*a*a) + (45.4*a*a*a) - (88*a*a) + (82.3*a) - 26;
      check2 = (0.65*b*b*b*b*b) - (9*b*b*b*b) + (45.4*b*b*b) - (88*b*b) + (82.3*b) - 26;
      if((check1 * check2) > 0)
      {
                 printf("Enter correct intervals \n");
      }
      else
      {
           n = (log((b-a)/(e/100)))/log(2);
           int c=0;
           while(c < n)
           {
                   c = c+1;
           }
           
           for(int i=0;i<c;i++)
           {
                   m=(a+b)/2;
                   check3= (0.65*m*m*m*m*m) - (9*m*m*m*m) +(45.4*m*m*m) - (88*m*m) + (82.3*m) - 26;
                   if((check1 * check3)>0)
                   {
                              a = m;
                   }
                   else if((check2 * check3)>0)
                   {
                              b = m;
                   }
           } 
      }
      printf("Root is %f \n",(a+b)/2);
      getch();
}
