class Solution {
public:
    
    
    class Graph {
     private:
        
        int numRooms;
        int numVisited;
        vector<vector<int>>& connections;
        vector<bool> visited;
        
    public:
        
        Graph(int numRooms, vector<vector<int>>& connections) : numRooms(numRooms), numVisited(0), connections(connections), visited(vector<bool>(numRooms)) {}
        
        bool isConnected() {
            visitRooms(0);
            return numRooms == numVisited;
        }
        
    private:
        
        void visitRooms(int room) {
            
            if(visited[room]) {
                return;
            }
            
            visited[room] = true;
            ++numVisited;
            
            for(size_t i = 0; i < connections[room].size(); ++i) {
                visitRooms(connections[room][i]);
            }
            
        }
        
    };
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        Graph graph(rooms.size(), rooms);
        
        return graph.isConnected();
        
    }
};