//这题是已知BST的后序和中序遍历，求二叉树的层序遍历
#include<iostream>
#include<string>
#include<deque>
using namespace std;

class Node
{
public:
	int data;
	Node*left;
	Node*right;
	Node(int da) {
		data = da;
		left = NULL;
		right = NULL;
	}
};

Node* create(Node*ptr,int postorder[], int inorder[], int cnt)
{
	if (cnt == 0)
		return NULL;
	int data = postorder[cnt - 1];
	ptr = new Node(data);
	
	//在中序中找后序的最后一个
	int i = 0;
	for (; i < cnt; i++) {
		if (inorder[i] == data)
			break;
	}

	ptr->left = create(ptr->left, postorder, inorder, i);
	ptr->right = create(ptr->right, postorder + i, inorder + i + 1, cnt - i - 1);
	return ptr;
}





int main()
{
	int cnt;
	cin >> cnt;
	int*postorder = new int[cnt];
	int*inorder = new int[cnt];
	for (int i = 0; i < cnt; i++) 
		cin >> postorder[i];

	for (int i = 0; i < cnt; i++) 
		cin >> inorder[i];

	Node*ptr = NULL;
	ptr = create(ptr,postorder, inorder, cnt);
	
	deque<Node*> line;
	line.push_back(ptr);
	int all = 0;
	while (line.size() != 0) {
		Node*temp = line.front();
		line.pop_front();
		if (temp == NULL) continue;
		
		cout << temp->data;
		line.push_back(temp->left);
		line.push_back(temp->right);
		all++;
		if (all != cnt) cout << " ";
	}

	system("pause");
	return 0;
}