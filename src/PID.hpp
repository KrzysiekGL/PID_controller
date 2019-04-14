class PID {
//PID settings values
  float Ti;
  float Td;
  float kp;

//variables
  float SP; //Set Point - reference value
  float PV; //Process Variable - current value of process which is being monitored
  float CV; //Controll Variable - error ie. SP - PV

//needed variables
  float Ts; //sample time in miliseconds
  float integralValue;
  float previousError;

public:
  PID(float Ts, float Ti, float Td, float kp);
  PID(flaot Ts);

  ~PID() {}

  void setPointValue(float SP);
  void setProcessVariableValue(float PV);

  void tunePID(float Ti, float Td, float kp);

  //calculation - return current PID value
  float runPID();

protected:
  float derivative(float previousError, flaot error);
  void integral(float error);
};
