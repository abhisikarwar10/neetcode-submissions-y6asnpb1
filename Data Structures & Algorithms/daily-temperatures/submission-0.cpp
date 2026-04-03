class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        s.push(0);
        vector<int> out(temperatures.size(), 0);
        for(int i=1;i<temperatures.size();i++){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                int t = s.top();
                s.pop();
                out[t] = i-t;
            }
            s.push(i);
        }
        while(!s.empty()) {
            out[s.top()] = 0;
            s.pop();
        }
        return out;
        
    }
};
