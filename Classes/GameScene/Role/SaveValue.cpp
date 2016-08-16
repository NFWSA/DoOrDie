#include "SaveValue.h"

SaveValue::SaveValue(const cocos2d::ValueMap &map) : healthChange(nullptr), satiationChange(nullptr), spiritChange(nullptr),
vitalityChange(nullptr), explored(false)
{
	id = map.at("id").asInt();
	m_health = m_maxHealth = map.at("hp").asInt();
	m_spirit = m_maxSpirit = map.at("sp").asInt();
	m_satiation = m_maxSatiation = map.at("sat").asInt();
	m_vitality = m_maxVitality = map.at("vit").asInt();
	times = maxTimes = map.at("times").asInt();
	speed = map.at("speed").asInt();
	range = map.at("range").asInt();
	gain = map.at("gain").asFloat();
	material = map.at("material").asValueMap();
}

//if need invoke all changed interface, invoke this
void SaveValue::show() const
{
	if (healthChange != nullptr)
		healthChange(m_health, m_maxHealth);
	if (satiationChange != nullptr)
		satiationChange(m_satiation, m_maxSatiation);
	if (spiritChange != nullptr)
		spiritChange(m_spirit, m_maxSpirit);
	if (vitalityChange != nullptr)
		vitalityChange(m_vitality, m_maxVitality);
}

//when property changed, will invoke these functions
void SaveValue::setValueChanged(std::function<void(const int, const int)> hpChanged, std::function<void(const int, const int)> saChanged,
	std::function<void(const int, const int)> spChanged, std::function<void(const int, const int)> vitChanged)
{
	healthChange = hpChanged;
	satiationChange = saChanged;
	spiritChange = spChanged;
	vitalityChange = vitChanged;
	show();
}

void SaveValue::setMaxHealth(const int maxHealth)
{
	if (maxHealth > 0)
		m_maxHealth = maxHealth;
	if (m_health > m_maxHealth)
		m_health = m_maxHealth;
	if (healthChange != nullptr)
		healthChange(m_health, m_maxHealth);
}

void SaveValue::setHealth(const int health)
{
	m_health = health;
	if (m_health > m_maxHealth)
		m_health = m_maxHealth;
	if (m_health < 0)
		m_health = 0;
	if (healthChange != nullptr)
		healthChange(m_health, m_maxHealth);
}

void SaveValue::setMaxSatiation(const int maxSatiation)
{
	if (maxSatiation > 0)
		m_maxSatiation = maxSatiation;
	if (m_satiation > m_maxSatiation)
		m_satiation = m_maxSatiation;
	if (satiationChange != nullptr)
		satiationChange(m_satiation, m_maxSatiation);
}

void SaveValue::setSatiation(const int satiation)
{
	m_satiation = satiation;
	if (m_satiation > m_maxSatiation)
		m_satiation = m_maxSatiation;
	if (m_satiation < 0)
		m_satiation = 0;
	if (satiationChange != nullptr)
		satiationChange(m_satiation, m_maxSatiation);
}

void SaveValue::setMaxSpirit(const int maxSpirit)
{
	if (maxSpirit > 0)
		m_maxSpirit = maxSpirit;
	if (m_spirit > m_maxSpirit)
		m_spirit = m_maxSpirit;
	if (spiritChange != nullptr)
		spiritChange(m_spirit, m_maxSpirit);
}

void SaveValue::setSpirit(const int spirit)
{
	m_spirit = spirit;
	if (m_spirit > m_maxSpirit)
		m_spirit = m_maxSpirit;
	if (m_spirit < 0)
		m_spirit = 0;
	if (spiritChange != nullptr)
		spiritChange(m_spirit, m_maxSpirit);
}

void SaveValue::setMaxVitality(const int maxVitality)
{
	if (maxVitality > 0)
		m_maxVitality = maxVitality;
	if (m_vitality > m_maxVitality)
		m_vitality = m_maxVitality;
	if (vitalityChange != nullptr)
		vitalityChange(m_vitality, m_maxVitality);
}

void SaveValue::setVitality(const int vitality)
{
	m_vitality = vitality;
	if (m_vitality > m_maxVitality)
		m_vitality = m_maxVitality;
	if (m_vitality < 0)
		m_vitality = 0;
	if (vitalityChange != nullptr)
		vitalityChange(m_vitality, m_maxVitality);
}

const int SaveValue::getMaxHealth() const
{
	return m_maxHealth;
}

const int SaveValue::getHealth() const
{
	return m_health;
}

const int SaveValue::getMaxSatiation() const
{
	return m_maxSatiation;
}

const int SaveValue::getSatiation() const
{
	return m_satiation;
}

const int SaveValue::getMaxSpirit() const
{
	return m_maxSpirit;
}

const int SaveValue::getSpirit() const
{
	return m_spirit;
}

const int SaveValue::getMaxVitality() const
{
	return m_maxVitality;
}

const int SaveValue::getVitality() const
{
	return m_vitality;
}

