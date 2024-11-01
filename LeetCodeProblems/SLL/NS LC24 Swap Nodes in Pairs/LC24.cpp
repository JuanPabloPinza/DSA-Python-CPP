#include <iostream>
#include <unordered_map>

using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution:
//  1. Save the position and direction of every singe one in a unordered map
//  2. Check if it's odd or even.
//  3. Swap every two spaces the position saving the current and the next.
//  4. Valid the empty case.
//  5. Be careful heading the head.

// ListNode *swapPairs(ListNode *head)
// {
//   //Check if the LL is empty
//   if (head == nullptr)
//   {
//     return nullptr;
//   }
//   //Track all the directions in an unordered_map
//   unordered_map<int, ListNode*> track;
//   ListNode* temp = head;
//   for (int i = 1; head != nullptr; i++)
//   {
//     track[i]=head;
//     head = head->next;
//   }
//   //Check if is odd, if it's the case just swap every node without problems.
//   //No problem creating two cases, just if it's odd the last node keeps the same.

//   ListNode* curr = head;
//   ListNode* nxt = head;

// }

ListNode *swapPairs(ListNode *head)
{
  // Check if the LL is empty or if it's just one element on it.

  if (head == nullptr || head->next ==nullptr)
  {
    return head;
  }
  // Check if is odd, if it's the case just swap every node without problems.
  // No problem creating two cases, just if it's odd the last node keeps the same.
  ListNode *curr = head;
  ListNode *nxt = head->next;
  ListNode *dummy = nxt;


  ListNode *temp = nxt->next;
  while (head != nullptr && head->next != nullptr)
  {
    temp = nxt->next;
    curr->next = nxt;
    nxt->next = curr;
    curr = temp;

    nxt = temp->next;
  }
  //What happens with the left node in case is odd:Nothing apparently
  if (temp!=nullptr)
  {
    nxt->next = temp;
  }
  

  return ref;

}

int main()
{
  ListNode* four = new ListNode(4);
  ListNode* three = new ListNode(3,four);
  ListNode* two= new ListNode(2,three);
  ListNode* head = new ListNode(1,two);

  ListNode* temp = swapPairs(head);



  while (temp != nullptr)
  {
    cout<<temp->val<<"->";
    temp=temp->next;
  }


  
  
  
  return 0;
}