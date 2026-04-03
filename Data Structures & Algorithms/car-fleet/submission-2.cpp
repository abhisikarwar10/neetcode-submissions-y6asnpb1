class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> ps;
        for(int i =0;i<position.size();i++){
            ps[position[i]] = (double)(((double)(target-position[i]))/speed[i]);
        }
        // [0,1,4,7]
        // [10,4.5,3,3]
        stack<double> s;
        s.push(ps.rbegin()->second);
        if (!ps.empty()){
            for (auto it = next(ps.rbegin()); it != ps.rend(); ++it) {
                while( s.top()<it->second){
                    s.push(it->second);
                }               
            }
        }
        return s.size();
    }
};
