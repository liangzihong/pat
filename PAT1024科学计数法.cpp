#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<iterator>
#include<cmath>
using namespace std;

//�������У���ѡ����list������vector��ԭ����û�Թ�list������list��push����front��
//������ʵvectorҲ��insert�䵱pushfront�����ã����Ҳ�����ѭ�����
//Ҫע���ʴlist����ﶼҪ�е������䵱���ɣ����ҵ�����û������+1��ֻ������������Ҫ����Ѱ�ҵĺ��ʵ�λ��
//�����õ���ereaseҪ�õ�������findҲ�Ƿ��ص�������









int main()
{
	list<char> numlist;
	char ch;  //����ļ�¼
	while (cin >> ch)
	{
		numlist.push_back(ch);            //��������������numlist��
	}

	list<char>::iterator emark; //E��λ��;Ҫ�õ���������ʾ
	emark = find(numlist.begin(), numlist.end(), 'E');

	int zhishu; //ָ���Ĵ�С;
	string temp(++emark,numlist.end());  //temp��¼e�����ָ����
	zhishu = stoi(temp);
	//copy(emark, numlist.end(),
	//	insert_iterator<string>(temp, temp.begin()));


	list<char> answerlist(numlist.begin(),--emark);
	answerlist.pop_front();       //ȥ�������ţ�
	list<char>::iterator answerpoint=answerlist.begin();   //answerlist��ר�õ�����
	answerpoint = find(answerlist.begin(), answerlist.end(), '.');//�ҵ���.��
	answerlist.erase(answerpoint);//�Ѵ����ּ�¼��answerlist�У��ⲽ��ɾ����.��
	answerpoint = answerlist.begin();

	if (zhishu < 0)            //���ָ��С��0������ǰ���0����push����front�������Ӿ���ֵ��0
	{
		for (int i = 0; i < abs(zhishu); i++)
		{
			answerlist.push_front('0');
		}
		answerpoint = answerlist.begin();
		answerlist.insert(++answerpoint, '.');       //Ȼ��ֱ���ڵڶ�λinsert��С����
	}
	else                    //���ָ������0�������������
	{
		if (zhishu < answerlist.size() - 1)   //�����ں����0�ģ�Ҫ��С�����
		{
			//�ѵ�������λ�÷�����Ҫ��С����ĵط�
			answerpoint = ++answerlist.begin();
			while (zhishu-- > 0)
			{
				answerpoint++;
			}
			answerlist.insert(answerpoint, '.');   //��С����
		}
		else if (zhishu == answerlist.size() - 1)  //�պò��ü�0Ҳ���ü�С�����
		{
			/*while (answerpoint++ != answerlist.end())
			{
				cout << *answerpoint;
			}*/
		}
		else  //ֻ��0��
		{
			int temp = zhishu - answerlist.size() + 1;
			while (temp != 0)
			{
				answerlist.push_back('0');
				temp--;
			}
		}
	}


	if (*numlist.begin() == '-')              //���ǰ���з��ţ���push������ȥ
	{
		answerlist.push_front('-');
	}

	answerpoint = answerlist.begin();
	while (answerpoint != answerlist.end())       //�������
	{
		cout << *answerpoint++;
	}

	system("pause");
	return 0;
}