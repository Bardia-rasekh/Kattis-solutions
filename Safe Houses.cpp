#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <math.h>
#include <queue>

using namespace std;

int main()
{
    int l_w, temp_distance, distance;
    cin >> l_w;
    string* matrix = new string[l_w];
    vector<tuple<char, int, int>> locations;
    priority_queue<int> result;

    for (int i = 0; i < l_w; i++)
    {
        cin >> matrix[i];
        for (int j = 0;j < l_w;j++) if (matrix[i][j] == 'S' || matrix[i][j] == 'H') locations.push_back(make_tuple(matrix[i][j], i, j));
    }
    
//    for (int i = 0; i < l_w; i++) cout << matrix[i] << endl;
//    for (auto i = locations.begin(); i != locations.end(); i++) cout << get<0>(*i) << " : " << get<1>(*i) << " : " << get<2>(*i) << endl;

    for (auto i = locations.begin(); i != locations.end(); i++)
    {
        distance = 2147483640;
        if (get<0>(*i) == 'S')
        {
            for (auto j = locations.begin(); j != locations.end(); j++)
            {
                if (get<0>(*j) == 'H')
                {
                    temp_distance = abs(get<1>(*i) - get<1>(*j)) + abs(get<2>(*i) - get<2>(*j));
                    if (temp_distance < distance) distance = temp_distance;
                }
            }
        }
        if (distance != 2147483640) result.push(distance);
    }

    cout << result.top();
    
    return 0;
}
