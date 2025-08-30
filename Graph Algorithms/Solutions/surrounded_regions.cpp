// You are given a matrix mat of size N x M where each cell contains either 'O' or 'X'.
// Your task is to replace all 'O' cells that are completely surrounded by 'X' with 'X'.

// Rules:
// An 'O' (or a group of connected 'O's) is considered surrounded if it is not connected to any border of the matrix.
// Two 'O' cells are considered connected if they are adjacent horizontally or vertically (not diagonally).
// A region of connected 'O's that touches the border (i.e., first row, last row, first column, or last column) is not surrounded and should not be changed.


class Solution{

private:
    void dfs(int r, int c, vector <vector <char>> &mat, vector <vector <bool>> &vis) {
        vis[r][c] = true;
        int n = mat.size();
        int m = mat[0].size();
        vector <int> drow = {-1, 0, 1, 0};
        vector <int> dcol = {0, -1, 0, 1};
        for (int dr=0; dr<4; dr++) {
            for (int dc=0; dc<4; dc++) {
                int rn = r + dr, cn = c + dc;
                if (rn >= 0 && rn < n && cn >= 0 && cn < m) {
                    if (mat[rn][cn] == 'O' && !vis[rn][cn]) {
                        dfs(rn, cn, mat, vis);
                    }
                }
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <bool>> vis(n, vector <bool> (m, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 'O' && !vis[i][j]) {
                    if (i == 0 || i == n-1 || || j == 0 || j == m-1) {
                        dfs(i, j, mat, vis);
                    }
                }
            }
        }  
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (if (mat[i][j] == 'O' && !vis[i][j])) 
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};
