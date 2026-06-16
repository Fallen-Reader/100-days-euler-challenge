#include <iostream>
#include <vector>
using namespace std;

vector<int> precomputeDivisorSums(int MAX) {
    vector<int> divSum(MAX + 1, 0);
    
    for (int i = 1; i <= MAX; i++) {
        for (int j = i * 2; j <= MAX; j += i) {
            divSum[j] += i;
        }
    }
    
    return divSum;
}

int main() {
    int MAX = 10000;

    vector<int> divSum = precomputeDivisorSums(MAX);
    
    int totalSum = 0;

    for (int i = 1; i < MAX; i++) {
        int flag1 = divSum[i];   
        
        if (flag1 < MAX && flag1 != i) {
            int flag2 = divSum[flag1]; 
            
            if (i == flag2) {
                cout << "Amicable pair: " << i << " and " << flag1 << endl;
                totalSum += i + flag1;
            }
        }
    }
    
    cout << "\nSum of all amicable numbers: " << totalSum << endl;
    
    return 0;
}