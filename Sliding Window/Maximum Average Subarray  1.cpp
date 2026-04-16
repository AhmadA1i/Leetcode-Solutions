class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        // Calculate the sum of the first window
        double current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        
        // Slide the window across the array
        for (int i = k; i < nums.size(); ++i) {
            // Subtract element moving out, add element moving in
            current_sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum / k;
    }
};
