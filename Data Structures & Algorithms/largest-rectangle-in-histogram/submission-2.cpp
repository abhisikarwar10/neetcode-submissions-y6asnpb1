class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxA = 0;int h=0;int w=0;
        s.push(0);
        for(int i=1;i<=heights.size();i++){
            while(!s.empty() && (i == heights.size() || heights[s.top()] >= heights[i])){
                h = heights[s.top()];
                s.pop();
                w = s.empty()?i:i-s.top()-1;
                maxA = max(maxA,h*w);
            }
            s.push(i);
        }
        return maxA;
        
    }
};
