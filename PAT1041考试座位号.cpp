#include<iostream>
#include<string>
using namespace std;




//��Ȼ�������⣬���ǻ����������ܽ�һ��
//���ﶼ��һ�����ɣ�������������Ϊ���飬��������Ϊ�������������������ʡ�ܶ�ʱ�䣬�����������ռ�Ϊ����
//���������ṹ��һ��computer��int��Ϊ������
//�ǿ��Խ��ƾͼ�newһ�����飬���������ṹʱ������computer��Ϊ������±꣬�����Ǵ�i=0��ʼ֮���




//��������Ϊ���飬�����ռ任ȡʱ��
//��ص�����1061  1064  1065
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