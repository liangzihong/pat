#include<iostream>
#include<valarray>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;


//���������⾹Ȼ������һ����Сʱ
//��Ҫ��ϸ���ϳ��˲�����������ʽ��ȻҪ���ǵ�������ô���鷳
//�õ���һ��
/*while ((eh = cin.get()) && isdigit(eh) == 0)
{
	continue;
}*/
//ѭ�����Ե�����ǰ��Ķ���
//Ȼ����ʵ���ѣ��������ַ����жϴ��Ƿ���ȷ����


typedef struct fuck
{
	int issumenum; //��Ŀ���
	int fenzhi;    //����ֵ
	int choosenum; //ѡ����Ŀ
	int answernum; //����Ŀ
	string daan;   //��
	int wrongnum;  //��������
}issue;
bool cmp(issue&a, issue&b)
{
	if (a.wrongnum > b.wrongnum)
		return true;
	if (a.wrongnum == b.wrongnum&&a.issumenum < b.issumenum)
		return true;
	return false;
}
int main()
{
	int M;
	int N;
	cin >> N >> M;

	issue * arr = new issue[M + 1];

	for (int i = 1; i < M + 1; i++)
	{
		arr[i].issumenum = i;
		cin >> arr[i].fenzhi;
		cin >> arr[i].choosenum;
		cin >> arr[i].answernum;
		arr[i].daan = "";
		char ch;
		while (ch = cin.get())
		{
			if (ch == '\n') break;
			if (isalpha(ch)) arr[i].daan += ch;
		}
		arr[i].wrongnum = 0;
	}


	for (int idx = 0; idx < N; idx++)      //�ڼ���ѧ��
	{
		string stu = "";
		int num;   //ѧ��ÿһ���ѡ����Ŀ
		int mark = 0;    //ѧ���ķ���
		char eh;
		for (int i = 1; i < M + 1; i++)     //�ڼ���         
		{
			//cin.get();   //����������
			//cin >> num;        //ѧ��ÿһ���ѡ����Ŀ
			while ((eh=cin.get())&&isdigit(eh) == 0)
			{
				continue;
			}
			num = eh - '0';
			char dh;
			stu = "";
			for (int j = 0; j < num; j++)      //ÿһ���ѡ��
			{	
				dh = cin.get();
				while (!isalpha(dh))
					dh = cin.get();
				stu += dh;
			}
			if (stu == arr[i].daan)
			{
				mark += arr[i].fenzhi;
			}
			else
			{
				arr[i].wrongnum++;
			}
		}
		cout << mark << endl;
	}

	sort(&arr[1], &arr[M+1],cmp);
	int temp = arr[1].wrongnum;
	if (temp == 0)
	{
		cout << "Too simple\n";
	}
	else {
		cout << temp;
		for (int i = 1; i < M + 1; i++)
		{
			if (temp == arr[i].wrongnum)
				cout <<" "<< arr[i].issumenum;
		}
	}
	//system("pause");
	return 0;
}