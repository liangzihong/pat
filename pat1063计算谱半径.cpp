#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

//»¹ÊÇÈõÖÇÌâ


int main()
{
	int N;
	cin >> N;
	int a; int b;
	vector<double> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		double temp;
		temp = a*a + b*b;
		arr.push_back(sqrt(temp));
	}
	sort(arr.begin(), arr.end());
	cout << fixed;
	cout.precision(2);
	cout << *(arr.end() - 1);
	system("pause");
	return 0;
}