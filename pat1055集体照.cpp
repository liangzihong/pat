#include<iostream>
#include<stack>
#include<deque>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//这题给我的启示是   如果错了，首先要看题，这个非常重要
//其次，改了5次还错，则丢掉它，一段时间后重写，这个非常重要，希望这句话奠定了我以后的习惯。。
//改了五次后还错，丢掉它，一段时间后重写。

//这题的思路是这样的，首先是排序了，这个是毫无疑问的，
//紧接着把排完序后的东西一个接一个放入栈中
//然后在搞一个中转的作用的队列或者栈。
//除了第一次输出最高那一排有num=N/K+N%K个外，其他都是num=N/K个，所以这个要射一个if
//然后把num个逐个放入中转的队列或者栈中，然后剩下的人头数就是等于原先放所有人头那个栈（进去中转栈的people在原先栈中是要pop的）
//此时中转站中存放的就是那一排所要排队的人
//所以此时就要按照所给要求来排序
//于是又弄了一个结果队列！
//凡是单数的，从中转站转出，转入结果队列的后面
//凡是双数的，从中转站转出后，转入结果队列的前面
//直至中转站为空，此时结果队列中就是那一排的人头占位顺序了
//于是输出，输出后还要清空结果队列，然后一次次循环，直至cnt==0，此时就完成了！！

typedef struct fuck
{
	string name;
	int height;
}people;

bool cmp(people&a, people&b)
{
	if (a.height < b.height)
		return true;
	else if (a.height == b.height)
	{
		if (a.name > b.name)
			return true;
		else 
			return false;
	}
	else return false;
}

int main()
{
	int N;
	int K;
	cin >> N >> K;

	vector<people> vectorarr; //排序用的，没什么作用，其实可以用数组来代替，还可以delete掉
	deque<people> quearr1;    //中转队列
	deque<people> queanswer;  //结果队列
	stack<people> stackarr;   //原先栈
	people temp; 
	for (int i = 0; i < N; i++) {
		cin >> temp.name;
		cin >> temp.height;
		vectorarr.push_back(temp);
	}
	if (N == 0) {
		return 0;
	}
	if (K == 0) {
		return 0;
	}

	sort(vectorarr.begin(), vectorarr.end(),cmp);
	for (int i = 0; i < N; i++) {
		stackarr.push(vectorarr[i]);
	}

	int cnt = N;
	int state = 1;
	while (cnt != 0)
	{
		int num;
		//判断是否是最后一排
		if (state == 1) {
			num = N / K + N%K;
			state = 0;
		}
		else{
			num = N / K;
		}
		
		for (int i = 1; i <= num; i++) {       //把原先栈转到中转站并在原先栈中pop（）
			quearr1.push_back(stackarr.top());
			stackarr.pop();
		}

		cnt = stackarr.size();        //cnt是存放全部的栈剩下的个数

		for (int i = 1; quearr1.empty() == 0; i++)         //中转队列到结果队列的转换
		{
			if (i % 2 != 0) {
				queanswer.push_back(quearr1.front());
			}
			else
				queanswer.push_front(quearr1.front());
			quearr1.pop_front();                          //直至中转队列也为空
		}

		deque<people> ::iterator it;
		for (it = queanswer.begin(); it != queanswer.end(); it++)
		{
			cout << (*it).name;
			if (it != queanswer.end() - 1)
			{
				cout << " ";
			}
		}
		queanswer.erase(queanswer.begin(), queanswer.end());     //最后输出完后结果队列是要清空的
		cout << endl;
	}
	system("pause");
	return 0;
}