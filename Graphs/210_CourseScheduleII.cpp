class Graph {
    
private:
    
    vector<vector<int>> courses;
    vector<int> numPrereqs;
    vector<int> courseOrdering;
    
public:
    
    Graph(int numCourses) : courses(vector<vector<int>>(numCourses)),
    numPrereqs(vector<int>(numCourses, 0)) {}
    
    void insertPrereq(int before, int after) {
        courses[before].push_back(after);
        ++numPrereqs[after];
    }
    
    void findCourseOrdering() {
        
        queue<int> curCourses;
        
        for(size_t i = 0; i < numPrereqs.size(); ++i) {
            
            if(numPrereqs[i] == 0) {
                curCourses.push(i);
            }
            
        }
        
        while(!curCourses.empty()) {
            
            for(size_t i = 0; i < courses[curCourses.front()].size(); ++i) {
                
                --numPrereqs[courses[curCourses.front()][i]];
                
                if(numPrereqs[courses[curCourses.front()][i]] == 0) {
                    curCourses.push(courses[curCourses.front()][i]);
                }
                
            }
            
            courseOrdering.push_back(curCourses.front());
            curCourses.pop();
        }
        
    }
    
    vector<int> getOrdering() {
        
        if(courseOrdering.size() == courses.size()) {
            return courseOrdering;
        }
        
        return {};
    }
    
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        Graph g(numCourses);
        
        for(size_t i = 0; i < prerequisites.size(); ++i) {
            g.insertPrereq(prerequisites[i][1], prerequisites[i][0]);
        }
        
        g.findCourseOrdering();
        
        return g.getOrdering();
    }
};
