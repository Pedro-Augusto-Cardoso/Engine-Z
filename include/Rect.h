#include <Vect2.h>

class Rect{
    public:
        float x, y, w, h;
        Rect(float x = 0.0, float y = 0.0, float w = 0.0, float h = 0.0);
        void vsum(Vect2 v, Rect *r);
        Vect2 center(Rect r);
        float rdist(Rect r1, Rect r2); // Distance between the center of 2 rectangles
        bool in(Vect2 v, Rect r);

};