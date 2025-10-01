class Solution {
public:
int numWaterBottles(int numBottles, int numExchange) {
    int emptyBottles = numBottles;
    int res = numBottles;
    while (emptyBottles >= numExchange) {
        int news = emptyBottles/numExchange;
        res += news;
        emptyBottles = emptyBottles%numExchange + news;
    }
    return res;
}
};