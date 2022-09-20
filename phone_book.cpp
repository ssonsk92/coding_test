#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        string phone = phone_book[i];
        string next_phone = phone_book[i + 1];

        if (phone == next_phone.substr(0, phone.size()))
            return false;
    }

    return answer;
}

int main()
{
    vector<string> phone_book = { "115", "97674223", "1195524421" };

    cout << solution(phone_book) << endl;

    return 0;
}