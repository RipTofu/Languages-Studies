#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
int main()
{
    float sumatoria = 0, desvest, calculo1, prom, N1,N2,N3,N4,N5;
    cout << "ingresar valor 1>>";
    cin >> N1;
    cout << "ingresar valor 2>>";
    cin >> N2;
    cout << "ingresar valor 3>>";
    cin >> N3;
    cout << "ingresar valor 4>>";
    cin >> N4;
    cout << "ingresar valor 5>>";
    cin >> N5;
    float nums[5] = {N1, N2, N3, N4, N5};
    calculo1 = 1/4;
    prom = (N1 + N2 + N3+ N4 + N5) / 5;
    for(int i=0; i<=5;i++)
    {
        sumatoria = sumatoria + pow(2.0, nums[i] - prom);
    }
    desvest = sqrt(calculo1 + sumatoria);
    cout << "s = " << sumatoria;
}
