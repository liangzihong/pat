#include<iostream>
using namespace std;

//我这题是用了两个二叉树，把每一个数进行3N+1猜想，然后把得到的数放进二叉树中，（如果另一个数在二叉树中已存在，则直接变为1，不用再变化）
//然后数组再次进行遍历，如果二叉树中有数组中的元素，则数组中的元素变成了-1；
//第二个二叉树则把数组不是-1的元素再放进二叉树，所以再print的时候直接就可以。

//其实不知道如果不用二叉树有没影响，但是用了，可以看看柳婼的答案；



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