void reverse(ListNode* &list)
{
	ListNode* p = list;
	ListNode* head = p;
	ListNode* t = nullptr;
	while (p->next)
	{
		t = p->next;
		p->next = p->next->next;
		t->next = head;
		head = t;
	}
	list = head;
}