#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

//第一个错误:第一个错误是把#define和typedef弄反了，不知所措
//第二个错误是要用strtok
//strtok是可以等于java的spilt，可以将字符串分成n个字符串
//具体用法是：

/*char*temp = NULL;
	char*source = new char[5000];
	for (int i = 0; i < keyword.length(); i++) {
		source[i] = keyword[i];
	}
	
	temp = strtok(source, " ");
	strtok之后，然后循环，temp！=NULL，然后temp又再次等于strtok（NULL," "),返回上一次结束的位置
	while (temp != NULL) {
		string aaa = temp;
		ret.push_back(aaa);
		temp = strtok(NULL, " ");
	}*/

//然后自己写了一个分割字符串，捉住num，start，end，很快就可以完成
//map的用法

	

typedef string Title  ;
typedef string Author ;
typedef string Keyword ;
typedef string Publisher ;
typedef string Pubyear ;
typedef string ID ;
typedef vector<ID> IDs;

vector<string> tostrings(string keyword)
{
	keyword += "  ";
	vector<string> ret;
	int start = 0; int end = 0; int num = 0;
	for (int i = 0; i < keyword.size(); i++) {
		char c = keyword[i];
		
		if (c == ' ') {
			string temp = "";
			temp = keyword.substr(start, num);
			end++;
			start = end;
			num = 0;
			if (temp != "") ret.push_back(temp);

		}
		else {
			num++;
			end++;
		}



	}
	/*char*temp = NULL;
	char*source = new char[5000];
	for (int i = 0; i < keyword.length(); i++) {
		source[i] = keyword[i];
	}
	
	temp = strtok(source, " ");
	while (temp != NULL) {
		string aaa = temp;
		ret.push_back(aaa);
		temp = strtok(NULL, " ");
	}*/
	return ret;
}


int main()
{

	map<Title, IDs> Titles;
	map<Author, IDs> Authors;
	map<Keyword, IDs> Keywords;
	map<Publisher, IDs> Publishers;
	map<Pubyear, IDs> Pubyears;

	int cnt;
	cin >> cnt;
	cin.get();
	for (int i = 0; i < cnt; i++) {
		ID id; Author author; Keyword keyword;
		Title title; Publisher publisher; Pubyear pubyear;
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keyword);
		getline(cin, publisher);
		getline(cin, pubyear);

		vector<Keyword> restore = tostrings(keyword);
		for (int j = 0; j < restore.size(); j++) {
			Keywords[restore[j]].push_back(id);
		}

		Titles[title].push_back(id);
		Authors[author].push_back(id);
		Publishers[publisher].push_back(id);
		Pubyears[pubyear].push_back(id);
		
	}


	int num_query;
	cin >> num_query;
	
	for (int i = 0; i < num_query; i++) {
		/*1: a book title
		2: name of an author
		3: a key word
		4: name of a publisher
		5: a 4-digit number representing the year
		*/
		vector<ID> target;
		
		int mark;
		scanf("%d: ", &mark);
		
		string input;
		getline(cin, input);

		switch (mark) 
		{
		case 1:
			target = Titles[input]; break;
		case 2:
			target = Authors[input]; break;
		case 3:
			target = Keywords[input]; break;
		case 4:
			target = Publishers[input]; break;
		case 5:
			target = Pubyears[input]; break;
		}

		//输出
		cout << mark << ": ";
		cout << input << endl;
		if (target.size() == 0)
			cout << "Not Found\n";
		else {
			sort(target.begin(), target.end());
			for (int i = 0; i < target.size(); i++) 
				cout << target[i] << endl;
			
		}
	}

	system("pause");
	return 0;
}