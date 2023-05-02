#pragma once

/**
 * A colour representing RGB values
 */
class Colour final
{
    public:
        /**
         * Creates a colour
         */
        explicit Colour();

        /**
         * Creates a colour given red, green, and blue values in order
         *
         * @param r the red value of the colour
         * @param g the green value of the colour
         * @param b the blue value of the colour
         */
        Colour(float r, float g, float b);

        /**
         * Returns the red value of the colour
         *
         * @return the red value of the colour
         */
        float red() const;

        /**
         * Returns the green value of the colour
         *
         * @return the green value of the colour
         */
        float green() const;

        /**
         * Returns the blue value of the colour
         *
         * @return the blue value of the colour
         */
        float blue() const;

    private:
        float r_, g_, b_;
};

/**
 * Compares two Colours for equality
 *
 * @param a the first Colour
 * @param b the second Colour
 */
bool operator==(const Colour &a, const Colour &b);

/**
 * Compares two Colours for inequality
 *
 * @param a the first Tuple
 * @param b the second Tuple
 */
bool operator!=(const Colour &a, const Colour &b);

/**
 * Adds two Colours 
 *
 * @param a the first Colour
 * @param b the second Colour
 */
Colour operator+(const Colour &a, const Colour &b);

/**
 * Subtract two Colours
 *
 * @param a the first Colour
 * @param b the second Colour
 */
Colour operator-(const Colour &a, const Colour &b);

/**
 * Multiply a Colour and a scalar
 *
 * @param a the Colour
 * @param s the scalar
 */
Colour operator*(const Colour &a, const float &s);

/**
 * Multiply two Colours
 *
 * @param a the first Colour
 * @param b the second Colour
 */
Colour operator*(const Colour &a, const Colour &b);
