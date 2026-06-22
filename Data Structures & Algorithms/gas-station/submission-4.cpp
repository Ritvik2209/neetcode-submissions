class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int end = n - 1, start = 0;
        int tank = gas[end] - cost[end];
        while (end > start) {
            if (tank < 0) {
                end--;
                tank += gas[end] - cost[end];
            } else {
                tank += gas[start] - cost[start];
                start++;
            }
        }
        return tank >= 0 ? end : -1;
    }
};