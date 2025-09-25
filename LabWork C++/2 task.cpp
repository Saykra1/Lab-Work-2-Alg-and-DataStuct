//Задача 2: "Поиск цикла в односвязном списке"
//Условие : Напишите функцию, которая определяет, содержит ли односвязный список цикл
// (когда какой - то узел ссылается на предыдущий узел в списке).
#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Функция поиска цикла (алгоритм Черепахи и Зайца)
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head; // Черепаха (двигается на 1 узел)
        ListNode* fast = head; // Заяц (двигается на 2 узла)

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Черепаха на шаг
            fast = fast->next->next;    // Заяц на два шага

            if (slow == fast) {         // Если встретились - есть цикл
                return true;
            }
        }

        return false; // Если fast дошел до конца - цикла нет
    }

    // Функция для безопасного вывода списка (ограничивает количество элементов)
    void printList(ListNode* head, int maxNodes = 10) {
        if (head == nullptr) {
            std::cout << "NULL" << std::endl;
            return;
        }

        std::unordered_set<ListNode*> visited;
        int count = 0;
        ListNode* current = head;

        while (current != nullptr && count < maxNodes) {
            std::cout << current->val;

            // Проверяем, был ли узел уже посещен (для обнаружения цикла)
            if (visited.count(current)) {
                std::cout << " -> [ЦИКЛ к узлу " << current->val << "]";
                break;
            }
            visited.insert(current);

            if (current->next != nullptr) {
                std::cout << " -> ";
            }

            current = current->next;
            count++;
        }

        if (count >= maxNodes) {
            std::cout << " ... (превышен лимит " << maxNodes << " узлов)";
        }
        else if (current == nullptr) {
            std::cout << " -> NULL";
        }

        std::cout << std::endl;
    }

    // Функция для определения длины цикла (если есть)
    int cycleLength(ListNode* head) {
        if (!hasCycle(head)) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        // Находим точку встречи
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // Измеряем длину цикла
        int length = 1;
        fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            length++;
        }

        return length;
    }
};

// Демонстрация
int main() {
    setlocale(LC_ALL, "");

    Solution solution;

    // Создаем список с циклом: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (цикл)
    std::cout << "=== Список с циклом ===" << std::endl;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Создаем цикл на узел 2

    std::cout << "Структура списка: ";
    solution.printList(head);

    bool hasCycle = solution.hasCycle(head);
    std::cout << "Список содержит цикл: " << (hasCycle ? "Да" : "Нет") << std::endl;

    if (hasCycle) {
        std::cout << "Длина цикла: " << solution.cycleLength(head) << " узлов" << std::endl;
    }

    std::cout << std::endl;

    // Создаем список без цикла: 1 -> 2 -> 3 -> 4 -> 5
    std::cout << "=== Список без цикла ===" << std::endl;
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    std::cout << "Структура списка: ";
    solution.printList(head2);

    bool hasCycle2 = solution.hasCycle(head2);
    std::cout << "Второй список содержит цикл: " << (hasCycle2 ? "Да" : "Нет") << std::endl;

    std::cout << std::endl;

    // Тестируем пустой список
    std::cout << "=== Пустой список ===" << std::endl;
    ListNode* head3 = nullptr;
    std::cout << "Структура списка: ";
    solution.printList(head3);
    bool hasCycle3 = solution.hasCycle(head3);
    std::cout << "Третий список содержит цикл: " << (hasCycle3 ? "Да" : "Нет") << std::endl;

    // Очистка памяти (для списка без цикла)
    delete head2->next->next->next->next;
    delete head2->next->next->next;
    delete head2->next->next;
    delete head2->next;
    delete head2;

    // Для списка с циклом нужно аккуратно удалять, чтобы не попасть в бесконечный цикл
    // Разрываем цикл перед удалением
    head->next->next->next->next->next = nullptr;
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}