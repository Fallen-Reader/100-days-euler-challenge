#include<iostream>
#include<vector>

using namespace std;

int No_of_ways(int amt,const vector<int>& coins){
    vector<int> ways(amt+1,0);
    ways[0] = 1;
    for(int i=0;i<coins.size();i++){
        for(int j = coins[i];j<amt+1;j++){
            ways[j] += ways[j-coins[i]];
        }
    }
    return ways[amt];
}

int main(){
    int amt = 200;
    vector<int> coins = {1,2,5,10,20,50,100,200};
    cout<<No_of_ways(amt,coins)<<endl;
}