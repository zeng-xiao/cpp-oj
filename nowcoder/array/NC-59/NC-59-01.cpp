class Solution {
public:
    int minPathSum(vector<vector<int> >& matrix) {
        if (matrix.size() == 1 && matrix[0].size() == 1) 
	    return matrix[0][0];

        vector<vector<int> > ans(matrix.size(), vector<int>(matrix[0].size(), 0)); 
        ans[0][0] = matrix[0][0];

	for(int i = 0; i < matrix.size(); i++){
	    for(int j = 0; j < matrix[0].size(); j++){
	        // down
		if(j+1 < matrix[0].size())
		    ans[i][j+1] = ans[i][j+1] ? min(ans[i][j] + matrix[i][j+1], ans[i][j+1]) : ans[i][j] + matrix[i][j+1];
		// right
		if (i+1 < matrix.size())
		    ans[i+1][j] = ans[i+1][j] ? min(ans[i][j] + matrix[i+1][j], ans[i+1][j]) : ans[i][j] + matrix[i+1][j];
	    }
	}
	return ans[matrix.size()-1][matrix[0].size()-1];
    }
};
