#include "DialogLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cmath>

USING_NS_CC;

using namespace cocostudio::timeline;

DialogLayer* DialogLayer::createWithFile(const std::string &filename)
{
	DialogLayer *pRet = new(std::nothrow) DialogLayer();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->setDataFile(filename);
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

void DialogLayer::setDataFile(const std::string &filename)
{
	m_data = FileUtils::getInstance()->getValueMapFromFile(filename);
	m_background->setTexture(m_data["speech" + Value(m_id).asString()].asValueMap()["background"].asString());
	m_background->setScale(Director::getInstance()->getVisibleSize().width / m_background->getContentSize().width);
	m_speech->setString(m_data["speech" + Value(m_id).asString()].asValueMap()["text" + Value(m_num).asString()].asString());
}

bool DialogLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto layer = LayerColor::create(Color4B(0, 0, 0, 255));
	addChild(layer);

	m_background = Sprite::create();
	addChild(m_background);
	m_background->setPosition(Director::getInstance()->getVisibleSize() / 2);

	m_box = Sprite::create("UI/Speech.png");
	addChild(m_box);
	m_box->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 10 + m_box->getContentSize().height / 2));

	m_speech = Label::createWithSystemFont("", "Arial", 32);
	addChild(m_speech);
	m_speech->setPosition(m_box->getPosition());
	m_speech->setLineBreakWithoutSpace(true);

	m_speech->setDimensions(Director::getInstance()->getVisibleSize().width - 60, m_box->getContentSize().height - 40);

	_touchEvent = EventListenerTouchOneByOne::create();
	_touchEvent->onTouchBegan = CC_CALLBACK_2(DialogLayer::onTouchBegan, this);
	_touchEvent->onTouchEnded = CC_CALLBACK_2(DialogLayer::onTouchEnded, this);
	_touchEvent->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchEvent, this);

	m_id = m_num = 0;
	onEnded = nullptr;

    return true;
}

void DialogLayer::onExitTransitionDidStart()
{
	_eventDispatcher->removeEventListener(_touchEvent);
}

void DialogLayer::onExit()
{
	_eventDispatcher->removeEventListener(_touchEvent);
}

bool DialogLayer::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
	return true;
}

void DialogLayer::onTouchEnded(cocos2d::Touch*, cocos2d::Event*)
{
	 ++m_num;
	 if (m_data["speech" + Value(m_id).asString()].asValueMap().size() - 1 == m_num){
		 ++m_id;
		 m_num = 0;
		 if (m_data.size() == m_id){
			 if (nullptr != onEnded)
				 onEnded();
			 getParent()->removeChild(this);
			 return;
		 }
	 }
	 m_background->setTexture(m_data["speech" + Value(m_id).asString()].asValueMap()["background"].asString());
	 m_background->setScale(Director::getInstance()->getVisibleSize().width / m_background->getContentSize().width);
	 auto sent = m_data["speech" + Value(m_id).asString()].asValueMap()["text" + Value(m_num).asString()].asString();
	 m_speech->setString(sent);
}
