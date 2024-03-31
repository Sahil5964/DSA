#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(), wordList.end());

    int level = 0;
    queue<vector<string>> Q;
    vector<string> usedOnLevel;

    Q.push({beginWord});
    while (!Q.empty())
    {
        vector<string> x = Q.front();
        Q.pop();

        if (x.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
                st.erase(it);
            usedOnLevel.clear();
        }

        string word = x.back();
        if (word == endWord)
        {
            if (ans.size() == 0)
                ans.push_back(x);
            else if (ans[0].size() == x.size())
                ans.push_back(x);
        }

        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    x.push_back(word);
                    Q.push(x);
                    usedOnLevel.push_back(word);
                    x.pop_back();
                }
            }

            word[i] = original;
        }
    }

    return ans;
}