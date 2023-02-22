#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isPerfect(long long int n = 1)
{
    if (n == 1) return 0;

    long long int sum = 1;

    for (long long int i = 2; i * i <= n; i++)
    {
        if (!(n % i))
        {
            if (i * i != n) sum += i + n / i;
            else sum += i;  
        }
    }

    if (sum == n) return 1;
    if (sum <= n+2 && sum >= n-2) return 2;
    return 0;
}


int main()
{
    vector<long long int> source;
    string num;
    int result, sourceSize;

    while (true)
    {
        getline(cin, num);
        if (num == "") break;
        source.emplace_back(stod(num));
    }

    sourceSize = source.size();

    for (int i = 0;i < sourceSize ; i++)
    {
        result = isPerfect(source[i]);
        if (result == 1) cout << source[i] << " perfect" << '\n';
        else if(result == 2) cout << source[i] << " almost perfect" << '\n';
        else cout << source[i] << " not perfect" << '\n';
    }

    return 0;
}
