#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<iterator>
#include<cmath>
using namespace std;

//在这题中，我选择用list而不用vector的原因是没试过list，并且list有push——front用
//但是其实vector也有insert充当pushfront的作用，并且不需用循环添加
//要注意的蚀list许多表达都要有迭代器充当过渡，并且迭代器没有重载+1，只有自增，所以要不断寻找的合适的位置
//这里用到了erease要用迭代器，find也是返回迭代器。









int main()
{
	list<char> numlist;
	char ch;  //输入的记录
	while (cin >> ch)
	{
		numlist.push_back(ch);            //输入数字在链表numlist中
	}

	list<char>::iterator emark; //E的位置;要用迭代器来表示
	emark = find(numlist.begin(), numlist.end(), 'E');

	int zhishu; //指数的大小;
	string temp(++emark,numlist.end());  //temp记录e后面的指数；
	zhishu = stoi(temp);
	//copy(emark, numlist.end(),
	//	insert_iterator<string>(temp, temp.begin()));


	list<char> answerlist(numlist.begin(),--emark);
	answerlist.pop_front();       //去掉正负号；
	list<char>::iterator answerpoint=answerlist.begin();   //answerlist的专用迭代器
	answerpoint = find(answerlist.begin(), answerlist.end(), '.');//找到‘.’
	answerlist.erase(answerpoint);//把纯数字记录在answerlist中，这步是删掉‘.’
	answerpoint = answerlist.begin();

	if (zhishu < 0)            //如果指数小于0，则在前面加0，用push——front（），加绝对值个0
	{
		for (int i = 0; i < abs(zhishu); i++)
		{
			answerlist.push_front('0');
		}
		answerpoint = answerlist.begin();
		answerlist.insert(++answerpoint, '.');       //然后直接在第二位insert个小数点
	}
	else                    //如果指数大于0，则有三种情况
	{
		if (zhishu < answerlist.size() - 1)   //不用在后面加0的，要加小数点的
		{
			//把迭代器的位置放在需要加小数点的地方
			answerpoint = ++answerlist.begin();
			while (zhishu-- > 0)
			{
				answerpoint++;
			}
			answerlist.insert(answerpoint, '.');   //放小数点
		}
		else if (zhishu == answerlist.size() - 1)  //刚好不用加0也不用加小数点的
		{
			/*while (answerpoint++ != answerlist.end())
			{
				cout << *answerpoint;
			}*/
		}
		else  //只加0的
		{
			int temp = zhishu - answerlist.size() + 1;
			while (temp != 0)
			{
				answerlist.push_back('0');
				temp--;
			}
		}
	}


	if (*numlist.begin() == '-')              //如果前面有符号，则push个－进去
	{
		answerlist.push_front('-');
	}

	answerpoint = answerlist.begin();
	while (answerpoint != answerlist.end())       //输出即可
	{
		cout << *answerpoint++;
	}

	system("pause");
	return 0;
}