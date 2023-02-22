#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    vector<string> input;
    vector<string> edited_input;
    
    do
    {
        getline(cin, str, '\n');
        input.push_back(str);
    } while (!str.empty());
    input.erase(input.end() - 1);
    //for (auto i = input.begin(); i != input.end(); i++) cout << *i << endl;


    for (auto i = input.begin(); i != input.end(); i++)
    {
        for (int j = 1; j < i->length(); j++)
        {
            if (((*i)[j] == 'B' || (*i)[j] == 'F' || (*i)[j] == 'P' || (*i)[j] == 'V') && ((*i)[j-1] == 'B' || (*i)[j-1] == 'F' || (*i)[j-1] == 'P' || (*i)[j-1] == 'V'))
            {
                i->erase(j - 1,1);
                j--;
            }
            else if (((*i)[j] == 'C' || (*i)[j] == 'G' || (*i)[j] == 'J' || (*i)[j] == 'K' || (*i)[j] == 'Q' || (*i)[j] == 'S' || (*i)[j] == 'X' || (*i)[j] == 'Z') && ((*i)[j-1] == 'C' || (*i)[j-1] == 'G' || (*i)[j-1] == 'J' || (*i)[j-1] == 'K' || (*i)[j-1] == 'Q' || (*i)[j-1] == 'S' || (*i)[j-1] == 'X' || (*i)[j-1] == 'Z'))
            {
                i->erase(j - 1,1);
                j--;
            }
            else if (((*i)[j] == 'D' || (*i)[j] == 'T') && ((*i)[j-1] == 'D' || (*i)[j-1] == 'T'))
            {
                i->erase(j - 1,1);
                j--;
            }
            else if (((*i)[j] == 'L') && ((*i)[j-1] == 'L'))
            {
                i->erase(j - 1,1);
                j--;
            }
            else if (((*i)[j] == 'M' || (*i)[j] == 'N') && ((*i)[j-1] == 'M' || (*i)[j-1] == 'N'))
            {
                i->erase(j - 1,1);
                j--;
            }
            else if ((*i)[j] == 'R' && (*i)[j-1] == 'R')
            {
                i->erase(j - 1,1);
                j--;
            }
        }
        edited_input.push_back(*i);
    }
    input.clear();
    //for (auto i = edited_input.begin(); i != edited_input.end(); i++) cout << *i << endl;


    for (auto i = edited_input.begin(); i != edited_input.end(); i++)
    {
        str = "";
        for (int j = 0; j < i->size(); j++)
        {
            if ((*i)[j] == 'B' || (*i)[j] == 'F' || (*i)[j] == 'P' || (*i)[j] == 'V') str += "1";
            else if ((*i)[j] == 'C' || (*i)[j] == 'G' || (*i)[j] == 'J' || (*i)[j] == 'K' || (*i)[j] == 'Q' || (*i)[j] == 'S' || (*i)[j] == 'X' || (*i)[j] == 'Z') str += "2";
            else if ((*i)[j] == 'D' || (*i)[j] == 'T') str += "3";
            else if ((*i)[j] == 'L') str += "4";
            else if ((*i)[j] == 'M' || (*i)[j] == 'N') str += "5";
            else if ((*i)[j] == 'R') str += "6";
        }
        input.push_back(str);
    }
    for (auto i = input.begin(); i != input.end(); i++) cout << *i << endl;
    
    return 0;
}

