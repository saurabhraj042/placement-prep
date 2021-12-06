// https://leetcode.com/problems/robot-return-to-origin/
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> pos(2, 0);
        
        for(char c : moves){
            if(c == 'L'){
                pos[1]++;
            } else if(c == 'R'){
                pos[1]--;
            } else if(c == 'U'){
                pos[0]--;
            } else if(c == 'D'){
                pos[0]++;
            }
        }
        
        if(pos[1] == 0 && pos[0] == 0 ){
            return true;
        }
        
        return false;
    }
};