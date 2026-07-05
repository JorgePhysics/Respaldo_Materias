#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void estudiantesPorCarrera (int n){
    int innovacion = rand()%(n);
    cout << "Inscritos en Ingenieria e Innovacion Empresarial " << innovacion << endl;
    int meca = rand()%(n - innovacion);
    cout << "Inscritos en Ingeniería Mecatronica " << meca << endl;
    int disenio = rand()%(n - innovacion - meca);
    cout << "Incritos en Disenio digital " << disenio << endl;
    int sistemas = n - (innovacion + meca + disenio);
    cout << "Incritos en Ingenieria de Sistemas " << sistemas << endl;
}

int materias (){
    int m = rand()%(6 - 3 + 1) + 3;
    return m;
}

void materiasPorCiclo(int materias) {
    int segundo = rand()%(materias);
    cout << "De segundo semestre hay " << segundo << " materias" << endl;
    int tercero = rand()%(materias - segundo);
    cout << "De tercer semestre hay " << tercero << " materias " << endl;
    int cuarto = rand()%(materias - segundo - tercero);
    cout << "De cuarto semestre hay " << cuarto << " materias" << endl;
    int quinto = materias - (segundo + tercero + cuarto);
    cout << "De quinto semestre hay " << quinto << " materias " << endl;
}

int main (){
    srand(time(NULL));
    int n;
    cout << "Ingrese la cantidad de estudiantes: " << endl;
    cin >> n;
    cout << "===============================" << endl;
    estudiantesPorCarrera(n);
    cout << "===============================" << endl;
    int totalMaterias = 0;
    for(int i = 1; i <= n; i++){
        int m = materias();
        cout << "El estudiante " << i << " toma " << m << " materias" << endl;
        totalMaterias += m;
    }
    cout << "El total de materias es: " << totalMaterias << endl;
    cout << "===============================" << endl;
    materiasPorCiclo(totalMaterias);
    cout << "===============================" << endl;
    double totalDinero = totalMaterias * 5 * 525.0;
    cout << "El total de dinero recaudado por la UCB es: " << totalDinero << endl;
    return 0;
}