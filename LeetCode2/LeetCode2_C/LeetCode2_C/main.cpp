#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// Init local variables
	ListNode* l1_ite = l1;
	ListNode* l2_ite = l2;
	ListNode* answ_ite = new ListNode();
	ListNode* answ = answ_ite;
	int carry = 0;
	int num1 = 0;
	int num2 = 0;
	int answ_tmp = 0;
	bool init = false;

	// calculate
	while ((l1_ite || l2_ite) || carry) {
		(l1_ite) ? num1 = l1_ite->val : num1 = 0;
		(l2_ite) ? num2 = l2_ite->val : num2 = 0;
		answ_tmp = (num1 + num2 + carry) % 10;
		carry = (num1 + num2 + carry) / 10;
		answ_ite->next = new ListNode(answ_tmp);
		if (l1_ite) l1_ite = l1_ite->next;
		if (l2_ite) l2_ite = l2_ite->next;
		answ_ite = answ_ite->next;
	}
	return answ->next;
}

void printTest(ListNode* inp) {
	ListNode* ite = inp;
	while (ite) {
		cout << to_string(ite->val) << endl;
		ite = ite->next;
	}
}

int main() {
	// Init input value
	ListNode* list1 = new ListNode(9);
	/*list1->next = new ListNode(4);
	list1->next->next = new ListNode(3);*/
	ListNode* cur1 = list1;
	for (int i = 0; i < 6; i++) {
		cur1->next = new ListNode(9);
		cur1 = cur1->next;
	}
	printTest(list1);

	cout << "--------" << endl;

	ListNode* list2 = new ListNode(9);
	/*list2->next = new ListNode(6);
	list2->next->next = new ListNode(4);*/
	ListNode* cur2 = list2;
	for (int j = 0; j < 3; j++) {
		cur2->next = new ListNode(9);
		cur2 = cur2->next;
	}
	printTest(list2);

	cout << "--------" << endl;

	printTest(addTwoNumbers(list1, list2));

	return 0;
}