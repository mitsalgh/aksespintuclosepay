#define pinLimitSwitch 2
#define pinRelaySolenoid 0

String statePintu="closed";
String dataSTB-"";
void setup() {
 Serial.begin(9600);
 pinMode(pinLimitSwitch, INPUT);
 pinMode(pinRelaySolenoid,OUTPUT);
 statePintu="closed";
}

void loop() 
{
  if(Serial.available()>0)
  {
    delay(10);
    dataSTB= Serial.readString();
    if(dataSTB=="open")
    {
      digitalWrite(pinRelaySolenoid,LOW);
      while(digitalRead(pinLimitSwitch ==LOW))
      {
        while(digitalRead(pinLimitSwitch==HIGH))
        {
          statePintu="open";
          Serial.println(statePintu);
          delay(10);
          while(statePintu=="open")
          {
            if(digitalRead(pinLimitSwitch==LOW)
            {
              Serial.println("closed");
              delay(10);
              break;
              setup();
            }
          }
        }
      }
    }
  }

}
