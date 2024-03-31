#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> Q;
    Q.push({startWord, 1});
    st.erase(startWord);

    int ans = 0;
    while (!Q.empty())
    {
        string word = Q.front().first;
        int dis = Q.front().second;
        Q.pop();

        if (word == targetWord)
            ans = dis;
        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    Q.push({word, dis + 1});
                }
            }

            word[i] = original;
        }
    }

    return ans;
}