function check(skill, tree) {
    let check = "";
    for (let i = 0; i < tree.length; i++) {
        var idx = skill.search(tree[i]);
        if (idx === -1) {
            continue ;
        } else if (idx === check.length) {
            check += '1';
            if (check.length === skill.length) {
                return true;
            }
        } else {
            return false;
        }
    }
    return true;
}

function solution(skill, skill_trees) {
    var answer = 0;
    
    skill_trees.forEach(tree => {
        if (check(skill, tree)) {
            answer += 1;
        }
    });
    return answer;
}