class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> items;
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }
        sort(items.begin(), items.end(), greater<pair<double, int>>());
        double ans = 0.0;
        int cap = capacity;
        for (int i = 0; i < n; i++) {
            double ratio = items[i].first;
            int idx = items[i].second;
            if (wt[idx] <= cap) {
                ans += val[idx];
                cap -= wt[idx];
            } else {
                ans += ratio * cap;
                break;
            }
        }
        return ans;
    }
};