class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lr=0;
        int lc=0;
        int rr=matrix.size()-1;
        int rc=matrix[0].size()-1;
        int mr=(lr+rr)/2;
        int mc=(lc+rc)/2;

        while(lr<=rr && lc<=rc){
            if(matrix[mr][mc]==target){
                return true;
            }else if(matrix[mr][mc]<target){
                if(mc==matrix[0].size()-1){
                    lr++;
                    lc=0;
                }else{
                    lc++;
                }
            }else{
                if(mc==0){
                    rr--;
                    rc=matrix[0].size()-1;
                }else{
                    rc--;
                }
            }           
            mr=(lr+rr)/2;
            mc=(lc+rc)/2;
        }
        return false;
        
    }
};
