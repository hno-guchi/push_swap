#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	value;
	int	exponents;
	int	power;

	if (argc < 2)
	{
		return (0);
	}
	exponents = 1;
	power = 3;
	value = atoi(argv[1]);
	printf("Initial value\n");
	printf("exponents is [%4d]\n", exponents);
	printf("power     is [%4d]\n", power);
	printf("value     is [%4d]\n", value);
	while (power < value + 2)
	{
		power = 3 * power;
		exponents += 1;
		printf("exponents : [%d] | power : [%4d]\n", exponents, power);
	}
	printf("----------------------\n");
	printf("[%d] exponents is [%d]\n", value, exponents);
	printf("[%d]\n", 1000 / 3);
	return (0);
}
