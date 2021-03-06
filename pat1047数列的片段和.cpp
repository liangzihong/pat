#include<iostream>
#include<cstdio>
using namespace std;

/*PAT1049 题目如下
	给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列
	{0.1, 0.2, 0.3, 0.4}，
	我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2)
	(0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。
	给定正整数数列，求出全部片段包含的所有的数之和。
	如本例中10个片段总和是
	0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。*/

//通过列式子可以得到，1这个数是顺数第一个，倒数第四个，而相加的式子中出现了四次
//2这个数是顺数第二个，倒数第三个，而相加的式子中出现了2六次
//3这个数是顺数第三个，倒数第二个，而相加的式子中出现了3六次
//4这个数是顺数第四个，倒数第一个，而相加的式子中出现了4四次
//以上可以通过推理得到，因为从后往前算时，很容易就会有这个规律出现

//属于弱智题


int main()
{
	int T;
	cin >> T;
	
	double *arr = new double[T];

	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
	}

	int N = T;
	double result = 0.0;

	for (int i = 0; i < T; i++)
	{
		result += arr[i] * N*(T + 1 - N);
		N--;
	}

	printf("%.2f", result);
	system("pause");
	cout << endl;
}