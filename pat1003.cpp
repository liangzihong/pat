#include<iostream>
using namespace std;
#define max 101

int main()
{
	int search(char*s1, char*s2);
	char arr[max];
	int T;
	cin >> T;
	cin.get();
	int pnum = 0,anum=0, tnum = 0;
	int aleftn = 0, amidn = 0, arightn = 0;
	int cnt=0;

	char ch;
	while (T > 0)
	{
		ch = getchar();
		while (ch!= '\n')
		{
			switch (ch)
			{
				case 'P':
					if (!pnum) {
						pnum++;
						arr[cnt++] = ch;
					}
					else {
						goto end;
					}ch = getchar();
					break;
				
				
				case 'A':
					if (!pnum) {
						aleftn++;
						while ((ch = getchar()) == 'A') {
							aleftn++;
						}
					}
					else if (pnum && !tnum) {
						arr[cnt++] = ch;
						amidn++;
						while ((ch = getchar()) == 'A') {
							amidn++;
						}
					}
					else if (pnum&&tnum) {
						arightn++;
						while ((ch = getchar()) == 'A') {
							arightn++;
						}
					}
					break;


				case 'T':
					if (!tnum) {
						tnum++;
						arr[cnt++] = ch;
					}
					else {
						goto end;
					}ch = getchar();
					break;
				default:
				end:
					while (cin.get() != '\n')
					{
						continue;
					}
					goto aaa;
			}
		}
		arr[cnt] = '\0';
		if (search(arr, "PAT"))
		{
			if (aleftn == arightn&&amidn == 1)
			{
				cout << "YES" << endl;
			}
			else if (aleftn == 0 && arightn == 0)
			{
				cout << "YES" << endl;
			}
			else if (aleftn*amidn == arightn)
			{
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
		aaa:
			cout << "NO" << endl;
		}
		T--;
		pnum = 0;
		tnum = 0;
		cnt = 0;
		aleftn = 0, arightn = 0, amidn = 0;
	}
	system("pause");
	return 0;
}



int search(char*s1, char*s2)
{
	char*p2 = s2;
	char*p1 = s1;
	while (*s1)
	{
		p1 = s1;
		while (*s1 == *s2&&*s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == 0) {
			return 1;
		}
		p1++;
		s1 = p1;
		s2 = p2;
	}
	return 0;
}

