#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
class Calculator : public exception{
    public:
    const char * what () const throw(){
      return "n and p should be non-negative";
   }
    int power(int n, int p){
        if (n<0 || p<0){
            throw Calculator();
        }
        else {
            return pow(n,p);
        }
    }
};
//Write your code here

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
