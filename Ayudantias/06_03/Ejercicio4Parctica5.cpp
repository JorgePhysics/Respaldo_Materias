#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int numeroAleatorio (){
    int r = rand()%(1000 - 10 + 1) + 10;
    return r;
}

int valorTarjeta (){
    int indice = rand()%(6 - 1 + 1) + 1;
    int valor = 0;
    switch(indice){
        case 1:
            valor = 10;
            break;
        case 2:
            valor = 20;
            break;
        case 3:
            valor = 30;
            break;
        case 4:
            valor = 50;
            break;
        case 5: 
            valor = 100;
            break;
        case 6:
            valor = 200;
            break;
        default:
            cout << "Numero aleatorio incorrecto" << endl;
            break;
    }

    return valor;
}

int cantidadTarjetas (int dinero, int tarjeta){
    int c = dinero / tarjeta;
    return c;
}

void calculosFinales (int dinero, int cantidad, int tarjeta){
    cout << "Tiene " << dinero << " dinero" << endl;
    cout << "Compra la tarjeta de " << tarjeta << " Bs" << endl;
    cout << "Compra " << cantidad << " tarjetas" << endl;
    switch(tarjeta){
        case 10:
            cout << "Su bonificacion es de " << 5 * cantidad << " Bs" << endl; 
            break;
        case 20:
            cout << "Su bonificacion es de " << 10 * cantidad << " Bs" << endl;
            break;
        case 30:
            cout << "Su bonificacion es de " << 15 * cantidad << " Bs" << endl;
            break;
        case 50:
            cout << "Su bonificacion es de " << 25 * cantidad << " Bs" << endl;
            break;
        case 100: 
            cout << "Su bonificacion es de " << 50 * cantidad << " Bs" << endl;
            break;
        case 200:
            cout << "Su bonificacion es de " << 100 * cantidad << " Bs" << endl;
            break;
        default:
            cout << "No recibe bonificacion" << endl;
            break;
    }

    int cambio = dinero - (cantidad * tarjeta);
    cout << "Su cambio es de " << cambio << " Bs" << endl;

}

int main (){
    srand(time(NULL));
    int n;
    cout << "Ingrese la cantidad de personas" << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        int dinero = numeroAleatorio();
        int tarjeta = valorTarjeta();
        int cantidad = cantidadTarjetas(dinero, tarjeta);
        cout << "==============================" << endl;
        calculosFinales(dinero, cantidad, tarjeta);
    }

    return 0;
}