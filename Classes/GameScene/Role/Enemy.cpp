#include "Enemy.h"
#include "Player.h"
#include "../Module/FlowCtrl.h"

USING_NS_CC;

bool Enemy::damage(const int dam)
{
	if (dam == 0)
		return false;
	if (m_damLock && dam > 0)
		return false;
	if (dam > 0){
		m_damLock = true;
		m_enemy->runAction(m_flashAct);
		scheduleOnce(CC_CALLBACK_1(Enemy::unlockDamage, this), 1.0f, "unlockDamage");
	}
	m_hp -= dam;
	if (m_hp > m_maxHp)
		m_hp = m_maxHp;
	if (m_hp <= 0){
		m_hp = 0;
	}
	if (nullptr != onHpChanged)
		onHpChanged(m_hp, m_maxHp);
	if (m_hp == 0){
		// todo remove this
		unscheduleUpdate();
		getParent()->removeChild(this);
		return true;
	}
	return false;
}

const cocos2d::Vec2 Enemy::pos2coor(const cocos2d::Vec2 &pos)
{
	if (nullptr == m_map)
		return Vec2(-1, -1);
	int x = pos.x / m_map->getTileSize().width, y = (m_map->getTileSize().height*m_map->getMapSize().height - pos.y) / m_map->getTileSize().height;
	if (x < 0 || x >= m_map->getMapSize().width)
		return Vec2(-1, -1);
	if (y < 0 || y >= m_map->getMapSize().height)
		return Vec2(-1, -1);
	return Vec2(x, y);
}

void Enemy::setEnemyPos(const cocos2d::Vec2 &pos)
{
	m_pos = window2Map(pos);
	setPosition(m_pos);
}

void Enemy::update(float dt)
{
	setEnemyPos(map2Window(m_pos));
	// todo
	// enemy ai
	auto wpos = map2Window(m_pos);
	Vec2 to = m_player->getPosition() - wpos;
	if (to.length() > m_range || to.length() <= m_speed * dt)
		return;

	to.normalize();
	Vec2 boxTo = Vec2(m_enemy->getContentSize() / 2).getNormalized();
	boxTo = (to.x > -boxTo.x && to.x < boxTo.x) ? /* y */to*(m_enemy->getContentSize().height / 2 / std::abs(to.y)) : /* x */to*(m_enemy->getContentSize().width / 2 / std::abs(to.x));
	boxTo += wpos;
	if (isTarDisenabled(window2Map(boxTo)))
		return;

	to = to * m_speed * dt + wpos;
	setEnemyPos(to);
	if (mapDamage())
		return;

	if (m_player->getPlayerBox().containsPoint(map2Window(m_pos)))
		m_player->damage(m_damage);
}

// if the tar is collision, return true
bool Enemy::isTarDisenabled(const cocos2d::Vec2 &tar)
{
	if (nullptr == m_map)
		return false;

	auto pos = pos2coor(tar);
	if (pos.x == -1)
		return true;
	int gid = m_map->getLayer("Meta")->getTileGIDAt(pos);
	if (gid > 0){
		ValueMap proper = m_map->getPropertiesForGID(gid).asValueMap();
		if (proper.find("Collision") != proper.end()){
			if ("True" == proper["Collision"].asString())
				return true;
		}
	}
	return false;
}

cocos2d::Rect Enemy::getEnemyBox()
{
	auto rect = m_enemy->getBoundingBox();
	rect.origin += map2Window(m_pos);
	return rect;
}

const int Enemy::getHp() const
{
	return m_hp;
}

const int Enemy::getMaxHp() const
{
	return m_maxHp;
}

Enemy* Enemy::createWithEnv(MapType *map, Player *player, ValueMap &env)
{
	Enemy *pRet = new(std::nothrow) Enemy();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->m_map = map;
		pRet->m_player = player;
		// todo enemy set
		auto enemy = FileUtils::getInstance()->getValueMapFromFile(env["EnemyFile"].asString());
		pRet->m_damage = enemy["damage"].asInt();
		pRet->m_hp = pRet->m_maxHp = enemy["hp"].asInt();
		pRet->m_speed = enemy["speed"].asFloat();
		pRet->m_range = enemy["range"].asInt() * map->getTileSize().width;
		pRet->m_enemy->setTexture(enemy["texture"].asString());

		pRet->setEnemyPos(pRet->map2Window(Vec2(env["x"].asInt(), env["y"].asInt())));

		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool Enemy::init()
{
	if (!Node::init())
		return false;

	onHpChanged = nullptr;
	m_damLock = false;

	m_enemy = Sprite::create();
	addChild(m_enemy);

	m_map = nullptr;

	// todo enemy proper
	m_damage = 20;
	m_hp = m_maxHp = 100;
	m_speed = 50;
	m_range = 360.0f;

	auto flash1 = FadeTo::create(0.25f, 80), flash2 = FadeTo::create(0.25f, 255);
	m_flashAct = Sequence::create(flash1, flash2, flash1->clone(), flash2->clone(), nullptr);
	m_flashAct->retain();

	scheduleUpdate();

	return true;
}

bool Enemy::mapDamage()
{
	if (nullptr == m_map)
		return false;

	auto pos = pos2coor(getPosition());
	if (pos.x == -1)
		return false;

	int gid = m_map->getLayer("Meta")->getTileGIDAt(pos);
	if (gid > 0){
		ValueMap proper = m_map->getPropertiesForGID(gid).asValueMap();
		if (proper.find("Damage") != proper.end()){
			return damage(Value(proper["Damage"].asString()).asInt());
		}
	}
	return false;
}

void Enemy::unlockDamage(float dt)
{
	m_damLock = false;
}

const cocos2d::Vec2 Enemy::window2Map(const cocos2d::Vec2 &pos)
{
	if (nullptr == m_map)
		return Vec2(0, 0);
	return m_map->convertToNodeSpace(pos);
}

const cocos2d::Vec2 Enemy::map2Window(const cocos2d::Vec2 &pos)
{
	if (nullptr == m_map)
		return Vec2(0, 0);
	return m_map->convertToWorldSpace(pos);
}
