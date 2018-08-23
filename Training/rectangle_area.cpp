#include <iostream>
#include "rectangle_area.h"

using namespace std;

class Rectangle {
protected:
    int m_width = -1,
        m_height = -1;
public:
    virtual void display ()
    {
        cout << m_width << " " << m_height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input ()
    {
        cin >> m_width >> m_height;
    }
    void display()
    {
        cout << (m_width * m_height) << endl;
    }
};

int hackerrank::rectangle_area ()
{
    // START HACKERRANK GIVEN CODE

    /*
     * Declare a RectangleArea object
    */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;

    // END HACKERRANK GIVEN CODE
}
