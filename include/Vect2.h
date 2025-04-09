#include <Sprite.h>

class Vect2{
    public:
        float x, y;
        Vect2(float x, float y);
        Vect2 vsum(Vect2 v, Vect2 w);
        void mscalar(Vect2 *v, float c);
        float mag(Vect2 v);
        void norm(Vect2 * v);
        float dot(Vect2 v, Vect2 w);
        float dist(Vect2 v, Vect2 w);
        float ang(Vect2 v);
        float ang2(Vect2 v, Vect2 w);
        void rot(Vect2 *v, float t);
        

};