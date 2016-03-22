#inlcude <iostream>
/*
Divide-and-conquer method to calculate pow(x, n), O(log n)
*/
int Pow(int , int);
int main()
{
    int x = 2, n = 10;
    std::cout << Pow(x, n) << std::endl;
    return 0;
}

int Pow(int x, int n)
{
    if(n == 1)
        return x;
    if(n % 2 == 0)
        return Pow(x, n / 2) * Pow(x, n / 2);	//return Pow
    else
        return x * Pow(x, (n - 1) / 2) * Pow(x, (n - 1) / 2);
}

/*
Iteration method to calculate pow(x, n), O(n)
*/
int main()
{
    int x = 2, n = 10;
    int result = 1;
    for(int i = 1; i <= 10; i++)
        result *= x;
    cout << result;
    return 0;
}
