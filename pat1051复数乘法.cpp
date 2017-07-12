#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;


//注意-0.03输出的要是0.00而不是-0.00，这是一个知识盲点。


int main()
{
	long double a, b, r1,p1,r2,p2;
	cin >> r1 >> p1 >> r2 >> p2;
	long double c, d;
	a = r1*cos(p1)*r2*cos(p2);
	b = r1*sin(p1)*r2*sin(p2);
	cout << fixed;
	cout << setprecision(2);
	if (a - b < 0 && a - b + 0.005>0)
		cout << "0.00";
	else cout << a - b;


	c = r1*cos(p1)*r2*sin(p2);
	d = r2*cos(p2)*r1*sin(p1);

	if (c + d >=0)
		cout << "+" << abs(c + d) << "i";
	else if(c+d<0&&c+d+0.005>0)
		cout << "+0.00" << "i";
	else cout << "-" << abs(c + d) << "i";

	system("pause");
	return 0;
}