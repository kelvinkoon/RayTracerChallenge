#pragma once

static const float W_POINT = 1.0;
static const float W_VECTOR = 0.0;

/**
 * A tuple in 3D space
 */
class Tuple final
{
    public:
        /**
         * Creates a Tuple (Vector) at the origin (0.0, 0.0, 0.0, 0.0)
         */
        explicit Tuple();

        /**
         * Creates a Tuple at arbitrary coordinates
         *
         * @param x the x value of the Tuple
         * @param y the y value of the Tuple
         * @param z the z value of the Tuple
         * @param w the w value of the Tuple
         */
        Tuple(float x, float y, float z, float w);

        /**
         * Returns the x coordinate of this Tuple
         *
         * @return the x coordinate of this Tuple
         */
        float x() const;

        /**
         * Returns the y coordinate of this Tuple
         *
         * @return the y coordinate of this Tuple
         */
        float y() const;

        /**
         * Returns the z coordinate of this Tuple
         *
         * @return the z coordinate of this Tuple
         */
        float z() const;

        /**
         * Returns the w coordinate of this Tuple
         *
         * @return the w coordinate of this Tuple
         */
        float w() const;
    
        /**
         * Returns if the Tuple is a Point (ie. w=1.0)
         *
         * @return true if Tuple is a Point
         */
        bool isPoint() const;

        /**
         * Returns if the Tuple is a Vector (ie. w=0.0)
         *
         * @return true if Tuple is a Vector
         */
        bool isVector() const;

        /**
         * Returns magnitude / length of the Tuple
         *
         * @return the magnitude / length of the Tuple
         */
        float magnitude() const;

        /**
         * Returns the normalized Tuple
         *
         * @return the normalized Tuple
         */
        Tuple normalize() const;

        /**
         * Returns the dot product between the Tuple and another Tuple
         *
         * @return the dot product between the Tuple and another Tuple
         */
        float dot(Tuple a) const;

        /**
         * Returns the cross product between the Tuple and another Tuple
         *
         * @return the cross product between the Tuple and the another Tuple
         */
        Tuple cross(Tuple a) const;

    private:
        float x_, y_, z_, w_;
};

/**
 * Returns a Point (ie. 'w'=1.0)
 *
 * @param x the x value of the Point
 * @param y the y value of the Point
 * @param z the z value of the Point
 */
Tuple Point(float x, float y, float z);

/**
 * Returns a Vector (ie. 'w'=0.0)
 *
 * @param x the x value of the Vector
 * @param y the y value of the Vector
 * @param z the z value of the Vector
 */
Tuple Vector(float x, float y, float z);

/**
 * Compares two Tuples for equality
 *
 * @param a the first Tuple
 * @param b the second Tuple
 */
bool operator==(const Tuple &a, const Tuple &b);

/**
 * Compares two Tuples for inequality
 *
 * @param a the first Tuple
 * @param b the second Tuple
 */
bool operator!=(const Tuple &a, const Tuple &b);

/**
 * Adds two Tuples (ie. Vector and Point)
 *
 * @param a the first Tuple
 * @param b the second Tuple
 */
Tuple operator+(const Tuple &a, const Tuple &b);

/**
 * Subtract two Tuples (ie. Vector and Point)
 *
 * @param a the first Tuple
 * @param b the second Tuple
 */
Tuple operator-(const Tuple &a, const Tuple &b);

/**
 * Negates a Tuple
 *
 * @param a the Tuple to negate
 */
Tuple operator-(const Tuple &a);

/**
 * Multiply a Tuple and scalar
 *
 * @param a the Tuple to multiply
 * @param b the scalar value
 */
Tuple operator*(const Tuple &a, const float &b);

/**
 * Divide a Tuple and scalar
 *
 * @param a the Tuple to divide
 * @param b the scalar value
 */
Tuple operator/(const Tuple &a, const float &b);
