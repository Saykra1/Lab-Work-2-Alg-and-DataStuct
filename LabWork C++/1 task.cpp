//Задача 1: "Разворот односвязного списка"
//Условие : Напишите функцию, которая принимает голову односвязного списка
// и возвращает голову развернутого списка(элементы в обратном порядке).
#include <iostream>

// Узел списка
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Функция разворота списка (итеративная версия)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next; // Сохраняем следующий узел
            current->next = prev;               // Разворачиваем указатель
            prev = current;                     // Перемещаем prev на текущий
            current = nextTemp;                 // Перемещаем current на следующий
        }

        return prev; // prev теперь новая голова
    }
};

// Вспомогательная функция для печати списка
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Демонстрация
int main() {
    setlocale(LC_ALL, "");
    // Создаем список: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Исходный список: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Развернутый список: ";
    printList(reversedHead);

    return 0;
}