//
// Created by qyxie on 16/9/2021.
//
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_from_array(vector<int> &nums){
    ListNode *head = new ListNode(nums[0]);
    ListNode *curr = head;
    for(int i = 1; i < nums.size(); ++i){
        ListNode *node = new ListNode(nums[i]);
        curr->next = node;
        curr = curr->next;
    }
    return head;
}

void show_list(ListNode* l){
    while(l->next != nullptr){
        cout << l->val << " ";
        l = l->next;
    }
    cout << l->val << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = nullptr;
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *curr3 = l3;
        int flag = 0;
        while(curr1 != nullptr && curr2 != nullptr){
            int result = curr1->val + curr2->val + flag;
            if(result >= 10){
                flag = 1;
                result -= 10;
                if(l3 == nullptr){
                    ListNode *node = new ListNode(result);
                    l3 = node;
                    curr3 = l3;
                }else {
                    ListNode *node = new ListNode(result);
                    curr3->next = node;
                    curr3 = curr3->next;
                }
            }else{
                flag = 0;
                if(l3 == nullptr){
                    ListNode *node = new ListNode(result);
                    l3 = node;
                    curr3 = l3;
                }else {
                    ListNode *node = new ListNode(result);
                    curr3->next = node;
                    curr3 = curr3->next;
                }
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        if(curr2 == nullptr && curr1 != nullptr){
            if(flag == 0){
                curr3->next = curr1;
            }else{
                while(curr1 != nullptr){
                    int result = curr1->val + flag;
                    if(result >= 10){
                        flag = 1;
                        result -= 10;
                        ListNode *node = new ListNode(result);
                        curr3->next = node;
                        curr3 = curr3->next;
                    }else{
                        flag = 0;
                        curr1->val = curr1->val + 1;
                        curr3->next = curr1;
                        break;
                    }
                    curr1 = curr1->next;
                }
                if(curr1 == nullptr && flag == 1){
                    ListNode *node = new ListNode(1);
                    flag = 0;
                    curr3->next = node;
                    curr3 = curr3->next;
                }
            }
        }

        if(curr1 == nullptr && curr2 != nullptr){
            if(flag == 0){
                curr3->next = curr2;
            }else{
                while(curr2 != nullptr){
                    int result = curr2->val + flag;
                    if(result >= 10){
                        flag = 1;
                        result -= 10;
                        ListNode *node = new ListNode(result);
                        curr3->next = node;
                        curr3 = curr3->next;
                    }else{
                        flag = 0;
                        curr2->val = curr2->val + 1;
                        curr3->next = curr2;
                        break;
                    }
                    curr2 = curr2->next;
                }
                if(curr2 == nullptr && flag == 1){
                    ListNode *node = new ListNode(1);
                    flag = 0;
                    curr3->next = node;
                    curr3 = curr3->next;
                }
            }
        }

        if(curr1 == nullptr && curr2 == nullptr && flag == 1) {
            ListNode *node = new ListNode(1);
            flag = 0;
            curr3->next = node;
            curr3 = curr3->next;
        }
        return l3;
    }
};

// [2,4,3]
// [5,6,4]
// [9,9,9,9,9,9,9]
// [9,9,9,9]
int main(){
    vector<int> nums_1 = {9,9,1};
    vector<int> nums_2 = {1};

    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *l3 = nullptr;

    l1 = create_from_array(nums_1);
    l2 = create_from_array(nums_2);

    show_list(l1);
    show_list(l2);

    Solution s = Solution();
    l3 = s.addTwoNumbers(l1, l2);
    show_list(l3);
}