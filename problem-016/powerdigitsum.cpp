#include<iostream>
#include<vector>
#include<string>

using namespace std;

int digitSumOfPowerOfTwo(int exponent) {
    vector<int> digits = {1};

    for (int i = 0; i < exponent; i++) {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++) {
            int value = digits[j] * 2 + carry;
            digits[j] = value % 10;
            carry = value / 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    int sum = 0;
    for (int d : digits) sum += d;
    return sum;
}

int main(){
    int expo =1000;
    cout<<"the sum of all digits is : "<<digitSumOfPowerOfTwo(expo)<<endl;
    return 0;
}