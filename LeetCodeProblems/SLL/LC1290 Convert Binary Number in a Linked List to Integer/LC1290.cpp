#include <cmath> // Include cmath for pow function
#include <iostream>
#include <iterator>
#include <unordered_map>

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

int getDecimalValue(ListNode *head) {
  // HOW TO SOLVE THIS PROBLEM:
  // 1. Go trough the LL based on the positions and multiply them by 0 or 1.
  // 2. YOU JUST GOTTA SUM ALL THE 2^N
  ListNode *temp = head;
  unordered_map<int, bool> track;
  int result = 0;
  for (int i = 0; temp != nullptr; i++) {
    if (temp->val == 1) {
      track[i] = true;
    } else {
      track[i] = false;
    }
    temp = temp->next;
  }

  for (int i = 0; i < track.size(); i++) {

    if (track[i]) {
      result += pow(2, track.size() - i - 1);
    }
  }
  return result;
}

int main() {

  LL *ll1 = new LL();
  ll1->addNode(1);
  ll1->addNode(0);
  ll1->addNode(1);

  cout << getDecimalValue(ll1->head);
  return 0;
}