#include <iostream>
using namespace std;
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) { } 
    };
    // MyLinkedList的构造函数K
    MyLinkedList() {
        // 初始化成员变量
        prev = new ListNode(0); //虚拟头结点
        size = 0; // size0是虚拟头结点 size=1 是头结点,表示节点的数量
    }
    // 返回第index个节点的值 index=0 的时候是头结点索引，size-1 = index;
    int get(int index) {
        if ( index +1 > size || index<0) return -1;
        ListNode* cur = prev -> next; // 头结点
        while (index --) {
            cur = cur -> next;
        }
        return  cur -> val;
    }
    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        ListNode* head = new ListNode(val);
        head -> next = prev ->next;
        prev -> next = head;
        size ++;
    }
    // 将值为 val 的节点追加到链表的最后一个元素。
    void addAtTail(int val) {
        ListNode* cur = prev;
        ListNode* atTail = new ListNode(val);
        while (cur -> next != nullptr) {
           cur = cur ->next;
        }
        cur -> next = atTail;
        size++;
    }
    //addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。
    //如果 index 等于链表的长度，则该节点将附加到链表的末尾。
    //如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    void addAtIndex(int index, int val) {
        ListNode* atindex = new ListNode(val);
        if (index == size) { //index等于链表长度
            addAtTail(val);
        }
        else if (index < 0) {
            addAtHead(val);
        }
        else if (index  > size) {}
        else {
            ListNode* cur = prev;
            //index --;
            while (index --)
            {
                cur = cur ->next;
            }
            atindex -> next = cur ->next;
            cur -> next = atindex;
            size ++;
        }
    }
    //deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {}
        else {
            ListNode* cur = prev;
            //index --;
            while (index --) {
                cur = cur -> next;
            }
            ListNode* tmp = cur ->next;
            cur -> next = cur ->next ->next;
            delete tmp;
            size --;
        }
    }
    void printListNode() {
        ListNode* cur = prev;
        while (cur -> next != nullptr) {
            std::cout << cur ->next ->val << " " ;
            cur = cur -> next;
        }
        std::cout<<endl;
    }
    private:
        int size;
        ListNode* prev;
};
int main () {
    // 使用示例
    MyLinkedList List;
    List.addAtHead(5);
    List.addAtTail(3);
    List.printListNode();
    // 使用类指针的方式,注意初始化问题。
    MyLinkedList List1;
    MyLinkedList* List2 = &List1;
    List2 -> addAtHead(6);
    List2 -> addAtIndex(1,5);
    List2 -> printListNode();
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */