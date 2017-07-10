#include<iostream>
#include<algorithm>
using namespace std;
//其实也是弱智题
//其实就是与数组下标比较，因为数组下标可以表示成e天ekm，如果连当前都大于不了，则此消彼长肯定下一个也满足不了

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int N; cin >> N;
	int * arr = new int[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(&arr[1], &arr[N + 1], cmp);        
	
	for (int i = 0; i < N; i++) {    
		if (arr[i+1] <= i+1) {    //从0开始如果他后面那个不比数组下标大，则输出当前那个
			cout << i;
			break;
		}
		if (i == N - 1)    //一种情况就是全部都大于，此时上面考虑不了，所以再加一个if
			cout << N;
	}

	delete[]arr;
	system("pause");
	return 0;

}