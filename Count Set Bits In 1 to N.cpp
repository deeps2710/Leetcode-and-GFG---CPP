class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) {
            return 0;
        }

        int power = 1;
        int x = 0;

        // Find the largest power of 2 <= n
        while ((long long)power * 2 <= n) {
            power = power * 2;
            x++;
        }

        // Set bits from 1 to power - 1
        int bitsBeforePower = x * (power / 2);

        // Every number from power to n has its first bit set
        int firstBits = n - power + 1;

        // Remove that first bit and solve the remaining part
        int remaining = n - power;

        return bitsBeforePower
             + firstBits
             + countSetBits(remaining);
    }
};
