#ifndef __FLOW_CTRL_H__
#define __FLOW_CTRL_H__

#include "cocos2d.h"
#include <functional>

class SaveValue;
class SurvivalScene;
class Item;

class FlowCtrl
{
public:
	static FlowCtrl* getInstance();

	Item* item();
	SaveValue* people();
	cocos2d::ValueMap* makeList();
	bool havePeople(const int id) const;
	const int day() const;
	const int times() const;
	const int mapNumber() const;

	void newGame(const int saveNum, const int saveType);
	void startGame();
	void saveGame();
	void clearGame();
	void exploreStart();
	void exploreFinish();

	void setGameOver(std::function<void()> gameOver = nullptr);
	void setTimesChanged(std::function<void(const int)> timesChanged = nullptr);
	void switchPeople(const int id);
	void setValueChanged(std::function<void(const int, const int)> hpChanged = nullptr, std::function<void(const int, const int)> saChanged = nullptr,
		std::function<void(const int, const int)> spChanged = nullptr, std::function<void(const int, const int)> vitChanged = nullptr);
	const bool balance();
	const int newDay();
	const int delTimes();
	void procMap(const cocos2d::ValueMap &map);

private:
	FlowCtrl();
	void procMap(const cocos2d::ValueMap &map, SaveValue &people);

	int m_days;
	std::vector<SaveValue*>::size_type m_nowPlayer;
	std::function<void()> m_gameOver;
	std::function<void(const int)> m_timesChanged;
	std::vector<SaveValue*> m_players;
	Item *m_item;
	int m_saveNum;
	cocos2d::Scene *m_expScene, *m_surScene;
	cocos2d::ValueMap m_config, m_story, m_makeList;
	bool m_explored;
};

static FlowCtrl *instance = nullptr;

#endif //__FLOW_CTRL_H__
