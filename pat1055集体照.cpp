#include<iostream>
#include<stack>
#include<deque>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//������ҵ���ʾ��   ������ˣ�����Ҫ���⣬����ǳ���Ҫ
//��Σ�����5�λ����򶪵�����һ��ʱ�����д������ǳ���Ҫ��ϣ����仰�춨�����Ժ��ϰ�ߡ���
//������κ󻹴���������һ��ʱ�����д��

//�����˼·�������ģ������������ˣ�����Ǻ������ʵģ�
//�����Ű��������Ķ���һ����һ������ջ��
//Ȼ���ڸ�һ����ת�����õĶ��л���ջ��
//���˵�һ����������һ����num=N/K+N%K���⣬��������num=N/K�����������Ҫ��һ��if
//Ȼ���num�����������ת�Ķ��л���ջ�У�Ȼ��ʣ�µ���ͷ�����ǵ���ԭ�ȷ�������ͷ�Ǹ�ջ����ȥ��תջ��people��ԭ��ջ����Ҫpop�ģ�
//��ʱ��תվ�д�ŵľ�����һ����Ҫ�Ŷӵ���
//���Դ�ʱ��Ҫ��������Ҫ��������
//������Ū��һ��������У�
//���ǵ����ģ�����תվת����ת�������еĺ���
//����˫���ģ�����תվת����ת�������е�ǰ��
//ֱ����תվΪ�գ���ʱ��������о�����һ�ŵ���ͷռλ˳����
//��������������Ҫ��ս�����У�Ȼ��һ�δ�ѭ����ֱ��cnt==0����ʱ������ˣ���

typedef struct fuck
{
	string name;
	int height;
}people;

bool cmp(people&a, people&b)
{
	if (a.height < b.height)
		return true;
	else if (a.height == b.height)
	{
		if (a.name > b.name)
			return true;
		else 
			return false;
	}
	else return false;
}

int main()
{
	int N;
	int K;
	cin >> N >> K;

	vector<people> vectorarr; //�����õģ�ûʲô���ã���ʵ���������������棬������delete��
	deque<people> quearr1;    //��ת����
	deque<people> queanswer;  //�������
	stack<people> stackarr;   //ԭ��ջ
	people temp; 
	for (int i = 0; i < N; i++) {
		cin >> temp.name;
		cin >> temp.height;
		vectorarr.push_back(temp);
	}
	if (N == 0) {
		return 0;
	}
	if (K == 0) {
		return 0;
	}

	sort(vectorarr.begin(), vectorarr.end(),cmp);
	for (int i = 0; i < N; i++) {
		stackarr.push(vectorarr[i]);
	}

	int cnt = N;
	int state = 1;
	while (cnt != 0)
	{
		int num;
		//�ж��Ƿ������һ��
		if (state == 1) {
			num = N / K + N%K;
			state = 0;
		}
		else{
			num = N / K;
		}
		
		for (int i = 1; i <= num; i++) {       //��ԭ��ջת����תվ����ԭ��ջ��pop����
			quearr1.push_back(stackarr.top());
			stackarr.pop();
		}

		cnt = stackarr.size();        //cnt�Ǵ��ȫ����ջʣ�µĸ���

		for (int i = 1; quearr1.empty() == 0; i++)         //��ת���е�������е�ת��
		{
			if (i % 2 != 0) {
				queanswer.push_back(quearr1.front());
			}
			else
				queanswer.push_front(quearr1.front());
			quearr1.pop_front();                          //ֱ����ת����ҲΪ��
		}

		deque<people> ::iterator it;
		for (it = queanswer.begin(); it != queanswer.end(); it++)
		{
			cout << (*it).name;
			if (it != queanswer.end() - 1)
			{
				cout << " ";
			}
		}
		queanswer.erase(queanswer.begin(), queanswer.end());     //�����������������Ҫ��յ�
		cout << endl;
	}
	system("pause");
	return 0;
}