#include <iostream>
using namespace std;

void solicitud_datos();

void evaluar_edad(int anio_nac) {
    int anio_act = 2024;
    int edad = anio_act - anio_nac;
    cout << edad;
    if(edad < 17 && edad > 0){
        cout << "Menor de edad. No puede ingresar.";
    }
    else if(edad >= 19){
        cout << "Mayor de edad. Ingreso permitido.";
    }
    else if(edad == 18){
        int mes_nac;
        int mes_act = 2;
        cout << "Ingrese mes de nacimiento en numero>> ";
        cin >> mes_nac;
        if(mes_nac >= mes_act){
            cout << "Mayor de edad. Ingreso permitido.";
        }
        else{
            cout << "Menor de edad. No puede ingresar.";
        }
    }
    else{
        cout << "Ingreso incorrecto. Reintentar.\n";
        solicitud_datos();
    }
}

void solicitud_datos(){
    int anio_nac;
    cout << "Ingresar anio de nacimiento>> ";
    cin >> anio_nac;
    evaluar_edad(anio_nac);

};



main() {
    solicitud_datos();
    return 0;
}
