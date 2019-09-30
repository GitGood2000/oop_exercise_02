#include "angle.h"
#include <cmath>

#include <iostream>

int operator "" _deg (unsigned long long deg){
  return (deg / 60) % 360;
}

int operator "" _min (unsigned long long min){
  return min % 60;
}

void Angle::read(std::istream& is) {
  is >> deg >> min;
}

void Angle::awrite(std::ostream& os) const {
  os << deg << ' ' << min << '\n';
}

int Angle::mntsonly(){
  if (deg < 0){
    return 60 - abs(min);
  } else {
    return min;
  }
}

double Angle::deg_to_rad(){
  double rad = ((double)deg + ((double)min / 60)) / 180 * M_PI; //M_PI - Пи в cmath
  //(double)angle - перевод angle (заданый в int) из int в double 
  return rad;
}

int Angle::to360(){
  if (deg < 0) {  
    return 360 + (deg % 360);
  } else {
    return deg % 360;
  }
}

Angle Angle::operator+(const Angle& rhs) {
  Angle result;
  result.deg = deg + rhs.deg;
  result.min = min + rhs.min;
  if (result.min >= 60) {
    result.deg += 1;
    result.min -= 60;
  } else if (result.min <= -60) {
    result.deg -= 1;
    result.min += 60;
  }
  return result;
}

Angle Angle::operator-(const Angle& rhs) {
  Angle result;
  result.deg = deg - rhs.deg;
  result.min = min - rhs.min;
  if (result.min < 0) {
    result.deg -= 1;
    result.min += 60;
  } else if ((result.deg < 0) && (result.min > 0)) {
    result.deg += 1;
    result.min -= 60;
  }
  return result;
}


double Angle::operator/(const Angle& rhs) {
  double result = ((double)deg + ((double)min / 60)) / ((double)rhs.deg + ((double)rhs.min / 60));
  return result;
}

double Angle::asin() {
  return sin(((double)deg + ((double)min / 60)) / 180 * M_PI);
}

double Angle::acos() {
  return cos(((double)deg + ((double)min / 60)) / 180 * M_PI);
}

double Angle::atan(){
  return tan(((double)deg + ((double)min / 60)) / 180 * M_PI);
}

int Angle::operator>(const Angle& rhs) {
  int result = 0;
  if (deg > rhs.deg){
    result = 1;
  } else if (deg < rhs.deg) {
    result = -1;
  } else if (deg == rhs.deg) {
    if (min > rhs.min) {
      result = 1;
    } else if (min < rhs.min) {
      result = -1;
    }
  }
  return result;
}
