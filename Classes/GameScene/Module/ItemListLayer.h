#ifndef __ITEM_LIST_LAYER_H__
#define __ITEM_LIST_LAYER_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"

class Item;

class ItemListLayer : public cocos2d::Layer
{
public:
	static ItemListLayer* create();
	virtual bool init();

	void flushList();
	void onItemClick(cocos2d::Ref *ref);
	void onUseClick(cocos2d::Ref *ref);

private:
	Item *m_item;
	cocos2d::ui::Text *m_nameLabel, *m_descLabel;
	cocos2d::Sprite *m_icon;
	cocos2d::ui::ListView *m_itemList;
	cocos2d::ui::Button *m_useBtn;
	std::string m_nowId;
};

#endif // __ITEM_LIST_LAYER_H__
