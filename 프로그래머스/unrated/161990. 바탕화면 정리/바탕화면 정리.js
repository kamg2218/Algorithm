function solution(wallpaper) {
    const row = wallpaper.length;
    const col = wallpaper[0].length;
    const answer = [row,col,0,0];
    
    const splitedWallpaper = wallpaper.map(paper => paper.split(''));
    
    splitedWallpaper.forEach((wallPaper, x) => {
        wallPaper.forEach((paper, y) => {
            if (paper === '#') {
                if (x < answer[0]) answer[0] = x;
                if (x + 1 > answer[2]) answer[2] = x + 1;
                if (y < answer[1]) answer[1] = y;
                if (y + 1 > answer[3]) answer[3] = y + 1;
            }
        })
    })
    return answer;
}