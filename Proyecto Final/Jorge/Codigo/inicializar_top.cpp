#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Estructura estática exacta idéntica a la de tu programa principal
struct ReporteJugador 
{
    char nombreEstudiante[100];   
    int puntajeFinal;
    float tiempoTotalEmpleado;
    int idsPreguntasFalladas[25]; 
    int cantidadFalladas;         
};

int main() 
{
    // Abrimos en modo ios::out para sobreescribir y limpiar cualquier residuo previo
    ofstream archivo("TopScores.dat", ios::out | ios::binary);
    
    if (!archivo.is_open()) 
    {
        cout << "Error critico: No se pudo instanciar el archivo binario.\n";
        return -1;
    }

    ReporteJugador r1;
    
    // REGISTRO DE PRUEBA 1: Un record real alineado en bytes puros
    strcpy_s(r1.nombreEstudiante, "Jorge Delgadillo");
    r1.puntajeFinal = 210;
    r1.tiempoTotalEmpleado = 120.5f;
    r1.cantidadFalladas = 4;
    r1.idsPreguntasFalladas[0] = 4;  // Almacenamiento indexado estático
    r1.idsPreguntasFalladas[1] = 9;
    r1.idsPreguntasFalladas[2] = 12;
    r1.idsPreguntasFalladas[3] = 20;

    // Volcado crudo de la estructura a disco (sizeof(ReporteJugador) exacto)
    archivo.write(reinterpret_cast<const char*>(&r1), sizeof(ReporteJugador));

    // REGISTRO DE PRUEBA 2: Segundo bloque para demostrar que lee múltiples registros
    ReporteJugador r2;
    strcpy_s(r2.nombreEstudiante, "Estudiante Anonimo");
    r2.puntajeFinal = 150;
    r2.tiempoTotalEmpleado = 145.2f;
    r2.cantidadFalladas = 0; // Rendimiento perfecto ficticio

    archivo.write(reinterpret_cast<const char*>(&r2), sizeof(ReporteJugador));

    archivo.close();
    
    cout << "==================================================================\n";
    cout << "[SISTEMA]: Base de datos 'TopScores.dat' inicializada con exito.\n";
    cout << "[INFO]: Se han insertado 2 registros estaticos alineados en bytes.\n";
    cout << "==================================================================\n";
    
    return 0;
}
