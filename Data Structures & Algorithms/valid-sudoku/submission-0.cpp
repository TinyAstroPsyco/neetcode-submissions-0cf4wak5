class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool boxes[9][9] = {false};
        
        // Now lets traverse thorugh the sudoku row by row
        for(int i = 0; i<9; i++){ // i is rowns
            for(int j = 0; j<9; j++){// j is for columns
                if(board[i][j] == '.') continue;

                int value = board[i][j] - '0';
                // First we check if the corresponding row or column already has the value
                if(rows[i][value-1] == 1) return false;
                else rows[i][value-1] = 1;

                
                if(columns[j][value-1] == 1) return false;
                else columns[j][value-1] = 1; 
                
                // Second we check if the specific box has the value.
                int box_id = (i/3)*3 + j/3;
                if(boxes[box_id][value-1] == 1) return false;
                else boxes[box_id][value-1] = 1;
            } 
         }
        return true;

    }
};
