#include <iostream>
using namespace std;
// true es par
// false es impar
bool esPar (int n){
    bool p = true;

    if(n % 2 == 0){
        p = true;
    } else {
        p = false;
    }

    return p;
}

int main (){
    int n;
    cout << "Ingrese un numero: " << endl;
    cin >> n;

    bool par = esPar(n);
    if(par){
        cout << "Es un numero par" << endl;
    } else {
        cout << "Es un numero impar" << endl;
    }
}