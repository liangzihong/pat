#include<iostream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

//����⿴�Ƽ򵥣����кܶ����˵ĵط�
//�����Ƿ�Χ��������longlong
//������ö��ַ���ʱ��right�䵱��һ������
//�����õ�right�䵱standard+1�Ǹ�������Ϊ�������Ʊ�standard�ٴ󣬿϶���standard����

//Ȼ����Ϊ����ʵ��̫���ˣ��϶�����������������
//���S�������һ��������ȫ�ų������
//��Ϊ�����Ҫô�ܴ�Ҫô��С���������С��0����˵������̫������ֱ��right=middle-1��
//���standard>��������,˵������С��ֱ��left=middle+1��
//�����Ⱦ����
//else  ��ʣ���һ��������ƺܴ󣬵�������������Ҳ�ܴ����Դ�ʱһ��else ֱ���ж�right=middle-1��


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
	long long right = standard+1;         //��û����ʾ���Ƶ��Ǹ�������С���Ʊ���֪��standard��Ҫ��ֻ���������
											//һ������С���Ʊ�standard��һ����standardҪ����һ�Է�11==b�������
											//��һ�־�����С���Ʊ�standard��һ���ϣ��ǾͲ����������
	
	while (left <= right)
	{
		long long middle=(left + right) / 2;
		if (todecimal(temp, middle) < 0)           //��ָ���ǳ��󣬻�ȡ���ֵ����
			right = middle - 1;
		else if (todecimal(temp, middle) < standard)
			left = middle + 1;
		else if (todecimal(temp, middle) == standard)
		{
			cout << middle; //system("pause");
			return 0;
		}
		else  //�������������Ҳ�Ƿǳ���Ҳ��ȥ���ֵ
			right = middle - 1;
	}
	cout << "Impossible";
	
	system("pause");
	return 0;
}