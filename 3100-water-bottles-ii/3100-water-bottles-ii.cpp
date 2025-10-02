class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
    int emptyBottles = numBottles;
    int res = numBottles;
    while (emptyBottles >= numExchange) {
        res += 1;
        emptyBottles = emptyBottles-numExchange + 1;
        numExchange += 1;
    }
    return res;
}
};