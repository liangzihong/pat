#include<iostream>
using namespace std;



//��С���кͣ��ҵ��ǵ�����߽�����������mark����
//���õ���mark���ҽ���Ȼ�����������к����������
//���S�������õ����к�С��0ʱ��lefttemp�͵���i+1��
//�����кʹ���maxʱ��start�͵���lefttemp��
//��������lefttemp��ֻ�е����к�С��0ʱ�Ÿ��£����Բ��õ������к�һ�߼ӣ�lefttempһ�߼�


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