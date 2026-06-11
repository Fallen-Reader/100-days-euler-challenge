#include<iostream>
#include<vector>
using namespace std;


long long maxpathsum(vector<vector<int>> &triangle){
    int rows = triangle.size();
    vector<vector<int>> counter = triangle;

    for(int i = rows-2;i>=0;i--){
        for(int j =0;j<=i;j++){
            counter[i][j] = triangle[i][j]+ max(counter[i+1][j],counter[i+1][j+1]);
        }
    }
    return counter[0][0];
}
int main(){
    int rows=4;
    vector<vector<int>> triangle(rows,vector<int>(rows,0));
    triangle= {{3},{7,4},{2,4,6},{8,5,9,3}};
    long long t_sum = maxpathsum(triangle);
    cout<<"Maximum Path Sum is : "<<t_sum<<endl;
    return 0;
}