#include<iostream>
using namespace std;



//最小子列和，我担忧的是左边界限如何巧妙地mark下来
//我用的是mark下右界限然后根据最大子列和来推左界限
//柳婼大神是用当子列和小于0时，lefttemp就等于i+1；
//当子列和大于max时，start就等于lefttemp；
//巧妙在于lefttemp是只有当子列和小于0时才更新，所以不用担忧子列和一边加，lefttemp一边加


int main()
{
	int T;
	cin >> T;
	int*arr = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = T - 1;
	int sum = 0;
	int max = 0;
	int lefttemp=0;
	for (int i = 0; i < T; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0; 
			lefttemp = i + 1;
		}
		if (sum > max||arr[i]==0&&max==0) {
			start = lefttemp;
			max = sum;
			end = i;
		}
	}
	cout << max << " " << arr[start] << " " << arr[end];
	system("pause");
	return 0;
}