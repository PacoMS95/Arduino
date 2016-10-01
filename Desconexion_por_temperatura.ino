int ledRojo = 52;
int ledAzul = 50;
int pinSensor = A0;
float datosSensor = 0;

void setup() {
Serial.begin(9600);
Serial.println("Inicializando");
pinMode(pinSensor,INPUT);
pinMode(ledRojo,OUTPUT);
pinMode(ledAzul,OUTPUT);
digitalWrite(ledRojo,LOW);
digitalWrite(ledAzul,HIGH);
}

void loop() {
  float temperatura = 0.0;
  
  temperatura = leerSensor();
  invertirLuces(temperatura);
}


//módulo para la formulita del sensor (al principio te mostrará datos que no se entienden, hay que aplicar la fórmula)

float leerSensor (){
  //declaramos la variable para temperatura
  float temperatura = 0.0;
  //leemos datos del sensor
  datosSensor = analogRead(pinSensor);
  ////imprimimos el valor del sensor
  //Serial.print("Valor del sensor: ");
  //Serial.println(datosSensor);

  //Aplicamos e imprimimos la fórmula para calcular los grados Celsius con lo que recibimos del sensor
  temperatura = (datosSensor * 100 * 5.0)/1024.0;
  Serial.println(temperatura);
  return(temperatura);
  }


 //Módulo para invertir las luces si se calienta a más de cincuenta
 void invertirLuces(float temperatura) {
  
  if (temperatura<=50.0){
    digitalWrite(ledAzul,HIGH);
    digitalWrite(ledRojo,LOW);
    Serial.println ("La temperatura ha superado los cincuenta grados. Las luces se invertirán");
    }
   else {
    digitalWrite(ledAzul,LOW);
    digitalWrite(ledRojo,HIGH);
    }
  }
