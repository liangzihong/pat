#include<iostream>
#include<algorithm>
using namespace std;
//��ʵҲ��������
//��ʵ�����������±�Ƚϣ���Ϊ�����±���Ա�ʾ��e��ekm���������ǰ�����ڲ��ˣ�������˳��϶���һ��Ҳ���㲻��

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
		if (arr[i+1] <= i+1) {    //��0��ʼ����������Ǹ����������±���������ǰ�Ǹ�
			cout << i;
			break;
		}
		if (i == N - 1)    //һ���������ȫ�������ڣ���ʱ���濼�ǲ��ˣ������ټ�һ��if
			cout << N;
	}

	delete[]arr;
	system("pause");
	return 0;

}