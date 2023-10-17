#include <iostream>
#include <cmath>
#include "vec.h"
using namespace std;

//constructor
Vector3D::Vector3D(){vx_=0.0; vy_=0.0; vz_=0.0;}
Vector3D::Vector3D(const double vx, const double vy, const double vz){
    vx_=vx;
    vy_=vy;
    vz_=vz;
}
Vector3D Vector3D::Polar(const double& rho, const double& theta, const double& phi){
    return(Vector3D(rho*cos(phi)*sin(theta), rho*sin(phi)*sin(theta), rho*cos(phi)));
}
Vector3D Vector3D::Cartesian(const double& vx, const double& vy, const double& vz){
    return(Vector3D(vx, vy, vz));
}
////////setter///////////////////////////////////
void Vector3D::setX(const double& x){
    vx_=x;
}
void Vector3D::setY(const double& y){
    vy_=y;
}
void Vector3D::setZ(const double& z){
    vz_=z;
}
//////////////////////getter/////////////////////////////////////////
double Vector3D::getX() const {return vx_;}
double Vector3D::getY() const {return vy_;}
double Vector3D::getZ() const {return vz_;}
    //operator

///////////////////////////utility/////////////////////////////////
void Vector3D::print(){
    cout << "componenti del vettore: " << vx_ << " , " << vy_ << " , " << vz_ << endl;
}
///////////////operazioni////////////////////////////////
double Vector3D::magnitude(){
    return sqrt(vx_*vx_+vy_*vy_+vz_*vz_);
}
double Vector3D::theta(){
    return acos(vz_/Vector3D::magnitude());
}
double Vector3D::phi(){
    return atan2(vy_,vx_);
}

double Vector3D::ScalarProduct(const Vector3D& rhs){
    return (vx_*rhs.vx_+vy_*rhs.vy_+vz_*rhs.vz_);
}
Vector3D Vector3D::VectorProduct(const Vector3D& rhs){
    Vector3D res;
    res.setX(vy_*rhs.vz_ - vz_*rhs.vy_);
    res.setY(vz_*rhs.vx_- vx_*rhs.vz_);
    res.setZ(vx_*rhs.vy_ -vy_*rhs.vx_);
    return res;
}
double Vector3D::angle(Vector3D& rhs){
    double angle;
    angle=Vector3D::ScalarProduct(rhs);
    angle/=(Vector3D::magnitude()*rhs.magnitude());
    return acos(angle);
}
///////////////////overload//////////////////////////////
Vector3D Vector3D::operator+(const Vector3D& rhs){
    return Vector3D::Cartesian(vx_+rhs.vx_, vy_+rhs.vy_, vz_+rhs.vz_);

}
Vector3D Vector3D::operator-(const Vector3D& rhs){
    return Vector3D::Cartesian(vx_-rhs.vx_, vy_-rhs.vy_, vz_-rhs.vz_);

}
const Vector3D& Vector3D::operator=(const Vector3D& rhs){
    cout << "use assignment operator" << endl;
    vx_=rhs.vx_;
    vy_=rhs.vy_;
    vz_=rhs.vz_;
    return *this;
}
Vector3D Vector3D::operator*(const double& rhs){
    return Vector3D::Cartesian(vx_*rhs, vy_*rhs, vz_*rhs);
}
Vector3D Vector3D::operator/(const double& rhs){
    return Vector3D::Cartesian(vx_/rhs, vy_/rhs, vz_/rhs);
}
Vector3D operator*(const double& lhs, const Vector3D& rhs){
   
    return Vector3D::Cartesian(rhs.vx_*lhs, rhs.vy_*lhs, rhs.vz_*lhs);
}

   

// to remove everything from a directory
// $ rm -rf *
    

