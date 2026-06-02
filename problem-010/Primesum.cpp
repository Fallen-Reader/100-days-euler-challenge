#include <iostream>
#include <vector>

using namespace std;


long long sumOfPrimes(int n) {

    if (n < 2) return 0;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
  
    for (int p = 2; p * p <= n; p++) {
        
        if (is_prime[p]) {

            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    long long sum = 0;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            sum += p;
        }
    }

    return sum;
}

int main() {
    int n;
    
    cout << "Enter the upper limit (N): ";
    cin >> n;

    long long sum = sumOfPrimes(n);
    
    cout << "Sum of all prime numbers up to " << n << " is: " << sum << endl;

    return 0;
}
