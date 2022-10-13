class Solution {
   public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n / 2;  // Divide the whole array into two parts of size n/2

        vector<vector<int>> left(N + 1);   // 0 -- N-1   to store sum of all subsets of left half the nums
        vector<vector<int>> right(N + 1);  // N -- n-1   to store sum of all subsets of right half the nums

        for (int bitmask = 0; bitmask < (1 << N); bitmask++)  // Using bitmask find all the subsets of left part of nums
        {
            int mask = bitmask;
            int no_of_set_bits = 0;  // Denotes which element in nums is the part of subset (size of subset)
            int sum = 0;             // Ex = {1010} means {2,3,4,5} 2 & 4 are the part of subset
            int index = 0;           // Denotes the index of element in nums

            while (mask > 0) {
                if (mask & 1)  // If the bit is set then include it in subset
                {
                    sum += nums[index];  // calculate sum of the elements that are the part of the subset
                    no_of_set_bits++;
                }
                mask = mask >> 1;
                index++;
            }
            left[no_of_set_bits].push_back(sum);  // Corresponding to size of susbset add the sum of that subset
        }

        for (int bitmask = 0; bitmask < (1 << N); bitmask++)  // Find all the subsets of right part of the nums
        {
            int mask = bitmask;
            int no_of_set_bits = 0;
            int sum = 0;
            int index = 0;

            while (mask > 0) {
                if (mask & 1) {
                    sum += nums[index + N];  // To make sure we only include elements from the right half
                    no_of_set_bits++;        // we add N to the index so that it include right half elements
                }
                mask = mask >> 1;
                index++;
            }
            right[no_of_set_bits].push_back(sum);
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int size = 0; size <= N; size++)  // Now iterate over each sum in left part from size 0 to N
        {
            vector<int> v2 = right[N - size];  // Consider corresponding part of right half such that
            sort(v2.begin(), v2.end());        // no of element in left sum + right sum == N
            for (auto& a : left[size]) {
                int b = (sum - 2 * a) / 2;                        // To find appropriate sum b of subset of size N-size
                auto itr = lower_bound(v2.begin(), v2.end(), b);  // We use binary search in right half vector

                if (itr != v2.end()) {
                    b = *itr;
                    ans = min(ans, abs(sum - 2 * (a + b)));
                }
            }
        }
        return ans;
    }
};