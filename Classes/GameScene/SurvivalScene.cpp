#include "SurvivalScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include "Module\FlowCtrl.h"
#include "Module\ItemListLayer.h"
#include "Module\MakeListLayer.h"
#include "Module\GameOverLayer.h"
#include "SimpleAudioEngine.h"
#include "../HelpScene.h"

USING_NS_CC;
using namespace CocosDenshion;

void SurvivalScene::gameOver(EventCustom *event)
{
	auto scene = Scene::create();
	auto layer = GameOverLayer::createWithFunc();
	scene->addChild(layer);
	Director::getInstance()->replaceScene(scene);
}

void SurvivalScene::onRole1(cocos2d::Ref *ref)
{
	FlowCtrl::getInstance()->switchPeople(1);
	FlowCtrl::getInstance()->setValueChanged(CC_CALLBACK_2(SurvivalScene::setHpBar, this), CC_CALLBACK_2(SurvivalScene::setSatBar, this), CC_CALLBACK_2(SurvivalScene::setSpBar, this),
		CC_CALLBACK_2(SurvivalScene::setVitBar, this));
	FlowCtrl::getInstance()->setTimesChanged(CC_CALLBACK_1(SurvivalScene::setTimes, this));
	m_picture->setTexture("Role/1.png");
	setTimes(FlowCtrl::getInstance()->times());
}

void SurvivalScene::onRole2(cocos2d::Ref *ref)
{
	FlowCtrl::getInstance()->switchPeople(2);
	FlowCtrl::getInstance()->setValueChanged(CC_CALLBACK_2(SurvivalScene::setHpBar, this), CC_CALLBACK_2(SurvivalScene::setSatBar, this), CC_CALLBACK_2(SurvivalScene::setSpBar, this),
		CC_CALLBACK_2(SurvivalScene::setVitBar, this));
	FlowCtrl::getInstance()->setTimesChanged(CC_CALLBACK_1(SurvivalScene::setTimes, this));
	m_picture->setTexture("Role/2.png");
	setTimes(FlowCtrl::getInstance()->times());
}

void SurvivalScene::onRole3(cocos2d::Ref *ref)
{
	FlowCtrl::getInstance()->switchPeople(3);
	FlowCtrl::getInstance()->setValueChanged(CC_CALLBACK_2(SurvivalScene::setHpBar, this), CC_CALLBACK_2(SurvivalScene::setSatBar, this), CC_CALLBACK_2(SurvivalScene::setSpBar, this),
		CC_CALLBACK_2(SurvivalScene::setVitBar, this));
	FlowCtrl::getInstance()->setTimesChanged(CC_CALLBACK_1(SurvivalScene::setTimes, this));
	m_picture->setTexture("Role/3.png");
	setTimes(FlowCtrl::getInstance()->times());
}

void SurvivalScene::onUseItemClick(Ref *ref)
{
	auto layer = ItemListLayer::create();
	addChild(layer);
}

void SurvivalScene::onMakeItemClick(Ref *ref)
{
	auto layer = MakeListLayer::create();
	addChild(layer);
}

void SurvivalScene::onSkipClick(Ref *ref)
{
	setTimes(FlowCtrl::getInstance()->delTimes());
}

void SurvivalScene::onSleepClick(Ref *ref)
{
	if (FlowCtrl::getInstance()->balance()){
		return;
	}
	setDay(FlowCtrl::getInstance()->newDay());
	setTimes(FlowCtrl::getInstance()->times());
}

void SurvivalScene::onExploreClick(Ref *ref)
{
	// todo
	// any thing else need?
	FlowCtrl::getInstance()->exploreStart();
}

void SurvivalScene::onPauseClick(cocos2d::Ref *ref)
{
	auto scene = HelpUI::createScene();
	auto trans = TransitionMoveInT::create(0.5f, scene);
	Director::getInstance()->pushScene(trans);
}

void SurvivalScene::setCanSleep(const bool flag)
{
	if (flag){
		m_dayList->setVisible(false);
		m_nightList->setVisible(true);
	}
	else{
		m_dayList->setVisible(true);
		m_nightList->setVisible(false);
	}
}

void SurvivalScene::setDay(const int day)
{
	m_dayLabel->setString(Value(day).asString());
	if (FlowCtrl::getInstance()->havePeople(1))
		m_role1->setVisible(true);
	else
		m_role1->setVisible(false);
	if (FlowCtrl::getInstance()->havePeople(2))
		m_role2->setVisible(true);
	else
		m_role2->setVisible(false);
	if (FlowCtrl::getInstance()->havePeople(3))
		m_role3->setVisible(true);
	else
		m_role3->setVisible(false);
}

