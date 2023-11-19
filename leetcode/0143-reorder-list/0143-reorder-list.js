/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    let reverse = null;
    let cnt = 0;
    
    let tmp = head;
    while (tmp) {
        cnt++;
        if (!reverse) {
            reverse = new ListNode(tmp.val);
        } else {
            const newNode = new ListNode(tmp.val);
            newNode.next = reverse;
            reverse = newNode;
        }
        tmp = tmp.next;
    }
    
    tmp = head;
    while (cnt > 1) {
        cnt -= 2;
        const mid = tmp.next;
        tmp.next = reverse;
        reverse = reverse.next;
        tmp = tmp.next;
        if (cnt > 1) {
            tmp.next = mid;
            tmp = mid;
        } else if (cnt) {
            tmp = tmp.next;
            tmp.next = null;
        } else {
            tmp.next = null;
        }
    }
};