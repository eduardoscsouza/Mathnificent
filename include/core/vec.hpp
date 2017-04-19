
#ifndef POINT_HPP
#define POINT_HPP 1

class Vector
{
    public:
        float x;
        float y;
        float z;

        Vector(float x, float y, float z=0) : x(x), y(y), z(z) {}
        Vector(const Vector& p) : x(p.x), y(p.y), z(p.z) {}

        const Vector operator+(const Vector& p) const
        {
            return Vector(this->x + p.x, this->y + p.y, this->z + p.z);
        }

        Vector& operator+=(const Vector& p)
        {
            this->x += p.x;
            this->y += p.y;
            this->z += p.z;

            return *this;
        }

        const Vector operator-(const Vector& p) const
        {
            return Vector(this->x - p.x, this->y - p.y, this->z - p.z);
        }

        Vector& operator-=(const Vector& p)
        {
            this->x -= p.x;
            this->y -= p.y;
            this->z -= p.z;

            return *this;
        }

        const Vector operator-(void) const
        {
            return Vector(-this->x, -this->y, -this->z);
        }

        const Vector operator*(float f) const
        {
            return Vector(this->x * f, this->y * f, this->z * f);
        }

        friend const Vector operator*(float f, const Vector& v)
        {
            return v * f;
        }

        bool operator==(const Vector& p) const
        {
            return this->x == p.x && this->y == p.y && this->z == p.z;
        }

        bool operator!=(const Vector& p) const
        {
            return this->x != p.x || this->y != p.y || this->z == p.z;
        }
};

#endif