void SurvivalScene::setTimes(const int times)
{
	m_timesLabel->setString(Value(times).asString());
	setCanSleep(times == 0);
}

void SurvivalScene::setHpBar(const int value, const int max)
{
	m_hpBar->setPercent(value * 100 / max);
	m_hpLabel->setString(Value(value).asString());
}

void SurvivalScene::setSpBar(const int value, const int max)
{
	m_spBar->setPercent(value * 100 / max);
	m_spLabel->setString(Value(value).asString());
}

void SurvivalScene::setSatBar(const int value, const int max)
{
	m_satBar->setPercent(value * 100 / max);
	m_satLabel->setString(Value(value).asString());
}

void SurvivalScene::setVitBar(const int value, const int max)
{
	m_vitBar->setPercent(value * 100 / max);
	m_vitLabel->setString(Value(value).asString());
}

void SurvivalScene::setPicture(const std::string &filename)
{
	m_picture->setTexture(filename);
}

Scene* SurvivalScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SurvivalScene::create();
	scene->addChild(layer);
	layer->setName("layer");
	return scene;
}

bool SurvivalScene::init()
{
	if (!Layer::init())
		return false;

	auto background = CSLoader::createNode("UI/SurvivalBG.csb");
	addChild(background);
	
	m_role1 = static_cast<ui::Button*>(background->getChildByName("role1"));
	m_role1->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onRole1, this));
	m_role2 = static_cast<ui::Button*>(background->getChildByName("role2"));
	m_role2->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onRole2, this));
	m_role3 = static_cast<ui::Button*>(background->getChildByName("role3"));
	m_role3->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onRole3, this));
	
	m_ui = CSLoader::createNode("UI/SurvivalUI.csb");
	addChild(m_ui);

	m_picture = static_cast<Sprite*>(m_ui->getChildByName("picture"));
	m_dayLabel = static_cast<ui::Text*>(m_ui->getChildByName("dayLabGrp")->getChildByName("dayLabel"));
	m_timesLabel = static_cast<ui::Text*>(m_ui->getChildByName("timesLabGrp")->getChildByName("timesLabel"));
	m_hpBar = static_cast<ui::LoadingBar*>(m_ui->getChildByName("hpBar"));
	m_hpLabel = static_cast<ui::Text*>(m_hpBar->getChildByName("hpLabel"));
	m_spBar = static_cast<ui::LoadingBar*>(m_ui->getChildByName("spBar"));
	m_spLabel = static_cast<ui::Text*>(m_spBar->getChildByName("spLabel"));
	m_satBar = static_cast<ui::LoadingBar*>(m_ui->getChildByName("satBar"));
	m_satLabel = static_cast<ui::Text*>(m_satBar->getChildByName("satLabel"));
	m_vitBar = static_cast<ui::LoadingBar*>(m_ui->getChildByName("vitBar"));
	m_vitLabel = static_cast<ui::Text*>(m_vitBar->getChildByName("vitLabel"));
	m_dayList = static_cast<ui::ListView*>(m_ui->getChildByName("dayList"));
	static_cast<ui::Button*>(m_dayList->getChildByName("useItemBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onUseItemClick, this));
	static_cast<ui::Button*>(m_dayList->getChildByName("makeItemBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onMakeItemClick, this));
	static_cast<ui::Button*>(m_dayList->getChildByName("skipBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onSkipClick, this));
	m_nightList = static_cast<ui::ListView*>(m_ui->getChildByName("nightList"));
	static_cast<ui::Button*>(m_nightList->getChildByName("sleepBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onSleepClick, this));
	static_cast<ui::Button*>(m_nightList->getChildByName("exploreBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onExploreClick, this));
	static_cast<ui::Button*>(m_ui->getChildByName("pauseBtn"))->addClickEventListener(CC_CALLBACK_1(SurvivalScene::onPauseClick, this));

	//auto overEvent = EventListenerCustom::create("GameOver", CC_CALLBACK_1(SurvivalScene::gameOver, this));
	//getEventDispatcher()->addEventListenerWithSceneGraphPriority(overEvent, this);
	FlowCtrl::getInstance()->setGameOver(CC_CALLBACK_0(SurvivalScene::gameOver, this, nullptr));

	return true;
}

void SurvivalScene::onEnterTransitionDidFinish()
{
	onRole1(nullptr);
	setDay(FlowCtrl::getInstance()->day());
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/0001.mp3", true);
	Layer::onEnterTransitionDidFinish();
}