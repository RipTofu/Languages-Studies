//Suma-resta
//Entidad base: operacion | Entidades derivadas: suma y resta
#include <iostream>
using namespace std;

class operacion{
protected:
    int numero1, numero2;

public:
    void cargar_datos(int num1, int num2)
    {
        numero1 = num1;
        numero2 = num2;
    }
};

class suma: public operacion{
public:
    void operacion()
    {
        cout << numero1 + numero2 << endl;
    }
};

class resta: public operacion{
public:
    void operacion()
    {
        cout << numero1 - numero2 << endl;
    }
};

/*int main() {
    resta resta1;
    resta1.cargar_datos(3, 4);
    resta1.operacion();
    return 0;
}
*/
