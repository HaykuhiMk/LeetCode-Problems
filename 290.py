class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.size() != words.size()) {
            return false;  
        }
        
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;
        
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];
            
            if (char_to_word.contains(ch)) {
                if (char_to_word[ch] != w) return false; 
            } else {
                if (word_to_char.contains(w)) return false;  
                char_to_word[ch] = w;
                word_to_char[w] = ch;
            }
        }
        return true;
    }
};
