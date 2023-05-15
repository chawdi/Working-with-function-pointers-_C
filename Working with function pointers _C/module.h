#define _CRT_SECURE_NO_WARNINGS

#ifndef MODULE_H_
#define MODULE_H_

#define SUCCESS 0
#define STDIN_ERR 1
#define MEM_ERR 2
#define ARG_ERR 3

struct pair {
	double first, second;
};

int tabulate(double (*func)(double),
	      double const parstrt,
	      double const parend,
	      const unsigned npoints,
	      struct pair* results);

int for_each(struct pair* begin,
	      struct pair* end,
	      void (*handler)(struct pair*));

void print_pair(struct pair* el);

void terminate(char const* msg, int ecode);

#endif
