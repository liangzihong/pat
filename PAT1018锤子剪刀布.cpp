/*1018. 锤子剪刀布 (20)*/

//这题的思路是把双方的出手记录用vector记录下；
//然后用stl中的transform，把两个vector作比较，把结果放在int的vector中（赢得return1，平的return0，输的return-1）
//然后用count输出1，0，-1的个数

//然后再用一个for循环，遍历结果vector，如果是1，则cnt的数目++；最后把三个cnt放入到函数中
//看情况比较大小和字母顺序 输出c j b


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int judge(char ch1, char ch2)
{
	if (ch1 == 'C')
	{
		if (ch2 == 'C') return 0;
		else if (ch2 == 'J') return 1;
		else return -1;
	}
	else if (ch1 == 'J')
	{
		if (ch2 == 'J') return 0;
		else if (ch2 == 'B') return 1;
		else return -1;
	}
	else if (ch1 == 'B')
	{
		if (ch2 == 'B') return 0;
		else if (ch2 == 'C') return 1;
		else return -1;
	}
}

 
void cjb(int c, int j, int b)
{
	if (c > b&&c > j)cout << "C";
	else if (b > c&&b > j)cout << "B";
	else if (j > b&&j > c)cout << "J";
	else if (c == b&&c > j)cout << "B";
	else if (c == j&&c > b)cout << "C";
	else if (b == j&&b > c)cout << "B";
	else if (b == c&&b == j)cout << "B";

}


int main()
{
	int N;
	cin >> N;
	vector<char> jia;
	vector<char> yi;
	char ch1, ch2;
	
	while (cin >> ch1 >> ch2)
	{
		jia.push_back(ch1);
		yi.push_back(ch2);
	}

	vector<int> resjia(N);
	vector<int> resyi(N);

	transform(jia.begin(), jia.end(),yi.begin(), resjia.begin(), judge);
	transform(yi.begin(), yi.end(), jia.begin(), resyi.begin(), judge);

	cout << count(resjia.begin(), resjia.end(), 1) << " "
		<< count(resjia.begin(), resjia.end(), 0) << " "
		<< count(resjia.begin(), resjia.end(), -1)<<"\n";

	cout << count(resyi.begin(), resyi.end(), 1) << " "
		<< count(resyi.begin(), resyi.end(), 0) << " "
		<< count(resyi.begin(),resyi.end(), -1)<<"\n";

	int cntc = 0, cntj = 0, cntb = 0;
	for (int i = 0; i < N; i++)
	{
		if (resjia[i] == 1)
		{
			switch (jia[i])
			{
			case'C':cntc++; break;
			case'J':cntj++; break;
			case'B':cntb++; break;
			}
		}
	}
	cjb(cntc, cntj, cntb);
	cout << " ";
	cntc = 0, cntj = 0, cntb = 0;
	for (int i = 0; i < N; i++)
	{
		if (resyi[i] == 1)
		{
			switch (yi[i])
			{
			case'C':cntc++; break;
			case'J':cntj++; break;
			case'B':cntb++; break;
			}
		}
	}
	cjb(cntc, cntj, cntb);
	system("pause");
	return 0;
}