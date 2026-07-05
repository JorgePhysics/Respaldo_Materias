// ============================================================================
// CÓDIGO PARA EL ARDUINO (TRANSMISIÓN POR CABLE USB - COM6)
// ============================================================================

const int PIN_BTN_A = 2; 
const int PIN_BTN_B = 3; 
const int PIN_BTN_C = 4; 
const int PIN_BTN_D = 5; 

const int PIN_ANALOG_X = A0; 
const int PIN_ANALOG_Y = A1; 

unsigned long ultimoTiempoEnvio = 0;
const unsigned long intervaloEnvio = 80; 

void setup() 
{
  pinMode(PIN_BTN_A, INPUT_PULLUP);
  pinMode(PIN_BTN_B, INPUT_PULLUP);
  pinMode(PIN_BTN_C, INPUT_PULLUP);
  pinMode(PIN_BTN_D, INPUT_PULLUP);

  Serial.begin(9600); // Inicia la comunicación serie a 9600 baudios
}

void loop() 
{
  if (millis() - ultimoTiempoEnvio >= intervaloEnvio) 
  {
    int valorX = analogRead(PIN_ANALOG_X);
    int valorY = analogRead(PIN_ANALOG_Y);

    int btnA = (digitalRead(PIN_BTN_A) == LOW) ? 1 : 0;
    int btnB = (digitalRead(PIN_BTN_B) == LOW) ? 1 : 0;
    int btnC = (digitalRead(PIN_BTN_C) == LOW) ? 1 : 0;
    int btnD = (digitalRead(PIN_BTN_D) == LOW) ? 1 : 0;

    // Construcción de la trama requerida por el código de tu compañera
    Serial.print(valorX);     Serial.print(",");
    Serial.print(valorY);     Serial.print(",");
    Serial.print(btnA);       Serial.print(",");
    Serial.print(btnB);       Serial.print(",");
    Serial.print(btnC);       Serial.print(",");
    Serial.print(btnD);
    Serial.println(); // Envía el '\n' para cerrar la trama

    ultimoTiempoEnvio = millis();
  }
}