class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class ReverseLinkedList {

    // Функция разворота списка
    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode nextTemp = current.next; // Сохраняем следующий узел
            current.next = prev;              // Разворачиваем указатель
            prev = current;                   // Перемещаем prev на текущий
            current = nextTemp;               // Перемещаем current на следующий
        }

        return prev; // prev теперь новая голова
    }

    // Вспомогательная функция для печати списка
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    // Демонстрация
    public static void main(String[] args) {
        // Создаем список: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Исходный список: ");
        printList(head);

        ListNode reversedHead = reverseList(head);

        System.out.print("Развернутый список: ");
        printList(reversedHead);
    }
}