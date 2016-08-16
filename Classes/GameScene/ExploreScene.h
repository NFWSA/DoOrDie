#ifndef __EXPLORE_SCENE_H__
#define __EXPLORE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Player;

class ExploreScene : public cocos2d::Layer
{
public:
	void setHpBar(const int value, const int max);
	void setItemLabel(const std::string &name, const int num);

	void update(float dt) override;

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ExploreScene);

private:
	void exploreFinish(const bool dead = false);

	Player *m_player;
	float m_time, m_maxTime;
	cocos2d::ui::LoadingBar *m_timeBar, *m_hpBar;
	cocos2d::ui::Text *m_timeLabel, *m_hpLabel, *m_itemName, *m_itemNum, *m_itemLabel;
	cocos2d::EventListenerTouchOneByOne *m_screenListener;
};

#endif //__EXPLORE_SCENE_H__
