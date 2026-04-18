HardwareSerial canal(2);

#define rx2 18
#define tx2 21
#define veloc 38400

#define pinGas 34

String mensaje = "";

unsigned long tiempoAnterior = 0; 
const unsigned long intervalo = 5000;

void setup() {
  Serial.begin(9600);
  canal.begin(veloc, SERIAL_8N1, rx2, tx2);
}

void loop() {
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    int valorGas = analogRead(pinGas);

    Serial.print("Gas: ");
    Serial.println(valorGas);

    if (valorGas > 2000) {
      Serial.println("Gas detectado!");
      canal.println("ALERTA: GAS DETECTADO");
    }
  }

  if (Serial.available()) {
    char letra = Serial.read();
    mensaje = mensaje + letra;

    if (letra == '\n') {
      canal.print("te mandaron: " + mensaje);
      mensaje = "";
    }
  }

  if (canal.available()) {
    Serial.write(canal.read());
  }
}