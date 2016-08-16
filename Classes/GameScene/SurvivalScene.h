#ifndef __SURVIVAL_SCENE_H__
#define __SURVIVAL_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <functional>

class SurvivalScene : public cocos2d::Layer
{
public:
	void gameOver(cocos2d::EventCustom *event);

	void onRole1(cocos2d::Ref *ref);
	void onRole2(cocos2d::Ref *ref);
	void onRole3(cocos2d::Ref *ref);
	void onUseItemClick(cocos2d::Ref *ref);
	void onMakeItemClick(cocos2d::Ref *ref); 
	void onSkipClick(cocos2d::Ref *ref);
	void onSleepClick(cocos2d::Ref *ref);
	void onExploreClick(cocos2d::Ref *ref);
	void onPauseClick(cocos2d::Ref *ref);

	void setCanSleep(const bool flag);
	void setDay(const int day);
	void setTimes(const int times);
	void setHpBar(const int value, const int max);
	void setSpBar(const int value, const int max);
	void setSatBar(const int value, const int max);
	void setVitBar(const int value, const int max);
	void setPicture(const std::string &filename);

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SurvivalScene);

	virtual void onEnterTransitionDidFinish();

private:
	cocos2d::Node *m_ui;
	cocos2d::ui::LoadingBar *m_hpBar, *m_spBar, *m_satBar, *m_vitBar;
	cocos2d::ui::Button *m_role1, *m_role2, *m_role3;
	cocos2d::Sprite *m_picture;
	cocos2d::ui::Text *m_dayLabel, *m_hpLabel, *m_spLabel, *m_satLabel, *m_vitLabel, *m_timesLabel;
	cocos2d::ui::ListView *m_dayList, *m_nightList;
};

#endif //__SURVIVAL_SCENE_H__
