#include "ItemListLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Item.h"
#include "FlowCtrl.h"

USING_NS_CC;

ItemListLayer* ItemListLayer::create()
{
	ItemListLayer *pRet = new(std::nothrow) ItemListLayer();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->m_item = FlowCtrl::getInstance()->item();
		pRet->flushList();
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool ItemListLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bg = LayerColor::create(Color4B(0, 0, 0, 200));
	addChild(bg);

	auto layer = CSLoader::createNode("UI/ItemList.csb");
	addChild(layer);

	m_nameLabel = static_cast<ui::Text*>(layer->getChildByName("nameLabel"));
	m_descLabel = static_cast<ui::Text*>(layer->getChildByName("descLabel"));;
	m_icon = static_cast<Sprite*>(layer->getChildByName("icon"));
	m_itemList = static_cast<ui::ListView*>(layer->getChildByName("itemList"));
	auto btnList = static_cast<ui::ListView*>(layer->getChildByName("btnList"));
	m_useBtn = static_cast<ui::Button*>(btnList->getChildByName("useBtn"));
	m_useBtn->addClickEventListener(CC_CALLBACK_1(ItemListLayer::onUseClick, this));
	static_cast<ui::Button*>(btnList->getChildByName("returnBtn"))->addClickEventListener([=](Ref *ref){
		this->getParent()->removeChild(this);
	});

	return true;
}

void ItemListLayer::flushList()
{
	m_itemList->removeAllChildren();
	std::vector<std::string> list(m_item->itemList());
	for (auto &i : list){
		auto t = ui::Button::create();
		t->setTitleText(m_item->getName(i) + " * " + Value(m_item->getNum(i)).asString());
		t->setTitleFontSize(24);
		t->setColor(Color3B::WHITE);
		t->addClickEventListener(CC_CALLBACK_1(ItemListLayer::onItemClick, this));
		m_itemList->addChild(t);
	}
	if (m_item->getNum(m_nowId) == 0){
		m_nowId = "";
		m_nameLabel->setString("");
		m_descLabel->setString("Please click an item.");
		m_icon->setTexture("");
	}
	if (FlowCtrl::getInstance()->times() == 0)
		m_useBtn->setEnabled(false);
	else
		m_useBtn->setEnabled(true);
}

void ItemListLayer::onItemClick(cocos2d::Ref *ref)
{
	auto t = static_cast<ui::Button*>(ref);
	m_nowId = t->getTitleText();
	m_nowId.erase(m_nowId.find_first_of(" "));
	m_nowId = m_item->getId(m_nowId);
	m_nameLabel->setString(m_item->getName(m_nowId));
	m_descLabel->setString(m_item->getDesc(m_nowId));
	m_icon->setTexture(m_item->getIcon(m_nowId));
}

void ItemListLayer::onUseClick(cocos2d::Ref *ref)
{
	if (m_nowId == "")
		return;
	if (!m_item->useItem(m_nowId))
		return;
	m_item->delItem(m_nowId);
	FlowCtrl::getInstance()->delTimes();
	flushList();
}
