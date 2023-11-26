/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    let answer = null;
    let last = null;
    
    const list = new Map();
    const newList = [];
    
    let origin = head;
    let idx = 0;
    while (origin) {
        const tmp = new Node(origin.val);
        
        if (!answer) answer = tmp;
        else last.next = tmp;
        last = tmp;
        
        list.set(origin, idx++);
        newList.push(tmp);
        
        origin = origin.next;
    }
    
    origin = head;
    last = answer;
    while (origin) {
        if (list.has(origin.random)) {
            last.random = newList[list.get(origin.random)];            
        } else {
            last.random = null;
        }
        last = last.next;
        origin = origin.next;
    }
    
    return answer;
};