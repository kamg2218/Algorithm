/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let answer = null;
    let last = answer;
    let extra = 0;
    
    while (l1 || l2) {
        let sum = (l1?.val || 0) + (l2?.val || 0) + extra;
        extra = 0;
        
        if (sum > 9) {
            extra = 1;
            sum -= 10;
        }
        
        const tmp = new ListNode(sum);
        if (!answer) answer = tmp;
        else last.next = tmp;
        
        last = tmp;
        
        if (l1) l1 = l1.next;
        if (l2) l2 = l2.next;
    }
    if (extra) {
        const tmp = new ListNode(extra);
        last.next = tmp;
    }
    return answer;
};