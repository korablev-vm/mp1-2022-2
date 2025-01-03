#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <locale.h>
#include <math.h>
#include "Header.h"

void myprint(double a, double b, int count)
{
	gotoxy(0, count + 1);
	printf("%d)", count);
	gotoxy(11, wherey());
	printf("%lf", a);
	gotoxy(35, wherey());
	printf("%lf", b);
	gotoxy(61, wherey());
	printf("%lf", fabs(a - b));
	gotoxy(0, wherey() + 1);
}

void myprintf(double a, double b, int count)
{
	printf("��������� ��������: %lf\n������������ ��������: %lf\n�����������: %lf\n���������� ���������: %d\n", a, b, fabs(a - b), count);
}

double factorial(int x)
{
	long long f;
	for (f = 1; x > 1; f *= (x--))
		;
	return f;
}

void B_arr(double* B, int N)
{
	double temp;
	double a, b, c, d, C;

	B[0] = 1;
	B[1] = -0.5;
	for (int n = 2; n < N; n++)
	{
		temp = 0;
		if ((n > 2) && (n % 2 == 1))
			continue;
		for (int k = 0; k < n; k++)
		{
			a = factorial(n);
			b = factorial(k);
			c = factorial(n - k);
			C = (a) / (b * c);
			d = B[k];
			temp += C * d / (n - k + 1);
		}
		B[n] = -temp;
	}
}

void tg(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0, answer = sin(x) / cos(x);
	int count = 0;
	double* B = calloc(n, sizeof(double));
	B_arr(B, n);
	do
	{
		a += (B[2 * count + 2] * pow(-4, count+1) * (1 - pow(4, count+1))) / factorial(2 * count+2) * pow(x, 2 * count + 1);
		count++;
	} while ((fabs(answer - a) > pog) && (count < n));
	free(B);
	pointer(answer, a, count);
}

void arth(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0, answer = 0.5 * log((1 + x) / (1 - x));
	int count = 0;
	do
	{
		a += pow(x, 2 * count + 1) / (2 * count + 1);
		count++;
	} while ((fabs(answer - a) > pog) && (count < n));
	pointer(answer, a, count);
}

void sinus(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0;
	int count = 0;
	do
	{
		if(count % 2 == 0)
			a += ((pow(x, 2 * count + 1)) / factorial(2 * count + 1));
		else
			a -= ((pow(x, 2 * count + 1)) / factorial(2 * count + 1));
		count++;
	} while ((fabs(sin(x) - a) > pog) && (count < n));
	pointer(sin(x), a, count);
}

void cosinus(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0;
	int count = 0;
	do
	{
		if (count % 2 == 0)
			a += ((pow(x, 2 * count)) / factorial(2 * count));
		else
			a -= ((pow(x, 2 * count)) / factorial(2 * count));
		count++;
	} while ((fabs(cos(x) - a) > pog) && (count < n));
	pointer(cos(x), a, count);
}

void exponenta(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0;
	int count = 0;
	do
	{
		a += pow(x, count) / factorial(count);
		count++;
	} while ((fabs(exp(x) - a) > pog) && (count < n));
	pointer(exp(x), a, count);
}

void secans(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0;
	int count = 0;
	do
	{
		if (count % 2 == 0)
			a += (pow(x, 2 * count)) / factorial(2 * count);
		else
			a -= (pow(x, 2 * count)) / factorial(2 * count);
		count++;
	} while ((fabs((1 / cos(x)) - 1/a) > pog) && (count < n));
	pointer(1 / cos(x), a, count);
}

void sh(double x, double pog, int n, void (*pointer)(double, double, int))
{

	double a = 0, answer = (exp(x) - exp((-1) * x) / 2);
	int count = 0;
	do
	{
		a += pow(x, 2 * count + 1) / factorial(2 * count + 1);
		count++;
	} while ((fabs(answer - a) > pog) && (count < n));
	pointer(answer, a, count);
}

void ch(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0, answer = (exp(x) + exp((-1) * x) / 2);
	int count = 0;
	do
	{
		a += pow(x, 2 * count) / factorial(2 * count);
		count++;
	} while ((fabs(answer - a) > pog) && (count < n));
	pointer(answer, a, count);
}

void ln(double x, double pog, int n, void (*pointer)(double, double, int))
{
	double a = 0;
	int count = 0;
	do
	{
		if (count % 2 == 0)
			a -= pow(x, count) / count + 1;
		else
			a += pow(x, count) / count + 1;
		count++;
	} while ((fabs(log(x) - a) > pog) && (count < n));
	pointer(log(x), a, count);
}
