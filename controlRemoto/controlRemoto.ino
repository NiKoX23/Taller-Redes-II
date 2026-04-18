#define pinIzqDir 2
#define pinDerDir 4
#define pinVelIzq 5
#define pinVelDer 6
//musica arduino tone (pin,frecuencia,duracion[ms])
//si recive la letra h recibe el tono, otro 
int velocidadBase = 40;
int pasoVelocidad = 20;
char ultMov = 'x';

void setup() {
  Serial.begin(9600);

  pinMode(pinIzqDir, OUTPUT);
  pinMode(pinDerDir, OUTPUT);
  pinMode(pinVelIzq, OUTPUT);
  pinMode(pinVelDer, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    char comando = Serial.read();

    // AVANZAR
    if (comando == 'w') {
      digitalWrite(pinIzqDir, 1);
      digitalWrite(pinDerDir, 0);

      analogWrite(pinVelIzq, velocidadBase);
      analogWrite(pinVelDer, velocidadBase);
    }

    // RETROCEDER
    else if (comando == 's') {
      digitalWrite(pinIzqDir, 0);
      digitalWrite(pinDerDir, 1);

      analogWrite(pinVelIzq, velocidadBase);
      analogWrite(pinVelDer, velocidadBase);
    }

    // IZQUIERDA
    else if (comando == 'a') {
      digitalWrite(pinIzqDir, 0);
      digitalWrite(pinDerDir, 0);

      analogWrite(pinVelIzq, 0);
      analogWrite(pinVelDer, velocidadBase);
    }

    // DERECHA
    else if (comando == 'd') {
      digitalWrite(pinIzqDir, 1);
      digitalWrite(pinDerDir, 1);

      analogWrite(pinVelDer, 0);
      analogWrite(pinVelIzq, velocidadBase);
    }

    // STOP
    else if (comando == 'x') {
      analogWrite(pinVelIzq, 0);
      analogWrite(pinVelDer, 0);
    }

    else if(comando == '+'){
      velocidadBase+=pasoVelocidad;
      if(velocidadBase > 255){velocidadBase = 255;}
      analogWrite(pinVelIzq, velocidadBase);
      analogWrite(pinVelDer, velocidadBase);
      comando=ultMov;
    }

    else if(comando == '-'){
      velocidadBase-=pasoVelocidad;
      if(velocidadBase < 0){
        velocidadBase = 0;
        analogWrite(pinVelIzq, 0);
        analogWrite(pinVelDer, 0);
      }
      analogWrite(pinVelIzq, velocidadBase);
      analogWrite(pinVelDer, velocidadBase);
      comando=ultMov;
    }

    //Bocina
    else if(comando == 'h'){
      tone(8, 800,1000);
      comando=ultMov;
     }
  }
}