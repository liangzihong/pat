#include<iostream>
#include<string>
using namespace std;

typedef struct aaa
{
	string name;
	string xuehao;
	int mark;
}Node;

//结构体的数组排序，弱智题





typedef struct bbb
{
	Node *arr;
}List;

void sort(List*list,int n)
{
	Node*arr = list->arr;
	int k;
	Node temp;
	for (int i = 0; i < n-1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[k].mark < arr[j].mark)
			{
				k = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

int main()
{
	List list;
	int T;
	cin >> T;
	list.arr = new Node[T];
	int cnt = 0;

	while (cnt<T)
	{
		cin >> list.arr[cnt].name;
		cin >> list.arr[cnt].xuehao;
		cin >> list.arr[cnt++].mark;
	}

	sort(&list, T);
	cout << list.arr[0].name << " " << list.arr[0].xuehao << endl;
	cout<< list.arr[T-1].name << " " << list.arr[T-1].xuehao << endl;

	system("pause");
	return 0;
}