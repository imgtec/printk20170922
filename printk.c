#include <stdio.h>


int printchar(int ch)
{
	putchar(ch);
}

void printint(int m)
{
	int d, ch;

	d = 1;
	ch = d * 10;

	while (ch <= m) {
		d = ch;
		ch *= 10;
	}

	while(d) {
		ch = m / d;
		ch += '0';
		printchar(ch);
		m = m % d;

		d /= 10;
	}

	return;
}

void printhex(int hex)
{
	int ch;
	int i = 32;
	int cap = 'a'-10;
	
	while (i) {
		i -= 4;

		ch = hex>>i;
		ch &= 15;
		if(ch<10) {
			ch += '0';
		} else {
			ch += cap;
		}
		printchar(ch);	
	}	
}


/*
 * %d, %u, %nnd, %nnu, %nnx, %nnX
 */
int format(const char *fmt)
{
	int ch;
	int n = 0;

	printf("\n%s\n", fmt);

	if(*fmt++ != '%') {
		return;
	}

	ch = fmt[n];
	while(ch>='0' && ch<='9') {
		n++;
		ch = fmt[n];
	}

	printf("%d numbers in format\n", n);
}






int main(int argc, char *argv[])
{
	printint(12395588);
	printhex(0xdeadbeef);
	format("%12234234235253d\n");
}

