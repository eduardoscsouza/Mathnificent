
#ifndef POINT_HPP
#define POINT_HPP 1

#include <cmath>

class Vector
{
    public:
        float x;
        float y;
        float z;

        Vector(float x, float y, float z=0) : x(x), y(y), z(z) {}
        Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

        float norm(void) const
        {
            return std::sqrt(this->norm2());
        }

        float norm2(void) const
        {
            return this->x*this->x + this->y*this->y + this->z*this->z;
        }

        float dist(const Vector& v) const
        {
            return (*this - v).norm();
        }


        Vector add(const Vector& v) const
        {
            return Vector(this->x+v.x, this->y+v.y, this->z+v.z);
        }

        Vector sub(const Vector& v) const
        {
            return Vector(this->x-v.x, this->y-v.y, this->z-v.z);
        }

        Vector opposite(void) const
        {
            return Vector(-this->x, -this->y, -this->z);
        }

        Vector scale(float f) const
        {
            return Vector(this->x*f, this->y*f, this->z*f);
        }

        float dot(const Vector& v) const
        {
            return this->x*v.x + this->y*v.y + this->z*v.z;
        }

        Vector cross(const Vector& v) const
        {
            return Vector
            (
                this->y*v.z - this->z*v.y,
                this->z*v.x - this->x*v.z,
                this->x*v.y - this->y*v.x
            );
        }

        Vector normalized(void) const
        {
            return *this / this->norm();
        }

        Vector project(const Vector& v) const
        {
            return v * (*this * v) / v.norm2();
        }


        const Vector operator+(const Vector& v) const
        {
            return this->add(v);
        }


        const Vector operator-(const Vector& v) const
        {
            return this->sub(v);
        }

        const Vector operator-(void) const
        {
            return this->opposite();
        }


        const Vector operator*(float f) const
        {
            return this->scale(f);
        }

        friend const Vector operator*(float f, const Vector& v)
        {
            return v.scale(f);
        }

        float operator*(const Vector& v) const
        {
            return this->dot(v);
        }

        const Vector operator^(const Vector& v) const
        {
            return this->cross(v);
        }


        const Vector operator/(float f) const
        {
            return this->scale(1/f);
        }


        Vector& operator+=(const Vector& p)
        {
            this->x += p.x;
            this->y += p.y;
            this->z += p.z;

            return *this;
        }

        Vector& operator-=(const Vector& p)
        {
            this->x -= p.x;
            this->y -= p.y;
            this->z -= p.z;

            return *this;
        }

        Vector& operator*=(float f)
        {
            this->x *= f;
            this->y *= f;
            this->z *= f;

            return *this;
        }
        
        Vector& operator^=(const Vector& v)
        {
            Vector n = this->cross(v);
            this->x = n.x;
            this->y = n.y;
            this->z = n.z;

            return *this;
        }

        Vector& operator/=(float f)
        {
            this->x /= f;
            this->y /= f;
            this->z /= f;

            return *this;
        }


        bool operator==(const Vector& p) const
        {
            return this->x == p.x && this->y == p.y && this->z == p.z;
        }

        bool operator!=(const Vector& p) const
        {
            return this->x != p.x || this->y != p.y || this->z != p.z;
        }
};

#endif
