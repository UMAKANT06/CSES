#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Create a set of all unique Pokemon types
    unordered_set<char> uniqueTypes(s.begin(), s.end());
    int totalUnique = uniqueTypes.size();
    
    // Use a frequency map to track counts of Pokemon types in the current window
    unordered_map<char, int> freqMap;
    
    int l = 0, r = 0;
    int minLength = INT_MAX;
    int uniqueCount = 0;
    
    while (r < n) {
        // Expand the window by moving the right pointer
        char currentChar = s[r];
        if (freqMap[currentChar] == 0) {
            uniqueCount++;
        }
        freqMap[currentChar]++;
        r++;
        
        // Once the window contains all unique types, try to shrink it
        while (uniqueCount == totalUnique) {
            minLength = min(minLength, r - l);
            char leftChar = s[l];
            freqMap[leftChar]--;
            if (freqMap[leftChar] == 0) {
                uniqueCount--;
            }
            l++;
        }
    }
    
    cout << minLength << endl;
    
    return 0;
}
