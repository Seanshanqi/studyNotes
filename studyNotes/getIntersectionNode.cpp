
#include "List.h"
#include <cstddef>
#include <iostream>
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // ������A�ĳ���
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // ������B�ĳ���
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // ��curAΪ������ͷ��lenAΪ�䳤��
        if (lenB > lenA) {
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }
        // �󳤶Ȳ�
        int gap = lenA - lenB;
        // ��curA��curB��ͬһ����ϣ�ĩβλ�ö��룩
        while (gap--) {
            curA = curA->next;
        }
        // ����curA �� curB��������ͬ��ֱ�ӷ���
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};