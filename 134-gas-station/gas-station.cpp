#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_tank = 0;
        int current_tank = 0;
        int start_station = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            int net = gas[i] - cost[i];
            total_tank += net;
            current_tank += net;
            
            if (current_tank < 0) {
                start_station = i + 1;
                current_tank = 0;
            }
        }
        
        return total_tank >= 0 ? start_station : -1;
    }
};