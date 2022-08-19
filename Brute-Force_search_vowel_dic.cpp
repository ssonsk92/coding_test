#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool dfs(string combination, const string& word, int vowel_idx, int depth, int& answer)
{
    if (depth == 5)
        return false;

    if (vowel_idx == 5)
    {
        return false;
    }

    vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
    if (depth < combination.size())
    {
        combination[depth] = vowels[vowel_idx];
    }
    else
    {
        combination += vowels[vowel_idx];
    }

    cout << combination << endl;

    answer++;
    if (combination == word)
        return true;

    if (dfs(combination, word, 0, depth + 1, answer))
        return true;

    if (dfs(combination, word, vowel_idx + 1, depth, answer))
        return true;

    return false;
}

int solution(string word) {
    int answer = 0;

    string combination;

    dfs(combination, word, 0, 0, answer);

    return answer;
}
int main()
{
    string word("I");
    cout << solution(word) << endl;

    return 0;
}