#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3 {
public:
    float x;
    float y;
    float z;
    Vector3(float x = 0, float y = 0, float z = 0);
    bool operator==(const Vector3& vector) const;
    bool operator!=(const Vector3& vector) const;
    const Vector3 operator+() const;
    const Vector3 operator-() const;
    Vector3& operator+=(const Vector3& vector);
    Vector3& operator-=(const Vector3& vector);
    Vector3& operator*=(float value);
    Vector3& operator/=(float value);
    const Vector3 operator+(const Vector3& vector) const;
    const Vector3 operator-(const Vector3& vector) const;
    const Vector3 operator*(float value) const;
    const Vector3 operator/(float value) const;
    Vector3& set(float x = 0, float y = 0, float z = 0);
    float squaredLength() const;
    float length() const;
    const Vector3 norm() const;
    float dot(const Vector3& vector) const;
    const Vector3 cross(const Vector3& vector) const;
    const Vector3 maxEdge(Vector3& vector) const;
    const Vector3 minEdge(Vector3& vector) const;
};

#endif
