#include <Vect2.h>

class Rect{
    public:
        float x, y, w, h;
        Rect(float x, float y, float w, float h);
        void vsum(Vect2 v, Rect *r);
        Vect2 center(Rect r);
        float rdist(Rect r1, Rect r2); // Distance between the center of 2 rectangles
        bool in(Vect2 v, Rect r);

};