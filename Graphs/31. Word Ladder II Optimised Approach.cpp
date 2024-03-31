#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<string>> &ans, unordered_set<string> &st, unordered_map<string, int> &mp, vector<string> curAns)
{
    int level = mp[curAns.back()];
    if (level == 1)
    {
        reverse(curAns.begin(), curAns.end());
        ans.push_back(curAns);
        return;
    }

    string word = curAns.back();
    for (int i = 0; i < word.length(); i++)
    {
        char original = word[i];

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (st.find(word) != st.end() && (mp[word] + 1 == level))
            {
                curAns.push_back(word);
                dfs(ans, st, mp, curAns);
                curAns.pop_back();
            }
        }

        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    queue<string> Q;
    unordered_map<string, int> mp;
    unordered_set<string> st(wordList.begin(), wordList.end());

    mp[beginWord] = 1;
    st.erase(beginWord);
    Q.push(beginWord);
    while (!Q.empty())
    {
        string word = Q.front();
        int dis = mp[word];
        Q.pop();

        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    Q.push(word);
                    mp[word] = dis + 1;
                }
            }

            word[i] = original;
        }
    }

    // DFS Call for Backtrack from ans;
    vector<string> curAns;
    vector<vector<string>> ans;
    unordered_set<string> stt(wordList.begin(), wordList.end());

    stt.insert(beginWord);
    curAns.push_back(endWord);
    dfs(ans, stt, mp, curAns);

    return ans;
}