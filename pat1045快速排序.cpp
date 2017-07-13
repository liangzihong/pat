#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *arr = new int[N];
	int cnt = 0;
	int ans[100];
	int left[100001] = { 0 };
	int right[100001] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int leftmax = -1;
	int rightmin = -1;
	leftmax = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] >= leftmax) { left[i]++; leftmax = arr[i]; }
	}
	rightmin = arr[N - 1];
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] <= rightmin) { right[i]++; rightmin = arr[i]; }
	}
	for (int i = 0; i < N; i++) {
		if (left[i] && right[i])
			ans[cnt++] = arr[i];
	}
	sort(ans + 0, ans + cnt);
	cout << cnt<<endl;
	for (int i = 0; i < cnt; i++) {
		cout << ans[i];
		if (i != cnt - 1) cout << " ";
	}
	cout << endl;     //这一句一定要加，当cnt==0是，要输出两个空行。。。。   
	system("pause");
	return 0;
}