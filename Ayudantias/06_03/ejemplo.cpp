//ejemplo de simplificar el for
#include <iostream>

#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main (){
    forn(i, 10){
        cout << i << " ";
    }
}