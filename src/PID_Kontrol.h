#ifndef PID_KONTROL_H
#define PID_KONTROL_H


class PID_Kontrol {

  private:
    double Kp;
    double Ki;
    double Kd;

    double Ti;
    double Td;

    double Output;

    double Sp;

    double InRangeMin;
    double InRangeMax;
    double OutRangeMin ;
    double OutRangeMax;
    
    unsigned long int waktuSekarang = 0;
    unsigned long int waktuLawas = 0;

    double error = 0;
    double errorLawas = 0;
    double sumError = 0;

    double cP = 0;
    double cI = 0;
    double cD = 0;

    unsigned long int waktuLawas_Ti = 0;
    unsigned long int waktuLawas_Td = 0;
    
  
  public:
    PID_Kontrol(double _Kp, double _Ki, double _Kd,double _SetPoints, int _InMin , int _InMax, int _OutMin, int _OutMax);
    void mulai();
    void setRange(int _InMin , int _InMax, int _OutMin, int _OutMax);
    void setKonstanta(double _Kp, double _Kd, double Ki);
    void setSetPoints(double _Sp);
    void setError(double _Error);
    void setSampling(double _Ti, double _Td);
    double kalkulasi(double _Feedback);
    void reset();
    
    double getOutput();
    
  
};

#endif
