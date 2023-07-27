#include <iostream>
#include <fstream>

using namespace std;

class Ventas {
private:
    float ventas[13][16];
    float ventasxsucursal[15];
    float ventasxmes[12];
    fstream archivo;

public:
    int recibir_informacion()
    {
        int sucursales, meses;
        //Evalúa ingreso correcto de sucursales.
        bool error_ingreso = true;
        while(error_ingreso == true) {
            cout << "Ingresar numero de sucursales (Maximo 15)>>";
            cin >> sucursales;
            if (sucursales > 15 or sucursales <= 0)
            {
                cout <<"El número de sucursales debe estar entre 1 y 15. Intente nuevamente." << endl;
            }
            else
            {
                error_ingreso = false;
            }
        }
        //Evalúa ingreso correcto de meses.
        error_ingreso = true;
        while(error_ingreso == true) {
            cout << "Ingresar numero de meses (Maximo 12)>>";
            cin >> meses;
            if (meses > 15 or meses <= 0)
            {
                cout <<"El número de meses debe estar entre 1 y 12. Intente nuevamente." << endl;
            }
            else
            {
                error_ingreso = false;
            }
        }
        //Guarda datos ingresados en LA matriz.
        for(int i = 0; i <= meses; ++ i) {
            for (int j = 0; j < sucursales; ++j) {
                cout << "Ingrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ">>";
                cin >> ventas[i][j];
                cout << ventas[i][j];
            }
        }
    }

    int crear_respaldo()
    {
        archivo.open("archivo.txt",ios::out);
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 16; ++j) {
                archivo << ventas[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
    }
    //empleado o directivo
    void mostrar_ventas(){}
    //directivo
    int leer_respaldo(){}
    void mayor_venta(){}
    void mostrar_promedioxmes(){}
    void mostrar_mayorpromedioxmes(){}




};





int main() {
    Ventas ventatest;
    ventatest.recibir_informacion();
    ventatest.crear_respaldo();
    return 0;
}
