#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int cantidadMaterias(){
    int c = rand()%(8 - 2 + 1) + 2;
    return c;
}

int creditos (int cantidad){
    int cr = 0;
    int idiomas = rand()%(cantidad);
    cr += idiomas * 3;
    int normales = rand()%(cantidad - idiomas);
    cr += normales * 5;
    int labo = cantidad - (idiomas + normales);
    cr += labo * 7;
    cout << "Cantidad de materias: " << cantidad << endl;
    cout << "\tIdiomas: " << idiomas << " Creditos: " << idiomas * 3 << endl;
    cout << "\tNormales: " << normales << " Creditos: " << normales * 5 << endl;
    cout << "\tLaboratorio: " << labo << " Creditos: " << labo * 7 << endl;
    cout << "\tTotal de creditos: " << cr << endl;
    return cr;
}

int main (){ 
    srand(time(NULL));
    int n;
    cout << "Ingrese la cantidad de estudiantes: " << endl;
    cin >> n;
    int cre = 0;
    for(int i = 1; i <= n; i++){
        cout << "==================================" << endl;
        cout << "Las materias del estudiante " << i << ":" << endl;
        int materias = cantidadMaterias();
        cre += creditos(materias);
    }

    cout << "El total de creditos es: " << cre << endl;
    double dinero = cre * 350.0;
    cout << "La ganancia de la UCB es: " << dinero << endl;
    return 0;
}