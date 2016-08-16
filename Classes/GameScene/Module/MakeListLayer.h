#ifndef __MAKE_LIST_LAYER_H__
#define __MAKE_LIST_LAYER_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include <functional>

class Item;

class MakeListLayer : public cocos2d::Layer
{
public:

	void flushList();
	void onToolClick(cocos2d::Ref *ref);
	void onItemClick(cocos2d::Ref *ref);
	void onMakeClick(cocos2d::Ref *ref);

	static MakeListLayer* create();
	virtual bool init();
private:
	Item *m_item;
	cocos2d::ValueMap *m_makeList;
	cocos2d::ui::Text *m_nameLabel, *m_descLabel;
	cocos2d::Sprite *m_icon;
	cocos2d::ui::ScrollView *m_toolList, *m_itemList;
	cocos2d::ui::Button *m_makeBtn;
	std::string m_nowToolId, m_nowItemId;

};

#endif // __MAKE_LIST_LAYER_H__
