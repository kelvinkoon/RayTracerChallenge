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

    private:
        float x_, y_, z_, w_;
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);
