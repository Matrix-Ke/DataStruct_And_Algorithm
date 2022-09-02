#include "stdafx.h"
#include <iostream>
#include<vector>
#include <queue>
#include <thread>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


using namespace std;
class kkopentest {
public:
	vector<vector<int>>  ret;
	vector<int> tempVec;
	void travel(TreeNode* root, int depth)
	{
		if (!root)
			return;
		if (ret.size() == depth)
		{
			ret.push_back(vector<int>());
			
		}
		ret[depth].push_back(root->val);
		if (root->left)
		{
			travel(root->left, depth + 1);
		}
		if (root->right)
		{
			travel(root->right, depth + 1);
		}
	}
	vector<vector<int> > levelOrder(TreeNode *root) {
		travel(root, 0);
		return ret;
	}


	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>   result;
		queue<TreeNode*> queueTree;
		vector<int> tempVector;
		queueTree.push(root);
		result.push_back(tempVector);
		tempVector.push_back(root->val);
		int counter = 0;
		TreeNode* header = nullptr;
		while (!queueTree.empty())
		{
			queue<TreeNode*> leveltemp;
			int size_num = queueTree.size();
			for (int i = 0; i < size_num; i++)
			{
				if (root->left)
				{
					leveltemp.push(root->left);
					//tempVector.push_back(root->left->val);
					//++counter;
				}
				if (root->right)
				{
					leveltemp.push(root->right);
					//tempVector.push_back(root->right->val);
					//++counter;
				}
				tempVector.push_back(queueTree.front()->val);
				queueTree.pop();
			}
			result.push_back(tempVector);
			while ( !leveltemp.empty() )
			{
				queueTree.push(leveltemp.front());
				leveltemp.pop();
			}
		}
		return result;
	}
};
void insert_node(TreeNode*& root, vector<int>& arr, int i)
{
	if (i >= arr.size())
		return;
	root = (TreeNode*)malloc(sizeof(TreeNode));
	std::cout << "插入节点:" << arr[i] << endl;
	root->val = arr[i];
	root->left = nullptr;
	root->right = nullptr;
	insert_node(root->left, arr, 2 * i + 1);
	insert_node(root->right, arr, 2 * i + 2);
}


void traval_node(TreeNode* root)
{
	if (!root)
		return;
	stack<TreeNode*> stack_temp;
	stack_temp.push(root);
	while (!stack_temp.empty())
	{
		root = stack_temp.top();
		stack_temp.pop();
		while (root)
		{
			cout << "浏览节点:" << root->val << std::endl;
			if (root->right)
				stack_temp.push(root->right);
			root = root->left;
		}		
	}
}

void pretraval(TreeNode* root)
{
	if (!root)
		return;
	stack<TreeNode*> t_stack;
	t_stack.push(root);
	while (!t_stack.empty())
	{
		root = t_stack.top();
		t_stack.pop();
		while (root)
		{
			std::cout << "此时输出节点：" << root->val << endl;
			t_stack.push(root->right);
			root = root->left;
		}
	}
}
int main()
{
	std::vector<int> foo = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	TreeNode* root = nullptr;
	insert_node(root, foo, 0);
	traval_node(root);
	/*cout << root->left->right->left->val;*/


	return 0;
}