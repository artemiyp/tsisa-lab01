#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <locale>

using namespace std;

double fun(double x)
{
	return x*x*sin(x);
}

double Fibonacci(int N, double aa, double bb)
{

	double *F,a,b,sigma;//последовательность чисел Фибонначи
	F=(double*)calloc(N,sizeof(double));
    F[0]=1;F[1]=1;

	for (int i=2; i <= N+1; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }

    printf("Итерация|a       |b       |Длина  |x       |f(x)\t|x1      |x2      |\n");
    double x1,x2;
    a=aa;b=bb;

    x1=a+F[N-1]*(b-a)/F[N+1];
    x2=a+F[N]*(b-a)/F[N+1];
    sigma=0.0001;

	for (int i=0; i <= N; i++)
    {
        if (i==N-1)
        {
            x1=x1-sigma;
            x2=x2+sigma;
        }
        printf("%d\t|%7.4f |%6.4f |%6.4f |%6.4f |%7.4f\t|%6.4f |%6.4f |\n",i,a,b,b-a,(a+b)/2,fun((a+b)/2),x1,x2);
        if (i<N-1)//пока не достигнем F[0]=F[1]=1, тогда
        {
            if (fun(x1)>fun(x2))
                {
                    a=x1;x1=x2;x2=a+F[N-i-1]*(b-a)/F[N-i];
                }
            else
                {
                    b=x2;x2=x1;x1=a+F[N-i-2]*(b-a)/F[N-i];
                }
        }
        if (i==N-1)
        {
        if (fun(x1)>fun(x2)) a=x1;
            else  b=x1;
        }
    }
    free(F);
    cout << "Достигнутая точность при N = " <<N<< " равна "<< (b-a)/2 <<endl;
	return (a+b)/2;
}

int main()
{
    double a,b,xmin,fmin,eps=0.1;
    int Np;

    setlocale(LC_ALL, "russian");
    a=9; b=12;
    //оптимальный пассивный поиск
    Np=2*(b-a)/eps-1;
    printf("N\t|x\t\t|f(x)\t\t|\n");
    for (int i=1; i <= Np+1; i++)
    {
        xmin=a+eps*i/2;
        fmin=fun(xmin);
        printf("%d\t|%7.4f\t|%7.4f\t|\n",i,xmin, fmin);
    }

    cout << "\nМетод  Фибоначчи:"<< endl;

    for (int j=8; j <= 12; j++)
    {
        xmin=Fibonacci(j, a, b);
        fmin=fun(xmin);
        cout << "Минимум функции в точке x = " << xmin << endl;
        cout << "Значение функции в этой точке f(x) = " << fmin << endl;
        cout <<"----------------------------------------------------------"<< endl;
    }
    return 0;
}
