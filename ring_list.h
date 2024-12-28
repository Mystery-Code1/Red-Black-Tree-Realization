#ifndef RING_LIST_H
#define RING_LIST_H


struct Elem {
    int data;
    Elem* next;
};

void print_list(Elem* start);

Elem* create_list();

Elem* add_to_list(Elem* start, int elem);

Elem* remove_all(Elem* first_pointer);

Elem* remove_elem(Elem* head, int elem);

bool in_list(int val, Elem* list_pointer);

#endif