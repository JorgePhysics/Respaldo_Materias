#include <windows.h> 
#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <cstring> 
#include <cstdlib> 

using namespace std;

// ============================================================================
// PARTE 1: ESTRUCTURAS DE DATOS ESTÁTICAS DE BAJO NIVEL (SIN VECTORES)
// ============================================================================

struct PreguntaQuiz 
{
    int idPregunta;               
    char rutaImagen[100];         
    char enunciado[250];          
    
    // Variables de texto planas e independientes exigidas en la pizarra
    char opcionA[100];
    char opcionB[100];
    char opcionC[100];
    char opcionD[100];
    
    int respuestaCorrecta;        
    char categoria[50];           
};

struct EstadoJuego 
{
    int pantallaActual;           // 0: Menú, 1: Quiz, 2: Reporte Final, -1: Salir
    int indicePreguntaActual;     // Posición de lectura secuencial (0 a 24)
    int puntajeAcumulado;         
    
    int joystickX;                
    int joystickY;                
    bool botonAPresionado;        
    bool botonBPresionado;        
    bool botonCPresionado;        
    bool botonDPresionado;        
    bool botonEPresionado;        
    bool botonKPresionado;        // Captura el pulsador mecánico del Joystick
};

struct ReporteJugador 
{
    char nombreEstudiante[100];   
    int puntajeFinal;
    float tiempoTotalEmpleado;
    int idsPreguntasFalladas[25]; // Arreglo fijo (máximo 25 preguntas)
    int cantidadFalladas;         // Contador de cuántas preguntas falló
};

// ============================================================================
// PARTE 2: PROTOCOLO SERIAL CABLEADO (API DE WINDOWS)
// ============================================================================

HANDLE iniciarComunicacionSerial(const char* puertoCOM) 
{
    HANDLE hSerial = CreateFileA(puertoCOM, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE) return hSerial;

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams)) 
    {
        dcbSerialParams.BaudRate = CBR_9600; 
        dcbSerialParams.ByteSize = 8;
        dcbSerialParams.StopBits = ONESTOPBIT;
        dcbSerialParams.Parity   = NOPARITY;
        SetCommState(hSerial, &dcbSerialParams);
    }
    return hSerial;
}

void procesarTramaSerial(HANDLE hSerial, EstadoJuego &estadoActual) 
{
    char buffer[256];
    DWORD bytesRead;
    static char tramaAcumulada[512] = ""; 

    if (ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) 
    {
        buffer[bytesRead] = '\0';
        strncat(tramaAcumulada, buffer, sizeof(tramaAcumulada) - strlen(tramaAcumulada) - 1);

        char* posFinal = strchr(tramaAcumulada, '\n');
        if (posFinal != NULL) 
        { 
            int longitudTrama = posFinal - tramaAcumulada;
            char trama[256] = "";
            strncpy_s(trama, tramaAcumulada, longitudTrama); 
            trama[longitudTrama] = '\0'; 
            
            int longitudRestante = strlen(posFinal + 1);
            memmove(tramaAcumulada, posFinal + 1, longitudRestante + 1); 
            
            int valores[12];
            int contadorTokens = 0;
            char* next_token = NULL;
            char* token = strtok_s(trama, ",", &next_token); 

            while (token != NULL && contadorTokens < 12) 
            {
                valores[contadorTokens++] = atoi(token); 
                token = strtok_s(NULL, ",", &next_token);      
            }

            if (contadorTokens >= 7) 
            {
                estadoActual.joystickX = valores[0];
                estadoActual.joystickY = valores[1];
                estadoActual.botonAPresionado = (valores[2] == 1);
                estadoActual.botonBPresionado = (valores[3] == 1);
                estadoActual.botonCPresionado = (valores[4] == 1);
                estadoActual.botonDPresionado = (valores[5] == 1);
                estadoActual.botonEPresionado = (valores[6] == 1); 
                
                if (contadorTokens >= 8) 
                {
                    estadoActual.botonKPresionado = (valores[7] == 1);
                } 
                else 
                {
                    estadoActual.botonKPresionado = (valores[contadorTokens - 1] == 1);
                }
            }
        }
    }
}

// ============================================================================
// PARTE 3: MANEJO DE RECURSOS ASÍNCRO-NATIVOS DE WINDOWS
// ============================================================================

void limpiarPantalla() 
{ 
    system("cls"); 
}

void desplegarRecursoWindows(const char* rutaRecurso) 
{
    string comando = "start \"\" \"" + string(rutaRecurso) + "\"";
    system(comando.c_str());
}

