#include <iostream>

using namespace std;

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для виведення зв'язаного списку
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для об'єднання двох списків
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 && l2) {
        current->next = l1;
        l1 = l1->next;
        current = current->next;

        current->next = l2;
        l2 = l2->next;
        current = current->next;
    }

    if (l1) {
        current->next = l1;
    }

    return dummy->next;
}

// Функція для знаходження середини списку
ListNode* findMiddle(ListNode* head) {
    if (!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Функція для перевпорядкування списку
void reorderList(ListNode* head) {
    if (!head || !head->next) {
        return;
    }

    // Знаходимо середину списку
    ListNode* middle = findMiddle(head);

    // Розділяємо список на два підсписки
    ListNode* l1 = head;
    ListNode* l2 = middle->next;
    middle->next = nullptr;

    // Реверсуємо другий підсписок
    ListNode* prev = nullptr;
    ListNode* current = l2;
    ListNode* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l2 = prev;

    // Об'єднуємо два підсписки
    head = mergeLists(l1, l2);
}

int main() {
    // Приклад 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Original List 1: ";
    printList(head1);

    reorderList(head1);

    cout << "Reordered List 1: ";
    printList(head1);

    // Приклад 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    cout << "Original List 2: ";
    printList(head2);

    reorderList(head2);

    cout << "Reordered List 2: ";
    printList(head2);

    return 0;
}
