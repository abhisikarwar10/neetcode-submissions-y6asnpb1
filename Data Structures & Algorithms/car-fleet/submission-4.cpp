class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> ps;
        for(int i =0;i<position.size();i++){
            ps[position[i]] = (double)(((double)(target-position[i]))/speed[i]);
        }
        stack<double> s;
        s.push(ps.rbegin()->second);
        if (!ps.empty()){
            for (auto it = next(ps.rbegin()); it != ps.rend(); ++it) {
                if( s.top()<it->second){
                    s.push(it->second);
                }               
            }
        }
        return s.size();
    }
};
