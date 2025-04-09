#include <Rect.h>

Rect::Rect(float x = 0.0, float y = 0.0, float w = 0.0, float h = 0.0){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Rect::vsum(Vect2 v, Rect * r){
    *r = Rect(r->x+v.x, r->y+v.y, r->w, r->h);
}

Vect2 Rect::center(Rect r){
    return Vect2(r.x + w/2, r.y + h/2);
}

float Rect::rdist(Rect r1, Rect r2){
    return Vect2(0, 0).dist(center(r1), center(r2));
}

bool Rect::in(Vect2 v, Rect r){
    Vect2 tmp = Vect2(-r.x, -r.y);
    tmp = tmp.vsum(tmp, v);
    if(tmp.x > 0 && tmp.y > 0){
        if(tmp.x <= r.w && tmp.y <= r.h){
            return true;
        }
    } else {
        return false;
    }
}