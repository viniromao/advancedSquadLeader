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
        Wiolan();
        virtual ~Wiolan();

        void render();
};

#endif