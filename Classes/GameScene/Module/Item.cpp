#include "Item.h"
#include "cocos2d.h"
#include "FlowCtrl.h"

USING_NS_CC;

Item::Item(const std::string &file)
{
	m_itemInfo = FileUtils::getInstance()->getValueMapFromFile(file);
}

void Item::addItem(const std::string &id, const int num)
{
	if (!isItem(id))
		return;
	if (m_items.find(id) != m_items.end())
		m_items[id] += num;
	else
		m_items[id] = num;
}

void Item::delItem(const std::string &id, const int num)
{
	if (m_items.find(id) != m_items.end())
	{
		m_items[id] -= num;
		if (m_items[id] <= 0)
		{
			m_items.erase(id);
		}
	}
}

bool Item::useItem(const std::string &id)
{
	if (!isItem(id))
		return false;
	if (m_itemInfo.at(id).asValueMap().find("effect") == m_itemInfo.at(id).asValueMap().end())
		return false;
	FlowCtrl::getInstance()->procMap(m_itemInfo.at(id).asValueMap().at("effect").asValueMap());
	return true;
}

void Item::clearItem()
{
	m_items.clear();
}

const std::vector<std::string> Item::itemList() const
{
	std::vector<std::string> itemList;
	for (auto &i : m_items){
		itemList.push_back(i.first);
	}
	return itemList;
}

bool Item::isItem(const std::string &id) const
{
	return m_itemInfo.find(id) != m_itemInfo.end();
}

const std::string Item::getId(const std::string &name) const
{
	for (auto &i : m_itemInfo){
		if (i.second.asValueMap().at("name").asString() == name)
			return i.first;
	}
	return "";
}

const std::string Item::getName(const std::string &id) const
{
	if (!isItem(id))
		return "";
	return m_itemInfo.at(id).asValueMap().at("name").asString();
}

const std::string Item::getDesc(const std::string &id) const
{
	if (!isItem(id))
		return "";
	return m_itemInfo.at(id).asValueMap().at("desc").asString();
}

const std::string Item::getIcon(const std::string &id) const
{
	if (!isItem(id))
		return "";
	return m_itemInfo.at(id).asValueMap().at("icon").asString();
}

const int Item::getNum(const std::string &id) const
{
	if (m_items.find(id) == m_items.end())
		return 0;
	return m_items.at(id);
}
