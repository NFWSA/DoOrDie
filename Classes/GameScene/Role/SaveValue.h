#ifndef __SAVE_VALUE_H__
#define __SAVE_VALUE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <functional>

class SaveValue
{
public:
	float speed;
	int id, times, maxTimes, range;
	bool explored;
	float gain;
	cocos2d::ValueMap material;

	SaveValue(const cocos2d::ValueMap &map);

	void show() const;
	void setValueChanged(std::function<void(const int, const int)> hpChanged, std::function<void(const int, const int)> saChanged,
		std::function<void(const int, const int)> spChanged, std::function<void(const int, const int)> vitChanged);
	void setMaxHealth(const int maxHealth);
	void setHealth(const int health);
	void setMaxSatiation(const int maxSatiation);
	void setSatiation(const int satiation);
	void setMaxSpirit(const int maxSpirit);
	void setSpirit(const int spirit);
	void setMaxVitality(const int maxVitality);
	void setVitality(const int vitality);
	const int getMaxHealth() const;
	const int getHealth() const;
	const int getMaxSatiation() const;
	const int getSatiation() const;
	const int getMaxSpirit() const;
	const int getSpirit() const;
	const int getMaxVitality() const;
	const int getVitality() const;

private:
	int m_maxHealth, m_health, m_maxSatiation, m_satiation,
		m_maxSpirit, m_spirit, m_maxVitality, m_vitality;
	std::function< void(const int, const int) > healthChange, satiationChange, spiritChange, vitalityChange;
};


#endif //__SAVE_VALUE_H__
