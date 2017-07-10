#include<iostream>
#include<string>
#include<stack>
using namespace std;

//弱智题
//这里要注意的是，字符串类始终不是c——型字符串，意味着即使是‘0’也不代表着就是字符串终止
//它后面的字符仍会打印出来
//所以只要变成c型字符串即可，或者是c_str（）来输出字符串！
int main()
{

	int N;
	cin >> N;
	char ch;
	cin >> ch;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int num; int i = 0;
	while (1)
	{
		if (2 * (i*i - 1) + 1 > N) {
			num = i - 1;
			break;
		}
		i++;
	}
	
	int remain = N - (2 * (num*num - 1) + 1);
	char*arr = new char[2 * num];
	for (int i = 0; i < 2 * num-1; i++) {
		arr[i] = ch;
	}
	arr[2 * num - 1] = 0;
	stack<string> arrstack;
	int head = 0; int tail = 2*num-1 - 1;
	for (int i = 1; i <= num ; i++) {
		cout << arr<<endl;
		arrstack.push(arr);
		arr[head++] = ' ', arr[tail--] =0;
	}
	arrstack.pop();  //把只有一个符号的剔除出去
	while (arrstack.empty() == 0) {
		cout << arrstack.top() << endl;
		arrstack.pop();
	}
	cout << remain << endl;
	system("pause");
	return 0;
}