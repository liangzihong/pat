
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;




//这题有点屌，用了我不少的时间。。。。。
//其实还是一道弱智题，但是自己想不到旧的答案哪里出错
//原理还是从大到小找，temp=arr【N+1】/p；然后从1开始找第一个比temp大的数
//但是直接这样找会超时
//于是我用了另一种方法。就是把原先的数排序，然后把0去掉，这个很关键。！！
//然后开一个结构point，里面记录了value和这个数的排名；
//并且顺手记录下比p要小的数的个数，（由数学原理可知，当两个数都比p小，则p*min》=max肯定成立）

//然后！！再把比p要大的数，将这个数/p作为point的value，change=1表示是除以过来的
//然后进行排序！！！！value小的排在大的后面，当value相等时，change=1的排在change=0的前面
//然后得到的就是一个原来的数+大于p的数/p的大小排列
//此时只要知道，每一个change=1的point中，它目前排的位置的后面的第一个change=0即为比第一个比temp大的数（与13行对应）
//所以可以数它左面有idx个change=0，答案就为point.oldrate-idx;
//如果不懂，可以举个简单例子
//如  7  10
//    1 2 20 30 40 160 200
//则变成  
//    1 2 2 3 4 16 20 20 30 40 160 200
//这里change=1的数有    第一个2，3，4，16，第一个20
//因为第一个20在原先的数列里面排在20的前面，所以它到200有5个数，所以最多
//而4在原先的数列里面排在20的前面，所以它到40有3个数
//如此类推

//但是看了柳婼的答案才知道，原先的答案其实改进一下不会超时！！！我顶！！！我觉得会超时啊




typedef struct fuck
{
	double value;
	int oldrate;
	int newrate;
	int change;
}point;

bool cmp(point&a, point&b)
{
	if (a.value < b.value)return true;
	else if ((!(a.value > b.value)) && (!(a.value<b.value)))
	{
		if (a.change == 1) return true;
		else return false;
	}
	return false;
}

int main()
{
	int N; cin >> N;
	double p; cin >> p;

	if (N == 0) {
		cout << 0;
		return 0;
	}

	double *arr = new double[N + 1];
	for (int i = 1; i < N + 1; i++) {
		cin >> arr[i];
	}
	sort(&arr[1], &arr[N + 1]);
	if (p == 0) {
		if(arr[1]==0)
		{
			cout << 1; return 0;
		}
		else {
			cout << 0; return 0;
		}
	}
	if (arr[1] == 0) {                //去掉0
		for (int i = 1; i < N; i++) {
			arr[i] = arr[i + 1];
		}
		N--;
	}
	vector<point> arr2(N+1);
	int cntnotchange = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (arr[i] <= p)
		{
			cntnotchange++;
		}
		arr2[i].value = arr[i];
		arr2[i].change = 0;
		arr2[i].oldrate = i;
	}
	for (int i = cntnotchange; i < N + 1; i++) {
		point temp;
		temp.value = arr[i] / double(p);
		temp.change = 1;
		temp.oldrate = i;
		arr2.push_back(temp);
	}
	sort(arr2.begin()+1, arr2.end(), cmp);

	vector<int> answer(1, cntnotchange);

	int idx = 0;
	for (vector<point>::iterator it = arr2.begin() + 1;
		it != arr2.end(); it++)
	{
		if ((*it).change == 0) {
			idx++;
		}
		else {
			int transmit;
			transmit = (*it).oldrate - idx;
			answer.push_back(transmit);
		}
	}

	sort(answer.begin(), answer.end());
	cout << *(answer.end() - 1);
	delete[]arr;
	system("pause");
	return 0;
}