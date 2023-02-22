#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> list;
    string input;

    do
    {
        cin >> input;
        list.push_back(input);
    } while (input != "END");


    size_t pos;
    int pre_pos, dot_number;
    vector<int> dot_number_array;
    bool even;
    for (int i = 0; i < list.size() - 1; i++)
    {
        even = true;

        pos = list[i].find('*');
        while (true)
        {
            pre_pos = pos;
            pos = list[i].find('*', pos + 1);
            if (pos != string::npos)
            {
                dot_number = pos - pre_pos - 1;
                dot_number_array.push_back(dot_number);
                if (dot_number_array.size() == 2)
                {
                    if (dot_number_array[0] == dot_number_array[1]) dot_number_array.erase(dot_number_array.begin());
                    else
                    {
                        even = false;
                        break;
                    }
                }
            }
            else break;
        }

        if (!even) cout << i + 1 << " " << "NOT EVEN" << endl;
        else cout << i + 1 << " " << "EVEN" << endl;
        dot_number_array.erase(dot_number_array.begin(), dot_number_array.end());
    }
    
    return 0;
}
