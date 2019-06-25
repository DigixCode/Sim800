/* Coded by E.Berat Bilir                                                 */ 
/*  MYTHOLOGY TECH ELEKTRONİK MÜHENDİSLİK San. ve Tic. LTD. ŞTİ.          */
/*      www.mythologytech.com                                             */
/*              V1.0                                                      */

#ifndef mythologygsm_h
#define mythologygsm_h
#include "Arduino.h"

class mythologygsm
{
  public:
  char mesaj_yollama(String numara2,String mesaj);
  void arama_yapma(String numara);
  void seri_durum();
  void gelen_mesaj();
  void gelen_arama();
  void arama_sonlandir();
  private:
  
};

#endif;

