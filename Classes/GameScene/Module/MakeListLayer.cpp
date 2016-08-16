#include "MakeListLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "FlowCtrl.h"
#include "../Role/SaveValue.h"
#include "Item.h"

USING_NS_CC;

MakeListLayer* MakeListLayer::create()
{
	MakeListLayer *pRet = new(std::nothrow) MakeListLayer();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->m_item = FlowCtrl::getInstance()->item();
		pRet->m_makeList = FlowCtrl::getInstance()->makeList();
		pRet->flushList();
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool MakeListLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto bg = LayerColor::create(Color4B(0, 0, 0, 200));
	addChild(bg);

	auto layer = CSLoader::createNode("UI/MakeList.csb");
	addChild(layer);

	m_nameLabel = static_cast<ui::Text*>(layer->getChildByName("nameLabel"));
	m_descLabel = static_cast<ui::Text*>(layer->getChildByName("descLabel"));;
	m_icon = static_cast<Sprite*>(layer->getChildByName("icon"));
	m_toolList = static_cast<ui::ListView*>(layer->getChildByName("toolList"));
	m_itemList = static_cast<ui::ListView*>(layer->getChildByName("itemList"));
	auto btnList = static_cast<ui::ListView*>(layer->getChildByName("btnList"));
	m_makeBtn = static_cast<ui::Button*>(btnList->getChildByName("makeBtn"));
	m_makeBtn->addClickEventListener(CC_CALLBACK_1(MakeListLayer::onMakeClick, this));
	static_cast<ui::Button*>(btnList->getChildByName("returnBtn"))->addClickEventListener([=](Ref *ref){
		this->getParent()->removeChild(this);
	});

	return true;
}

void MakeListLayer::flushList()
{
	m_toolList->removeAllChildren();
	for (auto &i : *m_makeList){
		if (m_item->getNum(i.first) != 0){
			auto t = ui::Button::create();
			t->setTitleText(m_item->getName(i.first));
			t->setTitleFontSize(24);
			t->setColor(Color3B::WHITE);
			t->addClickEventListener(CC_CALLBACK_1(MakeListLayer::onToolClick, this));
			m_toolList->addChild(t);
		}
	}
	m_makeBtn->setEnabled(FlowCtrl::getInstance()->times() != 0);
	if (m_item->getNum(m_nowToolId) == 0){
		m_nowItemId = m_nowToolId = "";
		m_itemList->removeAllChildren();
		m_nameLabel->setString("");
		m_descLabel->setString("Please select an item...");
		m_icon->setTexture("");
	}
	else{
		std::string desc = m_item->getDesc(m_nowItemId) + '\n';
		auto material = FlowCtrl::getInstance()->people()->material;
		for (auto &i : (m_makeList->at(m_nowToolId)).asValueMap().at(m_nowItemId).asValueMap()){
			int needNum = i.second.asInt();
			if (material.find(m_nowToolId) != material.end()){
				needNum *= material.at(m_nowToolId).asFloat();
				needNum = needNum == 0 ? 1 : needNum;
			}
			desc += m_item->getName(i.first) + ':' + Value(m_item->getNum(i.first)).asString() + '/' + Value(needNum).asString() + ' ';
		}
		m_descLabel->setString(desc);
	}
}

void MakeListLayer::onToolClick(cocos2d::Ref *ref)
{
	std::string id = static_cast<ui::Button*>(ref)->getTitleText();
	id = m_item->getId(id);
	if (m_nowToolId == id){
		return;
	}
	m_nowToolId = id;
	m_nowItemId = "";

	m_itemList->removeAllChildren();
	for (auto &i : m_makeList->at(m_nowToolId).asValueMap()){
		auto t = ui::Button::create();
		t->setTitleText(m_item->getName(i.first));
		t->setTitleFontSize(24);
		t->setColor(Color3B::WHITE);
		t->addClickEventListener(CC_CALLBACK_1(MakeListLayer::onItemClick, this));
		m_itemList->addChild(t);
	}

	m_nameLabel->setString("");
	m_descLabel->setString("Please select an item...");
	m_icon->setTexture("");
}

void MakeListLayer::onItemClick(cocos2d::Ref *ref)
{
	m_nowItemId = static_cast<ui::Button*>(ref)->getTitleText();
	m_nowItemId = m_item->getId(m_nowItemId);

	m_nameLabel->setString(m_item->getName(m_nowItemId));
	std::string desc = m_item->getDesc(m_nowItemId) + '\n';
	auto material = FlowCtrl::getInstance()->people()->material;
	for (auto &i : (m_makeList->at(m_nowToolId)).asValueMap().at(m_nowItemId).asValueMap()){
		int needNum = i.second.asInt();
		if (material.find(m_nowToolId) != material.end()){
			needNum *= material.at(m_nowToolId).asFloat();
			needNum = needNum == 0 ? 1 : needNum;
		}
		desc += m_item->getName(i.first) + ':' + Value(m_item->getNum(i.first)).asString() + '/' + Value(needNum).asString() + ' ';
	}
	m_descLabel->setString(desc);
	m_icon->setTexture(m_item->getIcon(m_nowItemId));
}

void MakeListLayer::onMakeClick(cocos2d::Ref *ref)
{
	if (m_nowItemId == "")
		return;
	for (auto &i : (m_makeList->at(m_nowToolId)).asValueMap().at(m_nowItemId).asValueMap()){
		if (m_item->getNum(i.first) < i.second.asInt())
			return;
	}
	m_item->addItem(m_nowItemId);
	auto material = FlowCtrl::getInstance()->people()->material;
	for (auto &i : (m_makeList->at(m_nowToolId)).asValueMap().at(m_nowItemId).asValueMap()){
		int needNum = i.second.asInt();
		if (material.find(m_nowToolId) != material.end()){
			needNum *= material.at(m_nowToolId).asFloat();
			needNum = needNum == 0 ? 1 : needNum;
		}
		m_item->delItem(i.first, needNum);
	}
	FlowCtrl::getInstance()->delTimes();
	flushList();
}