//���Ⳣ��������map
//��Ҫ����Ϊmap�����ü�ֵ����ʾ����ֵ

/*#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef struct fuck 
{
	string address;
	int data;
	string next;
}Node;

typedef map<string, Node> Map;
typedef pair<string, Node> Pair;

inline void output(Node&a)
{
	cout << a.address << " "
		<< a.data << " "
		<< a.next << endl;
	//printf("%s %d %s\n", a.address.c_str(), a.data, a.next.c_str());
}

int main()
{
	string start;
	int num;
	int target;
	cin >> start >> num >> target;
	int N = num;

	if(N==0)           //���Nwei0��ֱ��return0��
	{
		return 0;
	}
	Map nodemap;
	Node temp;
	while (N-- > 0)
	{
		cin >> temp.address
			>> temp.data
			>> temp.next;
		nodemap.insert(Pair(temp.address, temp));          //map�Ĳ��뷽ʽ
													   //��һ��pair��Ϊ�ڻ�
	}

	string final=start;       //finalΪҪ��ʼ����ĵ�ַ�����Ե�һ����ַΪstart��������Ϊ�Լ���next��
	vector<Node> nodevector;
	
	do
	{
		nodevector.push_back(nodemap[final]);     //��  nodemap[��ֵ]��ʾ��Ӧ��ֵ  ��һ�ص�
		final = nodemap[final].next;              //Ȼ��final�ָ�ֵΪҪ�ҵ���һ����ַ
	}while (final != "-1");

	//ѭ��һ�κ�nodevector��Ϊ��ȷ��˳����

	//���������ǿ�ʼ��ת������
	if (target == 0||target==1)       //�����ת�ĸ���Ϊ0������ֱ�����
	{
		for_each(nodevector.begin(), nodevector.end(), output);
		return 0;
	}

	vector<Node> reverse;
	for (int i = 1; i <= num / target; i++)      //�ܹ���num/target����Ҫ��ת�ģ����ܻ��ж���ĵ��´���
	{
		for (int j = i*target - 1; j >= i*target - target; j--)
			//����0��3����i=1��target=4�����ұ߽�Ϊi*target-1����߽�Ϊ(i-1)*target
		{
			reverse.push_back(nodevector[j]);
		}
	}
	if (num%target != 0)
	{
		int i = num%target;
		while (i!=0)
		{
			reverse.push_back(nodevector[num- i]);
			i--;
		}
	}
	int cnt;
	for (cnt= 0; cnt < reverse.size()-1; cnt++)
	{
		reverse[cnt].next = reverse[cnt + 1].address;
	}
	reverse[cnt].next = "-1";
	for_each(reverse.begin(), reverse.end(), output);

	system("pause");
	return 0;
}*/










//��һ��  �Ժ���pat��acm������cin��cout������scanf��printf
//����һ���У����õķ�����
//��һ�������������ݷ���һ�������У�������±꼴Ϊ���ݵ�address��stoi����������ֱ���������㶨
//�ڶ�����Ȼ���start��ʼ����start��Ϊ�������Ѵ������еĶ����ŵ�vector�У��ٰ�next��Ϊ��������Ѱ��
//��������ͬʱҪ���ϼ�������Ϊ�ղ������һ�����Щ�ǲ���������ģ�����Ҫ���¼���
//����ĵ���������Ҫ�����˴𰸲�֪�������������˵ģ�����������������

//���Ĳ�����ʼ��ת�ˣ������0��1����ֱ��������÷�ת
//���岽���ѷ�ת���������reverse�С�  �����룬���ǱȽ��鷳�ͷ���

//�����������


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef struct fuck
{
	string address;
	int data;
	string next;
}Node;

inline void output(Node&a)
{
	printf("%s %d %s\n", a.address.c_str(), a.data, a.next.c_str());
}

int main()
{
	string start;
	int num;
	int target;

	cin >> start >> num >> target;

	Node*arr = new Node[100000];
	Node temp;

	if (num == 0)
	{
		cout << "0 0 -1";
		return 0;
	}

	if (start == "-1")
	{
		cout << "-1 0 -1";
		return 0;
	}

	char aaa[20]; char bbb[20];
	for (int i = 0; i < num; i++)
	{
		/*cin >> temp.address
			>> temp.data
			>> temp.next;*/
		scanf("%s %d %s", aaa, &temp.data, bbb);
		temp.address = aaa; temp.next = bbb;
		arr[stoi(temp.address)] = temp;
	}

	string final = start;
	vector<Node> nodevec;
	
	int cnt = 0;                 //����Ҫ����num����Ϊ��Щ�ڵ��ǲ���������ģ���Щ�ڵ�Ҫ�ų���������������
	do                           //����Ҫ֪���ܹ��������ж��ٸ��ڵ�
	{
		cnt++;
		nodevec.push_back(arr[stoi(final)]);
		final = arr[stoi(final)].next;
	} while (final != "-1");


	//���¿�ʼ��reverse����

	if (target == 0 || target == 1)       
	{
		for_each(nodevec.begin(), nodevec.end(), output);
	}
	else
	{
		vector<Node> reverse;
		for (int i = 1; i <= cnt / target; i++)      //�ܹ���num/target����Ҫ��ת�ģ����ܻ��ж���ĵ��´���
		{
			for (int j = i*target - 1; j >= i*target - target; j--)
				//����0��3����i=1��target=4�����ұ߽�Ϊi*target-1����߽�Ϊ(i-1)*target
			{
				reverse.push_back(nodevec[j]);
			}
		}
		if (cnt%target != 0)
		{
			int i,yushu;
			i = cnt / target;
			yushu = cnt%target;
			i = i*target;
			while (yushu > 0)
			{
				reverse.push_back(nodevec[i]);
				i++, yushu--;
			}
		}

		for (int i = 0; i < reverse.size() - 1; i++)
		{
			reverse[i].next = reverse[i + 1].address;
		}
		reverse[reverse.size() - 1].next = "-1";


		for_each(reverse.begin(),reverse.end(), output);
	}
	delete[]arr;
	//system("pause");
	return 0;
}