/* Seri ekranda yolladağınız karaktere göre işlem yapan bir örnek programdır. 
   
       MYTHOLOGY TECH ELEKTRONİK MÜHENDİSLİK San. ve Tic. LTD. ŞTİ. 
               
                      www.mythologytech.com                                                      

                            V1.0                                               */
#include "mythologygsm.h"

mythologygsm mythologygsm;

void setup()
{
  Serial.begin(9600);
  Serial.println("Lutfen yapmak istediginiz islemi seciniz.");
  Serial.println("a-Mesaj Yollama");
  Serial.println("b-Arama Yapma");
  Serial.println("c-Mesaj Oku");
  Serial.println("d-Gelen Arama");
  Serial.println("e-Arama Sonlandir");
  Serial.println();
  delay(100);
  mythologygsm.arama_sonlandir();
}

void loop() 
{
   if(Serial.available()>0)
  {
    switch(Serial.read())
   {
      case 'a':
      mythologygsm.mesaj_yollama("+905xxxxxxx","sent by xxx");
      break;

      case 'b':
      mythologygsm.arama_yapma("+905xxxxxxx");
      break;

      case 'c':
      mythologygsm.gelen_mesaj();
      break;

      case 'd':
      mythologygsm.gelen_arama();
      break;

      case 'e':
      mythologygsm.arama_sonlandir();
      break;
   
   }
  }

  mythologygsm.seri_durum();

}
