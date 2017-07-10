
#include<iostream>
#include<cstdio>
using namespace std;

bool judge(int a, int b)
{
	int temp;
	if (a <= b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	if (a == 1)
		return true;
	else
		return false;
}
int main()
{
	int a, b, c, d, e;
	scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &e);
	int f = 0, g = 0;
	int temp1, temp2;
	if (a*d > b*c)
	{
		temp1 = a, temp2 = b;
		a = c, b = d;
		c = temp1, d = temp2;
	}
	while (1)
	{
		if (f*b > a*e)
			break;
		f++;
	}
	while (1)
	{
		if (g*d >= c*e)
			break;
		g++;
	}
	g--;
	int state = 1;
	for (int i = f; i <= g; i++)
	{
		if (judge(i, e)) {
			if (state)
			{
				state = 0;
				printf("%d/%d", i, e);
			}
			else
				printf(" %d/%d", i, e);
		}
	}
	//system("pause");
	return 0;
}