struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//��ͷ���
//void createList(ListNode* &root, vector<int>& arr)
//{
//	if (arr.size() > 0)
//	{
//		root = (ListNode*)malloc(sizeof(ListNode));
//		root->next = nullptr;
//		root->val = arr.size();
//	}
//	ListNode* nodePtr = root;
//	ListNode* temptr = nullptr;
//	for (auto itr = arr.begin(); itr != arr.end(); itr++)
//	{
//		temptr = (ListNode*)malloc(sizeof(ListNode));
//		temptr->val = *itr;
//		temptr->next = nullptr;
//		nodePtr->next = temptr;
//		nodePtr = nodePtr->next;	
//	}
//}
void createList(ListNode* &root, vector<int>& arr)
{
	if (arr.size() > 0)
	{
		root = (ListNode*)malloc(sizeof(ListNode));
		root->next = nullptr;
		root->val = arr[0];
	}
	ListNode* nodePtr = root;
	ListNode* temptr = nullptr;
	for (auto itr = arr.begin()+1; itr != arr.end(); itr++)
	{
		temptr = (ListNode*)malloc(sizeof(ListNode));
		temptr->val = *itr;
		temptr->next = nullptr;
		nodePtr->next = temptr;
		nodePtr = nodePtr->next;
	}
}


//��ͷ���
void sortList(ListNode* &head)
{
	if (!head || !head->next) return;
	ListNode* p = head->next;
	ListNode* q = p->next;
	ListNode* temp = nullptr;
	ListNode* preq = nullptr;
	while(q)
	{
		if (p->val <= q->val)
		{
			
			p = q;
			q = q->next;
		}
		else
		{
			preq = head;
			temp = head->next;
			while (temp->val <= q->val)
			{
				preq = temp;
				temp = temp->next;
			}
			
			p->next = q->next;
			q->next = temp;
			preq->next = q;

			q = p->next;
		}
	}
}
//û��ͷ���
void sortListNOhead(ListNode* &head)
{
	if (!head || !head->next) return;
	ListNode* p = head;
	ListNode* q = p->next;
	ListNode* temp = nullptr;
	ListNode* preq = nullptr;
	while (q)
	{
		if (p->val <= q->val)
		{
			p = q;
			q = q->next;
		}
		else
		{
			preq = head;
			temp = head;
			while (temp->val <= q->val)
			{
				preq = temp;
				temp = temp->next;
			}

			p->next = q->next;
			q->next = temp;
			if(preq == temp)
			{
				head = q;
			}
			else
			{
				preq->next = q;
			}
			q = p->next;
		}
	}
}