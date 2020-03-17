
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
     */
    Vec2();

    /** Class destructor
     */
    ~Vec2();

    /** Vector addition
     */
    Vec2 operator+(Vec2 v);

    /** Vector substraction
     */
    Vec2 operator-(Vec2 v);

    /** Scaling / Multiplication by a float
     */
    Vec2 operator*(float a);



};