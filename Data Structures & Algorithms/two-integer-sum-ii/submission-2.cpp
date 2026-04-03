class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> out;

        while(i<j){
            int sum = numbers[i]+numbers[j]; 
            if(sum == target){
                out.push_back(i+1);out.push_back(j+1);
                return out;
            }
            if(sum>target){
                j--;
            }
            if(sum<target){
                i++;
            }
        }
        return out;
    }
};
