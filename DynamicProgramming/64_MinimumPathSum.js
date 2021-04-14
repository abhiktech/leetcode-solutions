var findMinPathSum = function(grid, visited, curRow, curCol, numRows, numCols) {
    
    if(curRow == numRows || curCol == numCols || visited[curRow][curCol]) return;
    
    findMinPathSum(grid, visited, curRow + 1, curCol, numRows, numCols);
    findMinPathSum(grid, visited, curRow, curCol + 1, numRows, numCols);
    
    if(curRow == numRows - 1) grid[curRow][curCol] += grid[curRow][curCol + 1];
    else if(curCol == numCols - 1) grid[curRow][curCol] += grid[curRow + 1][curCol];
    else grid[curRow][curCol] += Math.min(grid[curRow + 1][curCol], grid[curRow][curCol + 1]);
    visited[curRow][curCol] = true;

}

var minPathSum = function(grid) {
    
    let visited = new Array(grid.length);
    
    for(let i = 0; i < visited.length; ++i) {
        visited[i] = new Array(grid[i].length).fill(false);
    }
    
    visited[grid.length - 1][grid[0].length - 1] = true;
    findMinPathSum(grid, visited, 0, 0, grid.length, grid[0].length);
    
    return grid[0][0];
};