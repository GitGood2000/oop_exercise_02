#ifndef D_ANGLE_H
#define D_ANGLE_H

#include <iostream>

struct Angle{
private:
  int deg;
  int min;

public:
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
};

#endif
