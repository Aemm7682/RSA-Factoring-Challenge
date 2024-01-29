#include <stdio.h>
/***#include <math.h>*/
#include <stdlib.h>
void fact_print(unsigned long long n);
int main(int argc, char *argv[])
{
	unsigned long long n;

	if (argc != 2)
	{
		printf("Usage: factor\n");
		return (1);
	}
	FILE *file = fopen(argv[1],"r");
	if (file == NULL)
	{
		printf("file could not open %s\n", argv[1]);
		return (1);
	}
	while (fscanf(file, "%llu", &n) == 1)
		fact_print(n);
	fclose(file);
	return (0);
}
void fact_print(unsigned long long n)
{
	unsigned long long p, q;

	for (p = 2; p * p < n; p++)
	{
		if (n % p == 0)
			break;
	}
	if (p * p > n)
		printf("%llu is a prime number\n", n);
	else
	{
		q = n / p;
		printf("%llu=%llu*%llu\n", n, p, q);
	}
}
