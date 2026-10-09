// Thermistor Temperature Measurement
// ME 351 - Lab 2
//

const byte PIN_THERMISTOR = A0;

const float R_FIXED = 10000.0;
const float V_IN    = 5.0;

const float A_COEFF = 0.001129148;
const float B_COEFF = 0.000234125;
const float C_COEFF = 0.0000000876741;
unsigned long pastTime = 0;
float threshold = 200;

//For LEDS
float Green = 5;
float Yellow = 6;
float Red = 7;

float Low_T = 26;
float High_T = 30;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT);
}

void loop() {
  float AnalVal = analogRead(A0);
  float VOLTAGE= (AnalVal/1023.0)*5.0;
  float RESISTANCE = (VOLTAGE * R_FIXED)/(V_IN - VOLTAGE);
  float TEMP_C = (1/(A_COEFF + B_COEFF*log(RESISTANCE)+C_COEFF*log(RESISTANCE)*log(RESISTANCE)*log(RESISTANCE)) - 273.15);
  unsigned long currentTime = millis();
  if ((currentTime - pastTime)>=threshold){
    pastTime = currentTime;

    //Serial.print(currentTime);
   // Serial.print(",");
   // Serial.print(AnalVal);
    //Serial.print(",");
   // Serial.print(VOLTAGE,3);
    //Serial.print(",");
   // Serial.print(RESISTANCE);
    //Serial.print(",");
  //  Serial.println(TEMP_C,2);
    if ((TEMP_C - Low_T) <= 0){
      digitalWrite(Green, HIGH);
      digitalWrite(Yellow, LOW);
      digitalWrite(Red, LOW);}
    else if ((TEMP_C - Low_T) <=4.0){
      digitalWrite(Green,LOW);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Red,LOW);}
    else if ((TEMP_C - Low_T)>=4.0){
      digitalWrite(Green,LOW);
      digitalWrite(Yellow,LOW);
      digitalWrite(Red,HIGH);
    }

    }
    

  }

  // --- Your code here (see lab manual) ---