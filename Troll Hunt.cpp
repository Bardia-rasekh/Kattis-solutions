#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int number_of_knights = 0, number_of_knights_per_group = 0, number_of_bridges = 0, number_of_groups;
    cin >> number_of_bridges >> number_of_knights >> number_of_knights_per_group;

    number_of_bridges -= 1;
    number_of_groups = number_of_knights / number_of_knights_per_group;
    cout << ceil(double(number_of_bridges) / double(number_of_groups));

    return 0;
}
