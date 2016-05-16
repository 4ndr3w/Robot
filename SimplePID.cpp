#include "SimplePID.h"
#include "Timer.h"
#include "math.h"

SimplePID::SimplePID(double kP, double kI, double kD, double kF) :
  setpoint(0), error(0), lastT(0), errSum(0), prevInput(0),
  minOut(-1), maxOut(1) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  this->kF = kF;
}

void SimplePID::setSetpoint(double setpoint) {
  this->setpoint = setpoint;
}

double SimplePID::getError() {
  return error;
}

bool SimplePID::isStable(double allowed) {
  return fabs(error) < allowed;
}

void SimplePID::reset(double initialPosition) {
  lastT = Timer::GetPPCTimestamp();
  prevInput = initialPosition;
  errSum = 0;
}

double SimplePID::calculate(double input) {
  double now = Timer::GetPPCTimestamp();
  double dT = now-lastT;

  error = setpoint-input;

  errSum += error*dT;

  double deltaPos = (input-prevInput);

  lastT = now;
  prevInput = input;

  return (kP*error) + (kI*errSum) - (kD*(deltaPos/dT)) + (kF * setpoint);
}
