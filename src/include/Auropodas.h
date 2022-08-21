#ifndef _AUROPODAS_H_
#define _AUROPODAS_H_

#include"include/Creature.h"
class Auropodas : public Creature
{
private:
    CircleShape shape; 
    float size;

    void intiVariables();
public:
    Auropodas();
    Auropodas(Vector2f position);
    virtual ~Auropodas();

    void render(RenderTarget *target);
    void initShape();
    void initShape(Vector2f position);
    void setPosition(Vector2f position);
};
#endif