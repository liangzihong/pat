#include<iostream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

//这道题看似简单，但有很多阴人的地方
//首先是范围，必须是longlong
//其次是用二分法的时候，right充当哪一个数。
//这里用到right充当standard+1那个数，因为这样进制比standard再大，肯定比standard更大

//然后因为进制实在太大了，肯定会有随机数（溢出）
//柳婼大神就用一个方法完全排除了溢出
//因为随机数要么很大，要么很小，所以如果小于0，则说明进制太大，所以直接right=middle-1；
//如果standard>处理后的数,说明进制小，直接left=middle+1。
//如果相等就最好
//else  还剩最后一种情况进制很大，导致溢出后处理的数也很大，所以此时一个else 直接判断right=middle-1；


int minradix(string arr)
{
	int cnt = arr.size();
	int min = 0;
	char ch = '0';
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= ch)
			ch = arr[i];
	}
	if (isalpha(ch))
		min =ch- 87;
	else
		min= ch-'0';
	return min + 1;
}


long long todecimal(string arr, long long radix)
{
	int each;
	long long sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (isalpha(arr[i]))
			each = arr[i] - 87;
		else 
			each = arr[i] - '0';
		sum = sum*radix + each;
	}
	return sum;
}

int main()
{
	string temp;
	string first;
	string second;
	cin >> first >> second;
	int tag;
	long long radix;
	cin >> tag >> radix;
	long long standard;
	long long ans;
	if (tag == 1)
		standard = todecimal(first, radix), ans = minradix(second),temp = second;
	else
		standard = todecimal(second, radix), ans = minradix(first),temp = first;
	long long res = todecimal(temp, ans);

	long long left = ans; 
	long long right = standard+1;         //当没有显示进制的那个数的最小进制比已知的standard还要大，只有两种情况
											//一种是最小进制比standard大一，则standard要加上一以防11==b这种情况
											//另一种就是最小进制比standard大一以上，那就不可能相等了
	
	while (left <= right)
	{
		long long middle=(left + right) / 2;
		if (todecimal(temp, middle) < 0)           //当指数非常大，会取随机值负数
			right = middle - 1;
		else if (todecimal(temp, middle) < standard)
			left = middle + 1;
		else if (todecimal(temp, middle) == standard)
		{
			cout << middle; //system("pause");
			return 0;
		}
		else  //其他情况，基数也是非常大，也是去随机值
			right = middle - 1;
	}
	cout << "Impossible";
	
	system("pause");
	return 0;
}