#include <iostream>

using namespace std;

class Node {
public:
  Node *next = nullptr;
  int value = 0;
  Node(int value) { this->value = value; }
};

class SLL {
private:
  Node *head;
  Node *tail;

public:
  SLL() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  ~SLL() {
    if (head == nullptr) {
      delete (head);
      delete (tail);
    } else {
      while (head != nullptr) {
        Node *temp = head->next;
        delete (head);
        head = temp;
      }
      delete (head);
      delete (tail);
    }
  }

  void addAtTail(int value) {
    Node *current = new Node(value);
    if (head == nullptr) {
      head = current;
      tail = current;
      return;
    }
    tail->next = current;
    tail = current;
  }

  void addAtHead(int value) {
    Node *current = new Node(value);
    if (head == nullptr) {
      head = current;
      tail = current;
      return;
    }
    current->next = head;
    head = current;
  }

  void printList() {
    if (head == nullptr) {
      cout << "List is empty";
      return;
    }
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->value<<" -> ";
      temp = temp->next;
    }
      cout << "nullptr";
  }
};

int main() {
  SLL *sll = new SLL();
  sll->addAtHead(3);
  sll->addAtHead(2);
  sll->addAtHead(1);
  sll->addAtHead(0);
  sll->addAtTail(8);
  sll->printList();

  return 0;
}