//we define macros, so when we say "redLED" we are talking about "11"
#define blueLED 2

void setup() {
  // We set the LED's as output and the light sensor as an input
  pinMode (blueLED, OUTPUT);
  //We set the communication between serial port and the PC
  Serial.begin(9600);
  
}

void loop() {
int LEDLuminosity = 0;
//here we set the up and down of the led
for (LEDLuminosity = 0; LEDLuminosity < 255; LEDLuminosity++)
  {
    Serial.println(LEDLuminosity);
    analogWrite (blueLED, LEDLuminosity);
    delay(10);
  }

for (LEDLuminosity = 255; LEDLuminosity > 0; LEDLuminosity--)
  {
    Serial.println(LEDLuminosity);
    analogWrite (blueLED, LEDLuminosity);
    delay(10);
  }
}
