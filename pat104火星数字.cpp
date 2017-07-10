#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;


//A��һ���е����࣬����������ʶ�����⣬Ҫ֪���治���ڵڶ������ʣ�ҲҪ֪�����ֻ��һ�����ʣ��ǵ�һ�����ʴ����ʮλ���Ǹ�λ
//����ʶ������ʹ�õ���   cin.get()�����������룬���ʶ��س���ֱ��break�����ʶ��ո��������أ������ڶ���target
//��������֣���Ҫ�����ֱ��13���ƣ���Ӧ���ַ���������������С��13����ֻ�����Ӧ��marsgewei��λ
//������ִ���13����ʱ���������������Ϊ����Ǹպ���13�������������λ��������������ˣ����ṹ��

//Ȼ���������ǻ������֣�ֻ��һ�����ʵģ�������target2=target1��ͬʱ������������ʱ��������һ�����У������������Ӧ��shi��geΪ
//��Ӧ�����֣�Ȼ�����shi*13+ge����

int main()
{
	int N; cin >> N; cin.get();
	string input;
	string mars[13] = { "tret","tam","hel","maa","huh","tou","kes","hei",
		"elo","syy","lok","mer","jou" };
	string marsgewei[13] = { "tret","jan","feb","mar","apr","may","jun",
		"jly","aug","sep","oct","nov","dec" };
	
	string target1 = "";
	string target2 = "";
	int state = 0;
	char first;
	
	for (int i = 0; i < N; i++) 
	{
		state = 0;
		target1 = "", target2 = "";
		while (first = cin.get())
		{
			if (first == '\n')
				break;
			else if (first == ' ')    //������пո�������������ʳ���
			{
				state = 1; continue;
			}
			if (state == 0)       //ֻ��һ�����ʣ�������ĸ�����target1
				target1 += first;
			else target2 += first;  //���������ʳ��֣�������ĸ�����target2
		}


		if (isdigit(target1[0])) {
			int digit = stoi(target1);
			if (digit < 13) cout << marsgewei[digit] << endl;
			else {
				cout << mars[digit / 13];
				(digit % 13) ? (cout << " " << marsgewei[digit % 13] << endl)
					: (cout << endl);
			}
		}

		else 
		{
			int shi = 0; int ge = 0;
			if (target2 == "") target2 = target1;      //��ֹֻ��һ������ʱ��֪����ʮλ���Ǹ�λ�������������ͨɱ�����벻�øĶ�̫��
				for (int i = 0; i < 13; i++) {
					if (mars[i] == target1) {
						shi = i;
						break;
					}
				}
				for (int j = 0; j < 13; j++) 
				{
					if (marsgewei[j] == target2) {
						ge = j; break;
					}
				}

			cout << shi * 13 + ge << endl;
		}
	}

	system("pause");
	return 0;
}