//
// Created by chopperhl on 2/7/18.
//

#include "MainScene.h"

USING_NS_CC;

bool MainScene::init() {
    durLong = 200;
    if (!Scene::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    player = Tank::create();
    player->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    addChild(player);
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);
    listener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    scheduleUpdate();
    return true;
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event) {
    if (player != nullptr) {
        if ((player->getDirection() == UP && keyCode == EventKeyboard::KeyCode::KEY_W)
            || (player->getDirection() == DOWN && keyCode == EventKeyboard::KeyCode::KEY_S)
            || (player->getDirection() == LEFT && keyCode == EventKeyboard::KeyCode::KEY_A)
            || (player->getDirection() == RIGHT && keyCode == EventKeyboard::KeyCode::KEY_D)) {
            player->setSpeed(0);
        }
    }
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event) {
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_J:
            player->shoot();
            break;
        case EventKeyboard::KeyCode::KEY_W:
            if (player != nullptr) {
                player->setDirection(UP);
            }
            break;
        case EventKeyboard::KeyCode::KEY_S:
            if (player != nullptr) {
                player->setDirection(DOWN);
            }
            break;
        case EventKeyboard::KeyCode::KEY_A:
            if (player != nullptr) {
                player->setDirection(LEFT);
            }
            break;
        case EventKeyboard::KeyCode::KEY_D:
            if (player != nullptr) {
                player->setDirection(RIGHT);
            }
            break;
        default:
            break;
    }
}

/**
 * 刷新敌人
 * @param dt
 */
void MainScene::update(float dt) {
    durLong++;
    CCLog("%ld\n", durLong);
    if (durLong >= 200) {
        float f = random(0, 2);
        spanPos = (int) f;
        durLong = 0;
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Tank *enmy = Tank::create();
        enmy->setSpeed(150);
        if (spanPos == 0) {
            enmy->setPosition(20, visibleSize.height);
        }
        if (spanPos == 1) {
            enmy->setPosition(visibleSize.width / 2, visibleSize.height);
        }
        if (spanPos == 2) {
            enmy->setPosition(visibleSize.width - 20, visibleSize.height);
        }
        addChild(enmy);
        enmy->setDirection(Direction::DOWN);
    }


}
