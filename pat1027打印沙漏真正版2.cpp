#include<iostream>
#include<string>
#include<stack>
using namespace std;

//������
//����Ҫע����ǣ��ַ�����ʼ�ղ���c�������ַ�������ζ�ż�ʹ�ǡ�0��Ҳ�������ž����ַ�����ֹ
//��������ַ��Ի��ӡ����
//����ֻҪ���c���ַ������ɣ�������c_str����������ַ�����
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
	arrstack.pop();  //��ֻ��һ�����ŵ��޳���ȥ
	while (arrstack.empty() == 0) {
		cout << arrstack.top() << endl;
		arrstack.pop();
	}
	cout << remain << endl;
	system("pause");
	return 0;
}