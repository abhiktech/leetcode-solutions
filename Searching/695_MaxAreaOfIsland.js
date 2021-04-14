var findIslandArea = function(grid, row, col) {
    
    if(row < 0 || col < 0 || row >= grid.length || col >= grid[row].length || grid[row][col] == 0) return 0; 
    grid[row][col] = 0;
    return findIslandArea(grid, row + 1, col) + findIslandArea(grid, row, col + 1) +
        findIslandArea(grid, row - 1, col) + findIslandArea(grid, row, col - 1) + 1;
    
}

var maxAreaOfIsland = function(grid) {
    
    let maxArea = 0;
    
    for(let i = 0; i < grid.length; ++i) {
        
        for(let j = 0; j < grid[i].length; ++j) {
            
            if(grid[i][j] == 1) {
                let curArea = findIslandArea(grid, i, j);
                if(curArea > maxArea) maxArea = curArea;
            }
            
        }
        
    }
    
    return maxArea;
};