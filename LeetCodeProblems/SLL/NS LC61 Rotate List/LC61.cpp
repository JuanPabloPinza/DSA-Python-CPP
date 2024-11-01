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

ListNode *rotateRight(ListNode *head, int k)
{
    //[1,2,3,4,5]
    // k=2
    // case is empty or no movements

    if (head == nullptr || k == 0 || head->next == nullptr)
    {
        return head;
    }

    ListNode *temp = head;
    ListNode *tail = new ListNode();
    temp = head;
    int size = 0;

    // Track the tail and connect it to the head
    while (temp != nullptr)
    {
        if (temp->next == nullptr)
            tail = temp;
        temp = temp->next;
        size++;
    }
    // size = 5
    // k=2
    int moves = (k % size); // 2 % 5 = 2 
    if (moves == 0)
    {
        return head;
    }

    // Connected into a Circular LL
    tail->next = head;
    
    // Now let´s move the positions needed. k = 2
    // E.g. if moves is 3: 1 -> 2 -> 3 -> 4 ->  5 nullptr ||  [2] [3] [4] [1]

    // For example: size 20, k = 27 -> k%size
    // Other: size 50, k = 27 -> k%size
    // We have to iterate size-moves: E.g. 5 - 2 = 3.
    // Since moves 
    for (int i = 0; i < (size-moves); i++)
    {
        head = head->next;
        tail = tail->next;
    }

    // Unlink
    tail->next = nullptr;
    return head;
}

void printList(ListNode* head){
    if (head == nullptr)
    {
        cout<<"Empty";
        return;
    }
    ListNode* temp = head;
    while (temp)
    {
        cout<< temp->val<< " -> ";
        temp = temp->next;
    }
    cout<< "nullptr";
    return;   
}


int main()
{
    ListNode* LL = new ListNode(1, (new ListNode(2, new ListNode(3, new ListNode (4, new ListNode(5))))));
    printList(LL);

    ListNode* res = rotateRight(LL,2);
    printList(res);


    return 0;
}