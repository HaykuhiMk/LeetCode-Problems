class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first_index(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';  
            if (first_index[idx] == -1) {
                first_index[idx] = i;  
            } else {
                if (i - first_index[idx] - 1 != distance[idx]) {
                    return false;
                }
            }
        }
        return true;
    }
};
