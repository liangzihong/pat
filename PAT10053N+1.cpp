#include<iostream>
using namespace std;

//��������������������������ÿһ��������3N+1���룬Ȼ��ѵõ������Ž��������У��������һ�����ڶ��������Ѵ��ڣ���ֱ�ӱ�Ϊ1�������ٱ仯��
//Ȼ�������ٴν��б�����������������������е�Ԫ�أ��������е�Ԫ�ر����-1��
//�ڶ���������������鲻��-1��Ԫ���ٷŽ���������������print��ʱ��ֱ�ӾͿ��ԡ�

//��ʵ��֪��������ö�������ûӰ�죬�������ˣ����Կ������S�Ĵ𰸣�



struct Node
{
	int n;
	Node*left;
	Node*right;
};

Node*addleaf(Node*a, int&s)
{
	if (a == NULL)
	{
		a = new Node;
		a->n = s, a->left = NULL, a->right = NULL;
	}
	else if (s < a->n)
	{
		a->left = addleaf(a->left, s);
	}
	else if (s > a->n)
	{
		a->right = addleaf(a->right, s);
	}
	else
		s = 1;
	return a;
}

void search(Node*a, int&s)
{
	if (a == NULL)
	{
		return;
	}
	if (s < a->n) {
		search(a->left, s);
	}
	else if (s > a->n) {
		search(a->right, s);
	}
	else
		s= -1;
	return;
}

void print(Node*a)
{
	static int cnt = 0;
	if (a == NULL) {
		return;
	}
	print(a->right);

	if (cnt != 0)
	{
		cout << " ";
	}
	cout << a->n;
	cnt++;

	print(a->left);
}


int main()
{
	int max;
	cin >> max;
	int*arr = new int[max];
	for (int i = 0; i < max; i++)
	{
		cin >> arr[i];
	}

	Node*head = NULL;
	int temp;
	for (int i = 0; i < max; i++)
	{
		temp = arr[i];
		while (temp != 1)
		{
			if (temp % 2)
			{
				temp = (temp * 3 + 1) / 2;
				head = addleaf(head, temp);
			}
			else {
				temp = temp / 2;
				head = addleaf(head, temp);
			}
		}
	}

	for (int i = 0; i < max; i++)
	{
		search(head, arr[i]);
	}

	Node*second = NULL;
	for (int i = 0; i < max; i++)
	{
		if (arr[i] != -1)
		{
			second = addleaf(second, arr[i]);
		}
	}

	print(second);
	system("pause");
	return 0;
}