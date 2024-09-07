// Online C compiler to run C program online
#include <stdio.h>

int main() {
   int n ; 
   printf("enter number");
   scanf("%d",&n);
   for(int i = 1;i<=n;i++)
   {
       for(int j = n-i;j>=1;j--)
       { 
           printf(" ");
   } 
   for (int k = i;k>=1;k--)
   {
       printf("%d",k);
   }
   for(int a = 2;a<=i;a++)
   {
       printf("%d",a);
   }
    printf("\n");
   }
    return 0;
}