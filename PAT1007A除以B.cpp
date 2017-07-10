#include<iostream>
#include<vector>
#include<string>
using namespace std;



//思路：直接像竖式除法那样算
//为了适应stl，这题用了STL里的vector容器，里面有push_back(),还有vector《int》：：iterator作为迭代器
//然后如果小于num的，就在答案上+0，并且将下一个数赋值为10**it+*（it+1）；
//然后输出的时候，就从第一个不是0的数开始输出，如果全部都为0，则输出0；


int main()
{
	vector<int> arr;
	vector<int> answer;

	string bignum;
	cin >> bignum;
	int num;
	cin >> num;
	int temp;
	int yushu;    //余数
	int zhengshu; //整数

	for (int i = 0; i<bignum.size(); i++)
	{
		arr.push_back(int(bignum[i] - 48));
	}

	vector<int>::iterator it;
	for (it = arr.begin(); it != arr.end()-1; it++)
	{
		if (*it < num)
		{
			/*temp = *it*10+*(it + 1);
			yushu = temp%num;
			zhengshu = temp / num;
			answer.push_back(zhengshu);
			*(it + 1) = yushu;*/
			
			answer.push_back(0);
			*(it + 1) = *it * 10 + *(it + 1);
		}
		else
		{
			zhengshu = *it / num;
			yushu = *it%num;
			answer.push_back(zhengshu);
			*(it + 1) = yushu * 10 + *(it + 1);
		}
	}

	zhengshu = *it / num;
	yushu = *it % num;
	answer.push_back(zhengshu);

	int state = 0;  //要从第一个不是0的数字开始输出;
	for (it = answer.begin(); it != answer.end(); it++)
	{
		if (it == answer.end() - 1 && state == 0)         //如果全部都为0，还是要输出0;
		{
			cout << *it;
		}
		if (*it == 0&&state==0)
		{
			continue;
		}

		state = 1;
		cout << *it;
	}
	cout << " "<<yushu;

	system("pause");
	return 0;
}