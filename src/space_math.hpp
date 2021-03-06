#ifndef __SPACE_MATH_H__
#define __SPACE_MATH_H__

#include <cmath>
#include <string>

namespace Math
{

    class Vector2
    {
    public:
        double X, Y;
        Vector2(double _x = 0.0, double _y = 0.0)
        {
            X = _x;
            Y = _y;
        }

        std::string to_string()
        {
            return(std::to_string(X) + "," + std::to_string(Y));
        }

        double length()
        {
            return sqrtf(this->X * this->X + this->Y * this->Y);
        }

        void translate(Vector2 v2)
        {
            this->X += v2.X;
            this->Y += v2.Y;
        }

        void scale(double s)
        {
            this->X *= s;
            this->Y *= s;
        }

        void normalize()
        {
            double l = length();
            this->scale(1.0 / l);
        }

        void dot(Vector2 v2)
        {
            this->X = this->X * v2.X;
            this->Y = this->Y * v2.Y;
        }
    };

    class Vector3
    {
    public:
        double X, Y, Z;
        Vector3(double _x = 0.0, double _y = 0.0, double _z = 0.0)
        {
            X = _x;
            Y = _y;
            Z = _z;
        }

        double vlength(Vector3 v)
        {
            return sqrtf(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
        }

        Vector3 vscale(Vector3 v, float s)
        {
            return (v.X * s) + (v.Y * s) + (v.Z * s);
        }

        Vector3 vnormalize(Vector3 v)
        {
            double l = vlength(v);
            return vscale(v, 1.0 / l);
        }

        Vector3 vdot(Vector3 v1, Vector3 v2)
        {
            Vector3 v_ret(v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z);
            return v_ret;
        }
    };
}

#endif
