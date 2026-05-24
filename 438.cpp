#include <vector>  
#include <unordered_map>
using namespace std;


class Solution{
    public:
    vector<int> findAnagrams(string s2, string s1){
        //abc => cba , bac...

        int n = s2.size(), m = s1.size();

        unordered_map<char, int> map1; // frequency of chars in s1
        for(char c : s1){
            map1[c]++;
        }

        unordered_map<char, int> map2;  // frequency of chars in the current window of s2
        vector<int> result;

        for(int i=0; i<n; i++){
            map2[s2[i]]++;  // add new right character to window

            if(i>=m){  // window size exceeded, remove leftmost character
                if(map2[s2[i-m]] == 1){
                    map2.erase(s2[i-m]);  // remove key if count becomes 0
                } else {
                    map2[s2[i-m]]--;  // otherwise just decrement the count of the leftmost character
                }
            }

            if(map1 == map2){  // compare the frequency maps
                result.push_back(i-m+1);  // start index = currecnt right - variavle size + 1
            }
        }
        return result;
    }
};


/*
Step 1: build the target map
it counts the frequency of each character in s1 and stores it in map1. this acts as a referecne answer key

step 2 : slide a window over s2
it loops through s2, adding characters one by one to a second map(map2) to track the current window of text

step 3 : constrain the window size
once the window gets larger than s1 ( if(i>=m), it removes the oldest character on the far left from the map2 to keep the window size the same as s1

step 4: check for a match
it directly compares map1 == map2. if they match, the current window is an anagram and its starting index (i-m+1) is saved to result
*/


/*
s1 = "ab" (target size m = 2)
s2 ="bab" (Search string size n=3)

step 1: build the target map (map1)
map1 = {'a': 1, 'b': 1}

step 2: slide a window over s2 ("bab")
iteration 1: i=0: map2 = {'b': 1} (window is "b") 

add to window: map2['b']++ -> map2 = {'b': 1}

check window size: i < m (0 < 2) so we don't remove anything

compare maps: does map1 == map2?
{'a': 1, 'b': 1} != {'b': 1} -> no match
result = []

Iteration 2: i = 1 (Character s2[1] is 'a')
Add to window: map2['a']++ -> map2 becomes {'b': 1, 'a': 1}
Check window size (i >= m): 1 >= 2 is False. (No characters are removed).
Compare maps: Does map1 == map2?
{'a': 1, 'b': 1} == {'b': 1, 'a': 1} \-> Yes! (Order does not matter in maps).
Calculate index: i - m + 1 -> 1 - 2 + 1 = 0.
result vector: [0]

Iteration 3: i = 2 (Character s2[2] is 'b')
Add to window: map2['b']++ -> map2 becomes {'b': 2, 'a': 1}
Check window size (i >= m): 2 >= 2 is True. (Time to shrink the left side!).
The character leaving the window is s2[i - m] -> s2[2 - 2] -> s2[0], which is 'b'.
Since map2['b'] is 2 (not 1), it triggers the else block: map2['b']--.
map2 updates to {'b': 1, 'a': 1}.

Compare maps: Does map1 == map2?
{'a': 1, 'b': 1} == {'b': 1, 'a': 1}-> Yes!
Calculate index: i - m + 1 -> 2 - 2 + 1 = 1.
result vector: [0, 1]
*/
