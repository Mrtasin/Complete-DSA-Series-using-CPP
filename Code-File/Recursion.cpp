#include<iostream>
using namespace std;

int SumN(int n) {
    if(n == 1)
        return 1;
    return (n + SumN(n-1));
}

int SumOfOdd(int n) {
    if(n == 1)
        return 1;
    return ((n*2)-1 + SumOfOdd(n-1));
}

int SumOfEven(int n)    {
    if(n == 1)
        return 2;
    return ((n*2) + SumOfEven(n-1));
}

int SumOfSquare(int n)   {
    if(n == 1)
        return 1;
    return ((n*n) + SumOfSquare(n-1));
}

int Factorial(int n)    {
    if(n == 0 || n == 1)
        return 1;
    return (n*Factorial(n-1));
}

int SumOfDigites(int n) {
    if(10>n)
        return n;
    return ((n%10) + SumOfDigites(n/10));
}

void PrintBinary(int n) {
    if(n)   {
        PrintBinary(n/2);
        cout<<n%2;
    }
}

int Fibonacci(int n)    {
    if(n == 0 || n == 1)
        return n;
    return (Fibonacci(n-1) + Fibonacci(n-2));
}

int main()  {
    PrintBinary(10);
    cout<<endl;
    return 0;
}
