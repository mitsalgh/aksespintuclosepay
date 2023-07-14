//#include <DigiUSB.h>
//#include <oddebug.h>
//#include <osccal.h>
//#include <osctune.h>
//#include <rx_buffer.h>
//#include <usbconfig-prototype.h>
//#include <usbconfig.h>
//#include <usbdrv.h>
//#include <usbportability.h>
//
//
//#include <SoftSerial.h>  // Serial Lib

#define pinLimitSwitch A1
#define pinRelaySolenoid 2
#define pinSensorNoTouch A2

String statePintu="closed";
String dataSTB="";
void setup() {
 Serial.begin(9600);
 pinMode(pinLimitSwitch, INPUT_PULLUP);
 pinMode(pinSensorNoTouch,INPUT_PULLUP);
 pinMode(pinRelaySolenoid,OUTPUT);
 statePintu="closed";
}

void loop() 
{
  if(Serial.available()>0)
  {
      delay(10);
      dataSTB= Serial.readString();
      if(dataSTB=="o\n" ||dataSTB=="o" || dataSTB=="O\n" || dataSTB=="O")
      {
        Serial.println("Diterima : open");
        digitalWrite(pinRelaySolenoid,HIGH);
        delay(5000);
        digitalWrite(pinRelaySolenoid,LOW);
        delay(200);
        while(digitalRead(pinLimitSwitch)==LOW)
        {
          delay(100);
          if(digitalRead(pinLimitSwitch)==HIGH)
          {
            Serial.println("closed");
            break;
          }
        }
      }
      
    }
    else if(digitalRead(pinSensorNoTouch)== LOW)
    {
      Serial.println("exit");
      digitalWrite(pinRelaySolenoid,HIGH);
      delay(5000);
      digitalWrite(pinRelaySolenoid,LOW);
      delay(200);
      while(digitalRead(pinLimitSwitch)==LOW)
        {
          delay(100);

          if(digitalRead(pinLimitSwitch)==HIGH)
          {
            Serial.println("closed");
            break;
          }
        }
    }
  
}
