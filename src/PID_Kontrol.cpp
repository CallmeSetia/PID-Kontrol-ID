#include "PID_Kontrol.h"
#include <Arduino.h>
PID_Kontrol::PID_Kontrol(double _Kp, double _Ki, double _Kd, double _SetPoints, int _InMin , int _InMax, int _OutMin, int _OutMax) {

  this->Kp = _Kp;
  this->Kd = _Kd;
  this->Ki = _Ki;

  this->Sp = _SetPoints;

  this->Ti = 0.100;
  this->Td = 0.100;

  this->Output;

  this->InRangeMin = _InMin;
  this->InRangeMax = _InMax;
  this->OutRangeMin = _OutMin;
  this->OutRangeMax = _OutMax;

}

void PID_Kontrol::mulai() {
  this->waktuSekarang = millis();
  this->waktuLawas = waktuSekarang;

  this->error = 0;
  this->errorLawas = 0;
  this->sumError = 0;

  this->cP = 0;
  this->cI = 0;
  this->cD = 0;

  this->waktuLawas_Ti = 0;
  this->waktuLawas_Td = 0;
}
// SETUP PARAMETERNYA
void PID_Kontrol::setRange(int _InMin , int _InMax, int _OutMin, int _OutMax) {
  this->InRangeMin = _InMin;
  this->InRangeMax = _InMax;
  this->OutRangeMin = _OutMin;
  this->OutRangeMax = _OutMax;
}
void PID_Kontrol::setSetPoints(double _Sp) {
  this->Sp = _Sp;
}
void PID_Kontrol::setKonstanta(double _Kp, double _Kd, double _Ki) {
  this->Kp = _Kp;
  this->Kd = _Kd;
  this->Ki = _Ki;
}

void PID_Kontrol::setError(double _Error) {
  this->error = _Error;
}

void PID_Kontrol:: setSampling(double _Ti, double _Td) {
  this->Ti = _Ti;
  this->Td = _Td;
}

double PID_Kontrol::getOutput(){
  return this->Output;
}
    

double PID_Kontrol::kalkulasi(double _Feedback) {
  this->waktuSekarang = millis();

  unsigned long int deltaWaktu = this->waktuSekarang - this->waktuLawas;
  double deltaError =  this->error -  this->errorLawas;

  this->error = (this->Sp - _Feedback) / (this->InRangeMax - this->InRangeMin);

  this->cP = this->error;
  this->cI = this->sumError;
  this->cD = deltaError;

  this->Output = this->Kp * this->cP +
                 this->Ki * this->cI  +
                 this->Kd *  this->cD;


  this->Output = this->Output * (this->OutRangeMax - this->OutRangeMin);

  if (this->Output > this->OutRangeMax) {
    this->Output = this->OutRangeMax;
  }
  else {
    if (this->Output < this->OutRangeMin) {
      this->Output = this->Output;
    }
    else {
      this->Output = this->Output;
    }
  }

  if (this->waktuSekarang - this->waktuLawas_Ti > this->Ti) {
    this->waktuLawas_Ti = this->waktuSekarang;

    this->sumError = this->sumError + this->error;
    if (this->sumError > this->OutRangeMax) {
      this->sumError = this->OutRangeMax;
    }
    else {
      if (this->sumError < this->OutRangeMin) {
        this->sumError =  this->OutRangeMin;
      }
      else {
        this->sumError = this->sumError;
      }
    }
  }

  if (this->waktuSekarang - this->waktuLawas_Td > this->Td) {
    this->waktuLawas_Td = this->waktuSekarang;
    this->errorLawas = this->error;
  }

  if ( this->errorLawas * this->error < 0 ) {
    this->sumError = 0;
  }

  this->waktuLawas = this->waktuSekarang;
  this->errorLawas = this->error;
  this->Output = this->Output;

  return this->Output;
}

void PID_Kontrol:: reset() {
  this->errorLawas = 0;
  this->sumError = 0;
  this->Output = 0;
}
