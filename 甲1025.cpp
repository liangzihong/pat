#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Testee
{
	string id;
	int mark;
	int region_num;
	int region_rank;
	int final_rank;
};


bool cmp(Testee &a, Testee&b)
{
	if (a.mark > b.mark
		|| a.mark == b.mark&&a.id < b.id)
		return true;
	else return false;
}


int main()
{
	int cnt_region;
	int allnum = 0;
	vector<Testee> testees;
	cin >> cnt_region;
	for (int i = 0; i < cnt_region; i++) {
		int num_region;
		cin >> num_region;
		vector<Testee> group;
		for (int j = 0; j < num_region; j++) {
			Testee temp;
			cin >> temp.id >> temp.mark;
			temp.region_num = i+1;
			group.push_back(temp);
		}

		sort(group.begin(), group.end(), cmp);
		for (int i = 0; i < group.size(); i++) 
		{
			group[i].region_rank = i + 1;

			//如果分数和前一名相同
			if (i != 0 && group[i].mark == group[i - 1].mark)
				group[i].region_rank = group[i - 1].region_rank;
			
			testees.push_back(group[i]);
		}
		allnum += num_region;
	}

	sort(testees.begin(), testees.end(), cmp);
	cout << allnum<<endl;
	for (int i = 0; i < testees.size(); i++) {
		testees[i].final_rank = i + 1;
		if (i != 0 && testees[i].mark == testees[i - 1].mark)
			testees[i].final_rank = testees[i - 1].final_rank;
		cout << testees[i].id << " " << testees[i].final_rank << " " << testees[i].region_num << " " << testees[i].region_rank << endl;
	}
	system("pause");
	return 0;
}