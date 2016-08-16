#ifndef __GAMEOVER_LAYER_H__
#define __GAMEOVER_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <functional>

class GameOverLayer : public cocos2d::Layer
{
public:
	static GameOverLayer* createWithFunc(std::function<void()> next = nullptr);
	virtual bool init();

	void onClick(cocos2d::Ref*);

private:
	cocos2d::ui::Button *m_nextBtn;
	std::function<void()> m_nextFunc;
};

#endif // __GAMEOVER_LAYER_H__
