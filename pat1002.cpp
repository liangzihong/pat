#include<iostream>
using namespace std;





//�����������֣�ʹresult�������ӣ�ֱ�������س�
//Ȼ����sprintf��result����ַ����飬���������
//�����⣻









void read(char*s)
{
	while (*s)
	{
		switch (*s)
		{
		case'0':cout << "ling"; break;
		case'1':cout << "yi"; break;
		case'2':cout << "er"; break;
		case'3':cout << "san"; break;
		case'4':cout << "si"; break;
		case'5':cout << "wu"; break;
		case'6':cout << "liu"; break;
		case'7':cout << "qi"; break;
		case'8':cout << "ba"; break;
		case'9':cout << "jiu"; break;
		}
		if (*++s!= 0)
		{
			cout << " ";
		}
	}
}


int main()
{
	char a;
	int sum=0;
	while ((a=cin.get())!='\n')
	{
		sum += (int(a) - 48);
	}
	char arr[10];
	sprintf(arr, "%d", sum);
	read(arr);
	system("pause");
	return 0;
}