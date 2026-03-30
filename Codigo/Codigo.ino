HardwareSerial canal(2);
#define rx2 18
#define tx2 21
#define veloc 38400
String mensaje="";

void setup() {
Serial.begin(9600);
canal.begin(veloc,SERIAL_8N1, rx2,tx2);

}

void loop() {
  if(Serial.available()){
    char letra=Serial.read();
    mensaje=mensaje+letra;

    if(letra ==10){
      canal.print("te mandaron: "+ mensaje);
      mensaje ="";
    }
    if(canal.available()){
      Serial.write(canal.read());
    }
  }

}
