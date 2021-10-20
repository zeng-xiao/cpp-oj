class Solution {
public:
    int solve(vector<vector<char> >& grid) {
        unsigned int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
	 	    ans++;
	 	    grid[i][j] = '0';
		    recursion(grid, i, j);
	        }
	    }
        }
        return ans;
    }

    void recursion(vector<vector<char> >& grid, int i, int j){
	// up
        if (i-1 >= 0 && grid[i-1][j] == '1'){
	    grid[i-1][j] = '0';
            recursion(grid, i-1, j);
	}	
	// down
        if (i+1 < grid.size() && grid[i+1][j] == '1'){
            grid[i+1][j] = '0';
            recursion(grid, i+1, j);
        }	
	// left
	if (j-1 >= 0 && grid[i][j-1] == '1'){
            grid[i][j-1] = '0';
            recursion(grid, i, j-1);
        }
	// right
	if (j+1 < grid[0].size() && grid[i][j+1] == '1'){
            grid[i][j+1] = '0';
            recursion(grid, i, j+1);
        }
    }
};
