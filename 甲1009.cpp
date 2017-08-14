#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct poly
{
	int exponent;
	double coefficients;
};


bool cmp(poly&a, poly&b)
{
	return a.exponent > b.exponent;
}


typedef vector<poly> ARR;

int main()
{
	int T; cin >> T;
	ARR arr1;
	poly temp;
	for (int i = 0; i < T; i++) {
		cin >> temp.exponent;
		cin >> temp.coefficients;
		arr1.push_back(temp);
	}

	cin >> T;
	ARR arr2;
	for (int i = 0; i < T; i++) {
		cin >> temp.exponent;
		cin >> temp.coefficients;
		arr2.push_back(temp);
	}

	ARR ans;
	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < arr2.size(); j++)
		{
			temp.exponent = arr1[i].exponent+arr2[j].exponent;
			temp.coefficients = arr1[i].coefficients*arr2[j].coefficients;
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	ARR output;
	int cnt;
	for (cnt = 1; cnt < ans.size(); cnt++)
	{
		if (ans[cnt].exponent == ans[cnt - 1].exponent)
			ans[cnt].coefficients += ans[cnt - 1].coefficients;
		else if(ans[cnt-1].coefficients!=0)
			output.push_back(ans[cnt - 1]);
	}
	output.push_back(ans[cnt - 1]);

	cout << fixed;
	cout.precision(1);
	cout << output.size() << " "<<output[0].exponent<<" "<<output[0].coefficients;
	for (int i = 1; i < output.size(); i++)
	{
		cout<< " " << output[i].exponent << " " << output[i].coefficients;
	}
	system("pause");
	return 0;
}