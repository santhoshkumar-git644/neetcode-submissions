class Solution {
public:
    long long minEnd(int n, int x) {
        n--;

        long long ans = x;
        int j = 0;

        for (int i = 0; i < 63; i++) {
            if (((ans >> i) & 1LL) == 0) {
                ans |= (1LL * ((n >> j) & 1) << i);
                j++;
                if ((n >> j) == 0) break;
            }
        }

        return ans;
    }
};