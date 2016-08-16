#ifndef __ITEM_H__
#define __ITEM_H__

#include <map>
#include <string>
#include <vector>
#include "cocos2d.h"

class Item
{
public:
	explicit Item(const std::string &file);

	void addItem(const std::string &id, const int num = 1);
	void delItem(const std::string &id, const int num = 1);
	bool useItem(const std::string &id);
	
	void clearItem();
	const std::vector<std::string> itemList() const;

	bool isItem(const std::string &id) const;

	const std::string getId(const std::string &name) const;
	const std::string getName(const std::string &id) const;
	const std::string getDesc(const std::string &id) const;
	const std::string getIcon(const std::string &id) const;
	const int getNum(const std::string &id) const;

private:
	std::map<std::string, int> m_items;
	cocos2d::ValueMap m_itemInfo;
};

#endif //__ITEM_H__
