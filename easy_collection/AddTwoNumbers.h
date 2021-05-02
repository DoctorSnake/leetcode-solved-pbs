#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode* l1)
{
  ListNode* it = l1;
  while(it != nullptr){
    std::cout << it->val; 
    if(it->next != nullptr) std::cout <<", ";
    it = it->next;
  }
  std::cout << std::endl;
}

void add(int x, ListNode*& l1)
{  
  l1 = new ListNode(x, l1);
}

void addList(std::vector<int> v, ListNode*& l1)
{ for(int i = v.size()-1; i >= 0; i--)
  {
    add(v[i], l1);
  }
}

ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int ret)
{
    if((l1 == nullptr) && (l2 == nullptr)){
        if(ret == 0){
            return nullptr;
        }
        else{
            ListNode* res = new ListNode(ret);
            return res;
        }
    }
    else{
        int sum = ret;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;
        if (l1 != nullptr) { sum += l1->val; next1 = l1->next; }
        if (l2 != nullptr) { sum += l2->val; next2 = l2->next; } 
        // std::cout << "sum = " << sum << std::endl;
        int r1 = sum >= 10 ? sum - 10 : sum; 
        int r2 = sum >= 10 ;
        // std::cout << "r1 = " << r1 << std::endl;
        // std::cout << "r2 = " << r2 << std::endl;
        ListNode* next = addTwoNumbersHelper(next1, next2, r2);
        ListNode* res = new ListNode(r1, next);
        // std::cout << "res->val = " << res->val << std::endl;
        // if (res->next != nullptr){
        //     std::cout << "res->next->val = " << res->next->val << std::endl;            
        // }
        return res;
    }
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbersHelper(l1, l2, 0);
};

void testAddTwoNumbers(){
  std::cout << "adding [2,4,3] and [5,6,4], expecting [7,0,8]" << std::endl;
  ListNode* l1 = nullptr; 
  addList({2,4,3}, l1);
  ListNode* l2 = nullptr; 
  addList({5,6,4}, l2);
  ListNode* sum1 = addTwoNumbers(l1, l2); 
  std::cout << "output : "; 
  printListNode(sum1);

  std::cout << "adding [5] and [5], expecting [0, 1]" << std::endl;
  ListNode* l3 = nullptr; 
  addList({5}, l3);
  ListNode* l4 = nullptr; 
  addList({5}, l4);
  ListNode* sum2 = addTwoNumbers(l3, l4); 
  std::cout << "output : "; 
  printListNode(sum2);
}