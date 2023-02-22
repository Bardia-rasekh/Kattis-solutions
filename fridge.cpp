#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool sort_functioon(pair<int,int> x,pair<int,int> y)
{
    return x.second < y.second;
}


int main()
{
    string digit_source;
    cin >> digit_source;
    sort(digit_source.begin(), digit_source.end());

    pair<int, int>* digit_count = new pair<int, int>[10]();
    int j = 0;
    for (int i = 0;i <= 9;i++)
    {
        digit_count[i].first = i;
        while (digit_source[j] - '0' == i) 
        {
            digit_count[i].second++;
            j++;
        }
    }
    sort(digit_count, digit_count + 10, sort_functioon);
    
    digit_source = "";
    if (!digit_count[0].first)
    {
        if (digit_count[1].second - digit_count[0].second > 0)
        {
            digit_source += to_string(digit_count[1].first);
            for (int i = 0; i < digit_count[0].second + 1; i++)
            {
                digit_source += '0';
            }
        }
        else
        {
            for (int i = 0; i < digit_count[1].second + 1; i++)
            {
                digit_source += to_string(digit_count[1].first);
            }
        }
    }
    else
    {
        for (int i = 0; i < digit_count[0].second + 1; i++)
        {
            digit_source += to_string(digit_count[0].first);
        }
    }

    cout << digit_source;

    return 0;
}

