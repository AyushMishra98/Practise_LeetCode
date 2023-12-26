class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(word == endWord)
                return steps;
            
            for(int i=0;i<word.length();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word) != s.end()){
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};