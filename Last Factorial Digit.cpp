#include <iostream>

using namespace std;

int lastDigitFactorial(int n)
{
    if (n == 0) return 1;
    else if (n <= 2) return n;
    else if (n == 3) return 6;
    else if (n == 4) return 4;
    else return 0;
}

int main()
{
    int count;
    cin >> count;
    int* numbers = new int[count];
    for (int j = 0; j < count; j++) cin >> numbers[j];
    for (int j = 0; j < count; j++) cout << lastDigitFactorial(numbers[j]) << endl;
    return 0;
}
