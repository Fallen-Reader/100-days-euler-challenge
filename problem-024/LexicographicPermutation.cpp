#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> fact(10);
    fact[0] = 1;
    for (int i = 1; i < 10; i++) fact[i] = fact[i-1] * i;

    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    long long target = 999999;
    string result;

    for (int i = 9; i >= 0; i--) {
        long long block = fact[i];        
        int index = target / block;
        result += to_string(digits[index]);
        digits.erase(digits.begin() + index);
        target %= block;
    }

    cout << result << endl;
    return 0;
}