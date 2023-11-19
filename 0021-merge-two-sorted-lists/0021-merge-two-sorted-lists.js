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
    
    while (list1 && list2) {
        const tmp = new ListNode();
        
        if (list1.val <= list2.val) {
            tmp.val = list1.val;
            list1 = list1.next;
        } else {
            tmp.val = list2.val;
            list2 = list2.next;
        }
        
        if (!answer) answer = tmp;
        else dir.next = tmp;
        dir = tmp;        
    }
    if (!dir) return list1 ? list1 : list2;
    if (list1) dir.next = list1;
    if (list2) dir.next = list2;
    
    return answer;
};