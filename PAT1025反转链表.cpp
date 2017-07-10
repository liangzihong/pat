//这题尝试以下用map
//主要是因为map可以用键值来表示他的值

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

	if(N==0)           //如果Nwei0，直接return0？
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
		nodemap.insert(Pair(temp.address, temp));          //map的插入方式
													   //用一个pair作为掩护
	}

	string final=start;       //final为要开始排序的地址，所以第一个地址为start，其他都为自己的next；
	vector<Node> nodevector;
	
	do
	{
		nodevector.push_back(nodemap[final]);     //用  nodemap[键值]表示对应的值  这一特点
		final = nodemap[final].next;              //然后final又赋值为要找的下一个地址
	}while (final != "-1");

	//循环一次后nodevector即为正确的顺序了

	//接下来就是开始反转链表了
	if (target == 0||target==1)       //如果反转的个数为0，可以直接输出
	{
		for_each(nodevector.begin(), nodevector.end(), output);
		return 0;
	}

	vector<Node> reverse;
	for (int i = 1; i <= num / target; i++)      //总共又num/target组需要反转的，可能会有多余的等下处理
	{
		for (int j = i*target - 1; j >= i*target - target; j--)
			//比如0到3，则i=1，target=4，则右边界为i*target-1，左边界为(i-1)*target
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










//第一点  以后做pat和acm，舍弃cin和cout，都用scanf和printf
//在这一题中，我用的方法是
//第一步：把所有数据放在一个数组中，数组的下标即为数据的address的stoi，这样可以直接用索引搞定
//第二步：然后从start开始，以start作为索引，把从数组中的东西放到vector中，再把next作为索引继续寻找
//第三步：同时要不断计数，因为刚才输入的一大堆有些是不在链表里的，所以要重新计数
//上面的第三步很重要，看了答案才知道还有这样坑人的！！！！！。。。。

//第四步：开始反转了，如果是0或1，则直接输出不用反转
//第五步：把反转的链表放入reverse中。  不难想，就是比较麻烦和繁琐

//第六步：输出


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
	
	int cnt = 0;                 //这里要舍弃num，因为有些节点是不在链表里的，这些节点要排除，不算在链表内
	do                           //所以要知道总共链表里有多少个节点
	{
		cnt++;
		nodevec.push_back(arr[stoi(final)]);
		final = arr[stoi(final)].next;
	} while (final != "-1");


	//以下开始做reverse操作

	if (target == 0 || target == 1)       
	{
		for_each(nodevec.begin(), nodevec.end(), output);
	}
	else
	{
		vector<Node> reverse;
		for (int i = 1; i <= cnt / target; i++)      //总共又num/target组需要反转的，可能会有多余的等下处理
		{
			for (int j = i*target - 1; j >= i*target - target; j--)
				//比如0到3，则i=1，target=4，则右边界为i*target-1，左边界为(i-1)*target
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