var findNumUniquePaths = function(grid, row, col) {
    
    if(grid[row][col] == -1) {
        findNumUniquePaths(grid, row + 1, col);
        findNumUniquePaths(grid, row, col + 1);
        grid[row][col] = grid[row + 1][col] + grid[row][col + 1];
    }
    
};

var initialize = function(grid, m, n) {
    
    for(let i = 0; i <= m; ++i) {
        for(let j = 0; j <= n; ++j) {
            if(i == m || j == n) {
                grid[i][j] = 0;
            } else {
                grid[i][j] = -1;
            }
        }
    }
    
    grid[m - 1][n - 1] = 1;
}

var uniquePaths = function(m, n) {
    
    let grid = new Array(m + 1);
    for(let i = 0; i <= m; ++i) {
        grid[i] = new Array(n + 1);
    }
    
    initialize(grid, m, n);
    findNumUniquePaths(grid, 0, 0);
    
    return grid[0][0];
};