#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int hour(vector<vector<int>> arr){
    int res=INT_MIN;
    for(int r=0; r<=3 ; ++r){
        for(int c=0; c<=3 ; ++c){
            int sum = arr[r][c] + arr[r][c+1] + arr[r][c+2] + arr[r+1][c+1] + arr[r+2][c] + arr[r+2][c+1] + arr[r+2][c+2];

            res = max(sum,res);
        }
    }
    return res;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
        int res = hour(arr);

        fout<<res<<endl;

        fout.close();

        return 0;
}
