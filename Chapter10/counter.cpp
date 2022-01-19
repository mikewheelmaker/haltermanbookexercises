#include "counter.h"

static int count;

int read()
{
	return count;
}

void increment()
{
	if (count < 5)
		count++;
}

void decrement()
{
	if (count > 0)
		count--;
}