#include<iostream>
using namespace std;


//ÈõÖÇÌâ²»½âÊÍ
int main()
{
	int N;
	cin >> N;
	int arr[4];

	int jiawin=0;
	int yiwin = 0;
	while (N-- > 0)
	{
		for (int i = 0; i < 4; i++) { cin >> arr[i]; }
		if (arr[0] + arr[2] == arr[1])
		{
			if (arr[0] + arr[2] != arr[3])
				jiawin++;
		}
		else if (arr[0] + arr[2] == arr[3])
		{
			if (arr[0] + arr[2] != arr[1])
				yiwin++;
		}
	}

	cout << yiwin << " " << jiawin;
	//system("pause");
	return 0;
}