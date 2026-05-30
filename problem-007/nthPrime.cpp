#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int target){
    int i;
    if(target == 2) return true;
    for(i=3;i<target;i=i+2){
        if(target%i==0){
            return false;
        }
    }
    if(i==target) return true;
    return false;
}

int WhatPrime(int terms){
    int i;
    static int j=0;
    for(i=0;;i++){
        if(isPrime(i)) j++;
        if(j==terms) return i;
    }
}

int main(){
    int term;
    cout<<"enter the term : "<<endl;
    cin>>term;
    cout<<"the prime number on term "<<term<<" is : "<<WhatPrime(term)<<endl;
    return 0;
}