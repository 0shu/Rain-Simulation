#pragma once

#include <SFML/Graphics.hpp>
#include "droplet.h"
#include <vector>

class Cloud : public sf::Drawable
{
private:
    sf::RectangleShape m_body;
    Droplet droplet1;
    Droplet droplet2;
    std::vector<Droplet> droplets;
    //Droplet droplets[arrSize];
    int arrSize;
    int modifier;
public:
    Cloud();
    bool update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int append(sf::Vector2i position);
    void setPostition(float X, float Y);
    void setSize(float fSize);
    void setSpeed(float fSpeed);
    void reset();
};