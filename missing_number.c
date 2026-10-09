#include <stdio.h>
int main()
{
  int n, i, sum=0;
int expected_sum,missing;
printf("Enter the value of n:");
scanf("%d", &n);
if (n<2)
{
printf("Invalid value of n.\n");
return 0; 
}
printf("Enter %d numbers:\n", n-1):
  for (i=0; i<n-1; i++)
{
int num;
scanf("%d", &num);
sum=sum+num;
}
expected_sum=n*(n+1)/2;
missing=expected_sum-sum;
printf("Missing number=%d\n", missing);
return 0;
}
