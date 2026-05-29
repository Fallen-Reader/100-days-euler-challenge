#include<iostream>
#include <cmath>
using namespace std;
int sumsqarediff(int n){
    int sum_of_square =n*(n+1)*(2*n+1)/6;
    
    int sum = n*(n+1)/2;
    int square_of_sum = sum*sum;
    
    int diff =  square_of_sum - sum_of_square;

    return diff;
}
int main(){
    int n;
    cout<<"enter a number : ";
    cin>>n;
    cout<<"diff is: "<<sumsqarediff(n);
    return 0;
    
}