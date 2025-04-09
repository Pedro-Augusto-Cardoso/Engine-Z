#include <Vect2.h>

Vect2::Vect2(float x = 0.0, float y = 0.0){
    this->x = x;
    this->y = y;
}

Vect2 Vect2::vsum(Vect2 v, Vect2 w){
    Vect2 s = Vect2(v.x + w.x, v.y + w.y);
    return s;
}

void Vect2::mscalar(Vect2 * v, float c){
    *v = Vect2(v->x * c, v->y * c);
}

float Vect2::mag(Vect2 v){
    return std::sqrt((v.x)*(v.x) + (v.y)*(v.y));
}

void Vect2::norm(Vect2 *v){
    mscalar(v, 1/(v->x*v->y));
}

float Vect2::dist(Vect2 v, Vect2 w){
    Vect2 wMinus = w;
    mscalar(&wMinus, -1);
    Vect2 s = vsum(v, wMinus);
    return mag(s);
}

float Vect2::ang(Vect2 v){
    return std::atan(v.x/v.y);
}

float Vect2::dot(Vect2 v, Vect2 w){
    return v.x * w.x + v.y * w.y;
}

float Vect2::ang2(Vect2 v, Vect2 w){
    return std::acos(dot(v, w)/(mag(v)*mag(w)));
}

void Vect2::rot(Vect2 * v, float t){
    *v = Vect2(v->x*std::cos(t) - v->y*std::sin(t), v->y*std::cos(t) + v->x*std::sin(t));
}