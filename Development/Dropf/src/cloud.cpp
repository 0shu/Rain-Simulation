#include "cloud.h"
#include <stdlib.h>

Cloud::Cloud()
{
    //m_bounds = sf::Vector2f(1000, 400);
    arrSize = 32;
    for (int i = 0; i < arrSize; i++)
    {
        droplets.push_back(droplet1);
        droplets[i].setPostition((1000.f / (float)arrSize) * i, 0);
        droplets[i].setSize((2 * ((float)rand() / (RAND_MAX))) + 1);
    }

    ripple1.setColor(sf::Color(80, 90, 85, 255));

    for (int i = 0; i < arrSize; i++)
    {
        ripples.push_back(ripple1);
        ripples[i].setPostition((1000.f / (float)arrSize) * i, (400 * ((float)rand() / (RAND_MAX))));
        ripples[i].setPower((2 * ((float)rand() / (RAND_MAX))));
    }

    m_body.setSize(sf::Vector2f(500, 400));
    m_body.setOrigin(sf::Vector2f(250, 200));
    m_body.setPosition(750, 200);
    m_body.setFillColor(sf::Color(135, 155, 140, 255));

    ripple1.setReset(true);
    
    droplet2.setReset(true);
    droplet2.setColor(sf::Color(80, 90, 85, 230));
    modifier = 0;
}

bool Cloud::update(float timeDelta)
{
    bool flag = false;

    for (int i = 0; i < arrSize + modifier; i++)
    {
        ripples[i].update(timeDelta);
        if(droplets[i].update()) flag = true;
    }
    return flag;
}

void Cloud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(m_body, states);
    for (int i = 0; i < arrSize + modifier; i++)
    {
        if (!hideDroplets) target.draw(droplets[i], states);
        if (!hideRipples) target.draw(ripples[i], states);
    }
}

int Cloud::append(sf::Vector2i position)
{
    modifier++;
    droplet2.setSize((5 * ((float)rand() / (RAND_MAX))) + 1);
    
    droplet2.setSpeed((((float)rand() / (RAND_MAX))) + 1);
    droplet2.setPostition(position.x, position.y);
    droplets.push_back(droplet2);

    ripple1.setPower((2 * ((float)rand() / (RAND_MAX))));
    ripple1.setReset(true);
    ripples.push_back(ripple1);
    return modifier;
}

void Cloud::showDroplets(bool show)
{
    hideDroplets = !show;
}

void Cloud::showRipples(bool show)
{
    hideRipples = !show;
}

void Cloud::setBounds(sf::Vector2f bounds)
{
    m_bounds = bounds;

    Ripple::m_bounds = bounds;
    Droplet::m_bounds = bounds;
}

void Cloud::reset()
{
    modifier = 0;
    droplets.resize(32);
    ripples.resize(32);
}

sf::Vector2f Cloud::m_bounds = sf::Vector2f(1000, 400);