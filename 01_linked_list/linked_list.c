#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} LinkedList;

Node* create_node(int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

LinkedList create_list() {
  LinkedList list;
  list.head = NULL;
  return list;
}

void append(LinkedList* list, int data) {
  Node* new_node = create_node(data);
  if (list->head == NULL) {
    list->head = new_node;
    return;
  }
  Node* current = list->head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void prepend(LinkedList* list, int data) {
  Node* new_node = create_node(data);
  new_node->next = list->head;
  list->head = new_node;
}

void display(LinkedList* list) {
  Node* current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("None\n");
}

void delete_node(LinkedList* list, int key) {
  Node* current = list->head;
  Node* prev = NULL;

  if (current != NULL && current->data == key) {
    list->head = current->next;
    free(current);
    return;
  }

  while (current != NULL && current->data != key) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) return;

  prev->next = current->next;
  free(current);
}
