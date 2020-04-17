#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int counter = 0, maxCounter = 0;
    
    while (n)
    {
        const auto rem = n % 2;        
        counter = (counter + rem) * rem;
        maxCounter = max(counter, maxCounter);        
        n >>= 1;
    }
    
    cout << maxCounter << endl;
        
    return 0;
}
