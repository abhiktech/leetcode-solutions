class Solution {
public:
    
    bool possibleDivide(const int& index, vector<vector<int>>& graph, vector<int>& colors) {
        
        // Mark the current vertex with a color
        
        colors[index] = 1;
        
        queue<int> levels;
        levels.push(index);
        
        while(!levels.empty()) {
            
            int cur_index = levels.front();
            levels.pop();
            
            for(int j = 0; j < graph[cur_index].size(); ++j) {
                
                // If the vertex hasn't been visited yet
                
                if(colors[graph[cur_index][j]] == 0) {
                    
                    // Mark it with the opposite color
                    
                    colors[graph[cur_index][j]] = (colors[cur_index] == 1) ? 2 : 1;
                    levels.push(graph[cur_index][j]);
                    
                } else if(colors[cur_index] == colors[graph[cur_index][j]]) {
                    
                    // Colors of two adjacent vertices are the same
                    
                    return false;
                } 
                
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        if(graph.size() == 1) {
            return true;
        }
        
        // 0 if a vertex is unvisited, 1 to mark it blue, 2 to mark it red
        
        vector<int> colors(graph.size());
        
        for(int i = 0; i < colors.size(); ++i) {
            
            if(colors[i] == 0) {
                
                if(!possibleDivide(i, graph, colors)){
                    return false;
                }
            }
        }
        
        return true;
    }
};