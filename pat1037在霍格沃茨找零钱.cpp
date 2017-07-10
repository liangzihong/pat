#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int big = 493;
const int small = 29;

int main()
{
	int houra, mina, seca;
	int hourb, minb, secb;
	scanf("%d.%d.%d", &houra, &mina, &seca);
	scanf("%d.%d.%d", &hourb, &minb, &secb);
	int alla;
	int allb;

	alla = houra*big + mina*small + seca;
	allb = hourb*big + minb*small + secb;
	
	if (alla > allb) {
		cout << "-";
	}
	int distan = abs(alla - allb);
	int a, b, c;
	a = distan / big;
	cout <<a << ".";
	b = distan - big*a;
	c = b / small;
	cout << c << ".";
	cout << b - c*small;
	system("pause");
	return 0;
}