01
#include<stdio.h>
02
#include<conio.h>
03
#include<math.h>
04
#include<stdlib.h>
05
void main()
06
{
07
    float a[20][20],x[20],e,big,temp,relerror,sum;
08
    int n,i,j,maxit,itr;
09
    char ch;
10
    clrscr();
11
    printf("\n\nENTER THE SIZE OF THE EQUATION :: ");
12
    scanf("%d",&n);
13
    for(i=1;i<=n;i++)
14
    {
15
        printf("\n\nEnter the coefficints of  equation %d and RHS \n",i);
16
        for(j=1;j<=n+1;j++)
17
        scanf("%f",&a[i][j]);
18
    }
19
    printf("\n\nEnter relative error and number of iteration ::  \n");
20
    scanf("%f%d",&e,&maxit);
21
    for(i=1;i<=n;i++)
22
    x[i]=0;
23
    for(itr=1;itr<=maxit;itr++)
24
    {
25
        big=0;
26
        for(i=1;i<=n;i++)
27
        {
28
            sum=0;
29
            for(j=1;j<=n;j++)
30
             {
31
               if(i!=j
32
               )
33
                  sum=sum+a[i][j]*x[j];
34
              }
35
            temp=(a[i][n+1]-sum)/a[i][i];
36
            relerror=fabs((x[i]-temp)/temp);
37
            if(relerror>big)
38
               big=relerror;
39
            x[i]=temp;
40
        }
41
    if(big<=e)
42
    {
43
        printf("Converges to a solution in %d iterations\n",itr);
44
        for(i=1;i<=n;i++)
45
        printf("\n%.4f\t",x[i]);
46
        getch();
47
        exit(1);
48
    }
49

50
     }
51
  printf("does not converge in %d iteration \n",maxit);
52
  getch();
53

54
 }
