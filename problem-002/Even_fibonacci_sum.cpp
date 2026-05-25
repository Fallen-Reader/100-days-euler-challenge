#include<iostream>
using namespace std;

int fiboevensum(int n){
    int sum=0,f=0,s=1,nx=1;
    while(nx<n){
        nx=f+s;
        f=s;
        s=nx;
        if(nx%2==0){
            sum+=nx;
        }
    }
    return sum;
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    cout<<fiboevensum(n);
    return 0;
}