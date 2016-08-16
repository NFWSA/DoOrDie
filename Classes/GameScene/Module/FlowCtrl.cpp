#include "FlowCtrl.h"
#include "../Role/SaveValue.h"
#include "cocos2d.h"
#include "../SurvivalScene.h"
#include "../ExploreScene.h"
#include "../../SaveSelectScene.h"
#include "DialogLayer.h"
#include "../../CreditScene.h"
#include "Item.h"

USING_NS_CC;

FlowCtrl* FlowCtrl::getInstance()
{
	if (nullptr == instance)
		instance = new FlowCtrl();
	return instance;
}

FlowCtrl::FlowCtrl() : m_days(0), m_nowPlayer(0), m_gameOver(nullptr), m_timesChanged(nullptr), m_expScene(nullptr), m_surScene(nullptr), m_explored(false)
{
	m_config = FileUtils::getInstance()->getValueMapFromFile("config.dat");
	m_story = FileUtils::getInstance()->getValueMapFromFile("Story.dat");
	m_item = new Item("itemConfig.dat");

	m_makeList = FileUtils::getInstance()->getValueMapFromFile("makeConfig.dat");
}

Item* FlowCtrl::item()
{
	return m_item;
}

SaveValue* FlowCtrl::people()
{
	if (m_players.size() <= m_nowPlayer)
		return nullptr;
	return m_players[m_nowPlayer];
}

ValueMap* FlowCtrl::makeList()
{
	return &m_makeList;
}

bool FlowCtrl::havePeople(const int id) const
{
	for (auto i : m_players)
	if (i->id == id)
		return true;
	return false;
}

const int FlowCtrl::day() const
{
	return m_days;
}

const int FlowCtrl::times() const
{
	if (m_players.size() <= m_nowPlayer)
		return 0;
	return m_players[m_nowPlayer]->times;
}

const int FlowCtrl::mapNumber() const
{
	return m_config.at("mapNumber").asInt();
}

void FlowCtrl::newGame(const int saveNum, const int saveType)
{
	m_days = 0;
	m_saveNum = saveNum;
	m_surScene = nullptr;
	m_expScene = nullptr;
	m_explored = false;
	m_gameOver = nullptr;

	clearGame();
	m_item->clearItem();

	auto i = new SaveValue(m_config["role1"].asValueMap());
	m_players.push_back(i);
	m_nowPlayer = 0;

	if (SaveSelect::SAVE_LOAD == saveType){
		//load old game
		ValueMap doc = FileUtils::getInstance()->getValueMapFromFile("Save/" + Value(m_saveNum).asString() + ".sav");
		m_days = doc["day"].asInt();
		for (auto &i : doc["items"].asValueMap()){
			m_item->addItem(i.first, i.second.asInt());
		}
		if (doc.find("role2") != doc.end()){
			auto i = new SaveValue(m_config["role2"].asValueMap());
			m_players.push_back(i);
		}
		if (doc.find("role3") != doc.end()){
			auto i = new SaveValue(m_config["role3"].asValueMap());
			m_players.push_back(i);
		}
		for (auto i : m_players){
			ValueMap role(doc["role" + Value(i->id).asString()].asValueMap());
			i->speed = role["speed"].asFloat();
			i->maxTimes = role["maxTimes"].asInt();
			i->times = role["times"].asInt();
			i->setMaxHealth(role["maxHp"].asInt());
			i->setHealth(role["hp"].asInt());
			i->setMaxSpirit(role["maxSp"].asInt());
			i->setSpirit(role["sp"].asInt());
			i->setMaxSatiation(role["maxSat"].asInt());
			i->setSatiation(role["sat"].asInt());
			i->setMaxVitality(role["maxVit"].asInt());
			i->setVitality(role["vit"].asInt());
		}
	}
	else {
		m_item->addItem("base", 1);
		m_item->addItem("food1", 5);
		m_item->addItem("food2", 10);
		m_item->addItem("stone", 100);
		m_item->addItem("wood", 100);
	}
}

