#include<iostream>
#include<algorithm>
using namespace std;

struct fuck{
	int idx;
	double ave;
};



bool cmp(fuck a, fuck b)
{
	return a.ave > b.ave;
}


int main()
{
	int cnt, need;
	cin >> cnt >> need;
	double *num = new double[cnt];
	double*price = new double[cnt];
	fuck*average = new fuck[cnt];
	double all = 0.0;
	int i = 0;

	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < cnt; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < cnt; i++) {
		average[i].idx = i;
		average[i].ave = double(price[i]) / num[i];
	}

	sort(average+0, average+cnt, cmp);
	 
	for (int i = 0; i < cnt; i++)
	{
		if (need > num[average[i].idx])
		{
			all +=price[average[i].idx];
			need -= num[average[i].idx];
		}
		else
		{
			all = all + average[i].ave*need;
			need = 0;
		}
		if (need <= 0)	break;
	}
	cout << fixed;
	cout.precision(2);
	cout << all;
	system("pause");
	return 0;

}