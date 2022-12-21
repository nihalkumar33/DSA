/*
//Printing sum of natural numbers using recursion.
#include<stdio.h>
int sum_n(int);
int main()
{
    int n, sum;
    printf("Enter the number upto which sum is to be calculated: ");
    scanf("%d", &n);
    sum = sum_n(n);
    printf("%d", sum);
    return 0;
}

int sum_n(int n)
{
    int sum=0;
    if (n>0)
        sum += (n + sum_n(n-1));
    return (sum);
}


// Factorial using recursion.
#include<stdio.h>
int fact(int n)
{
    if (n==0)
        return 1;
    else
        return (fact(n-1)*n);
}

int main()
{
    int inp, fac;
    printf("Enter the number whose factorial you need: ");
    scanf("%d", &inp);
    fac = fact(inp);
    printf("%d", fac);
    return 0;
}

#include<stdio.h>
int pow_n(int m, int n)
{
    if (n==0)
        return 1;
    else
        return (pow_n(m, n-1)*m);
}

int main()
{
    int m, n;
    printf("Enter the base and power respectively: ");
    scanf("%d %d", &m, &n);
    printf("%d", pow_n(m, n));
    return 0;
}

#include<stdio.h>
int pow(int m, int n)
{
    if (n==0)
        return 1;
    else if (n%2==0)
        return (pow(m*m, n/2));
    else
        return ((pow(m*m, (n-1)/2))*m);
}

int main()
{
    int n, m;
    printf("Enter the base and exponent: ");
    scanf("%d %d", &m, &n);
    printf("%d", pow(m, n));
    return 0;
}

//Recursive function for tylor series.
#include<stdio.h>
#include<math.h>

int fact(int n)
{
    if (n==0)
        return 1;
    else
        return (fact(n-1)*n);
}

int tylor_series(int x, int n)
{
    if (x==0)
        return 1;
    else  
        return (tylor_series(x, n-2) + pow(x, n-1)/fact(n-1));
    printf("Here in tylor_series\n");
}

int main()
{
    int x, n, v;
    printf("Enter the x and the number of terms till which series is to be formed: ");
    scanf("%d %d", &x, &n);
    v = tylor_series(x, n);
    return 0;
}

//Again trying the tylor series after learning the technique from SIR..!!
#include<stdio.h>

float e(int x, int n)
{
    static float D=1, P=1;  //D is denominator, P is power
    float F;
    if (n==0)
        return (1);
    else    
    {
        F = e(x, n-1);
        D *= n;
        P *= x;
        return (F + P/D);
    }
}

int main()
{
    int x, n;
    printf("Enter x of exponential and also enter the order of nth term: ");
    scanf("%d %d", &x, &n);
    printf("Exponential of %d upto %d terms is %f", x, n+1, e(x, n));
    return 0;
    
}


//Writing taylor series using honor's rule or to be simple series
//with less mumber of multiplications.

#include<stdio.h>
float e(float x, float n)
{
    static float s=1;
    if (n==0)
        return 1;
    else
    {
        s = 1+x/n*s;
        e(x, n-1);
        return s;
    }
}

int main()
{
    float x, n;
    printf("Enter the x and the maximum powre upto which series is to be calculated: ");
    scanf("%f %f", &x, &n);
    printf("%f", e(x, n));
    return 0;
}


#include<stdio.h>
void fib(int n)
{
    static int T1=0, T2=1, sum, i=1;
    if (i<=n)
    {
        if (i==1)
            printf("%d ", 0);
        else if (i==2)
            printf("%d ", 1);

        else
        {
            sum = T1 + T2;
            T1 = T2;
            T2 = sum;   
            printf("%d ", sum);
        }
        i++; fib(n);
    }
}  

int main()
{
    int inp;
    printf("Enter the number of terms of fibonacci sequence: ");
    scanf("%d", &inp);
    fib(inp);
    return 0;
}

//Programming fast recursive function for fibonacci sequense.
#include<stdio.h>
int fib_fast(int n) //The number whose fib is to be calculated.
{
    static int arr[10]; int i;
    for (i=0; i<n; i++)
    {
        arr[n] = -1;
    }

    if (arr[n]==-1)
    {
        //Here addition of the fib(n) is done in the array.
        if (n<=1)
            arr[n] = n;
        else
        {
            arr[n] = fib_fast(n-1) + fib_fast(n-2);
            return (arr[n-1] + arr[n-2]);
        }
    }
    else
    return arr[n];
}j

int main()
{
    int inp;
    printf("Enter the number whose fibonacci you want to know: ");
    scanf("%d", &inp);
    printf("Fibonacci of thr given number is %d", fib_fast(inp));
}


#include<stdio.h>
int nCr(int n, int r)
{
    if (n==r || r==0)
        return 1;
    else
        return (nCr(n-1, r-1) + nCr(n-1, r));
}

int main()
{
    int n, r;
    printf("Enter values of n and r(n>=r): ");
    scanf("%d %d", &n, &r);
    printf("%d", nCr(n, r));
    return 0;
}

#include <stdio.h>
void TOH(int n, int A, int B, int C)
{
    if (n>0)
    {
        TOH(n-1, A, C, B);
        printf("From %d to %d \n", A, C);
        TOH(n-1, B, A, C);
    }
}

int main()
{
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    TOH(n, 1, 2, 3);
    return;
}
*/
