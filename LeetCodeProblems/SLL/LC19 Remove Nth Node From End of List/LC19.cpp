#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// struct LL {
//     tail
// };

// The way to solve this problem is to create a hash map with
// The directions of the ListNodes and track the directions of every element
// And then delete them
//  This in order to avoid creating a struct and run the list with no purposes.

ListNode *removeNthFromEnd(ListNode *head, int n) {
  unordered_map<int, ListNode *> track;

  // 1,2,3,4,5 -> n = 2 ;  The index to remove is [i](4) = size(5) - n(2) + 1 = 4;
  // the length is 9 Length - n = num[i] +1 that you gotta remove. 9 - 3 = 6 + 1
  // = 7
  ListNode *temp = head;
  for (int i = 1; temp != nullptr; i++) {
    track[i] = temp;
    temp = temp->next;
  }

  //There's other case that occurs when there's only one element in the list
    if (track.size() == 1) {
        return nullptr;
    }

  // The head is just different only in case the node you remove is the first or
  // the last. In this case is the last:
  if (n == 1) {
    temp = track[track.size()-1];
    temp->next = nullptr;
    return head;
  } else if (n == track.size()) {
    // This is the case for the first:
    temp = track[2];
    head = temp;
    return head;
  }

  // ONCE WE GOT THE INDEX AND DIRECTION OF THE ELEMENT WE WANT TO REMOVE
  //  1. That element -1 and that element + 1
  //  2. -1.next = +1
  //  Delete [i] (optional)
  //  Return head

  int indexToRemove = track.size() - n + 1;
  ListNode *previous = track[indexToRemove - 1];
  ListNode *nxt = track[indexToRemove + 1];

  previous->next = nxt;
  return head;
}

int main() { return 0; }