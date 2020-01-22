//
// Created by chopperhl on 2/7/18.
//

#ifndef GAME_TANK_H
#define GAME_TANK_H

#include "cocos2d.h"
#include "Global.h"

class Tank : public cocos2d::Sprite {


public:

    CREATE_FUNC(Tank);

    bool init() override;

    Direction getDirection() const;

    void setDirection(Direction direction);

    int getSpeed() const;

    void setSpeed(int speed);

    void shoot();

private:

    Direction direction = UP;

    int speed = 0;

    void update(float dt) override;
};


#endif //GAME_TANK_H
