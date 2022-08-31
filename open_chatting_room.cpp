#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> name_table;
    vector<pair<string, string>> log_list;

    for (string log : record)
    {
        size_t pos = log.find(" ");
        string command = log.substr(0, pos);
        log = log.substr(pos + 1);
        pos = log.find(" ");
        string id = log.substr(0, pos);
        string name = log.substr(pos + 1);

        if ("Enter" == command || "Change" == command)
        {
            auto find_it = name_table.find(id);
            if (find_it == name_table.end())
            {
                name_table.insert(make_pair(id, name));
            }
            else
            {
                name_table[id] = name;
            }
        }

        if ("Enter" == command)
        {
            log_list.push_back(make_pair(id, "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù."));
        }
        else if ("Leave" == command)
        {
            log_list.push_back(make_pair(id, "´ÔÀÌ ³ª°¬½À´Ï´Ù."));
        }
    }

    for (pair<string, string> log : log_list)
    {
        string name = name_table[log.first];
        answer.push_back(name + log.second);
    }

    return answer;
}

int main()
{
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    vector<string> result = solution(record);

    for (string str : result)
    {
        cout << str << endl;
    }

    return 0;
}