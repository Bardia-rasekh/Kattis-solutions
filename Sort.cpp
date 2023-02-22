#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;


int main()
{
    int dig_count, max_dig;
    cin >> dig_count >> max_dig;
    int* dig_array = new int[dig_count];
    vector<tuple<int, int, int>> hash_table;
    bool exist;
    cin >> dig_array[0];
    hash_table.push_back(make_tuple(dig_array[0], 0, 0));
    for (int i = 1; i < dig_count; i++)
    {
        exist = false;
        cin >> dig_array[i];
        for (auto j = hash_table.begin(); j != hash_table.end(); j++)
        {
            if (dig_array[i] == get<0>(*j))
            {
                exist = true;
                break;
            }
        }
        if (!exist) hash_table.push_back(make_tuple(dig_array[i], 0, i));
    }

    sort(hash_table.begin(), hash_table.end(), [](auto& left, auto& right) {
        return get<0>(left) < get<0>(right);
        });

    sort(dig_array, dig_array + dig_count);

    int j = 0, temp = 0;
    for (int i = 0; i < dig_count; i++)
    {
        if (get<0>(hash_table[j]) == dig_array[i]) temp++;
        else
        {
            get<1>(hash_table[j]) = temp;
            j++;
            temp = 0;
            i--;
        }
    }
    get<1>(hash_table[j]) = temp;

    sort(hash_table.begin(), hash_table.end(), [](auto& left, auto& right) {
     return get<1>(left) > get<1>(right);
     });
    
    auto temp_loc = hash_table.begin();
    for (auto i = hash_table.begin() + 1; i != hash_table.end(); i++)
    {
        if (get<1>(*i) != get<1>(*temp_loc))
        {
            sort(temp_loc, i, [](auto& left, auto& right) {
                return get<2>(left) < get<2>(right);
                });
            
            temp_loc = i;
            i--;
        }
        if (i == hash_table.end() - 1)
        {
            sort(temp_loc, i+1, [](auto& left, auto& right) {
                return get<2>(left) < get<2>(right);
                });
        }
    }

    for (auto i = hash_table.begin(); i != hash_table.end(); i++) for (int j = 0;j < get<1>(*i);j++) cout << get<0>(*i) << " ";
    
    return 0;
}
