class Solution {
public:
    
    class Graph {
    
    private:
        
        unordered_map<string, unordered_set<string>> aList;
        
        unordered_map<string, bool> visited;
        
        int num_groups;
        
    public:
        
        Graph() : num_groups(0) {}
        
        void insertEdge(const string& s1, const string& s2) {
            
            if(edgeExists(s1, s2)) {
                return;
            }
            
            aList[s1].insert(s2);
            
            visited[s1] = false;
            visited[s2] = false;
        }
        
        int findNumberOfGroups(const int& num_unique) {
            
            num_groups += (num_unique - visited.size());
            
            for(const auto& vertex : aList) {
                
                if(!visited[vertex.first]) {
                    
                    ++num_groups;
                    
                    groupSimilarStrings(vertex.first);
                }
                
            }
            
            return num_groups;
        }
        
    private:
        
        bool edgeExists(const string& s1, const string& s2) {
            
            return (aList.find(s1) != aList.end()
                    && aList[s1].find(s2) != aList[s1].end());
        }
        
        void groupSimilarStrings(const string& cur_vertex) {
            
            visited[cur_vertex] = true;
            
            for(const auto& connected_vertex : aList[cur_vertex]) {
                
                if(!visited[connected_vertex]) {
                    groupSimilarStrings(connected_vertex);
                }
                
            }
            
        }
        
    };
    
    
    int findNumUniqueWords(vector<string>& strs) {
        
        unordered_set<string> unique_words;
        
        for(int i = 0; i < strs.size(); ++i) {
            unique_words.insert(strs[i]);
        }
        
        return unique_words.size();
    }
    
    bool areSimilar(const string& s1, const string& s2) {
        
        int diff = 0;
        
        for(int i = 0; i < s1.length(); ++i) {
            
            if(s1[i] != s2[i]) {
                ++diff;
            }
            
            if(diff > 2) {
                return false;
            }
        }
        
        return diff == 2;
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        
        // Dealing with the edge case
        
        if(strs.size() <= 1) {
            return strs.size();
        }
        
        Graph obj;
        
        int num_unique = findNumUniqueWords(strs);
        
        for(int i = 0; i < strs.size(); ++i) {
            
            for(int j = i + 1; j < strs.size(); ++j) {
                
                if(areSimilar(strs[i], strs[j])) {
                    
                    // Inserting the connection to the graph
                    
                    obj.insertEdge(strs[i], strs[j]);
                    obj.insertEdge(strs[j], strs[i]);
                }
            }
        }
        
        return obj.findNumberOfGroups(num_unique);
    }
};