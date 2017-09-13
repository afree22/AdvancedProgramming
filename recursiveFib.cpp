#include <iostream>
using namespace std;
int recursiveFib(int n);

int main(int argc, const char * argv[]) {
    cout << "Testing recursive Fib" << endl;
    for(int i=0; i<=5; i++)
    {
        cout << recursiveFib(i) << endl;
    }
    
    cout << endl;
    return 0;
}


int recursiveFib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return recursiveFib(n-1) + recursiveFib(n-2);
    }
}
