#include<iostream>
#include "ListNode.h"

using std::cout;
using std::endl;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * result = NULL;
    ListNode * temp = NULL;
    if(!list1) {
        result =  list2;
    }
    if(!list2) {
        result =  list1;
    }
    while (list1&&list2) {
        if(list1->val<=list2->val) {
            if(!result) {
                temp = list1;
                result = temp;
            } else {
                temp->next = list1;
                temp = temp->next;
            }
            list1 = list1->next;
        } else {
            if(!result) {
                temp = list2;
                result = temp;
            } else {
                temp->next = list2;
                temp = temp->next;
            }
            list2 = list2->next;
        }
    }
    if(list1) {
        temp->next = list1;
        temp = temp->next;
    }
    if(list2) {
        temp->next = list2;
        temp = temp->next;
    }
    return result;
}

int main() {
    //创建头指针
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    //创建首元节点
    ListNode* temp1 = (ListNode*)malloc(sizeof(ListNode));
    //首元节点先初始化
    temp1->val = 1;
    temp1->next = NULL;
    list1 = temp1;

    ListNode* a = (ListNode*)malloc(sizeof(ListNode));
    a->val = 2;
    a->next = NULL;
    temp1->next = a;
    temp1 = temp1->next;

    ListNode* b = (ListNode*)malloc(sizeof(ListNode));
    b->val = 4;
    b->next = NULL;
    temp1->next = b;
    temp1 = temp1->next;

    ListNode* temp2 = (ListNode*)malloc(sizeof(ListNode));
    //首元节点先初始化
    temp2->val = 1;
    temp2->next = NULL;
    list2 = temp2;

    ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
    a2->val = 3;
    a2->next = NULL;
    temp2->next = a2;
    temp2 = temp2->next;

    ListNode* b2 = (ListNode*)malloc(sizeof(ListNode));
    b2->val = 4;
    b2->next = NULL;
    temp2->next = b2;
    temp2 = temp2->next;

    ListNode* result = mergeTwoLists(list1,list2);
    while(result) {
        cout<<result->val<<" ,";
        result = result->next;
    }
}