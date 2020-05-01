#pragma once

#include <SFML/Graphics.hpp>
#include "droplet.h"
#include "ripple.h"
#include <vector>

class Cloud : public sf::Drawable
{
private:
    sf::RectangleShape m_body;
    Droplet droplet1;
    Droplet droplet2;
    Ripple ripple1;
    std::vector<Droplet> droplets;
    std::vector<Ripple> ripples;
    int arrSize;
    int modifier;
    bool hideDroplets = false;
    bool hideRipples = false;
public:
    static sf::Vector2f m_bounds;
    Cloud();
    bool update(float timeDelta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int append(sf::Vector2i position);
    void showDroplets(bool show);
    void showRipples(bool show);
    void setBounds(sf::Vector2f bounds);
    void reset();
};

