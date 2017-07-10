#include<iostream>
#include<string>
using namespace std;




//虽然是弱智题，但是还是在这里总结一下
//这里都有一个技巧，就是用数字作为数组，用数字作为索引来搜索，这样会节省很多时间，但是以牺牲空间为代价
//如这里，这个结构有一个computer的int作为搜索的
//那可以将计就计new一个数组，输入整个结构时，就以computer作为数组的下标，而不是从i=0开始之类的




//用数字作为数组，牺牲空间换取时间
//相关的题是1061  1064  1065
typedef struct fuck
{
	string longnum;
	int computer;
	int seat;
}student;

int main()
{
	int N;
	cin >> N;
	student *arr = new student [1001];
	string tempnum;
	int tempcomputer;
	int tempseat;
	for (int i = 0; i < N; i++)
	{
		cin >> tempnum;
		cin >> tempcomputer;
		cin >> tempseat;
		arr[tempcomputer].longnum = tempnum;
		arr[tempcomputer].computer = tempcomputer;
		arr[tempcomputer].seat = tempseat;
	}

	int cnt;
	cin >> cnt;
	int test;
	for (int i = 0; i < cnt; i++)
	{
		cin >> test;
		cout << arr[test].longnum << " " << arr[test].seat << endl;
	}
	//system("pause");
	return 0;
}