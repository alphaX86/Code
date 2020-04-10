#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n ;
    vector <int> x(n);
    vector <int> y(n);    
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        y[i] = x[n-i-1];
    }
    for(int i=0;i<n;i++){
        cout << y[i] <<' ';
    }
    return 0;
}
