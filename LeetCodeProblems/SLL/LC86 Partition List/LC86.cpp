#include <iostream>


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x) {
  // Constrains head null or just one node
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  // Create two list, first is the one that saves nodes less than x
  //  The 2nd is the one that will keep the reminder and delete the other nodes.
  ListNode *hLess = new ListNode();
  ListNode *tLess = new ListNode();
  ListNode *hRem =new ListNode();
  ListNode *tRem = new ListNode();
  bool isHless = true;
  bool isHrem = true;

  ListNode *temp = head;

  // Check if our head is rem or less, and check if it's our first node to set
  // it as a head.
  while (temp != nullptr) {
    if (isHless && temp->val < x) {
      hLess = temp;
      tLess = hLess;
      isHless = false;
      temp = temp->next;
      continue;
    }
    if (isHrem && temp->val >= x) {
      hRem = temp;
      tRem = hRem;
      isHrem = false;
    temp = temp->next;
      continue;
    }
    // Now we're sure that always we'll have a head
    if (temp->val < x) {
      tLess->next = temp;
    temp = temp->next;
      tLess = tLess->next;
    } else {
      tRem->next = temp;
          temp = temp->next;
      tRem = tRem->next;
    }
  }
  // Join the lists.
  // But first check if we didn't had any other list created.
  if (isHless) {
    tRem->next = nullptr;
    return hRem;
  } else if (isHrem) {
    tLess->next = nullptr;
    return hLess;
  }

  //Now join the lists lessLL -> remLL
  tRem->next = nullptr;
  tLess->next = hRem;
  return hLess;

}

// Función para mostrar los elementos de la lista enlazada
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl; // Marca el final de la lista
}

// Función para crear una lista enlazada con 10 elementos
ListNode* createList() {
    ListNode* head = new ListNode(10); // Primer nodo
    ListNode* current = head;
    
    for (int i = 0; i <= 10; i++) {
        current->next = new ListNode(i); // Crear nuevo nodo
        current = current->next;         // Mover al siguiente nodo
    }
    
    return head;
}

ListNode* createRandomList(int length) {
    // Inicializa el generador de números aleatorios
    srand(static_cast<unsigned int>(time(0))); // Usar la hora actual para inicializar el generador

    ListNode* head = new ListNode(rand() % 100); // Primer nodo con un valor aleatorio entre 0 y 99
    ListNode* current = head;
    
    for (int i = 1; i < length; ++i) {
        current->next = new ListNode(rand() % 100); // Crear nuevo nodo con valor aleatorio
        current = current->next;                    // Mover al siguiente nodo
    }
    
    return head;
}

int main() {
    // ListNode* head = createRandomList(2); 
    ListNode* head = new ListNode(2,new ListNode(1));
    printList(head);               
    ListNode* res = partition(head,2); 
    printList(res);               

    return 0;
}
