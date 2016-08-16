#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "../TypeDefine.h"
#include <functional>

class Player : public cocos2d::Node
{
public:
	std::function<void()> onDied;
	std::function<void(const std::string&, const int)> onItemGet;
	std::function<void(const int, const int)> onHpChanged;

	bool damage(const int dam);

	// arg in map(node) space
	const cocos2d::Vec2 pos2coor(const cocos2d::Vec2 &pos);
	// set in world space
	void setPlayerPos(const cocos2d::Vec2 &pos);
	//set in world space
	void setTar(const cocos2d::Vec2 &tar);

	void update(float dt) override;

	//return in map(node) space
	bool isTarDisenabled(const cocos2d::Vec2 &tar);

	//return in world space
	cocos2d::Rect getPlayerBox();
	const int getHp() const;
	const int getMaxHp() const;

	static Player* createWithMap(MapType *map);
	virtual bool init();

private:
	void clearFog();
	bool mapDamage();
	void mapItem();

	void unlockDamage(float dt);

	const cocos2d::Vec2 window2Map(const cocos2d::Vec2 &pos);
	const cocos2d::Vec2 map2Window(const cocos2d::Vec2 &pos);

	bool m_damLock;
	MapType *m_map;
	int m_hp, m_maxHp, m_cameraType;
	float m_speed, m_gain;
	cocos2d::Sprite *m_player;
	// save in map(node) space
	cocos2d::Vec2 m_tar;
	std::vector<cocos2d::Vec2> m_dvec;
	cocos2d::Sequence *m_flashAct;
};

#endif //__PLAYER_H__
