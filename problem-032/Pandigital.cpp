#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    cout<<" enter a no : ";
    cin>>n;
    vector<int> digits(n);
    set<int> products;
    for(int i=0;i<n;i++) digits[i] = i+1;
    do{
        for(unsigned int LenA =1;LenA<n;LenA++){
            for(unsigned int LenB =1;LenB<n-LenA;LenB++){
                unsigned int LenC = n - LenA - LenB;
                if(LenC<LenA||LenC<LenB) break;
                unsigned pos =0;
                unsigned a = 0;

                for(int i =0;i<LenA;i++){
                    a*=10;
                    a+= digits[pos++];
                }
                unsigned b = 0;

                for(int i =0;i<LenB;i++){
                    b*=10;
                    b+= digits[pos++];
                }
                unsigned c = 0;

                for(int i =0;i<LenC;i++){
                    c*=10;
                    c+= digits[pos++];
                }
                if(a*b==c){
                    products.insert(c);
                    cout<<c<<endl;
                }
            }
        }
        
    } while (next_permutation(digits.begin(),digits.end()));

    unsigned long long sum = 0;
    for(auto num:products) sum+=num;

    cout<<sum<<endl;

}