class Spot {
private:  
    
    int state;
    
public:
    
    Spot() : state(0) {}
    
    void setState(const int& state) {
        this->state = state;
    }
    
    int getState() {
        return state;
    }
    
};

class Player {
private:
    
    int playerId;
    
public:
    
    Player() : playerId(0) {}
    
    bool noId() {
        return playerId == 0;
    }
    
    int getId() const {
        return playerId;
    }
    
    void setId(const int& playerId) {
        this->playerId = playerId;
    }
    
};

class Move {
private:
    
    const Player& cur;
    int row;
    int col;
    
public:
    
    Move(const Player& cur, const int& row, const int& col) : cur(cur), row(row), col(col) {}
    
    int getPlayerState() const {
        return cur.getId();
    }
    
    int getRow() const {
        return row;
    }
    
    int getCol() const {
        return col;
    }
    
};

class Board {
private:
    
    int n;
    vector<vector<Spot>> grid;
    
public:
    
    Board(const int& n) : n(n), grid(vector<vector<Spot>>(n, vector<Spot>(n))) {}
    
    void move(const Move& m) {
        grid[m.getRow()][m.getCol()].setState(m.getPlayerState());
    }
    
    vector<vector<Spot>>& getBoard() {
        return grid;
    }
    
    // Testing purposes
    void printBoard() {
        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid.size(); ++j) {
                cout << grid[i][j].getState() << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
};

class TicTacToe {
private:
    
    Player p1;
    Player p2;
    Board board;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : board(n) {}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        if(p1.noId() && p2.getId() != player) {
            p1.setId(player);
        } else if(p2.noId() && p1.getId() != player) {
            p2.setId(player);
        }
        
        Player* ptr = nullptr;
        
        if(p1.getId() == player) {
            ptr = &p1;
        } else {
            ptr = &p2;
        }
        
        Move m(*ptr, row, col);
        board.move(m);
        return getGameStateAndValidate(m);
        
    }
    
private:
    
    int getGameStateAndValidate(const Move& m) {
        
        vector<vector<Spot>>& grid = board.getBoard();
        
        size_t i = 0;
        
        // Checking the same row
        
        for(i = 0; i < grid.size(); ++i) {
            if(grid[m.getRow()][i].getState() != m.getPlayerState()) {
                break;
            }
        }
        
        if(i == grid.size()) {
            return m.getPlayerState();
        }
        
        // Checking the same column
        
        for(i = 0; i < grid.size(); ++i) {
            if(grid[i][m.getCol()].getState() != m.getPlayerState()) {
                break;
            }
        }
        
        if(i == grid.size()) {
            return m.getPlayerState();
        }
        
        // Checking the left diagonal if necessary
        
        if(m.getCol() == m.getRow()) {
            
            for(i = 0; i < grid.size(); ++i) {
                if(grid[i][i].getState() != m.getPlayerState()) {
                    break;
                }
            }
        
            if(i == grid.size()) {
                return m.getPlayerState();
            }
        
        }
        
        // Checking right diagnol if necessary
        
        if(m.getCol() + m.getRow() == grid.size() - 1) {
            
            for(i = 0; i < grid.size(); ++i) {
                if(grid[i][grid.size() - i - 1].getState() != m.getPlayerState()) {
                    break;
                }
            }
            
            if(i == grid.size()) {
                return m.getPlayerState();
            }
            
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
