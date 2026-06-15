#include<iostream>
#include<vector>

using namespace std;

long long sumofdigit(int n){
    const int Base = 10000;
    vector<int> digits ={1};
    for(int j = 2;j<=n;j++){
        int carry = 0;
        for(int i=0;i<digits.size();i++){
            int val = digits[i]*j+carry;
            carry = val/Base;
            digits[i] = val%Base;
        }
        while(carry>0){
            digits.push_back(carry%Base);
            carry /=Base;
        }
        
    }
    long long sum =0 ;
    for (int block : digits) {
    while (block > 0) {
        sum += block % 10;  
        block /= 10;         
    }
}

    return sum;
}

int main(){
    int num =100;
    cout<<"sum of digits "<<sumofdigit(num)<<endl;
    return 0;
}