#include <iostream>

void rotate(int ind, int n, int arr[])
{
    int buff;
    for (ind; ind < n - 1; ind++)
        buff = arr[ind], arr[ind] = arr[ind + 1], arr[ind + 1] = buff;
}

void someFunc(int ind, int n, int arr[])
{
    int buff;
    if (ind != n)
    for (int i = ind; i < n; i++) {
        buff = arr[ind], arr[ind] = arr[i], arr[i] = buff;
        someFunc(ind + 1, n, arr);
    }
    else
    {
        for (int i = 0; i < n; i++)
            std::cout << arr[i];
        std::cout << std::endl;
    }
    rotate(ind, n, arr);
}

int main()
{
    const int n = 4;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    someFunc(0, n, arr);
    return 0;
}