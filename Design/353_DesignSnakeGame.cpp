class SnakeGame {

private:
    
    int height;
    int width;
    vector<vector<int>> food;
    int score;
    deque<pair<int, int>> dq;
    unordered_map<int, unordered_set<int>> umap;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) : height(height), width(width), food(food), score(0) {
        dq.push_front(make_pair(0, 0));
        umap[0].insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        
        pair<int, int> newHead = getMovePosition(direction);
        
        if(validMove(newHead)) {
            makeMove(newHead);
            return score;
        }
        
        return -1;
    }
    
    
private:
    
    pair<int, int> getMovePosition(const string& direction) {
        
        int row = dq.front().first, col = dq.front().second;
        
        if(direction == "U") {
            --row;
        } else if(direction == "D") {
            ++row;
        } else if(direction == "L") {
            --col;
        } else {
            ++col;
        }
        
        return make_pair(row, col);
    }
    
    bool validMove(pair<int, int>& newHead) {
        
        if(newHead.first < 0 || newHead.first >= height
           || newHead.second < 0 || newHead.second >= width) {
            return false;
        }
        
        if(newHead != dq.back() && umap.find(newHead.first) != umap.end() 
            && umap[newHead.first].find(newHead.second) != umap[newHead.first].end()) {
            return false;
        }
        
        return true;
        
    }
    
    void makeMove(pair<int, int>& newHead) {
        if(score < food.size() && (newHead.first == food[score][0] && newHead.second == food[score][1])) {
            ++score;
            
        } else {
            umap[dq.back().first].erase(dq.back().second);
            dq.pop_back();
        }
        
        dq.push_front(newHead);
        umap[newHead.first].insert(newHead.second);
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
