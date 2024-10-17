// Задача №4 - интерполяция
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double f(double x)
{
	return x * x + 1 / x;
}


double LagrangeInter(double* X, double* Y, int n, double _xj)
{
	double result = 0.0;

	for (int i = 0; i < n; i++)
	{
		double P = 1.0;

		for (int j = 0; j < n; j++) {
			if (j != i)
			{
				P *= (_xj - X[j]) / (X[i] - X[j]);
			}
		}
		result += P * Y[i];
	}

	return result;
}




int main()
{
	setlocale(LC_CTYPE, "ru");
	double a, b;
	int n;
	cout << "Введите концы отрезка: " << endl;
	cin >> a >> b;
	cout << "Введите параметр n: " << endl;
	cin >> n;

	double *Y = new double[n+1];
	double *X = new double[n+1];

	ofstream fout ("rezult.txt");   

	for (int i = 0; i <= n; i++)
	{
		X[i] = a + i * (b - a) / n;
		Y[i] = f(X[i]);
		cout <<" ("<< X[i] << "; " << Y[i] << ") " << endl;
		fout << " (" << X[i] << "; " << Y[i] << ") " << endl;

	}
	cout << " "<<endl;;
	cout << "Интерполянт "<<endl;
   
	     
	
	for (int i = 0; i <= 35-2; i ++)
	{
		double xj;
		xj = a + i * 0.03;
		
		double LI = LagrangeInter(X, Y, n, xj);
		//вывод интерполянта на экран
		cout << xj << "; " << LI << "; " << f(xj) - LI << endl;

		//вывод интерполянта в файл
		fout << xj << "; " << LI << "; " << f(xj) - LI << endl;
	}
	
	cout << "File has been written" << endl;
	

	fout.close();
	delete[] Y;
	delete[] X;

}
