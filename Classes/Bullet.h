//
// Created by chopperhl on 2/7/18.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "cocos2d.h"
#include "Global.h"

class Bullet : public cocos2d::Sprite {
public:
    CREATE_FUNC(Bullet);

    bool init() override;

    Direction getDirection() const;

    void setDirection(Direction direction);

    int getSpeed() const;

    void setSpeed(int speed);

private:
    Direction direction = UP;

    int speed = 300;

    void update(float dt) override;
};


#endif //GAME_BULLET_H
