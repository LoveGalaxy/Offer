/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

// 每次都插入 vector 的头部，如果是链表那插入头部的效率会更高
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        while(head != NULL){
            int val = head->val;
            array.insert(array.begin(), val);
            head = head->next;
        }
        return array;
    }
};

// 如果是一个数组，插入头部效率低，那就每次插末尾，最后反转
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        while(head != NULL){
            int val = head->val;
            array.push_back(val);
            head = head->next;
        }
        reverse(array.begin(),array.end()); 
        return array;
    }
};

// 递归
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == NULL){
            vector<int> array;
            return array;
        }
        vector<int> array = printListFromTailToHead(head->next);
        array.insert(array.end(), head->val);
        return array;
    }
};

// 用栈 
// stack.pop 删除栈顶返回 void
// stack.top 返回栈顶
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> array;
        while(head != NULL){
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()){
            array.push_back(s.top());
            s.pop();
        }
        return array;
    }
};