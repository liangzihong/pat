#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

struct Student
{
	string id;
	string name;
	int mark;
};

bool cmp1(Student a, Student b)
{
	if (a.id < b.id) return true;
	return false;
}

bool cmp2(Student a, Student b)
{
	if (a.name < b.name) return true;
	else if (a.name == b.name&&a.id < b.id) return true;
	else return false;
}

bool cmp3(Student a, Student b)
{
	if (a.mark < b.mark) return true;
	else if (a.mark == b.mark&&a.id < b.id) return true;
	else return false;
}

int main()
{
	
		int cnt;
		int idx;
		cin >> cnt >> idx;
		Student*arr = new Student[cnt];
		for (int i = 0; i < cnt; i++) {
			char*temp = new char[100];
			scanf("%s", temp);
			arr[i].id = temp;
			scanf("%s", temp);
			arr[i].name = temp;
			scanf("%d", &arr[i].mark);
			delete[]temp;
		}
		switch (idx) {
		case 1:sort(arr, arr + cnt, cmp1); break;
		case 2:sort(arr, arr + cnt, cmp2); break;
		case 3:sort(arr, arr + cnt, cmp3); break;
		}

		for (int i = 0; i < cnt; i++)
			printf("%s %s %d\n", arr[i].id.c_str(), arr[i].name.c_str(), arr[i].mark);

	return 0;
}