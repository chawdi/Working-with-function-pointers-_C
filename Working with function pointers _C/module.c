#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "module.h"

int tabulate(double (*func)(double), double const parstrt,double const parend,unsigned const npoints,struct pair* results)
{
	if (!func || !results || npoints < 1 || parstrt > parend)
		return ARG_ERR;
	double diff = npoints == 1 ? 0 : (parend - parstrt) / (npoints - 1);
	double par = parstrt;
	for (int i = 0; i < npoints; i++) {
		results->first = par;
		results->second = func(par);
		par += diff;
		results++;
	}
	return SUCCESS;
}

int for_each(struct pair* begin,struct pair* end,void (*handler)(struct pair*))
{
	if (begin > end || !handler)
		return ARG_ERR;
	for (struct pair* el = begin; el != end; el++) {
		printf("Element #%ld out of %ld:\n",
		       el - begin + 1,
		       end - begin);
		handler(el);
	}
	getchar();
	return SUCCESS;
}

void print_pair(struct pair* el)
{
	if (el)
		printf("(%.2lf;%.2lf)\n", el->first, el->second);
}

inline void terminate(char const* msg, int ecode)
{
	FILE *out = ecode ? stderr : stdout;

	if (msg)
		fprintf(out, "%s\n", msg);
	exit(ecode);
}
