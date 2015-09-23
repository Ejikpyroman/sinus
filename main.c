#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265
#define MB 1024 * 1024

void foo(int *i);

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

void foo(int *i) {
	int time = 60;
	int amplitude = 4;
	if (*i < 360) {
		int* p = calloc(4, MB);
		delay(((int)(cos(*i * PI / 180) * 1000) + 1000) / time);
		*i += 1;
		foo(i);
		free(p);
		*i -= 1;
		delay(((int)(cos(*i * PI / 180) * 1000) + 1000) / time);
	}
}

int main() {
	int qty = 4;
	int i = 0;
	for (int j = 0; j < qty; j++)
		foo(&i);
}