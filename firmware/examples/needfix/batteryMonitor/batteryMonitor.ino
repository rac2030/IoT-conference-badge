/**
 * This is an example of reading out the battery voltage on the MakeZurich badge
 * @author Michel Racic
 **/

#define MONITOR_PIN 35

void setup()
{
    Serial.begin(115200);
    delay(1000); // let serial console settle
    Serial.println("Battery Monitor\n");
}

void loop(){ 
  float Rl=100.0f;
  float Rh=470.0f;
  float Vref=3.36f;
  float Vout=float(analogRead(MONITOR_PIN));
  float adc_resolution=4095;
  float raw = Vout / ( Rl / ( Rh + Rl ) );
  float VBAT = fmap(raw, 0, adc_resolution, 0.0, Vref);
  
    Serial.print("Battery Voltage = "); Serial.print(VBAT, 2); Serial.println(" V");  
    delay(1000);
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
