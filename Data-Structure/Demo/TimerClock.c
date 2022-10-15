#include <math.h>
#include <stdio.h>
#include <time.h>

clock_t start, end;
// clock_t is the type of variable returned by clock() function
double duration;
// the running time of the timer function,in seconds
#define MAXN 101 // the number of maximum terms
#define MAXK 1e5 // the number of maximum repeated invocations
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
void run(double (*f)(int n, double *, double), double a[], int func_n);
int main()
{
    int i;
    double a[MAXN]; // store the coefficients
    a[0] = 1;
    for (i = 1; i < MAXN; i++)
    {
        a[i] = (double)(1.0 / i);
    }
    run(f1, a, 1);
    run(f2, a, 2);
    return 0;
}
double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i < n; i++)
    {
        p += (a[i] * pow(x, i));
    }
    return p;
}
double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

void run(double (*f)(int n, double *, double), double a[], int func_n)
{
    int i;
    start = clock();
    for (i = 0; i < MAXK; i++)
    {
        f(MAXN - 1, a, 1.1);
    }
    end = clock();
    duration = ((double)(end - start)) / CLK_TCK;
    printf("ticks%d=%f\n", func_n, (double)(end - start));
    printf("duration%d=%6.2e\n", func_n, duration);
}
