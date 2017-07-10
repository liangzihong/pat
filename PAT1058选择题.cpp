#include<iostream>
#include<valarray>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;


//这题弱智题竟然用了我一个半小时
//主要是细节上出了差错，他的输入格式竟然要考虑到括号那么嘿麻烦
//用到了一个
/*while ((eh = cin.get()) && isdigit(eh) == 0)
{
	continue;
}*/
//循环，吃掉数字前面的东西
//然后其实不难，就是用字符串判断答案是否正确即可


typedef struct fuck
{
	int issumenum; //题目编号
	int fenzhi;    //满分值
	int choosenum; //选项数目
	int answernum; //答案数目
	string daan;   //答案
	int wrongnum;  //错误人数
}issue;
bool cmp(issue&a, issue&b)
{
	if (a.wrongnum > b.wrongnum)
		return true;
	if (a.wrongnum == b.wrongnum&&a.issumenum < b.issumenum)
		return true;
	return false;
}
int main()
{
	int M;
	int N;
	cin >> N >> M;

	issue * arr = new issue[M + 1];

	for (int i = 1; i < M + 1; i++)
	{
		arr[i].issumenum = i;
		cin >> arr[i].fenzhi;
		cin >> arr[i].choosenum;
		cin >> arr[i].answernum;
		arr[i].daan = "";
		char ch;
		while (ch = cin.get())
		{
			if (ch == '\n') break;
			if (isalpha(ch)) arr[i].daan += ch;
		}
		arr[i].wrongnum = 0;
	}


	for (int idx = 0; idx < N; idx++)      //第几个学生
	{
		string stu = "";
		int num;   //学生每一题的选项数目
		int mark = 0;    //学生的分数
		char eh;
		for (int i = 1; i < M + 1; i++)     //第几题         
		{
			//cin.get();   //吸收左括号
			//cin >> num;        //学生每一题的选项数目
			while ((eh=cin.get())&&isdigit(eh) == 0)
			{
				continue;
			}
			num = eh - '0';
			char dh;
			stu = "";
			for (int j = 0; j < num; j++)      //每一题的选项
			{	
				dh = cin.get();
				while (!isalpha(dh))
					dh = cin.get();
				stu += dh;
			}
			if (stu == arr[i].daan)
			{
				mark += arr[i].fenzhi;
			}
			else
			{
				arr[i].wrongnum++;
			}
		}
		cout << mark << endl;
	}

	sort(&arr[1], &arr[M+1],cmp);
	int temp = arr[1].wrongnum;
	if (temp == 0)
	{
		cout << "Too simple\n";
	}
	else {
		cout << temp;
		for (int i = 1; i < M + 1; i++)
		{
			if (temp == arr[i].wrongnum)
				cout <<" "<< arr[i].issumenum;
		}
	}
	//system("pause");
	return 0;
}