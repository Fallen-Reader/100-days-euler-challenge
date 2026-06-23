#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

long long Todecimal(long long den){
    string result ="";
    
    result += to_string(1/den);
    long long rem = 1%den;
    
    result +=".";
    unordered_map<long long,int> rem_pos;

    while(rem!=0){
        if(rem_pos.count(rem)>0){
            int open_bracket_index = rem_pos[rem];
            result.insert(open_bracket_index, "(");
            result += ")";
            break;
        }
        rem_pos[rem] = result.size();
        rem*=10;
        result+= to_string(rem/den);
        rem %=den;
    }
    result.erase(result.begin(),find(result.begin(),result.end(),'('));
    long long recur_size = result.size()-2;
    return recur_size ;
}

int main(){
    int n =1000;
    long long max_size =0;
    int ans =0;
    for(int d =2;d<=n;d++){
        long long cur_size = Todecimal(d);
        if(cur_size>max_size){
            max_size = cur_size;
            ans = d;
        }
    }
    cout<<ans<<endl;
    return 0;
    
}