/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let tmp = null;
    let cnt = 0;
    
    let answer = head;
    while (answer) {
        answer = answer.next;
        cnt++;
    }
    
    if (cnt - n === 0) return head.next;
    
    answer = head;
    for (let i = 0; i < cnt - n; i++) {
        tmp = head;
        head = head.next;
    }
    tmp.next = head.next;
    
    return answer;
};