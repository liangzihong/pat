#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void mergesort(int arr[], int left, int right)
{
	sort(arr + left, arr + right + 1);
}

void insertsort(int arr[], int needtoinsert)
{
	int cnt = needtoinsert;
	int i;
	int temp = arr[cnt];
	for (i = 0; i <= cnt - 1; i++)
	{
		if (arr[cnt] < arr[i])
		{
			for (int j = cnt - 1; j >= i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i] = temp; break;
		}
	}
}

bool judge(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] ;
		if (i != n - 1)
			cout << " ";
	}
}

int main()
{
	int bug = 0;
	int N;
	cin >> N;
	int *merge = new int[N];
	int *insert = new int[N];
	int*arr = new int[N];
	int* cmp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		merge[i] = insert[i] = arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cmp[i];
	}
	//归并排序
	int cnt = 0;
	int i = 0;
	int state = 1;
	while (cnt<N)     //归并排序的循环
	{
		i = 0;
		for (; i < N; i = i + cnt+1)
		{
			if (i + cnt < N) {
				mergesort(merge, i, i + cnt);
			}
			else
			{
				mergesort(merge, i, N-1);
			}
			
		}
		cnt = cnt * 2;
		if (judge(cmp, merge, N)||state==0)
		{
			if (state == 0) {     //这是符合条件的下一round
				bug = 1;
				break;
				//cout << "Merge Sort\n";
				//output(merge, N);   //输出答案
				//system("pause");
				//return 0;
			}
			state = 0;
		}
	}


	/*if (state == 0) {
		while (1);
		mergesort(merge, 0, N-1);
		cout << "Merge Sort\n";
		output(merge, N);
		system("pause");
		return 0;
	}*/
	state = 1;
	//插入排序
	int j = 0;
	for (; j < N; j++)
	{
		insertsort(insert, j);
		if (judge(cmp, insert, N) || state == 0)
		{
			if (state == 0)
			{
				if (bug == 1)
					bug = 3;
				else
				{
					bug = 2;
				}
				break;
				//cout << "Insertion Sort\n";
				//output(insert, N);
				//system("pause");
				//return 0;
			}
			state = 0;
		}
	}


	if (bug == 1)  //归并
	{
		cout << "Merge Sort\n";
		output(merge, N);   //输出答案
	}
	else if (bug == 2)  //插入
	{
		cout << "Insertion Sort\n";
		output(insert, N);
	}
	else {
		cout<< "Merge Sort\n";
		output(insert, N);   //输出答案
	}

	system("pause");
	return 0;

}