#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> get_answer(int n, int idx)
{
    vector<int> answer;

    int eliminator_num = (idx % n) + 1;
    answer.push_back(eliminator_num);
    int loop_count = idx / n + 1;
    answer.push_back(loop_count);

    return answer;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    set<string> check_overlap;

    char last_alphabet;
    for (size_t i = 0; i < words.size(); ++i)
    {
        string word = words[i];
        auto find_it = check_overlap.find(word);
        if (find_it != check_overlap.end())
        {
            answer = get_answer(n, i);
            break;
        }

        if (0 < i && last_alphabet != word[0])
        {
            answer = get_answer(n, i);
            break;
        }

        check_overlap.insert(word);
        last_alphabet = word[word.length() - 1];
    }

    return answer;
}

int main()
{
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    vector<int> v = solution(3, words);

    cout << v[0] << " " << v[1] << endl;

    return 0;
}