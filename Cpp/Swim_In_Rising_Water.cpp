Approach

Binary Search on Time (t)

The smallest possible time is 0, and the largest possible is n*n - 1 (since the grid contains unique values from 0 to n²−1).

For each mid-value (possible time) in the binary search, we check if we can reach the destination using only cells whose height ≤ mid.

DFS to Check Reachability

Start from (0, 0) if grid[0][0] ≤ mid.

Use recursion to traverse neighbors (up, down, left, right).

Only move to a cell if it hasn’t been visited and its height ≤ mid.

If we reach (n-1, n-1), then the path is possible for this mid (i.e., possibleToReach() returns true).

Binary Search Update Rules

If a path is possible for mid, try smaller values (high = mid - 1).

Otherwise, move to larger times (low = mid + 1).

Continue until binary search completes — ans will hold the minimum required time.

Here I have used Binary Search and DFS Traversal To traverse the matrix from coordinates - (0,0) to (n-1,n-1)  top left to bottom right

T.C - O(n^2 log(n^2))
S.C - O(n^2)

class Solution {
public:
    bool possibleToReach(vector<vector<int>>& grid, int row, int col, int t, vector<vector<bool>>& visited, vector<int>& delRow, vector<int>& delCol){
        int n = grid.size();

        if(row < 0 || row >= n || col < 0 || col >= n || visited[row][col] == true || grid[row][col] > t){
            return false;
        }

        visited[row][col] = true;

        if(row == n - 1 && col == n -1){
            return true;
        }

        for(int i=0;i<4;i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(possibleToReach(grid, newRow, newCol, t, visited, delRow, delCol)){
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int low = grid[0][0];
        int high = n*n - 1;

        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};

        int result = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            vector<vector<bool>> visited(n , vector<bool>(n, false));

            if(possibleToReach(grid, 0, 0, mid, visited, delRow, delCol)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return result;
    }
};
