class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //#3
        int row = matrix.size(), col = matrix[0].size();
        if(row==0 || col==0) return 0;
        //1D formate 
        int s=0,e=row*col - 1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int r = mid/col; // formula to find current row index
            int c = mid%col; // formula to find current col index 
            if(matrix[r][c]==target){
                return 1;
            }
            else if(matrix[r][c]<target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return 0;
    }
};