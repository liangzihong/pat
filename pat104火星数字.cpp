#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;


//A这一题有点辛苦，首先是输入识别问题，要知道存不存在第二个单词，也要知道如果只有一个单词，那第一个单词代表的十位还是个位
//这里识别首先使用的是   cin.get()来逐个逐个输入，如果识别回车，直接break，如果识别空格，则开启开关，启动第二个target
//如果是数字，则要把数字变成13进制，对应的字符串输出，如果数字小于13，则只输出对应的marsgewei个位
//如果数字大于13，这时又有两种情况，因为如果是刚好是13的整数倍，则个位不输出，于是用了？：结构，

//然后便是如果是火星数字，只有一个单词的，可以用target2=target1来同时进行搜索，此时反正都有一个会中，搜索到，则对应的shi，ge为
//对应的数字，然后输出shi*13+ge即可

int main()
{
	int N; cin >> N; cin.get();
	string input;
	string mars[13] = { "tret","tam","hel","maa","huh","tou","kes","hei",
		"elo","syy","lok","mer","jou" };
	string marsgewei[13] = { "tret","jan","feb","mar","apr","may","jun",
		"jly","aug","sep","oct","nov","dec" };
	
	string target1 = "";
	string target2 = "";
	int state = 0;
	char first;
	
	for (int i = 0; i < N; i++) 
	{
		state = 0;
		target1 = "", target2 = "";
		while (first = cin.get())
		{
			if (first == '\n')
				break;
			else if (first == ' ')    //如果是有空格，则会有两个单词出现
			{
				state = 1; continue;
			}
			if (state == 0)       //只有一个单词，所以字母添加再target1
				target1 += first;
			else target2 += first;  //有两个单词出现，所以字母添加在target2
		}


		if (isdigit(target1[0])) {
			int digit = stoi(target1);
			if (digit < 13) cout << marsgewei[digit] << endl;
			else {
				cout << mars[digit / 13];
				(digit % 13) ? (cout << " " << marsgewei[digit % 13] << endl)
					: (cout << endl);
			}
		}

		else 
		{
			int shi = 0; int ge = 0;
			if (target2 == "") target2 = target1;      //防止只有一个单词时不知道是十位还是个位，这样处理就能通杀，代码不用改动太多
				for (int i = 0; i < 13; i++) {
					if (mars[i] == target1) {
						shi = i;
						break;
					}
				}
				for (int j = 0; j < 13; j++) 
				{
					if (marsgewei[j] == target2) {
						ge = j; break;
					}
				}

			cout << shi * 13 + ge << endl;
		}
	}

	system("pause");
	return 0;
}