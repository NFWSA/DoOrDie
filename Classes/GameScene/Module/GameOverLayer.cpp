#include "cocostudio/CocoStudio.h"
#include "GameOverLayer.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include <functional>

USING_NS_CC;

using namespace CocosDenshion;
using namespace cocostudio::timeline;

GameOverLayer* GameOverLayer::createWithFunc(std::function<void()> next)
{
	GameOverLayer *pRet = new(std::nothrow) GameOverLayer();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->m_nextFunc = next;
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool GameOverLayer::init()
{
	if (!Layer::init())
		return false;

	m_nextFunc = nullptr;

	auto layer = LayerColor::create(Color4B(77, 77, 77, 200));
	addChild(layer);

	auto info = Label::createWithSystemFont("Game Over", "Arial", 64);
	addChild(info);
	info->setPosition(Director::getInstance()->getVisibleSize() / 2);
	m_nextBtn = ui::Button::create();
	m_nextBtn->setTitleText("Please touch here to restart...");
	m_nextBtn->setTitleFontName("Arial");
	m_nextBtn->setTitleFontSize(36);
	addChild(m_nextBtn);
	m_nextBtn->setPosition(Vec2(info->getPositionX(), info->getPositionY() - info->getContentSize().height));
	m_nextBtn->addClickEventListener(CC_CALLBACK_1(GameOverLayer::onClick, this));

	return true;
}

void GameOverLayer::onClick(Ref *ref)
{
	if (nullptr != m_nextFunc)
		m_nextFunc();
	else
		Director::getInstance()->popScene();
}