void abrirGuiaRepaso(int nivel) 
{
    string comando = "";
    if (nivel == 0) comando = "start notepad.exe C:\\Codigo\\Archivos\\Guia_Intro_Circuitos.txt";
    else if (nivel == 1) comando = "start notepad.exe C:\\Codigo\\Archivos\\Guia_Circuitos_1.txt";
    else if (nivel == 2) comando = "start notepad.exe C:\\Codigo\\Archivos\\Guia_Circuitos_2.txt";
    else if (nivel == 3) comando = "start notepad.exe C:\\Codigo\\Archivos\\Guia_Circuitos_3.txt";
    else comando = "start notepad.exe C:\\Codigo\\Archivos\\Guia_Circuitos_Digitales.txt";

    system(comando.c_str());
}

// FUNCIÓN CORREGIDA: Bloquea el flujo y espera a que el usuario levante el dedo por completo
char capturarBotonShield(HANDLE hSerial, EstadoJuego &estado) 
{
    while (true) 
    {
        procesarTramaSerial(hSerial, estado);
        
        char botonDetectado = ' ';

        if (estado.botonAPresionado) botonDetectado = 'A';
        else if (estado.botonBPresionado) botonDetectado = 'B';
        else if (estado.botonCPresionado) botonDetectado = 'C';
        else if (estado.botonDPresionado) botonDetectado = 'D';
        else if (estado.botonEPresionado) botonDetectado = 'E'; 
        else if (estado.botonKPresionado) botonDetectado = 'K'; 
        
        // RESPALDO POR TECLADO
        else if (GetAsyncKeyState(0x4B) & 0x8000) botonDetectado = 'K'; // Tecla K
        else if (GetAsyncKeyState(0x41) & 0x8000) botonDetectado = 'A'; // Tecla A

        // SI SE DETECTÓ ENTRADA, CONTROLAMOS EL FLANCO DE BAJADA (ESPERA A QUE SE SUELTE)
        if (botonDetectado != ' ') 
        {
            bool botonSiguePresionado = true;
            while (botonSiguePresionado) 
            {
                procesarTramaSerial(hSerial, estado);
                
                bool tecladoK = (GetAsyncKeyState(0x4B) & 0x8000);
                bool tecladoA = (GetAsyncKeyState(0x41) & 0x8000);
                
                // Solo se libera cuando el Shield y el teclado reporten reposo absoluto (0)
                if (!estado.botonAPresionado && !estado.botonBPresionado && 
                    !estado.botonCPresionado && !estado.botonDPresionado && 
                    !estado.botonEPresionado && !estado.botonKPresionado && 
                    !tecladoK && !tecladoA) 
                {
                    botonSiguePresionado = false; 
                }
                Sleep(10); 
            }
            return botonDetectado; 
        }

        Sleep(15); 
    }
}

void pedirDatosJugador(ReporteJugador &reporte) 
{
    cout << "\n========================================================\n";
    cout << "               NUEVO INGRESO DE ESTUDIANTE                \n";
    cout << "========================================================\n";
    cout << " Escriba su nombre para iniciar la sesion: ";
    
    cin.clear();
    fflush(stdin);
    cin.getline(reporte.nombreEstudiante, 100);
    
    reporte.cantidadFalladas = 0;
}

void guardarPuntajeTop(const ReporteJugador &reporte) 
{
    ofstream archivoBinario("TopScores.dat", ios::binary | ios::app);
    if (archivoBinario.is_open()) 
    {
        archivoBinario.write((const char*)&reporte, sizeof(ReporteJugador));
        archivoBinario.close();
        cout << "\n[SISTEMA]: Datos de sesion respaldados en 'TopScores.dat' con exito.\n";
    } 
    else 
    {
        cout << "Error: No se pudo acceder al disco para guardar los datos.\n";
    }
}

void leerPuntajesTop() 
{
    ifstream archivoBinario("TopScores.dat", ios::binary);
    if (archivoBinario.is_open()) 
    {
        ReporteJugador reporte;
        cout << "\n=== TOP PUNTAJES GUARDADOS (BINARIO) ===\n";
        cout << "========================================\n";
        
        while (archivoBinario.read((char*)&reporte, sizeof(ReporteJugador))) 
        {
            cout << "Estudiante: " << reporte.nombreEstudiante 
                 << " | Puntaje: " << reporte.puntajeFinal << "/250 | Errores: " << reporte.cantidadFalladas << "\n";
        }
        archivoBinario.close();
        cout << "========================================\n";
    } 
    else 
    {
        cout << "\nNo hay puntajes guardados aun.\n";
    }
    system("pause");
}

