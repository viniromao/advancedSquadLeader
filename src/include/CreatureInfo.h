#ifndef _CREATURE_INFO_H_
#define _CREATURE_INFO_H_

enum MoveMode {
    RUN,
    WAIT,
};

enum FiringMode {
    HOLD_FIRE,
    FIRE_AT_WILL
};

class CreatureInfo {
    private:
    public:
        FiringMode firingMode = FIRE_AT_WILL;
        MoveMode moveMode = RUN;

        CreatureInfo();
        virtual ~CreatureInfo();
};

#endif