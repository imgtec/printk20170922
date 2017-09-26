#include <stdio.h>


int printchar(int ch)
{
	putchar(ch);
}

void printint(int m, int base)
{
	int i, ch;
	char buf[33];

	i = 0;

	do {
		buf[i++] = m % base;
		m /= base;
	} while (m);

fprintf(stderr, "i: %d\n", i);

	while(i--) {
		ch = buf[i];
		printchar(ch+'0');
	}
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
//	printint(12395588, 2);
printf("\r\n");
	printint(0x7fffffff, 10);
printf("\r\n");
//	printhex(0xdeadbeef);
printf("\r\n");
	format("%12234234235253d\n");
printf("\r\n");
}

