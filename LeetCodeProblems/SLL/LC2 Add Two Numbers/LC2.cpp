#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LL {
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  LL() : head(nullptr), tail(nullptr) {}

  void addNode(int val) {
    ListNode *temp = new ListNode(val);
    if (head == nullptr) {
      head = temp;
      tail = temp;
      return;
    }
    tail->next = temp;
    tail = temp;
  }

  void print() {
    if (head == nullptr) {
      cout << "Empty";
      return;
    }

    ListNode *temp = head;
    while (temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "NULL";
  }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  LL *ll = new LL();
  int res = 0;
  while (l1 != nullptr && l2 != nullptr) {
    if ((l1->val + l2->val + res) >= 10) {
      ll->addNode((l1->val + l2->val + res) % 10);
      res = ((l1->val + l2->val + res) / 10);
    } else {
      ll->addNode(l1->val + l2->val + res);
      res = 0;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  // Three cases, if there is elements left in l1, l2 or res is != zero

  if (l1 != nullptr) {
    if (res == 0) {
      ll->tail->next = l1;
      //UPDATE THE TAIL *** BE CAREFUL WITH IT
    }else {
        //SI QUEDA RESIUDO, voy a añadir el residuo hasta que sea nullprt
        while (l1!=nullptr) {
            if ((l1->val+res)>=10) {
                ll->addNode((l1->val+res)%10);
                res = (l1->val+res)/10;
            }else {
                ll->addNode((l1->val+res)%10);
                res = 0;
            }
            l1 = l1->next;
        }
    
    }
  } else  if (l2 != nullptr) {
    if (res == 0) {
      ll->tail->next = l2;
      //UPDATE THE TAIL *** BE CAREFUL WITH IT
    }else {
        //SI QUEDA RESIUDO, voy a añadir el residuo hasta que sea nullprt
        while (l2!=nullptr) {
            if ((l2->val+res)>=10) {
                ll->addNode((l2->val+res)%10);
                res = (l2->val+res)/10;
            }else {
                ll->addNode((l2->val+res)%10);
                res = 0;
            }
            l2 = l2->next;
        }
    
    }
  }

  //AL FINAL SI QUEDA RESIDUO SE CONVIERTE EN UN NUEVO NODO Y YA
  if (res!=0) {
    ll->addNode(res);
  }

  return ll->head;
}

int main() {
  LL *ll1 = new LL();
  ll1->addNode(9);
  ll1->addNode(9);
  ll1->addNode(9);
  ll1->addNode(9);
  ll1->addNode(9);
  ll1->addNode(9);
  ll1->addNode(9);
  LL *ll2 = new LL();
  ll2->addNode(9);
  ll2->addNode(9);
  ll2->addNode(9);
  ll2->addNode(9);

  LL *res = new LL();

  res->head = addTwoNumbers(ll1->head, ll2->head);

  ll1->print();
  ll2->print();
  res->print();

  return 0;
}
