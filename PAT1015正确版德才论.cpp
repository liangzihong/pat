#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

int hege;
int good;

typedef struct aaa
{
	string num;
	int demark;
	int caimark;
}Node;

bool cmp(Node&a, Node&b)         //����һ��ֻ����һ���в��е�ͨ
{
	if (a.caimark >= good&&a.demark >= good&&                    //aΪ��һ��,bΪ��һ��
		b.caimark >= good&&b.demark >= good)
	{
		if (a.caimark + a.demark > b.caimark + b.demark) return true;
		else if ((a.caimark + a.demark == b.caimark + b.demark)&&a.demark > b.demark) return true;
		else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark == b.demark&&a.num<b.num) return true;
		else return false;
	}

	if (a.caimark >= good&&a.demark >= good)   
	{
		if (b.caimark < good || b.demark < good) return true;         //bΪ�ǵ�һ��
	}




	if (a.caimark < good&&a.demark >= good)                                //aΪ�ڶ���
	{
		if (b.caimark >= good&&b.demark >= good)                            //bΪ��һ��
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //bΪ�ڶ���
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark > b.demark) return true;
			else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark==b.demark&&a.num < b.num) return true;
			else return false;
		}
		else return true;                                                //bΪ�ǵ�һ�ڶ�
		
	}



	if (a.caimark < good&&a.demark < good&&a.demark>=a.caimark)                   //aΪ������
	{
		if (b.caimark >= good&&b.demark >= good)                            //bΪ��һ��
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //bΪ�ڶ���
		{
			return false;
		}
		else if (b.caimark < good&&b.demark < good&&b.demark >= b.caimark)      //bΪ������
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark > b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark==b.demark&&a.num < b.num) return true;
			else return false;
		}
		else
		{
			return true;                                                //bΪ��һ����
		}
	}

	else                      //aΪ������
	{
		if (b.caimark >= good&&b.demark >= good)                            //bΪ��һ��
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //bΪ�ڶ���
		{
			return false;
		}
		else if (b.caimark < good&&b.demark < good&&b.demark >= b.caimark)      //bΪ������
		{
			return false;
		}
		else
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark > b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark == b.demark&&a.num < b.num) return true;
			else return false;
		}
	}

}
int main()
{
	int N;
	cin >> N;
	vector<Node> arr;      //����N��Node�Ķ�̬����

	cin >> hege;          //���¼ȡ������
	cin >> good;        //����¼ȡ������

	int cnt = 0;//�ϸ�����
	Node fucktemp;
	for (int i = 0; i < N; i++)
	{
		char temp[20];
		int detemp; int caitemp;
		//cin >> temp >> detemp >> caitemp;

		scanf("%s %d %d", temp, &detemp, &caitemp);
		
		if (detemp >= hege&&caitemp >= hege)
		{
			fucktemp.num = temp;
			fucktemp.demark = detemp;
			fucktemp.caimark = caitemp;
			cnt++;
			arr.push_back(fucktemp);
		}
	}

	sort(arr.begin(), arr.end(),cmp);

	cout << cnt << endl;
	vector<Node>::iterator it;
	for (it=arr.begin();it!=arr.end();it++)
	{
		/*cout << arr[i].num << " "
			<< arr[i].demark << " "
			<< arr[i].caimark << endl;*/
		printf("%s %d %d\n", (*it).num.c_str(), (*it).demark, (*it).caimark);
	}
	//system("pause");
	return 0;
}