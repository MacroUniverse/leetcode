class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size(), ans = 0;
        vector<int> st;
        for (int i = 1; i < N; ++i) {
            int Hi = height[i], Hi_1 = height[i-1];
            if (Hi < Hi_1)
                st.push_back(i-1);
            else if (Hi > Hi_1 && st.size() > 0) {
                int bottom = Hi_1;
                while (st.size() > 0) {
                    int j = st.back();
                    if (height[j] <= Hi) {
                        ans += (i-j-1)*(height[j] - bottom);
                        bottom = height[j]; st.pop_back();
                    }
                    else {
                        ans += (i-j-1)*(Hi - bottom);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
