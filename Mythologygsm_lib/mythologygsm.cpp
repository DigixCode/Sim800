/* Coded by E.Berat Bilir                                                */ 
/*  MYTHOLOGY TECH ELEKTRONİK MÜHENDİSLİK San. ve Tic. LTD. ŞTİ.         */
/*      www.mythologytech.com                                            */
/* V1.0 */
#include "mythologygsm.h"
#include "Arduino.h"
#include <SoftwareSerial.h>

SoftwareSerial mythologygsm_serial(2,3);

char msg;
char call;

char mythologygsm::mesaj_yollama(String numara2,String mesaj)
{
      mythologygsm_serial.begin(9600);
      Serial.println("Mesaj yollaniyor.");
      mythologygsm_serial.println("AT+CMGF = 1");
      delay(1000);
      mythologygsm_serial.println("AT+CMGS=\""+numara2+"\"");
      delay(1000);
      mythologygsm_serial.println(""+mesaj);
      delay(1000);
      mythologygsm_serial.println((char)26);
      delay(1000); 
}

void mythologygsm::arama_yapma(String numara)
{
     // numara = numara + ";";
      mythologygsm_serial.begin(9600);
      mythologygsm_serial.println("ATD+ "+numara+";");
      Serial.println("Araniyor");
      delay(1000);
}

void mythologygsm::seri_durum()
{
      if (mythologygsm_serial.available()>0)
      Serial.write(mythologygsm_serial.read());
}

void mythologygsm::gelen_mesaj()
{     
      mythologygsm_serial.begin(9600);
      mythologygsm_serial.println("AT+CNMI=2,2,0,0,0");
      delay(1000);
      if (mythologygsm_serial.available()>0)
      {
      msg=mythologygsm_serial.read();
      Serial.print(msg);
      } 
}

void mythologygsm::gelen_arama()
{     
      mythologygsm_serial.begin(9600);
      mythologygsm_serial.println("ATA");
      delay(1000);
      {
      call=mythologygsm_serial.read();
      Serial.print(call);
      }
}

void mythologygsm::arama_sonlandir()
{
  mythologygsm_serial.begin(9600);
  mythologygsm_serial.println("ATH");
  Serial.println("Arama Sonlandirildi");
  delay(1000);
}


