
var MinStack = function() {
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    return this._stack ? this._stack.push(val) : this._stack = [val];
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    return this._stack ? this._stack.pop() : -1;
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this._stack ? this._stack.at(-1) : -1;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    if (!this._stack) return -Infinity;
    let min = this._stack[0]
    for (let i = 1; i < this._stack.length; i++) {
        if (this._stack[i] < min) min = this._stack[i];
    }
    return min;
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */