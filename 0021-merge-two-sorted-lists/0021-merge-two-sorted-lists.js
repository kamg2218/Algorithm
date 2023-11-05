/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let answer = null;
    let dir = null;
    let left = list1;
    let right = list2;
    
    while (list1 || list2) {
        let first = list1?.val !== undefined ? list1.val : Infinity;
        let second = list2?.val !== undefined ? list2.val : Infinity;
        let num = Math.min(first, second);
        const tmp = new ListNode(num);
        
        if (!answer) answer = tmp;
        else dir.next = tmp;

        dir = tmp;
        
        if (list1?.val === num) list1 = list1.next;
        else list2 = list2.next;
    }
    
    return answer;
};