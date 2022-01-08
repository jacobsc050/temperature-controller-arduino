float Thermistor_volts = A0; //sets pin A0
float Vo;
float C = 250891.0;
float B = -0.037;
float Temp_Actual;
float Ratio = 202.39; //Ratio between pot and Vout
float Tset = 320; //Temperature in Kelvin
const int Heater = 12; // sets pin 12 as heater


void setup() {
  Serial.begin(9600);
  pinMode(Thermistor_volts, INPUT); //Sets Vout as an input
  pinMode(Heater, OUTPUT);
}
void loop() {
  Vo = float(analogRead(Thermistor_volts) / Ratio);
  float Temp_Actual = ((log((Vo / C))) / B); //Equation from calibaration
  Serial.print("Temp in Kelvin: ");
  Serial.print(Temp_Actual);
  Serial.println("   ");
  Serial.print("Vout:   ");
  Serial.print(analogRead(Thermistor_volts) / Ratio);
  Serial.println("   ");
  int var = 1;
  switch (var)
  {
    case 1:
      if (Temp_Actual < Tset)
      {
        digitalWrite(Heater, HIGH);
        Serial.println(" Heat on!!! " );
        delay(10000);
        var = var + 1;
        break;
      }
    case 2:
      if (Temp_Actual > Tset)
      {
        digitalWrite(Heater, LOW);
        Serial.println(" Heat off!!! " );
        delay(10000);
        var = 0 ;
      }
      var = 0 ;
    default:
      var = 1;
  }
}
