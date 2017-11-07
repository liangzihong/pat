#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

vector<string> change(int source, int base)
{
	stack<string> yushu;
	while (source != 0)
	{
		yushu.push(to_string(source%base));
		source = source / base;
	}
	vector<string> vec;
	while (yushu.size() != 0)
		vec.push_back(yushu.top()), yushu.pop();
	return vec;
}


int main()
{
	int source;
	int base;
	cin >> source >> base;
	if (source == 0)
	{cout << "Yes\n" << 0; return 0;}
	vector<string> changed = change(source, base);
	
	int len = changed.size()-1;
	for (int i = 0; i < changed.size(); i++)
	{
		if (changed[i] != changed[len - i])
		{
			cout << "No\n";
			for (int j = 0; j < changed.size(); j++) {
				cout << changed[j];
				if (j != changed.size() - 1) cout << " ";
			}
			system("pause");
			return 0;
		}
	}

	cout << "Yes\n";
	for (int j = 0; j < changed.size(); j++) {
		cout << changed[j];
		if (j != changed.size() - 1) cout << " ";
	}
	system("pause");
	return 0;

}