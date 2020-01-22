//
// Created by chopperhl on 2/7/18.
//

#include "Bullet.h"

USING_NS_CC;

bool Bullet::init() {
    if (!Sprite::init()) {
        return false;
    }
    initWithFile("bullet.png");
    scheduleUpdate();
    return true;
}

Direction Bullet::getDirection() const {
    return direction;
}

void Bullet::setDirection(Direction direction) {
    Bullet::direction = direction;
    setRotation((direction - 1) * 90);
}

int Bullet::getSpeed() const {
    return speed;
}

void Bullet::setSpeed(int speed) {
    Bullet::speed = speed;
}

void Bullet::update(float dt) {
    switch (direction) {
        case UP: {
            Vec2 pos = getPosition();
            setPosition(pos.x, pos.y + dt * speed);
            break;
        }
        case DOWN: {
            Vec2 pos = getPosition();
            setPosition(pos.x, pos.y - dt * speed);
            break;
        }
        case LEFT: {
            Vec2 pos = getPosition();
            setPosition(pos.x - dt * speed, pos.y);
            break;
        }
        case RIGHT: {
            Vec2 pos = getPosition();
            setPosition(pos.x + dt * speed, pos.y);
            break;
        }
        default:

            break;
    }
}

