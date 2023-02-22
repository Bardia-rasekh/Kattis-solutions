#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string temp_str;
    int n_m[2];
    int i, j, k;
    vector<int> result;

    while (true)
    {
        // initialize data
        getline(cin, temp_str);
        temp_str += " ";

        i = temp_str.find(" ");
        n_m[0] = stoi(temp_str.substr(0, i));
        temp_str.erase(0, i + 1);

        i = temp_str.find(" ");
        n_m[1] = stoi(temp_str.substr(0, i));
        temp_str.erase(0, i + 1);

        if (!n_m[0] && !n_m[1])
        {
            for (auto i = result.begin(); i != result.end(); i++) cout << *i << endl;
            return 0;
        }

        auto n_lines = new int[n_m[0]][2];
        auto m_lines = new int[n_m[1]][2];

        for (k = 0; k < n_m[0]; k++)
        {
            getline(cin, temp_str);
            temp_str += " ";
            j = 0;
            temp_str.erase(0, temp_str.find(" ") + 1);
            temp_str.erase(0, temp_str.find(" ") + 1);

            i = temp_str.find(" ");
            n_lines[k][0] = stoi(temp_str.substr(0, i));
            temp_str.erase(0, i + 1);

            i = temp_str.find(" ");
            n_lines[k][1] = stoi(temp_str.substr(0, i)) + n_lines[k][0];
            temp_str.erase(0, i + 1);
        }

        for (k = 0; k < n_m[1]; k++)
        {
            getline(cin, temp_str);
            temp_str += " ";

            i = temp_str.find(" ");
            m_lines[k][0] = stoi(temp_str.substr(0, i));
            temp_str.erase(0, i + 1);

            i = temp_str.find(" ");
            m_lines[k][1] = stoi(temp_str.substr(0, i)) + m_lines[k][0];
            temp_str.erase(0, i + 1);
        }

        // final
        int passed;
        for (int i = 0; i < n_m[1]; i++)
        {
            passed = 0;
            for (int j = 0; j < n_m[0]; j++)
            {
                if (m_lines[i][0] <= n_lines[j][0] && m_lines[i][1] >= n_lines[j][1]) passed++;
                else if (m_lines[i][0] >= n_lines[j][0] && m_lines[i][1] <= n_lines[j][1]) passed++;
                else if (m_lines[i][0] >= n_lines[j][0] && m_lines[i][0] < n_lines[j][1] && m_lines[i][0] + 1 <= n_lines[j][1]) passed++;
                else if (m_lines[i][1] > n_lines[j][0] && m_lines[i][1] <= n_lines[j][1] && m_lines[i][1] - 1 >= n_lines[j][0]) passed++;
            }
            result.push_back(passed);
        }
    }

    return 0;
}

