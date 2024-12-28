#include <iostream>
#include "ring_list.h"


void print_list(Elem* start) {
    if (start == nullptr) {
        std::cout << "-" << std::endl;
        return;
    }

    Elem* h = start;
    do {
        std::cout << h->data << ' ';
        h = h->next;
    } while (h != start);
    std::cout << std::endl;
}

Elem* create_list() {
    return nullptr;
}

Elem* add_to_list(Elem* start, int elem) {
    Elem* add_elem = new Elem();
    add_elem->data = elem;

    if (start == nullptr) {
        add_elem->next = add_elem; // Указатель на самого себя
        return add_elem;
    } else {
        Elem* c_elem = start;
        while (c_elem->next != start) {
            c_elem = c_elem->next;
        }
        c_elem->next = add_elem;
        add_elem->next = start;
    }
    return start; // Возвращаем начальный элемент списка
}

bool in_list(int val, Elem* list_pointer) {
    if (list_pointer == nullptr) return false;

    Elem* c_elem = list_pointer;
    do {
        if (c_elem->data == val) {
            return true;
        }
        c_elem = c_elem->next;
    } while (c_elem != list_pointer);
    return false;
}

Elem* remove_all(Elem* first_pointer) {
    if (first_pointer == nullptr) return nullptr;

    Elem* c_elem = first_pointer;
    do {
        Elem* cr_elem = c_elem;
        c_elem = c_elem->next;
        delete cr_elem;
    } while (c_elem != first_pointer);
    
    return nullptr; // Возвращаем nullptr, так как список пуст
}

Elem* remove_elem(Elem* head, int elem) {
    if (head == nullptr) return nullptr;

    Elem* current = head;
    Elem* end_elem = head;

    do {
        end_elem = end_elem->next;
    } while (end_elem->next != head);

    do {
        if (current->next->data == elem && head->data != elem) {
            Elem* next_link = current->next->next;
            delete current->next;
            current->next = next_link;
        } else if (head->data == elem && head->next == head) {
            delete head;
            return nullptr; // Список стал пустым
        } else if (head->data == elem) {
            Elem* next_head = head->next;
            delete head;
            end_elem->next = next_head;
            head = next_head;
            current = next_head;
        } else {
            current = current->next;
        }
    } while (current != head);
    
    return head; // Возвращаем начальный элемент списка
}
