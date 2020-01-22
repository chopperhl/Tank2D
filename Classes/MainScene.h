//
// Created by chopperhl on 2/7/18.
//

#ifndef GAME_MAINSCENE_H
#define GAME_MAINSCENE_H


#include "cocos2d.h"
#include "Tank.h"

class MainScene : public cocos2d::Scene {
public:

    CREATE_FUNC(MainScene);

    bool init() override;

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

private:
    long durLong = 0;
    int  spanPos = 0;

    Tank *player = nullptr;

    void update(float dt) override;
};


#endif
