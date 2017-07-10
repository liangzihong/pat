
#include<iostream>
#include<cstdio>
using namespace std;
          


//方法就是把数用它要的方式表达出来，我用了类，还可以啦



long fuck(long a, long b)
{
	long big, small;
	if (a > b)
		big = a, small = b;
	else
		big = b, small = a;
	long temp;
	while (small != 0)
	{
		temp = big%small;
		big = small;
		small = temp;
	}
	return big;
}


class fraction
{
	long zhenfz;
	long zhenfm;
	long zhengshu;
	long jiafz;
	long jiafm;
public:
	fraction(long fz, long fm=0)
	{
		int fuhao = 1;
		zhenfz = fz, zhenfm = fm;   //真分子分母要相同
		if (fz < 0) fuhao = -1, fz = -fz;   //如果分子小于0，fuhao=-1，fz变为正数
		if (fz == 0)  //一开始就为0
		{
			zhengshu = 0, jiafz = 0, jiafm = 0;      //暂时把jiafm当为0做界值条件
		}

		if (fz%fm == 0)   //1、能整除的
		{
			zhengshu = fz / fm*fuhao, jiafz = 0, jiafm = 0;
		}
		else if (fz > fm)  //2、分子大于分母，但不能整除
		{
			zhengshu = fz / fm*fuhao;
			fz = fz%fm;
			jiafz = fz / fuck(fz, fm);
			jiafm = fm / fuck(fz, fm);
		}
		else    //3、分子小于分母
		{
			zhengshu = 0;
			jiafz = fuhao*fz / fuck(fz, fm);
			jiafm = fm / fuck(fz, fm);
		}
	}

	void show()
	{
		if (zhenfz < 0)
			cout << "(";
		if (jiafm == 0)    //界值条件,表示只表示整数即可
		{
			cout << zhengshu;
		}
		else if (zhengshu != 0)
			cout << zhengshu << " " << jiafz << "/" << jiafm;
		else
			cout << jiafz << "/" << jiafm;
		if (zhenfz < 0)
			cout << ")";
	}


	bool iszero()
	{
		if (zhengshu == 0 && jiafm == 0)
			return true;
		else return false;
	}
};

int main()
{
	long a, b, c, d;
	scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
	fraction one(a, b), two(c, d);
	fraction three(a*d + b*c, b*d);
	one.show(); cout << " + "; two.show(); cout << " = "; three.show();cout << endl;
	fraction four(a*d - b*c, b*d);
	one.show(); cout << " - "; two.show(); cout << " = "; four.show(); cout << endl;
	fraction aaa(a*c, b*d);
	one.show(); cout << " * "; two.show(); cout << " = "; aaa.show(); cout << endl;
	
	one.show(); cout << " / "; two.show(); cout << " = ";
	if (two.iszero())
		cout << "Inf" << endl;
	else {
		if (c < 0) a = -a, c = -c;
		fraction bbb(a*d, b*c);
		bbb.show();
		cout << endl;
	}
	system("pause"); 
	return 0;
}














