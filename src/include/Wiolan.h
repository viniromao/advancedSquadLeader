#ifndef _WIOLAN_H_
#define _WIOLAN_H_

#include"include/Creature.h"

class Wiolan: public Creature {
    private:
        CircleShape shape; 
        float size;

        void intiVariables();

    public:
        Wiolan();
        Wiolan(Vector2f position);
        virtual ~Wiolan();

        void render(RenderTarget *target);
        void initShape();
        void initShape(Vector2f position);
        void setPosition(Vector2f position);
};

#endif