//�������������еĽڵ�
#include "List.h"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // ����һ������ͷ���
        dummyHead->next = head; // ������ͷ���ָ��head���������������ɾ������
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // ��¼��ʱ�ڵ�
            ListNode* tmp1 = cur->next->next->next; // ��¼��ʱ�ڵ�

            cur->next = cur->next->next;    // ����һ
            cur->next->next = tmp;          // �����
            cur->next->next->next = tmp1;   // ������

            cur = cur->next->next; // cur�ƶ���λ��׼����һ�ֽ���
        }
        return dummyHead->next;
    }
};