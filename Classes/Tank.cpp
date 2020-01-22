//
// Created by chopperhl on 2/7/18.
//

#include "Tank.h"
#include "Bullet.h"

USING_NS_CC;

bool Tank::init() {
    if (!Sprite::init()) {
        return false;
    }
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player.plist");
    initWithSpriteFrameName("player1_1_1_1.png");
    scheduleUpdate();
    return true;
}

void Tank::update(float dt) {
    if (speed <= 0) {
        return;
    }
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

Direction Tank::getDirection() const {
    return direction;
}

void Tank::setDirection(Direction direction) {
    if (speed <= 0) {
        speed = 150;
    }

    if (direction == Tank::direction) {
        return;
    }
    setSpriteFrame("player1_1_1_1.png");
    setRotation((direction - 1) * 90);
    Tank::direction = direction;
}

int Tank::getSpeed() const {
    return speed;
}

void Tank::setSpeed(int speed) {
    Tank::speed = speed;
}

void Tank::shoot() {
    switch (direction) {
        case UP: {
            auto node = getParent();
            Bullet *bullet = Bullet::create();
            Vec2 p = getPosition();
            bullet->setPosition(p.x, p.y + 20);
            bullet->setDirection(direction);
            node->addChild(bullet);
            break;
        }
        case DOWN: {
            auto node = getParent();
            Bullet *bullet = Bullet::create();
            Vec2 p = getPosition();
            bullet->setPosition(p.x, p.y - 20);
            bullet->setDirection(direction);
            node->addChild(bullet);
            break;
        }
        case LEFT: {
            auto node = getParent();
            Bullet *bullet = Bullet::create();
            Vec2 p = getPosition();
            bullet->setPosition(p.x - 20, p.y);
            bullet->setDirection(direction);
            node->addChild(bullet);
            break;
        }
        case RIGHT: {
            auto node = getParent();
            Bullet *bullet = Bullet::create();
            Vec2 p = getPosition();
            bullet->setPosition(p.x + 20, p.y);
            bullet->setDirection(direction);
            node->addChild(bullet);
            break;
        }
        default:
            break;
    }
}

