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

void touch_4_MB(int* p) {
	for (int j = 0; j < 1024; j++) {
		p[j * 1024 + 100] = 42;
	}
}

void foo(int *i) {
	int speed = 60;
	int amplitude = 4;
	if (*i < 360) {
		int* p = malloc(amplitude * MB);
		touch_4_MB(p);
		delay(((int)(cos(*i * PI / 180) * 1000) + 1000) / speed);
		*i += 1;
		foo(i);
		free(p);
		*i -= 1;
		delay(((int)(cos(*i * PI / 180) * 1000) + 1000) / speed);
	}
}

int main() {
	int qty = 4;
	int i = 0;
	for (int j = 0; j < qty; j++)
		foo(&i);
}
