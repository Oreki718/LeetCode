public class Main {

    public static void printTest(ListNode list){
        ListNode ite = list;
        while (ite != null){
            System.out.println(ite.val);
            ite = ite.next;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        // Init local variables
        ListNode l1_ite = new ListNode(0, l1);
        ListNode l2_ite = new ListNode(0, l2);
        ListNode ans_ite = new ListNode(0);
        ListNode ans = ans_ite;
        int num1 = 0;
        int num2 = 0;
        int ans_tmp = 0;
        int carry = 0;

        // Calculate
        while ((l1_ite.next != null || l2_ite.next != null) || carry != 0){
            num1 = (l1_ite.next != null) ? l1_ite.next.val : 0;
            num2 = (l2_ite.next != null) ? l2_ite.next.val : 0;
            ans_tmp = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            ans_ite.next = new ListNode(ans_tmp);
            if (l1_ite.next != null) l1_ite = l1_ite.next;
            if (l2_ite.next != null) l2_ite = l2_ite.next;
            ans_ite = ans_ite.next;
        }
        ans = ans.next;
        return ans;
    }

    public static void main(String[] args) {

        // Init input value
        ListNode list1 = new ListNode(9);
        ListNode cur1 = list1;
        for (int i=0; i < 6; i++){
            cur1.next = new ListNode(9);
            cur1 = cur1.next;
        }
//        list1.next = new ListNode(4);
//        list1.next.next = new ListNode(3);
        printTest(list1);

        System.out.println("-------");

        ListNode list2 = new ListNode(9);
        ListNode cur2 = list2;
        for (int j=0; j < 3; j++){
            cur2.next = new ListNode(9);
            cur2 = cur2.next;
        }
//        list2.next = new ListNode(6);
//        list2.next.next = new ListNode(4);
        printTest(list2);

        System.out.println("-------");
        printTest(addTwoNumbers(list1, list2));


    }
}