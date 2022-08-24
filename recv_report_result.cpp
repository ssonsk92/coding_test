#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> report_table;
    map<string, int> report_count_table;
    for (string id : id_list)
    {
        report_table.insert(make_pair(id, set<string>()));
        report_count_table.insert(make_pair(id, 0));
    }

    for (string report_info : report)
    {
        auto seperator = report_info.find(" ");
        string reporter = report_info.substr(0, seperator);
        string bad_user = report_info.substr(seperator + 1);

        auto find_it = report_table[reporter].find(bad_user);
        if (find_it == report_table[reporter].end())
        {
            report_table[reporter].insert(bad_user);
            report_count_table[bad_user]++;
        }
    }

    for (string id : id_list)
    {
        int mail_count = 0;
        set<string> report_list = report_table[id];
        for (string bad_user : report_list)
        {
            int report_count = report_count_table[bad_user];
            if (k <= report_count)
            {
                mail_count++;
            }
        }
        answer.push_back(mail_count);
    }

    return answer;
}