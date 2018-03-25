#pragma once

#include <SFML/Graphics.hpp>

class Droplet : public sf::Drawable
{
private:
    sf::RectangleShape m_body;
    float m_size;
    float m_speed;
    float m_wibble;
    bool m_reset;
public:
    Droplet();
    bool update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setPostition(float X, float Y);
    void setSize(float fSize);
    void setSpeed(float fSpeed);
    void setReset(bool reset);
    void setColor(sf::Color color);
};