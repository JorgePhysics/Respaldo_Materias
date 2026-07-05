// ============================================================================
// PROGRAMA AUXILIAR: GENERADOR DEL BANCO DE DATOS BINARIO COMPLETO (25 ITEMS)
// UBICACIÓN RECOMENDADA: C:/Codigo/generar_banco.cpp
// REQUISITOS DOCENTE: CERO VECTORES + ARREGLOS EXPLÍCITOS NOMBRADOS "opcion"
// ============================================================================

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Estructura estática idéntica a la del programa del juego (Exigencia de la Pizarra)
struct PreguntaQuiz 
{
    int idPregunta;               
    char rutaImagen[100];         
    char enunciado[250];          
    
    // Variables de texto planas e independientes exigidas por el docente
    char opcionA[100];
    char opcionB[100];
    char opcionC[100];
    char opcionD[100];
    
    int respuestaCorrecta; // 0=A, 1=B, 2=C, 3=D
    char categoria[50];           
};

// Función de bajo nivel para serializar la estructura en el flujo binario de Windows
void escribirPregunta(ofstream &archivo, const PreguntaQuiz &p) 
{
    archivo.write(reinterpret_cast<const char*>(&p), sizeof(PreguntaQuiz));
}

int main() 
{
    ofstream archivo("preguntas.dat", ios::out | ios::binary);
    if (!archivo.is_open()) 
    {
        cout << "Error critico: No se pudo crear el archivo binario preguntas.dat.\n";
        return -1;
    }

    PreguntaQuiz p;

    // ========================================================================
    // NIVEL 0: INTRODUCCIÓN A LOS CIRCUITOS
    // ========================================================================
    p.idPregunta = 1; 
    strcpy_s(p.categoria, "Intro a los Circuitos (Nivel 0)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 0/n0_p1.png");
    strcpy_s(p.enunciado, "Fisicamente, ¿cual es la funcion principal de una fuente de voltaje en un lazo cerrado?");
    strcpy_s(p.opcionA, "Crear electrones de la nada"); 
    strcpy_s(p.opcionB, "Aumentar la resistencia");
    strcpy_s(p.opcionC, "Proporcionar diferencia de potencial"); 
    strcpy_s(p.opcionD, "Interrumpir el paso");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 2; 
    strcpy_s(p.categoria, "Intro a los Circuitos (Nivel 0)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 0/n0_p2.png");
    strcpy_s(p.enunciado, "Si un circuito tiene un cable suelto o un interruptor apagado, ¿como se define este estado?");
    strcpy_s(p.opcionA, "Circuito Cerrado"); 
    strcpy_s(p.opcionB, "Circuito Abierto");
    strcpy_s(p.opcionC, "Cortocircuito de linea"); 
    strcpy_s(p.opcionD, "Malla Equivalente");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 3; 
    strcpy_s(p.categoria, "Intro a los Circuitos (Nivel 0)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 0/n0_p3.png");
    strcpy_s(p.enunciado, "En un circuito abierto, ¿cual es el valor teorico de la resistencia del aire y de la corriente?");
    strcpy_s(p.opcionA, "R = 0 y Corriente infinita"); 
    strcpy_s(p.opcionB, "R infinita y Corriente = 0");
    strcpy_s(p.opcionC, "R = 100 y Corriente variable"); 
    strcpy_s(p.opcionD, "R nula y Corriente nula");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 4; 
    strcpy_s(p.categoria, "Intro a los Circuitos (Nivel 0)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 0/n0_p4.png");
    strcpy_s(p.enunciado, "¿Que condicion de peligro ocurre al unir el polo positivo y negativo de una fuente sin carga?");
    strcpy_s(p.opcionA, "Circuito ideal"); 
    strcpy_s(p.opcionB, "Aislamiento completo");
    strcpy_s(p.opcionC, "Cortocircuito"); 
    strcpy_s(p.opcionD, "Divisor de corriente");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 5; 
    strcpy_s(p.categoria, "Intro a los Circuitos (Nivel 0)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 0/n0_p5.png");
    strcpy_s(p.enunciado, "Para comprobar de manera practica el valor de voltaje de una bateria, ¿como se conecta el voltimetro?");
    strcpy_s(p.opcionA, "En serie abriendo el circuito"); 
    strcpy_s(p.opcionB, "En paralelo a las terminales");
    strcpy_s(p.opcionC, "Directo a la toma de tierra"); 
    strcpy_s(p.opcionD, "Mediendo los hilos sueltos");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    // ========================================================================
    // CIRCUITOS ELÉCTRICOS I (NIVEL 1)
    // ========================================================================
    p.idPregunta = 6; 
    strcpy_s(p.categoria, "Circuitos Electricos I (Nivel 1)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 1/n1_p1.png");
    strcpy_s(p.enunciado, "Segun la Ley de Ohm, si duplicamos la resistencia manteniendo el voltaje constante, la corriente:");
    strcpy_s(p.opcionA, "Se duplica linealmente"); 
    strcpy_s(p.opcionB, "Permanece invariable");
    strcpy_s(p.opcionC, "Se reduce a la mitad"); 
    strcpy_s(p.opcionD, "Cae a cero");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 7; 
    strcpy_s(p.categoria, "Circuitos Electricos I (Nivel 1)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 1/n1_p2.png");
    strcpy_s(p.enunciado, "Para medir la corriente electrica real que pasa por un resistor, el amperimetro debe colocarse:");
    strcpy_s(p.opcionA, "En paralelo con la carga"); 
    strcpy_s(p.opcionB, "En serie dentro del lazo");
    strcpy_s(p.opcionC, "Entre las terminales GND"); 
    strcpy_s(p.opcionD, "Sin tocar los cables");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 8; 
    strcpy_s(p.categoria, "Circuitos Electricos I (Nivel 1)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 1/n1_p3.png");
    strcpy_s(p.enunciado, "En un circuito cerrado con tres resistores en SERIE, ¿cual de las siguientes afirmaciones es correcta?");
    strcpy_s(p.opcionA, "La corriente es igual en todos"); 
    strcpy_s(p.opcionB, "El voltaje es igual en todos");
    strcpy_s(p.opcionC, "La resistencia total baja"); 
    strcpy_s(p.opcionD, "Los nodos dividen corriente");
    p.respuestaCorrecta = 0; 
    escribirPregunta(archivo, p);

    p.idPregunta = 9; 
    strcpy_s(p.categoria, "Circuitos Electricos I (Nivel 1)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 1/n1_p4.png");
    strcpy_s(p.enunciado, "Al conectar dos resistores en PARALELO a una fuente de DC, podemos asegurar que:");
    strcpy_s(p.opcionA, "Comparten la misma corriente"); 
    strcpy_s(p.opcionB, "Soportan el mismo voltaje");
    strcpy_s(p.opcionC, "La resistencia equivalente sube"); 
    strcpy_s(p.opcionD, "Se anulan entre si");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 10; 
    strcpy_s(p.categoria, "Circuitos Electricos I (Nivel 1)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 1/n1_p5.png");
    strcpy_s(p.enunciado, "Internamente en un protoboard, ¿como se conectan los cinco orificios de una misma columna central?");
    strcpy_s(p.opcionA, "Estan totalmente aislados"); 
    strcpy_s(p.opcionB, "Tienen una conexion en serie");
    strcpy_s(p.opcionC, "Comparten continuidad comun"); 
    strcpy_s(p.opcionD, "Se une horizontalmente");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    // ========================================================================
    // CIRCUITOS ELÉCTRICOS II (NIVEL 2)
    // ========================================================================
    p.idPregunta = 11; 
    strcpy_s(p.categoria, "Circuitos Electricos II (Nivel 2)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 2/n2_p1.png");
    strcpy_s(p.enunciado, "Cuando se incrementa la frecuencia de la señal en un circuito de CA, ¿que ocurre con la oposicion al paso de corriente de inductores y capacitores?");
    strcpy_s(p.opcionA, "La oposicion aumenta tanto en los inductores como en los capacitores."); 
    strcpy_s(p.opcionB, "La oposicion aumenta en los inductores y disminuye en los capacitores.");
    strcpy_s(p.opcionC, "La oposicion disminuye en los inductores y aumenta en los capacitores."); 
    strcpy_s(p.opcionD, "La oposicion disminuye tanto en los inductores como en los capacitores.");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 12; 
    strcpy_s(p.categoria, "Circuitos Electricos II (Nivel 2)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 2/n2_p2.png");
    strcpy_s(p.enunciado, "En un circuito compuesto unicamente por una resistencia y un capacitor en serie, ¿cual es la relacion de fase entre la corriente y el voltaje?");
    strcpy_s(p.opcionA, "La corriente se encuentra adelantada en fase respecto al voltaje de la fuente."); 
    strcpy_s(p.opcionB, "El voltaje de la fuente se encuentra adelantado exactamente noventa grados.");
    strcpy_s(p.opcionC, "La corriente se encuentra atrasada en fase respecto al voltaje de la fuente."); 
    strcpy_s(p.opcionD, "La corriente y el voltaje de la fuente se encuentran perfectamente en fase.");
    p.respuestaCorrecta = 0; 
    escribirPregunta(archivo, p);

    p.idPregunta = 13; 
    strcpy_s(p.categoria, "Circuitos Electricos II (Nivel 2)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 2/n2_p3.png");
    strcpy_s(p.enunciado, "Cuando un OPAMP ideal trabaja en su region lineal con retroalimentacion negativa, ¿que condiciones se presentan en sus entradas?");
    strcpy_s(p.opcionA, "La diferencia de voltaje es maxima y la corriente que ingresa es infinita."); 
    strcpy_s(p.opcionB, "La diferencia de voltaje es cero y la corriente que ingresa es infinita.");
    strcpy_s(p.opcionC, "La diferencia de voltaje es cero y no ingresa corriente a ninguna terminal."); 
    strcpy_s(p.opcionD, "El voltaje en la entrada inversora se conecta siempre a la tierra fisica.");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 14; 
    strcpy_s(p.categoria, "Circuitos Electricos II (Nivel 2)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 2/n2_p4.png");
    strcpy_s(p.enunciado, "¿Qué le sucede a la capacidad de amplificación de voltaje de un OPAMP real a medida que la frecuencia aumenta significativamente?");
    strcpy_s(p.opcionA, "La amplificación aumenta de forma proporcional al incremento de la frecuencia."); 
    strcpy_s(p.opcionB, "La amplificación disminuye, reduciendo el ancho de banda útil del circuito.");
    strcpy_s(p.opcionC, "La amplificación se mantiene perfectamente constante en cualquier rango."); 
    strcpy_s(p.opcionD, "La amplificación cae a cero de forma inmediata al salir de DC.");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 15; 
    strcpy_s(p.categoria, "Circuitos Electricos II (Nivel 2)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 2/n2_p5.png");
    strcpy_s(p.enunciado, "Si en un amplificador inversor se conecta un capacitor en paralelo con la resistencia de retroalimentacion, ¿que efecto se logra?");
    strcpy_s(p.opcionA, "Las frecuencias altas se amplifican mucho más que las frecuencias bajas."); 
    strcpy_s(p.opcionB, "El circuito bloquea por completo el paso de la corriente continua.");
    strcpy_s(p.opcionC, "Las frecuencias bajas se amplifican, mientras que las altas sufren atenuacion."); 
    strcpy_s(p.opcionD, "El comportamiento del circuito se vuelve totalmente independiente.");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    // ========================================================================
    // CIRCUITOS ELÉCTRICOS III (NIVEL 3)
    // ========================================================================
    p.idPregunta = 16; 
    strcpy_s(p.categoria, "Circuitos Electricos III (Nivel 3)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 3/n3_p1.png");
    strcpy_s(p.enunciado, "¿Cuál es la diferencia fundamental en el principio de operación entre un transistor BJT y un MOSFET?");
    strcpy_s(p.opcionA, "El BJT se controla por voltaje en su terminal, mientras que el MOSFET por corriente."); 
    strcpy_s(p.opcionB, "El BJT se controla por corriente en su terminal, mientras que el MOSFET por voltaje.");
    strcpy_s(p.opcionC, "Ambos se controlan exclusivamente por el flujo de corriente externo."); 
    strcpy_s(p.opcionD, "El MOSFET requiere una corriente constante en su compuerta para encender.");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 17; 
    strcpy_s(p.categoria, "Circuitos Electricos III (Nivel 3)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 3/n3_p2.png");
    strcpy_s(p.enunciado, "Desde el punto de vista del analisis, ¿que caracteristica destaca en la compuerta de un MOSFET ideal en DC?");
    strcpy_s(p.opcionA, "Presenta una resistencia de entrada extremadamente baja."); 
    strcpy_s(p.opcionB, "Se comporta como un cortocircuito directo hacia la terminal de fuente.");
    strcpy_s(p.opcionC, "Presenta una impedancia de entrada infinita, por lo que su corriente es cero."); 
    strcpy_s(p.opcionD, "Permite el paso de corriente en un solo sentido, actuando como diodo.");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 18; 
    strcpy_s(p.categoria, "Circuitos Electricos III (Nivel 3)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 3/n3_p3.png");
    strcpy_s(p.enunciado, "Para que un transistor BJT funcione correctamente como un amplificador de señal lineal, ¿en que region debe polarizarse?");
    strcpy_s(p.opcionA, "Región de saturación."); 
    strcpy_s(p.opcionB, "Región de corte.");
    strcpy_s(p.opcionC, "Región activa directa."); 
    strcpy_s(p.opcionD, "Región de ruptura óhmica.");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 19; 
    strcpy_s(p.categoria, "Circuitos Electricos III (Nivel 3)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 3/n3_p4.png");
    strcpy_s(p.enunciado, "Cuando un MOSFET de enriquecimiento se utiliza como interruptor cerrado (encendido), ¿en que region trabaja principalmente?");
    strcpy_s(p.opcionA, "Región de corte"); 
    strcpy_s(p.opcionB, "Región de saturación o zona activa.");
    strcpy_s(p.opcionC, "Región óhmica o de triodo."); 
    strcpy_s(p.opcionD, "Región de avalancha.");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 20; 
    strcpy_s(p.categoria, "Circuitos Electricos III (Nivel 3)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 3/n3_p5.png");
    strcpy_s(p.enunciado, "¿Cual describe una caracteristica típica del comportamiento termico de un BJT en comparacion con un MOSFET?");
    strcpy_s(p.opcionA, "El BJT es más propenso al embalamiento térmico porque su conduccion aumenta con la T."); 
    strcpy_s(p.opcionB, "El BJT ocupa mucho menos espacio en un circuito integrado que un MOSFET.");
    strcpy_s(p.opcionC, "El BJT no sufre caídas de voltaje internas cuando está conduciendo."); 
    strcpy_s(p.opcionD, "El BJT disipa menos potencia de control en reposo que un MOSFET.");
    p.respuestaCorrecta = 0; 
    escribirPregunta(archivo, p);

    // ========================================================================
    // CIRCUITOS DIGITALES Y COMPUERTAS LÓGICAS (NIVEL 4)
    // ========================================================================
    p.idPregunta = 21; 
    strcpy_s(p.categoria, "Circuitos Digitales (Nivel 4)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 4/n4_p1.png");
    strcpy_s(p.enunciado, "¿Cuales son los dos unicos estados discretos validos con los que opera la electronica digital?");
    strcpy_s(p.opcionA, "Lineal y cuadratico"); 
    strcpy_s(p.opcionB, "Voltaje variable y rizado");
    strcpy_s(p.opcionC, "Alto (1) y Bajo (0)"); 
    strcpy_s(p.opcionD, "Saturacion e inductancia");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 22; 
    strcpy_s(p.categoria, "Circuitos Digitales (Nivel 4)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 4/n4_p2.png");
    strcpy_s(p.enunciado, "¿Que compuerta logica entrega un estado ALTO (1) solo cuando TODAS sus entradas estan en ALTO?");
    strcpy_s(p.opcionA, "Compuerta OR"); 
    strcpy_s(p.opcionB, "Compuerta NOT");
    strcpy_s(p.opcionC, "Compuerta AND"); 
    strcpy_s(p.opcionD, "Compuerta XOR");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 23; 
    strcpy_s(p.categoria, "Circuitos Digitales (Nivel 4)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 4/n4_p3.png");
    strcpy_s(p.enunciado, "¿Como se denomina al encapsulado clasico cuyas patas atraviesan la placa para soldarse?");
    strcpy_s(p.opcionA, "Encapsulado SMD"); 
    strcpy_s(p.opcionB, "Encapsulado BGA");
    strcpy_s(p.opcionC, "Encapsulado DIP"); 
    strcpy_s(p.opcionD, "Encapsulado QFP");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    p.idPregunta = 24; 
    strcpy_s(p.categoria, "Circuitos Digitales (Nivel 4)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 4/n4_p4.png");
    strcpy_s(p.enunciado, "Un bus de datos que transmite multiples bits de informacion de forma SIMULTANEA se clasifica como:");
    strcpy_s(p.opcionA, "Bus Serial"); 
    strcpy_s(p.opcionB, "Bus Paralelo");
    strcpy_s(p.opcionC, "Bus de Potencia"); 
    strcpy_s(p.opcionD, "Bus Asincrono");
    p.respuestaCorrecta = 1; 
    escribirPregunta(archivo, p);

    p.idPregunta = 25; 
    strcpy_s(p.categoria, "Circuitos Digitales (Nivel 4)"); 
    strcpy_s(p.rutaImagen, "Imagenes/Nivel 4/n4_p5.png");
    strcpy_s(p.enunciado, "¿Que bloque interno de un microprocesador realiza las operaciones aritmeticas y comparaciones?");
    strcpy_s(p.opcionA, "El oscilador de cristal"); 
    strcpy_s(p.opcionB, "La memoria cache de datos");
    strcpy_s(p.opcionC, "La Unidad Aritmetico Logica"); 
    strcpy_s(p.opcionD, "El regulador de voltaje");
    p.respuestaCorrecta = 2; 
    escribirPregunta(archivo, p);

    archivo.close();
    cout << "Archivo binario 'preguntas.dat' generado exitosamente con los 25 items actualizados.\n";
    return 0;
}
