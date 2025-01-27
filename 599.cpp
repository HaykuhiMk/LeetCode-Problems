class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index_map;  
        for (int i = 0; i < list1.size(); i++) {
            index_map[list1[i]] = i;
        }
        vector<string> result;
        int min_sum = INT_MAX;
        for (int j = 0; j < list2.size(); j++) {
            if (index_map.count(list2[j])) {
                int index_sum = j + index_map[list2[j]];
                if (index_sum < min_sum) {
                    min_sum = index_sum;
                    result = {list2[j]};
                } else if (index_sum == min_sum) {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
