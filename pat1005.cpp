#include<iostream>
#include<string>
using namespace std;

int n = 0;



//���ַ����࣬��һ�����ʣ���c=getchar�������տո���߻س�
//����ǿո���ݹ���У�����ǻس����򲻽�����һ��ݹ��ˣ�
//�ݹ������ʼ���Ϳ�ʼ���������return��


void read(void)
{
	n++;
	int b = n;
	string a;
	cin >> a;
	char c = getchar();

	if (c != '\n')
	{
		read();
	}
	cout << a;
	if (b != 1)
	{
		cout<< " ";
	}
	return;
}

int main()
{
	read();
	system("pause");
	return 0;
}