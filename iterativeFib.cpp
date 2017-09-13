#include <iostream>
using namespace std;
int iterativeFib(int n);

int main(int argc, const char * argv[]) {
     //insert code here...

    cout << "Testing iterative Fib" << endl;
    for(int i=0; i<=5; i++)
    {
        cout << iterativeFib(i) << endl;
    }
  
    cout << endl;
    return 0;
}

int iterativeFib(int n)
{
    int f[n+1]; //1 step
    
    f[0] = 0; //2 steps
    f[1] = 1; //2 steps
    
    for (int i = 2; i <= n; i++) //2 steps for initial declaration of i and comparison
    {
        f[i] = f[i-1] + f[i-2]; //5 steps * (n-1) (3 for array access,
                                //1 for assignment and 1 for addition)
    } //3 steps*(n-1) ( i<=n; i++)
    
    return f[n];
}
