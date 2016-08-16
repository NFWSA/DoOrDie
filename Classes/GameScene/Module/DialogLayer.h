#ifndef __DIALOG_LAYER_H__
#define __DIALOG_LAYER_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include <functional>

class DialogLayer : public cocos2d::Layer
{
public:
	static DialogLayer* createWithFile(const std::string &filename);

    virtual bool init();
	virtual void onExitTransitionDidStart();
	virtual void onExit();

	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);

	void setDataFile(const std::string &filename);

	std::function<void()> onEnded;
private:
	cocos2d::EventListenerTouchOneByOne *_touchEvent;
	cocos2d::Sprite *m_box, *m_background;
	cocos2d::Label *m_speech;
	cocos2d::ValueMap m_data;
	int m_id, m_num;
};

#endif // __DIALOG_LAYER_H__
