/** @file Vec2.h
 */
#ifndef VEC2
#define VEC2

/** @class Vec2
 *  @brief This class handles all vector operations
 */
class Vec2{
public:
    float x; ///< X coordinate
    float y; ///< Y coordinate

public:
    /** Class constructor
     *  @param x [in] Initialisation value for x
     *  @param y [in] Initialisation value for y
     */
    Vec2(float x, float y);

    /** Default constructor : initializes at (0, 0)
     *  
     */
    Vec2();

    /** Class destructor
     */
    ~Vec2();

    /** Vector addition
     *  @param v [in] Right hand side operator
     */
    Vec2 operator+(Vec2 v) const;

    /** Vector incrementation
     *  @param v [in] Right hand side operator
     */
    Vec2 operator+=(Vec2 v);

    /** Vector substraction
     *  @param v [in] Right hand side operator
     */
    Vec2 operator-(Vec2 v) const;

    /** Scaling / Multiplication by a float number
     *  @param a [in] Right hand side operator (float)
     */
    Vec2 operator*(float a) const;

    /** @brief length/norm of the vector
     *  @return lenghth of the vector
     */
    float norm() const;

    /** @brief inequality operator
     *  @param rhs [in] Right hand side operator
     */
    bool operator!=(const Vec2& rhs) const;

    /** @brief equality test operator
     *  @param rhs [in] Right hand side operator
     */
    bool operator==(const Vec2& rhs) const;

    /** @brief Tests if a Vec2 is in an array
     *  @param t [in] Pointer too first element of an array of Vec2
     *  @param size [in] size of the array
     */
    bool isInTab(const Vec2* t, int size) const;

    /** @brief finds a Vec2 in an array
     *  @param t [in] Pointer too first element of an array of Vec2
     *  @param size [in] size of the array
     *  @return index of t where the Vec2 can be found
     */
    int findInTab(const Vec2* t, int size) const;


};

#endif