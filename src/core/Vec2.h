#ifndef VEC2
#define VEC2

/** This class handles all vector operations
 *  @class Vec2
 * 
 */
class Vec2{
public:
    float x; ///< X coordinate
    float y; ///< Y coordinate

public:
    /** Class constructor
     *  @param [in] x : initialisation value for x
     *  @param [in] y : initialisation value for y
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
     */
    Vec2 operator+(Vec2 v);

    /** Vector incrementation
     */
    Vec2 operator+=(Vec2 v);

    /** Vector substraction
     */
    Vec2 operator-(Vec2 v);

    /** Scaling / Multiplication by a float
     */
    Vec2 operator*(float a);

    /** @brief length/norm of the vector
     */
    float norm() const;

    /** @brief inequality operator
     */
    bool operator!=(const Vec2& rhs);

    /** @brief equality test operator
     */
    bool operator==(const Vec2& rhs);

    /** @brief Tests if a Vec2 is in an array
     *  @param t Pointer too first element of an array of Vec2
     *  @param size size of the array
     */
    bool isInTab(Vec2* t, int size) const;

    /** Prints value in the console for debugging purposes
     */
    void print() const;



};

#endif