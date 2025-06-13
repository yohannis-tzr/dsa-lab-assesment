class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size(), cols = board[0].size();
        int clickRow = click[0], clickCol = click[1];

        // Using lambda function to perform Depth-First Search (DFS)
        function<void(int, int)> dfs = [&](int row, int col) {
            int mineCount = 0;

            // Count mines in adjacent cells
            for (int x = row - 1; x <= row + 1; ++x) {
                for (int y = col - 1; y <= col + 1; ++y) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] == 'M') {
                        ++mineCount;
                    }
                }
            }

            // If mines exist around the cell, update the cell with the mine count. Otherwise, mark the cell as 'B' and continue DFS.
            if (mineCount > 0) {
                board[row][col] = mineCount + '0';
            } else {
                board[row][col] = 'B';
                for (int x = row - 1; x <= row + 1; ++x) {
                    for (int y = col - 1; y <= col + 1; ++y) {
                        if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] == 'E') {
                            dfs(x, y);
                        }
                    }
                }
            }
        };

        // Handle the initial click
        if (board[clickRow][clickCol] == 'M') {
            // If the clicked cell contains a mine, game over
            board[clickRow][clickCol] = 'X';
        } else {
            // If the clicked cell is empty ('E'), perform DFS to reveal cells
            dfs(clickRow, clickCol);
        }

        return board;
    }
};