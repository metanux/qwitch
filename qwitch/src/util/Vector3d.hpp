//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class Vector3d {
public:
    Vector3d();
    Vector3d(double aX, double aY, double aZ);
    Vector3d& operator+=(const Vector3d& aRhs);
    void move(double aX, double aY, double aZ);

    ///
    void setX(double aX);
    void setY(double aY);
    void setZ(double aZ);

    ///
    double x() const;
    double y() const;
    double z() const;
private:
    double mX;
    double mY;
    double mZ;
};

} // namespace