#include <iostream>
#include "fstream"
#include <vector>

using namespace std;

int convertToRing(int a, int p)
{
	while (a < 0)
		a += p;
	a %= p;
	return a;
}

int fraction(int one, int two, int p)
{
	int i = 1;
	while ((two * i) % p != 1)
	{
		i++;
	}
	return (one * i) % p;
}

int lagrangePol(int p, int a, int n, vector<int> x, vector<int> y)
{
	int res = 0;
	int P;
	for (int i = 0; i < n; i++)
	{
		P = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				P *= fraction(convertToRing(a - x[j], p), convertToRing(x[i] - x[j], p), p);
				P = convertToRing(P, p);
			}
		}
		res += (convertToRing(y[i], p) * convertToRing(P, p));
		res = convertToRing(res, p);
	}
	return res;
}
int main()
{
	int p; 
	ifstream data("C:\\Users\\hp\\Desktop\\УЧЕБА\\input.txt");
	ofstream result("C:\\Users\\hp\\Desktop\\УЧЕБА\\result.txt");
	if (!data.is_open())
	{
		return 0;
	}
	data >> p;
	int a;
	data >> a;
	int N; 
	data >> N;
	vector<int> x{};
	vector<int> y{};
	int xi, yi;
	for (int i = 0; i < N; i++)
	{
		data >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
	}
	result << lagrangePol(p, a, N, x, y);
	cout << "IT'S OKAY" << endl;
}
