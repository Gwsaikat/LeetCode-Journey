class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int digitMul = 1;
            int temp = n;

            while (temp > 0) {
                digitMul *= (temp % 10);
                temp /= 10;
            }

            if (digitMul % t == 0) {
                return n;
            }

            n++;
        }
    }
};