#include "Player.h"
#include "SaveValue.h"
#include "../Module/FlowCtrl.h"
#include "../Module/Item.h"

USING_NS_CC;

bool Player::damage(const int dam)
{
	if (dam == 0)
		return false;
	if (m_damLock && dam > 0)
		return false;
	if (dam > 0){
		m_damLock = true;
		m_player->runAction(m_flashAct);
		scheduleOnce(CC_CALLBACK_1(Player::unlockDamage, this), 1.0f, "unlockDamage");
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
		if (nullptr != onDied)
			onDied();
		return true;
	}
	return false;
}

const cocos2d::Vec2 Player::pos2coor(const cocos2d::Vec2 &pos)
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

void Player::setPlayerPos(const cocos2d::Vec2 &pos)
{
	Vec2 ppos(pos), tar = m_map->convertToNodeSpace(pos), mapTar(m_map->getPosition()),
		dpos(Director::getInstance()->getVisibleSize() / 2), lpos(m_map->getMapSize().width * m_map->getTileSize().width, m_map->getMapSize().height * m_map->getTileSize().height);
	if (m_cameraType == 0){
		// show player with the player is center point
		if (tar.x < dpos.x){
			mapTar.x = 0;
		}
		else if (tar.x>lpos.x - dpos.x){
			mapTar.x = dpos.x * 2 - lpos.x;
		}
		else {
			mapTar.x = dpos.x - tar.x;
			//ppos.x = dpos.x;
		}

		if (tar.y < dpos.y){
			mapTar.y = 0;
		}
		else if (tar.y>lpos.y - dpos.y){
			mapTar.y = dpos.y * 2 - lpos.y;
		}
		else {
			mapTar.y = dpos.y - tar.y;
			//ppos.y = dpos.y;
		}

	}
	else {
		// show player in a box that the player could move
		// todo
	}
	m_map->setPosition(mapTar);
	setPosition(map2Window(tar));
	return;
}

void Player::setTar(const cocos2d::Vec2 &tar)
{
	m_tar = window2Map(tar);
}

void Player::update(float dt)
{
	Vec2 to = m_tar - window2Map(getPosition());
	if (to.length() <= m_speed * dt){
		setTar(getPosition());
		return;
	}
	to.normalize();
	Vec2 boxTo = Vec2(m_player->getContentSize() / 2).getNormalized();
	boxTo = (to.x > -boxTo.x && to.x < boxTo.x) ? /* y */to*(m_player->getContentSize().height / 2 / std::abs(to.y)) : /* x */to*(m_player->getContentSize().width / 2 / std::abs(to.x));
	boxTo += getPosition();
	if (isTarDisenabled(window2Map(boxTo)))
		return;
	to = to * m_speed * dt + getPosition();
	setPlayerPos(to);
	clearFog();
	mapItem(); 
	mapDamage();
}

// if the tar is collision, return true
bool Player::isTarDisenabled(const cocos2d::Vec2 &tar)
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

cocos2d::Rect Player::getPlayerBox()
{
	auto rect = m_player->getBoundingBox();
	rect.origin += getPosition();
	return rect;
}

const int Player::getHp() const
{
	return m_hp;
}

const int Player::getMaxHp() const
{
	return m_maxHp;
}

Player* Player::createWithMap(MapType *map)
{
	Player *pRet = new(std::nothrow) Player();
	if (pRet&&pRet->init()){
		pRet->autorelease();
		pRet->m_map = map;
		auto pos = map->getObjectGroup("Objects")->getObject("Player");
		if (!pos.empty()){
			pRet->setPlayerPos(pRet->map2Window(Vec2(pos["x"].asInt(), pos["y"].asInt())));
			pRet->setTar(pRet->getPosition());
			pRet->clearFog();
		}
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool Player::init()
{
	if (!Node::init())
		return false;

	onDied = nullptr;
	onHpChanged = nullptr;
	onItemGet = nullptr;
	m_damLock = false;

	m_player = Sprite::create("Role/Player.png");
	addChild(m_player);

	m_map = nullptr;

	m_tar = getPosition();

	auto people = FlowCtrl::getInstance()->people();
	m_hp = m_maxHp = people->getMaxHealth();
	m_speed = people->speed;
	m_cameraType = 0;
	int range = people->range;
	m_dvec.clear();
	for (int i = -range; i <= range; ++i){
		for (int j = std::abs(i) - range; j <= range - std::abs(i); ++j){
			auto t = Vec2(j, i);
			m_dvec.push_back(t);
		}
	}
	m_gain = people->gain;

	auto flash1 = FadeTo::create(0.25f, 80), flash2 = FadeTo::create(0.25f, 255);
	m_flashAct = Sequence::create(flash1, flash2, flash1->clone(), flash2->clone(), nullptr);
	m_flashAct->retain();

	scheduleUpdate();

	return true;
}

void Player::clearFog()
{
	if (nullptr == m_map)
		return;

	auto fog = m_map->getLayer("Fog");
	auto pos = pos2coor(window2Map(getPosition()));

	for (auto &i : m_dvec){
		Vec2 tar(pos.x + i.x, pos.y + i.y);
		if (tar.x < 0 || tar.x >= m_map->getMapSize().width)
			continue;
		if (tar.y < 0 || tar.y >= m_map->getMapSize().height)
			continue;
		fog->removeTileAt(tar);
	}
}

bool Player::mapDamage()
{
	if (nullptr == m_map)
		return false;

	auto pos = pos2coor(window2Map(getPosition()));
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

void Player::mapItem()
{
	if (nullptr == m_map)
		return;

	auto meta = m_map->getLayer("Meta");
	auto pos = pos2coor(window2Map(getPosition()));
	auto item = m_map->getLayer("Item");

	if (pos.x == -1)
		return;

	int gid = meta->getTileGIDAt(pos);
	if (gid > 0){
		ValueMap proper = m_map->getPropertiesForGID(gid).asValueMap();
		if (proper.find("Item")!=proper.end()){
			auto name = proper["Item"].asString();
			int num = Value(proper["Number"].asString()).asInt() * m_gain;
			FlowCtrl::getInstance()->item()->addItem(name, num);
			if (nullptr != onItemGet)
				onItemGet(FlowCtrl::getInstance()->item()->getName(name), num);
			meta->removeTileAt(pos);
			item->removeTileAt(pos);
		}
	}
}

void Player::unlockDamage(float dt)
{
	m_damLock = false;
}

const cocos2d::Vec2 Player::window2Map(const cocos2d::Vec2 &pos)
{
	if (nullptr == m_map)
		return Vec2(0, 0);
	return m_map->convertToNodeSpace(pos);
}

const cocos2d::Vec2 Player::map2Window(const cocos2d::Vec2 &pos)
{
	if (nullptr == m_map)
		return Vec2(0, 0);
	return m_map->convertToWorldSpace(pos);
}
