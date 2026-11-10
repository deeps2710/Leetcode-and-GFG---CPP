class Solution {
public:
    long double power(long double x, long long n) {
        if (n == 0) {
            return 1.0L;
        }

        long double half = power(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        }

        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        long double base = x;

        if (N < 0) {
            base = 1.0L / base;
            N = -N;
        }

        return (double)power(base, N);
    }
};