bool leerPreguntaBinaria(int indice, PreguntaQuiz &preguntaDestino) 
{
    ifstream archivoBinario("preguntas.dat", ios::in | ios::binary);
    if (!archivoBinario.is_open()) return false;

    streampos posicion = indice * sizeof(PreguntaQuiz);
    archivoBinario.seekg(posicion); 

    archivoBinario.read(reinterpret_cast<char*>(&preguntaDestino), sizeof(PreguntaQuiz));
    archivoBinario.close();
    return true;
}

// ============================================================================
// MOTOR PRINCIPAL DE LA MÁQUINA DE ESTADOS
// ============================================================================
int main() 
{
    cout << "UCB Embedded Engine: Abriendo conexion por cable USB en COM6...\n";
    HANDLE hSerial = iniciarComunicacionSerial("\\\\.\\COM6");

    if (hSerial == INVALID_HANDLE_VALUE) 
    {
        cerr << "\n[CONEXION FALLIDA]: No se detecto el Arduino Uno en COM6.\n";
        system("pause");
        return -1;
    }

    Sleep(2000); 

    EstadoJuego estado = {0, 0, 0, 512, 512, false, false, false, false, false, false};
    ReporteJugador reporte = {"", 0, 0.0f, {0}, 0};
    PreguntaQuiz pActual; 

    int preguntasRespondidasNivel = 0;
    int puntajeNivelActual = 0;
    int imagenDesplegadaId = -1;  
    const int TOTAL_PREGUNTAS = 25; 

    while (estado.pantallaActual != -1) 
    {
        
        // --- PANTALLA 0: MENÚ ---
        if (estado.pantallaActual == 0) 
        {
            limpiarPantalla();
            cout << "========================================================\n";
            cout << "       CIRCUQUIZ INTERACTIVO BINARIO COMPLETO - UCB     \n";
            cout << "========================================================\n\n";
            cout << " ENLACE: CABLE [COM6] | PERSISTENCIA: ARCHIVO BINARIO (.DAT)\n\n";
            cout << " [BOTON A] -> Comenzar Evaluacion Completa (25 Items)\n";
            cout << " [BOTON B] -> Visualizar Historial de Puntajes (TopScores.dat)\n";
            cout << "Esperando enlace de hardware... ";

            char accion = capturarBotonShield(hSerial, estado);
            if (accion == 'A') 
            {
                pedirDatosJugador(reporte);
                
                cin.clear();
                
                estado.pantallaActual = 1;
                estado.indicePreguntaActual = 0;
                estado.puntajeAcumulado = 0;
                preguntasRespondidasNivel = 0;
                puntajeNivelActual = 0;
                reporte.cantidadFalladas = 0; 
                imagenDesplegadaId = -1; 
                
                Sleep(500); // Estabilidad inicial
            } 
            else if (accion == 'B') 
            {
                clearerr(stdin); // Limpieza de flujo
                leerPuntajesTop();
            } 
            else if (accion == 'E') 
            {
                estado.pantallaActual = -1;
            }
        }

        // --- PANTALLA 1: QUIZ ACTIVO ---
        else if (estado.pantallaActual = 1) 
        {
            limpiarPantalla();
            
            if (!leerPreguntaBinaria(estado.indicePreguntaActual, pActual)) 
            {
                cout << "Error de persistencia binaria al procesar el indice: " << estado.indicePreguntaActual << "\n";
                system("pause");
                estado.pantallaActual = 0;
                continue;
            }

            // Despliegue único controlado
            if (imagenDesplegadaId != pActual.idPregunta) 
            {
                desplegarRecursoWindows(pActual.rutaImagen);
                imagenDesplegadaId = pActual.idPregunta;
            }

            cout << "========================================================\n";
            cout << " CATEGORIA: " << pActual.categoria << " | Item: [" << (estado.indicePreguntaActual + 1) << "/" << TOTAL_PREGUNTAS << "]\n";
            cout << "========================================================\n\n";
            cout << pActual.enunciado << "\n\n";

            cout << " [BOTON A] -> " << pActual.opcionA << "\n";
            cout << " [BOTON B] -> " << pActual.opcionB << "\n";
            cout << " [BOTON C] -> " << pActual.opcionC << "\n";
            cout << " [BOTON D] -> " << pActual.opcionD << "\n\n";
            cout << "--------------------------------------------------------\n";
            cout << " [BOTON E] -> Abortar y volver al Menu\n";
            cout << "--------------------------------------------------------\n\n";
            cout << "Presione un boton en el Shield: ";

            char respuesta = capturarBotonShield(hSerial, estado);
            if (respuesta == 'E') 
            {
                estado.pantallaActual = 0;
                continue;
            }

            int indexRespuesta = respuesta - 'A'; 
            preguntasRespondidasNivel++;

            if (indexRespuesta == pActual.respuestaCorrecta) 
            {
                estado.puntajeAcumulado += 10;
                puntajeNivelActual += 10;
            } 
            else 
            {
                reporte.idsPreguntasFalladas[reporte.cantidadFalladas] = pActual.idPregunta;
                reporte.cantidadFalladas++;
            }

            // CONTROL PEDAGÓGICO DE RENDIMIENTO POR BLOQUE
            if (preguntasRespondidasNivel == 5) 
            {
                if (puntajeNivelActual < 30) 
                { 
                    bool alertaActiva = true;
                    int nivelBloque = pActual.idPregunta / 5;
                    if(pActual.idPregunta % 5 == 0) nivelBloque--; 
                    
                    while (alertaActiva) 
                    {
                        limpiarPantalla();
                        cout << "########################################################\n";
                        cout << "         DEBES REPASAR EL CONTENIDO DE LA MATERIA        \n";
                        cout << "########################################################\n\n";
                        cout << "Rendimiento menor al 60% en el bloque binario detectado.\n";
                        cout << "Puntaje del bloque: " << puntajeNivelActual << " / 50 pts.\n\n";
                        cout << " [TECLA K / PALANCA] -> ABRIR ARCHIVO DE REPASO (.TXT)\n";
                        cout << " [BOTON A] -> Confirmar Repaso, Cerrar Alerta y Continuar\n\n";
                        cout << "Esperando interaccion... ";

                        char btnAlerta = capturarBotonShield(hSerial, estado);
                        if (btnAlerta == 'K') 
                        {
                            cout << "\n[SISTEMA]: Desplegando archivo guia...";
                            abrirGuiaRepaso(nivelBloque);
                            Sleep(600); 
                        } 
                        else if (btnAlerta == 'A') 
                        {
                            alertaActiva = false; 
                        }
                    }
                }
                puntajeNivelActual = 0;
                preguntasRespondidasNivel = 0;
            }

            if (estado.indicePreguntaActual + 1 < TOTAL_PREGUNTAS) 
            {
                estado.indicePreguntaActual++;
                
                // Forzamos el reset de flancos lógicos para la nueva pregunta
                estado.botonAPresionado = false;
                estado.botonBPresionado = false;
                estado.botonCPresionado = false;
                estado.botonDPresionado = false;
                estado.botonEPresionado = false;
                estado.botonKPresionado = false;
                
                Sleep(100); 
            } 
            else 
            {
                estado.pantallaActual = 2; 
            }
        }

        // --- PANTALLA 2: REPORTE DE RESULTADOS ---
        else if (estado.pantallaActual == 2) 
        {
            limpiarPantalla();
            reporte.puntajeFinal = estado.puntajeAcumulado;
            guardarPuntajeTop(reporte);

            cout << "========================================================\n";
            cout << "                  EVALUACION COMPLETADA                 \n";
            cout << "========================================================\n\n";
            cout << " Estudiante: " << reporte.nombreEstudiante << "\n";
            cout << " Puntuacion Consolidada: " << reporte.puntajeFinal << " Puntos.\n\n";
            
            if (reporte.cantidadFalladas > 0) 
            {
                cout << " Codigos de Preguntas a Reforzar: ";
                for (int i = 0; i < reporte.cantidadFalladas; i++) 
                {
                    cout << reporte.idsPreguntasFalladas[i] << " ";
                }
                cout << "\n";
            } 
            else 
            {
                cout << " ¡Felicidades! Rendimiento perfecto sin errores.\n";
            }
            cout << "\n\n";

            cout << " [BOTON A] -> Regresar al Menu Inicial\n";
            cout << "Comando Hardware: ";

            char fin = capturarBotonShield(hSerial, estado);
            if (fin == 'A') estado.pantallaActual = 0;
            else if (fin == 'E') estado.pantallaActual = -1;
        }
    }

    CloseHandle(hSerial);
    return 0;
}