void FlowCtrl::startGame()
{
	m_surScene = SurvivalScene::createScene();
	auto transScene = TransitionPageTurn::create(1.0f, m_surScene, false);
	Director::getInstance()->replaceScene(transScene);
	static_cast<SurvivalScene*>(m_surScene->getChildByName("layer"))->setDay(newDay());
}

void FlowCtrl::saveGame()
{
	//save the document
	ValueMap doc, items;
	doc["day"] = m_days;
	for (auto &i : m_item->itemList()){
		items[i] = m_item->getNum(i);
	}
	doc["items"] = items;
	for (auto i : m_players){
		ValueMap role;
		role["id"] = i->id;
		role["speed"] = i->speed;
		role["maxTimes"] = i->maxTimes;
		role["times"] = i->times;
		role["maxHp"] = i->getMaxHealth();
		role["hp"] = i->getHealth();
		role["maxSp"] = i->getMaxSpirit();
		role["sp"] = i->getSpirit();
		role["maxSat"] = i->getMaxSatiation();
		role["sat"] = i->getSatiation();
		role["maxVit"] = i->getMaxVitality();
		role["vit"] = i->getVitality();
		doc["role" + Value(i->id).asString()] = role;
	}
	auto path = FileUtils::getInstance()->fullPathForFilename("Save/default.sav");
	path.erase(path.size() - 11);
	FileUtils::getInstance()->writeValueMapToFile(doc, path + Value(m_saveNum).asString() + ".sav");
}

void FlowCtrl::clearGame()
{
	for (auto i : m_players)
		delete i;
	m_players.clear();
}

void FlowCtrl::exploreStart()
{
	setValueChanged();
	setTimesChanged();
	m_players[m_nowPlayer]->explored = true;
	m_explored = true;
	m_expScene = ExploreScene::createScene();
	auto transScene = TransitionPageTurn::create(1.0f, m_expScene, false);
	Director::getInstance()->pushScene(transScene);
}

void FlowCtrl::exploreFinish()
{
	Director::getInstance()->popScene();
	if (balance())
		return;
	newDay();
}

void FlowCtrl::setGameOver(std::function<void()> gameOver)
{
	m_gameOver = gameOver;
}

void FlowCtrl::setTimesChanged(std::function<void(const int)> timesChanged)
{
	m_timesChanged = timesChanged;
}

void FlowCtrl::switchPeople(const int id)
{
	if (!havePeople(id))
		return;
	if (m_players[m_nowPlayer]->id == id)
		return;
	setValueChanged();
	for (auto i = 0; i < m_players.size(); ++i){
		if (m_players[i]->id == id)
			m_nowPlayer = i;
	}
}

void FlowCtrl::setValueChanged(std::function<void(const int, const int)> hpChanged, std::function<void(const int, const int)> saChanged,
	std::function<void(const int, const int)> spChanged, std::function<void(const int, const int)> vitChanged)
{
	if (m_players.size() <= m_nowPlayer)
		return;
	m_players[m_nowPlayer]->setValueChanged(hpChanged, saChanged, spChanged, vitChanged);
}

