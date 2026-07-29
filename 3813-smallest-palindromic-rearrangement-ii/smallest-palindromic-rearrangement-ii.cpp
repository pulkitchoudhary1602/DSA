class Solution {
public:
    long long permCount(array<int,26>& counts, int length, long long cap) {
        long long result = 1;
        int remaining = length;
        for (int c = 0; c < 26; c++) {
            int cnt = counts[c];
            if (cnt == 0) continue;
            int base = remaining - cnt;
            for (int i = 1; i <= cnt; i++) {
                result = result * (base + i) / i;
                if (result > cap) return cap + 1;
            }
            remaining -= cnt;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        long long K = k;
        int n = s.size();
        array<int,26> fullCount{};
        for (char ch : s) fullCount[ch - 'a']++;

        char midChar = 0;
        array<int,26> half{};
        for (int c = 0; c < 26; c++) {
            if (fullCount[c] % 2 == 1) midChar = 'a' + c;
            half[c] = fullCount[c] / 2;
        }

        int halfLen = n / 2;

        long long total = permCount(half, halfLen, K);
        if (total < K) return "";

        string firstHalf;
        int remainingLen = halfLen;
        array<int,26> counts = half;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (counts[c] == 0) continue;
                counts[c]--;
                long long cnt = permCount(counts, remainingLen - 1, K);
                if (K <= cnt) {
                    firstHalf.push_back('a' + c);
                    remainingLen--;
                    break;
                } else {
                    K -= cnt;
                    counts[c]++;
                }
            }
        }

        string result = firstHalf;
        if (midChar) result.push_back(midChar);
        reverse(firstHalf.begin(), firstHalf.end());
        result += firstHalf;
        return result;
    }
};