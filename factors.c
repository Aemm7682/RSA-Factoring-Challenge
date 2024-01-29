#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void fact_print(unsigned long n);
int main(int argc, char *argv[])
{
	unsigned long n;

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
	while (fscanf(file, "%lu", &n) == 1)
		fact_print(n);
	fclose(file);
	return (0);
}
void fact_print(unsigned long n)
{
	unsigned long p, q;

	for (p = 2; p <= sqrt(n); p++)
	{
		if (n % p == 0)
			break;
	}
	if (p > sqrt(n))
		printf("%lu is a prime number\n", n);
	else
	{
		q = n / p;
		printf("%lu=%lu*%lu\n", n, p, q);
	}
}
