class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int a=accumulate(gas.begin(),gas.end(),0);
        int b=accumulate(cost.begin(),cost.end(),0);
          int c=0,d=0;
        if(a<b){
            return -1;
        }else{
          
            for(int i=0;i<gas.size();i++){
             c+=gas[i]-cost[i];
             if(c<0){
                c=0;
                d=i+1;
             }
            }
        }
        return d;
    }
};