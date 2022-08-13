class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map < char , int > mp;
        for ( auto i : s ) mp[i] += 1;
        set < int > st;
        for ( auto i : mp ) st.insert(i.second);
        return st.size() == 1;
    }
};