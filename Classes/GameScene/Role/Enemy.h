#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"
#include "../TypeDefine.h"
#include <functional>

class Player;

class Enemy : public cocos2d::Node
{
public:
	std::function<void(const int, const int)> onHpChanged;

	bool damage(const int dam);

	void finish();

	// arg in map(node) space
	const cocos2d::Vec2 pos2coor(const cocos2d::Vec2 &pos);
	// set in world space
	void setEnemyPos(const cocos2d::Vec2 &pos);

	void update(float dt) override;

	//return in map(node) space
	bool isTarDisenabled(const cocos2d::Vec2 &tar);

	//return in world space
	cocos2d::Rect getEnemyBox();
	const int getHp() const;
	const int getMaxHp() const;

	static Enemy* createWithEnv(MapType *map, Player *player, cocos2d::ValueMap &env);
	virtual bool init();

private:
	bool mapDamage();

	void unlockDamage(float dt);

	const cocos2d::Vec2 window2Map(const cocos2d::Vec2 &pos);
	const cocos2d::Vec2 map2Window(const cocos2d::Vec2 &pos);

	bool m_damLock;
	MapType *m_map;
	int m_hp, m_maxHp, m_damage;
	float m_speed, m_range;
	cocos2d::Sprite *m_enemy;
	// save in map(node) space
	cocos2d::Vec2 m_pos;
	Player *m_player;
	cocos2d::Sequence *m_flashAct;
};

#endif //__ENEMY_H__
