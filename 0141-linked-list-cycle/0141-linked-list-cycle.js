/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let last = new Map();
    
    while (head) {
        if (last.has(head)) return true;
        last.set(head, head);
        head = head.next;
    }
    return false;
};