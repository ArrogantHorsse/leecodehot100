#include <iostream>
#include <unordered_map>

#include "ListNode.h"
using std::cout;
using std::endl;
using std::unordered_map;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == nullptr && n == 1) {
        return nullptr;
    }
    unordered_map<int, ListNode*> nodeMap;
    int i = 1;
    ListNode* headBackup = head;
    while (head) {
        nodeMap[i] = head;
        if (head->next) {
            head = head->next;
            i++;
        } else {
            break;
        }
    }
    int deleteNum = i + 1 - n;
    if (deleteNum == 1) {
        headBackup = (ListNode*)nodeMap[2];
        return headBackup;
    }
    ListNode* deleteNodePre = (ListNode*)nodeMap[i - n];
    ListNode* deleteNode = (ListNode*)nodeMap[i + 1 - n];
    deleteNodePre->next = deleteNode->next;

    return headBackup;
}

int main() {
    //创建头指针
    ListNode* p = NULL;
    //创建首元节点
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    //首元节点先初始化
    temp->val = 1;
    temp->next = NULL;
    //头指针指向首元节点
    p = temp;
    // 从第二个节点开始创建
    for (int i = 2; i < 3; i++) {
        //创建一个新节点并初始化
        ListNode* a = (ListNode*)malloc(sizeof(ListNode));
        a->val = i;
        a->next = NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp = temp->next;
    }
    ListNode* resultNode = removeNthFromEnd(p, 1);
    return 0;
}