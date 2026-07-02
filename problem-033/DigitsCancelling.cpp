#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*There are exactly four non-trivial 
examples of this type of fraction, less than one in value, and containing 
two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator.*/

int GDC(int a, int b){
    if(b==0) return a;
    return GDC(b,a%b);
}
int main(){
    long long prod_n = 1,prod_d =1;
    for(int i =12;i<=99;i++){
        for(int j =11;j<i;j++){
            
            if(i%10==0 || j%10==0) continue;

            int n = j/10;
            int c_1 = j%10;
            int d = i%10;
            int c_2 = i/10;
            if(c_1 != c_2 || n>=d) continue;

            double frac_ori = j/(double)i;
            double frac_can = n/(double)d;

            if(frac_ori==frac_can) {
                prod_n *=j;
                prod_d *=i;
            }

        }
        
    }
    int gdc = GDC(prod_n,prod_d);
    cout<<prod_d/gdc<<endl;
}