const bool FlowCtrl::balance()
{
	bool flag = false, over = false;
	for (auto &i : m_players){
		ValueMap role = m_config["role" + Value(i->id).asString()].asValueMap();

		//less proper
		if (i->getSatiation() == 0)
			procMap(m_config["satLess"].asValueMap(), *i);
		if (i->getSpirit() == 0)
			procMap(m_config["spLess"].asValueMap(), *i);
		if (i->getVitality() == 0)
			procMap(m_config["vitLess"].asValueMap(), *i);

		//little proper
		if (i->getSatiation() < m_config["satMin"].asValueMap()["value"].asInt())
			procMap(m_config["satMin"].asValueMap(), *i);
		if (i->getSpirit() < m_config["spMin"].asValueMap()["value"].asInt())
			procMap(m_config["spMin"].asValueMap(), *i);
		if (i->getVitality() < m_config["vitMin"].asValueMap()["value"].asInt())
			procMap(m_config["vitMin"].asValueMap(), *i);

		//must per day
		//explore or sleep
		if (i->explored)
			procMap(role["explore"].asValueMap(), *i);
		else
			procMap(role["sleep"].asValueMap(), *i);

		//alone ?
		if (!i->explored && (m_players.size() == 1 || (m_players.size() == 2 && m_explored)))
			procMap(role["alone"].asValueMap(), *i);
		i->explored = false;

		if (i->getHealth() == 0){
			//game over
			if (i->id == 1)
				over = true;
			delete i;
			i = nullptr;
			flag = true;
		}
	}
	m_explored = false;
	if (flag)
	for (int i = m_players.size() - 1; i >= 0; --i)
	if (m_players[i] == nullptr)
		m_players.erase(m_players.begin() + i);
	if (over){
		if (nullptr != m_gameOver)
			m_gameOver();
		//m_surScene->getEventDispatcher()->dispatchCustomEvent("GameOver");
		return true;
	}
	return false;
}

const int FlowCtrl::newDay()
{
	for (auto &i : m_players){
		i->times = i->maxTimes;
	}
	saveGame();
	++m_days;
	if (m_story.find("day" + Value(m_days).asString()) != m_story.end()){
		auto layer = DialogLayer::createWithFile(m_story.at("day" + Value(m_days).asString()).asValueMap()["filename"].asString());
		m_surScene->addChild(layer);
		if (m_days == 35){
			layer->onEnded = [=](){
				auto scene = CreditScene::createScene("Credit.dat", "CreditTexture.dat");
				auto trans = TransitionFade::create(2.0f, scene);
				Director::getInstance()->replaceScene(trans);
			};
		}
	}
	if (m_days == 5){
		auto i = new SaveValue(m_config["role2"].asValueMap());
		m_players.push_back(i);
	}
	if (m_days == 10){
		auto i = new SaveValue(m_config["role3"].asValueMap());
		m_players.push_back(i);
	}
	return m_days;
}

const int FlowCtrl::delTimes()
{
	// need to change
	if (m_players.size() <= m_nowPlayer)
		return 0;
	if (m_players[m_nowPlayer]->times <= 0)
		return 0;
	--(m_players[m_nowPlayer]->times);
	if (nullptr != m_timesChanged)
		m_timesChanged(m_players[m_nowPlayer]->times);
	return m_players[m_nowPlayer]->times;
}

void FlowCtrl::procMap(const ValueMap &map)
{
	if (m_players.size() <= m_nowPlayer)
		return;
	procMap(map, *m_players[m_nowPlayer]);
}

void FlowCtrl::procMap(const ValueMap &map, SaveValue &people)
{
	for (auto &i : map){
		if (i.first == "hp")
			people.setHealth(people.getHealth() + i.second.asInt());
		if (i.first == "sp")
			people.setSpirit(people.getSpirit() + i.second.asInt());
		if (i.first == "sat")
			people.setSatiation(people.getSatiation() + i.second.asInt());
		if (i.first == "vit")
			people.setVitality(people.getVitality() + i.second.asInt());

		if (i.first == "hpMax")
			people.setMaxHealth(people.getMaxHealth() + i.second.asInt());
		if (i.first == "spMax")
			people.setMaxSpirit(people.getMaxSpirit() + i.second.asInt());
		if (i.first == "satMax")
			people.setMaxSatiation(people.getMaxSatiation() + i.second.asInt());
		if (i.first == "vitMax")
			people.setMaxVitality(people.getMaxVitality() + i.second.asInt());

		if (i.first == "speed")
			people.speed += i.second.asFloat();
		if (i.first == "range")
			people.range += i.second.asInt();
		if (i.first == "timesMax")
			people.maxTimes += i.second.asInt();
	}
}
