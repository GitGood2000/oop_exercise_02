#ifndef D_ANGLE_H
#define D_ANGLE_H

#include <iostream>

struct Angle{
private:
  int deg;
  int min;

public:
  Angle();
  Angle(int d, int m);
  void read(std::istream& is);
  void awrite(std::ostream& os) const;
  int mntsonly();

  double deg_to_rad();

  int to360();

  //Angle& operator+=(const Angle& o);
  Angle operator+(const Angle& o); // operator[] - перегрузка операторов
  Angle operator-(const Angle& o);
  double operator/(const Angle& o);

  double asin();
  double acos();
  double atan();

  int operator>(const Angle& o);
  friend std::istream& operator >> (std::istream& is, Angle& a);
  friend std::ostream& operator << (std::ostream& os, const Angle& a);
};

Angle operator "" _deg (unsigned long long deg);
Angle operator "" _min (unsigned long long min);
std::istream& operator >> (std::istream& is, Angle& a);
std::ostream& operator << (std::ostream& os, const Angle& a);
#endif
