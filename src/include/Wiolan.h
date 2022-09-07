#ifndef _WIOLAN_H_
#define _WIOLAN_H_

#include"include/Creature.h"

class Wiolan: public Creature {
    private:
        CircleShape shape; 
        float size;

        void intiVariables();

    public:
        CircleShape shadowShape;
        CircleShape destinationShape;

        Wiolan();
        Wiolan(Vector2f position);
        virtual ~Wiolan();

        void render(RenderTarget *target);
        void renderDestinationShadow(RenderTarget *target);
        void renderShadow(RenderTarget *target);
        void initShape();
        void initShadowShape(Vector2f position);
        void initDestinationShape(Vector2f position);
        void clearShadow();
        void initShape(Vector2f position);
        void setPosition(Vector2f position);
};

#endif