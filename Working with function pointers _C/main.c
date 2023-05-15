#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module.h"

double sqr(double x)
{
	return x*x;
}

int main(void)
{
	double first, last;
	int npoints, menu;
	double (*func)(double) = NULL;

	printf("Choose the function to tabulate.\n"
	       "1 - y = x^2;\n"
	       "2 - y = log(x);\n"
	       "3 - y = sin(x).\n");
	if(scanf("%ud", &menu) != 1)
		terminate("Invalid input.", STDIN_ERR);;
	switch(menu) {
	case 1:
		func = sqr;
		break;
	case 2:
		func = log;
		break;
	case 3:
		func = sin;
		break;
	default:
		terminate("Invalid function specified.", STDIN_ERR);
	}

	printf("First point: ");
	if(scanf("%lf", &first) != 1)
		terminate("Invalid input.", STDIN_ERR);
	printf("Last point: ");
	if(scanf("%lf", &last) != 1 || first > last)
		terminate("Invalid input.", STDIN_ERR);
	printf("Number of points: ");
	if(scanf("%ud", &npoints) != 1 || npoints < 1)
		terminate("Invalid input.", STDIN_ERR);

	struct pair* results = malloc(npoints * sizeof(struct pair));
	if(!results)
		terminate("Can't allocate.", MEM_ERR);

	tabulate(func, first, last, npoints, results);
	for_each(results, results + npoints, print_pair);
	getchar();
	free(results);
	results = NULL;
	return 0;
}
