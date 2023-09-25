/*
 * 给定一个链表，两两交换其中相邻的节点
 * 并返回交换后链表的头节点
 * 必须在不朽该节点内部的值的情况下完成
 * 
 * input: head = [1, 2, 3, 4, 5]
 * output:  [2, 1, 4, 3, 5]
 * 
 * (链表中节点数目范围[0, 100]， 0 <= Node.val <= 100)
 * 
 * 
 * 
 * 使用迭代方式，创建一个虚拟节点dummy，令dummy.next = head，
 * 令p表示当前节点，初始化时p = dummy.next（即链表头）
 * 变换如下：
 * >>>  dummy ---> node1 ---> node2  <<<
 * >>>  dummy ---> node2 ---> node1  <<<
 * 完成之后再令 dummy 等于node1
 * 以此类推
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    // 创建虚拟节点dummy
    struct ListNode dummy;
    // dummy --> head --> (head->next)
    // *prev     *p       *q
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *p = dummy.next;

    while (p != NULL && p->next != NULL) {
        struct ListNode *q = p->next;
        p->next = q->next;
        q->next = p;
        prev->next = q;
        prev = p;
        p = p->next;
    }
    return dummy.next;
}

int main(int argc, char **argv)
{
    struct ListNode *p, *prev, dummy, *list;

    dummy.next = NULL;
    prev = &dummy;

    for (int i = 1; i < argc; i++) {
        p = malloc(sizeof(*p));
        int n = atoi(argv[i]);
        printf("%d ", n);
        p->val = n;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    putchar('\n');

    list = swapPairs(dummy.next);
    for (p = list; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    return 0;
}
