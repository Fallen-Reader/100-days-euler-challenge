#include<iostream>
#include<cmath>

using namespace std;

long long lattice_path(int GridSize){
    long long total_paths = 1;
    int total_steps = 2*GridSize;
    int right_moves = GridSize;

    for(int i =1;i<=right_moves;i++){
        total_paths=total_paths*(total_steps+1-i)/i;
    }
    return total_paths;
}

int main(){
    int gridsize = 20;
    cout<<"total no of paths is : "<<lattice_path(gridsize)<<endl;
    return 0;
}