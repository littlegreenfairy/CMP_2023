//vec.h
#include <cmath>
class Vector3D{
    private:
    double vx_, vy_, vz_;
    public:
    //constructor
    Vector3D();
    Vector3D(const double vx, const double vy, const double vz);
     
    static Vector3D Polar(const double& rho, const double& theta, const double& phi);
    static Vector3D Cartesian(const double& vx, const double& vy, const double& vz);
    //setter
    void setX(const double& x);
    void setY(const double& y);
    void setZ(const double& z);
    //getter
    double getX() const;
    double getY() const;
    double getZ() const;
    //operazioni
    double theta();
    double phi();
    double magnitude();
    double ScalarProduct(const Vector3D& rhs);
    Vector3D VectorProduct(const Vector3D& rhs);
    double angle(Vector3D& rhs);
    //operator
    Vector3D operator+(const Vector3D& rhs);
    Vector3D operator-(const Vector3D& rhs);
    const Vector3D& operator=(const Vector3D& rhs);
    Vector3D operator*(const double& rhs);
    Vector3D operator/(const double& rhs);
    friend Vector3D operator*(const double& lhs, const Vector3D & rhs);
    

    //utility
    void print();

    //deconstructor
    ~Vector3D(){ };
    

};
