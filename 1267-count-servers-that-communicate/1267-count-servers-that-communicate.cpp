class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0 ;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        vector<int>rowCount(rowSize, 0);
        vector<int>colCount(colSize, 0);

        for ( int row = 0 ; row < rowSize ; ++row ){
            for ( int col = 0 ; col < colSize ; ++col ){
                if ( grid[row][col] == 1 ){
                    rowCount[row]++ ;
                }
            }
        }

        for ( int row = 0 ; row < rowSize ; ++row ){
            for ( int col = 0 ; col < colSize ; ++col ){
                if ( grid[row][col] == 1 ){
                    colCount[col]++ ;
                }
            }
        }

        for ( int row = 0 ; row < rowSize ; ++row ){
            for ( int col = 0 ; col < colSize ; ++col ){
                if (grid[row][col] == 1 && (rowCount[row] > 1 || colCount[col] > 1)){
                    result ++ ;
                }
            }
        }

        return result;
    }
};