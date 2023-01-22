class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """

    l1_ite = ListNode(val=0, next=l1)
    l2_ite = ListNode(val=0, next=l2)
    answ_ite = ListNode(0)
    answ = answ_ite
    carry = 0

    while (l1_ite.next or l2_ite.next or carry):
        num1 = l1_ite.next.val if (l1_ite.next) else 0
        num2 = l2_ite.next.val if (l2_ite.next) else 0
        answ_tmp = (num1 + num2 + carry) % 10
        carry = (num1 + num2 + carry) // 10
        answ_ite.next = ListNode(answ_tmp)
        if (l1_ite.next):
            l1_ite = l1_ite.next
        if (l2_ite.next):
            l2_ite = l2_ite.next
        answ_ite = answ_ite.next
    answ = answ.next
    return answ


def printTest(list):
    ite = list
    while (ite):
        print(ite.val)
        ite = ite.next


# init input value
# list1 = ListNode(0)
# list1_ite = list1
# for i in range(7):
#     list1_ite.next = ListNode(9)
#     list1_ite = list1_ite.next
# list1 = list1.next

# list2 = ListNode(0)
# list2_ite = list2
# for i in range(4):
#     list2_ite.next = ListNode(9)
#     list2_ite = list2_ite.next
# list2 = list2.next

list1 = ListNode(2)
list1.next = ListNode(4)
list1.next.next = ListNode(3)

list2 = ListNode(5)
list2.next = ListNode(6)
list2.next.next = ListNode(4)


answ = addTwoNumbers(list1, list2)
printTest(answ)
