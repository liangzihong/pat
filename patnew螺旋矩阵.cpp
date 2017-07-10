#include<iostream>
#include<cmath>
using namespace std;














typedef struct
{
	int x;
	int y;
	int num;
}Node;

typedef struct
{
	Node*head;
	int top;
}List;

int m;
int n;

void findmn(int input)
{
	int min = input;
	int a;
	for (a = 1; a <= sqrt(input); a++)
	{
		if (input%a == 0)
		{
			n = a;
			m = input / a;
			min = m - n;
		}
	}
}


int main()
{
	void selectsort(int*p, int a);
	void put(int left, int right, int down, int up, List*p, int arr[], int *arrtop);
	int N;
	cin >> N;
	findmn(N);

	List list;
	list.head= new Node[N];
	list.top = 0;

	int*arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		arr[i]=i;
	}
	selectsort(arr, N);
	int arrtop = 0;

	put(1, n, m, 1, &list, arr, &arrtop);

	/*for (int cnt = 0; cnt < N; cnt++)
	{
		cout << list.head[cnt].num << endl;
	}*/

	
	{
		int min; int mark; Node*data = list.head; int idx; Node temp;
		for (int cnt = 0; cnt < N - 1; cnt++)
		{
			min = data[cnt].y;
			mark = cnt;
			for (idx = cnt + 1; idx < N; idx++)
			{
				if (data[idx].y < min)
				{
					min = data[idx].y;
					mark = idx;
				}
			}
			temp = data[cnt];
			data[cnt] = data[mark];
			data[mark] = temp;
		}
	}

	{
		int i = 0;int min; int mark; Node*data = list.head; int idx; Node temp;
		while (i < N)
		{
			for (int cnt = i; cnt <= i + n - 1 - 1; cnt++)
			{
				min = data[cnt].x;
				mark = cnt;
				for (idx = cnt + 1; idx <= i + n - 1; idx++)
				{
					if (data[idx].x < min) 
					{
						min = data[idx].x;
						mark = idx;
					}
				}
				temp = data[cnt];
				data[cnt] = data[mark];
				data[mark] = temp;
			}
			i += n;
		}
	}


	for (int cnt = 0; cnt < N; cnt++)
	{
		cout << list.head[cnt].num;
		if ((cnt + 1) % n)
		{
			cout << " ";
		}
		else
			cout << endl;
	}

	system("pause");
	return 0;

}

void put(int left, int right, int down, int up,List*p,int arr[],int *arrtop)
{
	//最左=left，最右=right，最上=up，最下=down，打横的有right-left个格子
	//打竖有down-up个格子

	Node *data = p->head;
	if (left == right) 
	{
		for (int a = up; a <= down; a++)
		{
			data[p->top].y = a;
			data[p->top].x = left;
			data[p->top].num = arr[*arrtop];
			p->top++;
			(*arrtop)++;
		}
		return;
	}
	if (up == down)
	{
		for (int a = left; a <= right; a++)
		{
			data[p->top].y = up;
			data[p->top].x = a;
			data[p->top].num = arr[*arrtop];
			p->top++;
			(*arrtop)++;
		}
		return;
	}
	if (left > right || up > down)
	{
		return;
	}

	for (int a = left; a <= right - 1; a++)
	{
		data[p->top].y = up;
		data[p->top].x = a;
		data[p->top].num = arr[*arrtop];
		p->top++;
		(*arrtop)++;
	}

	for (int a = up; a <= down - 1; a++)
	{
		data[p->top].y = a;
		data[p->top].x = right;
		data[p->top].num = arr[*arrtop];
		p->top++;
		(*arrtop)++;
	}

	for (int a = right; a >= left + 1; a--)
	{
		data[p->top].y = down;
		data[p->top].x = a;
		data[p->top].num = arr[*arrtop];
		p->top++;
		(*arrtop)++;
	}

	for (int a = down; a >= up + 1; a--)
	{
		data[p->top].y = a;
		data[p->top].x = left;
		data[p->top].num = arr[*arrtop];
		p->top++;
		(*arrtop)++;
	}

	put(left + 1, right - 1, down - 1, up + 1, p, arr, arrtop);
}

void selectsort(int*p, int x)
{
	int max;
	int mark;
	int j;
	int temp;
	for (int i = 0; i < x; i++)
	{
		max = p[i];
		mark = i;
		for (j = i + 1; j < x; j++)
		{
			if (max < p[j])
			{
				max = p[j];
				mark = j;
			}
		}
		temp = p[mark];
		p[mark] = p[i];
		p[i] = temp;
	}
}