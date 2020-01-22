#include "AppDelegate.h"
#include "Global.h"
#include "MainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() = default;

AppDelegate::~AppDelegate() = default;

void AppDelegate::initGLContextAttrs() {

    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::createWithRect("Game", Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(SCREEN_WIDTH, SCREEN_HEIGHT, ResolutionPolicy::EXACT_FIT);

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0f / 60);

    auto fileUtils = FileUtils::getInstance();
    fileUtils->addSearchPath("fonts");
    fileUtils->addSearchPath("images");
    fileUtils->addSearchPath("configs");
    fileUtils->addSearchPath("sounds");
    MainScene *scene = MainScene::create();
    director->runWithScene(scene);
    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
