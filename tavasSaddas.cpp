#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007;

int main()
{
    int n;
    cin >> n;
    int temp = n;
    int len = 0;

    while (temp)
    {
        len++;
        temp /= 10;
    }
    int count_of_digits_smaller = pow(2, len) - 2;
    int pos = 0;
    int count_of_numbers_smaller_of_same_digits = 0;
    while (n)
    {
        if (n % 10 == 7)
            count_of_numbers_smaller_of_same_digits += pow(2, pos);
        pos++;
        n /= 10;
    }
    cout << count_of_numbers_smaller_of_same_digits + count_of_digits_smaller + 1;
}