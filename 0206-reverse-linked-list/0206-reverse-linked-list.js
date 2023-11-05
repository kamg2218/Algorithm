/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let answer = null;
    let tmp = null;
    
    while (head) {
        if (answer) {
            tmp = new ListNode(head.val);
            tmp.next = answer;
            answer = tmp;
        } else {
            answer = new ListNode(head.val);
            tmp = answer;
        }
        head = head.next;
    }
    return answer;
};