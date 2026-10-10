
class Solution {
public:
    int hash[100001];
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long sumdiff = 0;
        int mxdiff = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            hash[diff]++;
            sumdiff += diff;
            mxdiff = max(mxdiff, diff);
        }
        long long k = (long long)k1 + k2;
        if (sumdiff <= k) return 0;
        int tempmxdiff = mxdiff; 

        while (k > 0) {
            int count = hash[mxdiff];

            if (count <= k) {
                hash[mxdiff - 1] += count;
                hash[mxdiff] = 0;
                mxdiff -= 1;
            } else {
                hash[mxdiff] -= k;
                hash[mxdiff - 1] += k;
            }
            k -= count;
        }

        long long ans = 0;
        for(int i = 0;i <= tempmxdiff;i++){
            ans += 1LL * i * i * hash[i];
        }

        return ans;
    }
};

/* --------------------------------------------------- JAVA CODE -------------------------------------------*/
class Solution {
    int[] hash = new int[100001];
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        long sumdiff = 0;
        int mxdiff = 0;
        for (int i = 0; i < nums1.length; i++) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            hash[diff]++;
            sumdiff += diff;
            mxdiff = Math.max(mxdiff, diff);
        }
        long k = (long)k1 + k2;
        if (sumdiff <= k) return 0;
        int tempmxdiff = mxdiff;

        while (k > 0) {
            int count = hash[mxdiff];

            if (count <= k) {
                hash[mxdiff - 1] += count;
                hash[mxdiff] = 0;
                mxdiff -= 1;
            } else {
                hash[mxdiff] -= k;
                hash[mxdiff - 1] += k;
            }
            k -= count;
        }

        long ans = 0;
        for(int i = 0;i <= tempmxdiff;i++){
            ans +=  1l * i * i * hash[i];
        }

        return ans;
    }
}