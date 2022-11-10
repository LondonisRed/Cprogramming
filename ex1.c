#include <stdio.h>
#include <math.h>

int main()
{
	int n, m, Result, i, F1 = 1, F2 = 0;
	printf("Enter value of n:");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++){
		F1 = F1 * i;
		F2 += i;
	}
	printf("F1 = %d\n", F1);
	printf("F2 = %d\n", F2);
	
	printf("Enter value of m:");
	scanf("%d", &m);
	Result = pow(n,m);
	
	printf("Result = %d", Result);
	
	return 0;
}
