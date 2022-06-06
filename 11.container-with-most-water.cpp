class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t N = height.size();
        size_t area, area_max = 0, thresh = 0;
        for (size_t i = 0; i < N; ++i) {
            if (height[i] < thresh)
                    continue;
            for (size_t j = N-1; j > i; --j) {
                if (height[j] < thresh)
                    continue;
                thresh = min(height[i], height[j]);
                area = thresh * (j-i);
                if (area > area_max)
                    area_max = area;
            }
        }
        return area_max;
    }
};
