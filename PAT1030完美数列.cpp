
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;




//�����е�ţ������Ҳ��ٵ�ʱ�䡣��������
//��ʵ����һ�������⣬�����Լ��벻���ɵĴ��������
//ԭ���ǴӴ�С�ң�temp=arr��N+1��/p��Ȼ���1��ʼ�ҵ�һ����temp�����
//����ֱ�������һᳬʱ
//������������һ�ַ��������ǰ�ԭ�ȵ�������Ȼ���0ȥ��������ܹؼ�������
//Ȼ��һ���ṹpoint�������¼��value���������������
//����˳�ּ�¼�±�pҪС�����ĸ�����������ѧԭ���֪��������������pС����p*min��=max�϶�������

//Ȼ�󣡣��ٰѱ�pҪ��������������/p��Ϊpoint��value��change=1��ʾ�ǳ��Թ�����
//Ȼ��������򣡣�����valueС�����ڴ�ĺ��棬��value���ʱ��change=1������change=0��ǰ��
//Ȼ��õ��ľ���һ��ԭ������+����p����/p�Ĵ�С����
//��ʱֻҪ֪����ÿһ��change=1��point�У���Ŀǰ�ŵ�λ�õĺ���ĵ�һ��change=0��Ϊ�ȵ�һ����temp���������13�ж�Ӧ��
//���Կ�������������idx��change=0���𰸾�Ϊpoint.oldrate-idx;
//������������Ծٸ�������
//��  7  10
//    1 2 20 30 40 160 200
//����  
//    1 2 2 3 4 16 20 20 30 40 160 200
//����change=1������    ��һ��2��3��4��16����һ��20
//��Ϊ��һ��20��ԭ�ȵ�������������20��ǰ�棬��������200��5�������������
//��4��ԭ�ȵ�������������20��ǰ�棬��������40��3����
//�������

//���ǿ������S�Ĵ𰸲�֪����ԭ�ȵĴ���ʵ�Ľ�һ�²��ᳬʱ�������Ҷ��������Ҿ��ûᳬʱ��




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
	if (arr[1] == 0) {                //ȥ��0
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