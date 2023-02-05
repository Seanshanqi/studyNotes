#include "List.h"
#include <cstddef>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // ����cur����һ���ڵ�
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur) {
            temp = cur->next;  // ����һ�� cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
            cur->next = pre; // ��ת����
            // ����pre �� curָ��
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};