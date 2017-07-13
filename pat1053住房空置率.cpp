/*在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：

在观察期内，若存在超过一半的日子用电量低于某给定的阈值e，则该住房为“可能空置”；
若观察期超过某给定阈值D天，且满足上一个条件，则该住房为“空置”。
现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

输入格式：

输入第一行给出正整数N（<=1000），为居民区住房总套数；正实数e，即低电量阈值；正整数D，即观察期阈值。随后N行，每行按以下格式给出一套住房的用电量数据：

K E1 E2 ... EK

其中K为观察的天数，Ei为第i天的用电量。*/

#include<iostream>
using namespace std;

int main()
{
	double N, e, D;
	int idx = 0;  //可能空置的数目
	int state = 0; //可能空置的状态
	int empty = 0;
	cin >> N >> e >> D;
	for (int i = 0; i < N; i++) {
		int state = 0;
		int K;
		cin >> K;
		double *arr = new double [K];
		int cnt = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> arr[j];
			if (arr[j] < e) cnt++;
		}
		if (cnt > K / 2) { idx++; state = 1; }
		if (state == 1 && K > D) { empty++; }
		delete[]arr;
	}
	cout << fixed;
	cout.precision(1);
	cout << 100*(idx-empty) / N << "% " << 100*empty / N << "%";
	system("pause");
	return 0;
}