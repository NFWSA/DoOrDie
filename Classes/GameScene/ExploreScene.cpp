#include "ExploreScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"
#include "TypeDefine.h"
#include "Role/SaveValue.h"
#include "Role/Player.h"
#include "Role/Enemy.h"
#include "Module/FlowCtrl.h"
#include <cmath>

USING_NS_CC;
using namespace CocosDenshion;

void ExploreScene::setHpBar(const int value, const int max)
{
	m_hpBar->setPercent(value * 100 / max);
	m_hpLabel->setString(Value(value).asString());
}

void ExploreScene::setItemLabel(const std::string &name, const int num)
{
	m_itemName->setString(name);
	m_itemNum->setString(Value(num).asString());
	m_itemLabel->setOpacity(255);
	auto action = FadeOut::create(1.0f);
	m_itemLabel->runAction(action);
}

void ExploreScene::exploreFinish(const bool dead)
{
	_eventDispatcher->removeEventListener(m_screenListener);
	unscheduleUpdate();
	m_player->unscheduleUpdate();
	m_player->onItemGet = nullptr;
	m_player->onHpChanged = nullptr;
	m_player->onDied = nullptr;
	if (dead){
		auto people = FlowCtrl::getInstance()->people();
		people->setHealth(people->getHealth() - 10);
	}
	FlowCtrl::getInstance()->exploreFinish();
}

void ExploreScene::update(float dt)
{
	m_time -= dt;

	m_timeBar->setPercent(m_time * 100.0f / m_maxTime);
	m_timeLabel->setString(Value(static_cast<int>(m_time)).asString());
	if (m_time <= 0.0f){
		exploreFinish();
	}
}

Scene* ExploreScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ExploreScene::create();
	scene->addChild(layer);
	layer->setName("layer");
	return scene;
}

bool ExploreScene::init()
{
	if (!Layer::init())
		return false;

	auto background = MapType::create("Map/ExploreScene" + Value(random() % FlowCtrl::getInstance()->mapNumber()).asString() + ".tmx");
	addChild(background);
	background->getLayer("Meta")->setVisible(false);
	background->getLayer("Fog")->setLocalZOrder(100);
	auto objects = background->getObjectGroup("Objects");
	auto player = objects->getObject("Player");
	m_maxTime = m_time = Value(player["Time"].asString()).asFloat();
	SimpleAudioEngine::getInstance()->playBackgroundMusic(player["BGM"].asString().c_str(), true);

	m_player = Player::createWithMap(background);

	auto enemys = objects->getObjects();
	for (auto &i : enemys){
		auto j = i.asValueMap();
		if ("Enemy" == j["name"].asString()){
			auto enemy = Enemy::createWithEnv(background, m_player, j);
			// addChild(enemy);
			background->addChild(enemy);
			enemy->setLocalZOrder(50);
		}
	}

	m_screenListener = EventListenerTouchOneByOne::create();
	m_screenListener->onTouchBegan = [](Touch* touch, Event* event) -> bool{
		return true;
	};
	m_screenListener->onTouchMoved = [=](Touch* touch, Event* event){
		m_player->setTar(touch->getLocation());
	};
	m_screenListener->onTouchEnded = [=](Touch* touch, Event* event){
		m_player->setTar(touch->getLocation());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_screenListener, this);

	addChild(m_player);

	m_player->onItemGet = CC_CALLBACK_2(ExploreScene::setItemLabel, this);
	m_player->onHpChanged = CC_CALLBACK_2(ExploreScene::setHpBar, this);
	m_player->onDied = CC_CALLBACK_0(ExploreScene::exploreFinish, this, true);

	auto layer = CSLoader::createNode("UI/ExploreUI.csb");
	addChild(layer);

	m_timeBar = static_cast<ui::LoadingBar*>(layer->getChildByName("timeBar"));
	m_timeLabel = static_cast<ui::Text*>(m_timeBar->getChildByName("timeLabel"));
	m_hpBar = static_cast<ui::LoadingBar*>(layer->getChildByName("hpBar"));
	m_hpLabel = static_cast<ui::Text*>(m_hpBar->getChildByName("hpLabel"));
	m_itemLabel = static_cast<ui::Text*>(layer->getChildByName("itemLabGrp"));
	m_itemName = static_cast<ui::Text*>(m_itemLabel->getChildByName("nameLabel"));
	m_itemNum = static_cast<ui::Text*>(m_itemLabel->getChildByName("numLabel"));

	m_itemLabel->setOpacity(0);
	m_itemLabel->setVisible(true);

	setHpBar(m_player->getHp(), m_player->getMaxHp());

	scheduleUpdate();

	return true;
}
