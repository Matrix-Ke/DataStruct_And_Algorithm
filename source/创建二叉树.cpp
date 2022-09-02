struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void createBtree(TreeNode*& root, vector<int>& arr, int i)
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



int mindepth(TreeNode* root)
{
	int L;
	int R;
	if (!root)
	{
		return 0;
	}
	return ((L = mindepth(root->left)) < (R = mindepth(root->right)) ? L : R) + 1;
}


void inoreder(TreeNode* head)
{
	if (!head)
	{
		return;
	}
	inoreder(head->left);
	std::cout << head->val << endl;
	inoreder(head->right);
}
void pretraval(TreeNode* head)
{
	stack<TreeNode*> stack;
	TreeNode* temp = nullptr;
	stack.push(head);
	while (!stack.empty())
	{
		temp = stack.top();
		stack.pop();
		while (temp)
		{
			std::cout << temp->val;
			stack.push(temp->right);
			temp = temp->left;
		}

	}
}