#include <iostream>
using namespace std;
int recursiveFactorial(int n);


int main(int argc, const char * argv[]) 
{

    cout << "Testing recursive Factorial" << endl;
    for(int i=0; i<=5; i++)
    {
        cout << recursiveFactorial(i) << endl;
    }
    
    
    cout << endl;
    return 0;
}


int recursiveFactorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * recursiveFactorial(n-1);
    }
}
