#ifndef _AUROPODAS_H_
#define _AUROPODAS_H_

#include"include/Creature.h"
class Auropodas : public Creature
{
private:
    CircleShape shape; 
    Sprite sprite;
    Texture texture;

    void intiVariables();
public:
    CircleShape shadowShape;
    CircleShape destinationShape;
    unsigned sight;

    ClickEventProducer *producer;
    Auropodas();
    Auropodas(ClickEventProducer *producer);
    Auropodas(Vector2f position);
    virtual ~Auropodas();

    void render(RenderTarget *target);
    void renderHud(RenderTarget *target);
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