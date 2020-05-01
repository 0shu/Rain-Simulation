#pragma once

#include <SFML/Graphics.hpp>

class Ripple : public sf::Drawable
{
private:
    sf::CircleShape m_body;
    float m_power;
    float m_timer;
    float m_ratio = 0.5f;

    float m_scaler = 1.0f;
    bool m_reset;
public:
    static sf::Vector2f m_bounds;
    Ripple();
    void update(float timeDelta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setPostition(float X, float Y);
    void setPower(float fPower);
    void setReset(bool reset);
    void setColor(sf::Color color);
    void setThickness(float thickness);
    void setBounds(sf::Vector2f bounds);
};

//sf::Vector2f Ripple::m_bounds = sf::Vector2f(1000, 400);