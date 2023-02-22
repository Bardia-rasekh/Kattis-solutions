#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string temp_str;
    int n, m, i;
    float p;
    
    getline(cin, temp_str);
    temp_str += " ";

    i = temp_str.find(" ");
    n = stoi(temp_str.substr(0, i));
    temp_str.erase(0, i + 1);
    i = temp_str.find(" ");
    m = stoi(temp_str.substr(0, i));
    temp_str.erase(0, i + 1);
    p = stof(temp_str.substr(0, temp_str.find(" "))) / 100;

    float* n_arr = new float[n];
    float* m_arr = new float[m];

    getline(cin, temp_str);
    temp_str += " ";

    for (int j = 0; j < n; j++)
    {
        i = temp_str.find(" ");
        n_arr[j] = stof(temp_str.substr(0, i));
        temp_str.erase(0, i + 1);
    }

    getline(cin, temp_str);
    temp_str += " ";

    for (int j = 0; j < m; j++)
    {
        i = temp_str.find(" ");
        m_arr[j] = stof(temp_str.substr(0, i));
        temp_str.erase(0, i + 1);
    }
    
    vector<float> result;
    
    for (i = 0; i < n; i++) for (int j = 0; j < m; j++) result.push_back(m_arr[j] / n_arr[i]);
    sort(result.begin(), result.end());

    for (auto j = result.begin(); j != result.end() - 1; j++)
    {
        if (*j + (*j) * p < *(j + 1))
        {
            cout << "Time to change gears!";
            return 0;
        }
    }
    cout << "Ride on!";
    return 0;
}

