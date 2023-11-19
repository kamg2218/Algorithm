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
    let answer = new ListNode(null);
    let dir = answer;
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            dir.next = list1;
            list1 = list1.next;
        } else {
            dir.next = list2;
            list2 = list2.next;
        }
        dir = dir.next;
    }
    dir.next = list1 || list2;
    
    return answer.next;
};