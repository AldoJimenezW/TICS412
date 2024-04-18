// Definición de los pines de los botones
const int botonAdelante = 2;
const int botonAtras = 3;
const int botonIzquierda = 4;
const int botonDerecha = 5;

// Definición de los pines del motor (ejemplo para puente H L298N)
const int motor1Pin1 = 6;
const int motor1Pin2 = 7;
const int motor2Pin1 = 8;
const int motor2Pin2 = 9;

void setup() {
  // Configuración de pines de entrada para los botones
  pinMode(botonAdelante, INPUT);
  pinMode(botonAtras, INPUT);
  pinMode(botonIzquierda, INPUT);
  pinMode(botonDerecha, INPUT);

  // Configuración de pines de salida para los motores
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  // Definir serial print
  Serial.begin(9600);
}

void loop() {
  // Leer el estado de los botones
  int estadoAdelante = digitalRead(botonAdelante);
  int estadoAtras = digitalRead(botonAtras);
  int estadoIzquierda = digitalRead(botonIzquierda);
  int estadoDerecha = digitalRead(botonDerecha);
	
  Serial.println(estadoAdelante);
  Serial.println(estadoAtras);
  Serial.println(estadoIzquierda);
  Serial.println(estadoDerecha);
  
  if (estadoAdelante == HIGH) {
    // Mover ambos motores hacia adelante
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else if (estadoAtras == HIGH) {
    // Mover ambos motores hacia atrás
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  } else if (estadoIzquierda == HIGH) {
    // Mover motor 1 adelante y motor 2 atrás
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  } else if (estadoDerecha == HIGH) {
    // Mover motor 1 atrás y motor 2 adelante
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else {
    // Detener ambos motores
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
  }
}
