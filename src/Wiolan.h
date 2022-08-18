#ifndef _WIOLAN_H_
#define _WIOLAN_H_

#include"Creature.h"

class Wiolan: public Creature {
    private:
        CircleShape shape; 
        float size;

        void intiVariables();
        void initShape(Vector2f position);

    public:
        Wiolan(Vector2f position);
        virtual ~Wiolan();

        void render(RenderTarget *target);
};

#endif