#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//������㷨�ĺ����ǽ�һ���������������顣�ؼ����������ж��Ƿ�������Ƿ�Ϊ���������
//���S���뷨��6���ȶ��������������������������������������sizeС��n�������Ϊ�������������������size����С��n����������������

//����ʵ�ֻ����ҵ��뷨��ûŪ�����S�Ĵ��룩
//��ΪҪ�ж��Ƿ������Ҫ��������������Ҫ�ȵ�һ��С���������������Ҫ�ȵ�һ�����С

//���һ�����ȶ�������д����������������������ҵ���һ����arr[0]��Ľڵ㣬����ڵ�right�϶�Ϊ��������root2
//���Ը�����ѧ�ƶϣ�right�������������Ҫ��arr[0]��ģ��������ǰ�right����ı�arr[0]С�Ķ�ɾ������Ȼɾ������size�϶���nС��
//Ȼ������ƶϣ��������ĸ���left=right-1��0��right֮ǰ�ĸ���������right=cnt-right��right��cnt�ĸ�������

//Ȼ�󲻶ϵݹ飬�ս������Ǵ���������ֻ��һ������û����




typedef vector<int> VEC;

void foward(int*arr,int &all,int iso)   
{/*arrΪ���������飬startΪ��һ����ʼ��allΪȫ������ĸ���*/
	//������start=all��Ȼ���ҳ�start��Ϊ��ʼ��

	/*���ڲ��Ǿ�����������������ȼ���������Ϊ��arr[0]С�ģ���ô���������ҵ���һ����arr[0]�����ڵ�right�����һ����
	right�������ȫ��Ϊ��������rightǰ�����Ϊ��������������Ϊ����������arr[0]����������Ҫ��right��all����������
	��right�����arr[0]С��ȫ��ȥ����Ȼ������Ԫ��ǰ�ơ�����һ���Ϳ��Ա���������׼����*/

	/*������Ǿ���������������ҵ���һ����arr��0��С��right��Ȼ��right����Ҳ����������ǰ��Ϊ��������Ȼ���right��ʼ��right����
	��arr[0]���ȫ��ȥ����Ȼ��Ԫ��ǰ�ơ�*/

	if (all == 0||all==1)return;
	int start=all;
	if (iso == 0)
	{
		for (int i = 1; i < all; i++) {
			if (arr[i] >= arr[0]) { start = i; break; }
		}
		for (int i = start; i < all; i++)
		{
			if (arr[i] < arr[0])
			{
				for (int j = i; j < all-1; j++)
					arr[j] = arr[j + 1];
				all--; i--;                //��Ϊɾ��һ����ǰ��λ��Ϊԭ�ȵ���һ��������Ҫ�ӵ�ǰλ�����¼��
			}
		}
	}
	else
	{
		for (int i = 1; i < all; i++) {
			if (arr[i] < arr[0]) { start = i; break; }
		}
		for (int i = start; i < all; i++)
		{
			if (arr[i] >= arr[0])
			{
				for (int j = i; j < all - 1; j++)
					arr[j] = arr[j + 1];
				all--; i--;                //��Ϊɾ��һ����ǰ��λ��Ϊԭ�ȵ���һ��������Ҫ�ӵ�ǰλ�����¼��
			}
		}
	}
}


void select(int*arr, int cnt, int iso,VEC &ans)
{
	if (cnt == 0)return;
	foward(arr, cnt, iso);
	int left = 0;
	int right = cnt;
	//����forward�����ٽ�����ֳ���������������������������ĵݹ�
	if (iso == 0)
	{
		for (int i = 1; i < cnt; i++) 
		{
			if (arr[i] >= arr[0]) 
			{
				right = i; break;
			}
		}
	}
	//����foward�����ٽ�����ֳ���������������������������ĵݹ�
	else
	{
		for (int i = 1; i < cnt; i++) 
		{
			if (arr[i] < arr[0]) 
			{
				right = i; break;
			}
		}
	}		

	left = right - 1;
	right = cnt - right;
	select(arr + 1, left, iso, ans);    //������
	select(arr + left + 1, right, iso, ans);   //������
	ans.push_back(arr[0]);
	return;

} 

int main() 
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int *arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	VEC ans;
	int iso = 0;
	select(arr, n, iso, ans);   
	if (ans.size() == n)
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << ans[i];
			if (i != n - 1) cout << " ";
		}
	}
	else {
		iso = 1;
		arr = arr2;
		ans.erase(ans.begin(), ans.end());
		select(arr, n, iso, ans);
		if (ans.size() == n)
		{
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << ans[i];
				if (i != n - 1) cout << " ";
			}
		}
		else cout << "NO";
	}
	system("pause");
}