#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//������

int main()
{
	string good;
	string bad;
	cin >> good;
	cin >> bad;
	string check = "";
	char temp;
	for (int i = 0; i < good.size(); i++)
	{
		temp = good[i];
		if (bad.find(temp) == string::npos)  //��bad���Ҳ���
		{
			if (check.find(temp) == string::npos)  //��check��Ҳ�Ҳ���
			{
				check += temp;
				if (isalpha(temp))   //�������ĸ��Ҫ���д
				{
					temp = tolower(temp);        //����Ǵ�д��ĸҪ��Сд
					check += temp;
					temp = toupper(temp);         //Ȼ���ֱ�ش�д
					check += temp;
				}
				cout << temp;
			}
		}
	}
	system("pause");
	return 0;
}