
#include<iostream>
#include<cstdio>
using namespace std;
          


//�������ǰ�������Ҫ�ķ�ʽ���������������࣬��������



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
		zhenfz = fz, zhenfm = fm;   //����ӷ�ĸҪ��ͬ
		if (fz < 0) fuhao = -1, fz = -fz;   //�������С��0��fuhao=-1��fz��Ϊ����
		if (fz == 0)  //һ��ʼ��Ϊ0
		{
			zhengshu = 0, jiafz = 0, jiafm = 0;      //��ʱ��jiafm��Ϊ0����ֵ����
		}

		if (fz%fm == 0)   //1����������
		{
			zhengshu = fz / fm*fuhao, jiafz = 0, jiafm = 0;
		}
		else if (fz > fm)  //2�����Ӵ��ڷ�ĸ������������
		{
			zhengshu = fz / fm*fuhao;
			fz = fz%fm;
			jiafz = fz / fuck(fz, fm);
			jiafm = fm / fuck(fz, fm);
		}
		else    //3������С�ڷ�ĸ
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
		if (jiafm == 0)    //��ֵ����,��ʾֻ��ʾ��������
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














