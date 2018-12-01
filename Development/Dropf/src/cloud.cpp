#include "cloud.h"
#include <stdlib.h>
//TODO: Cloud ought to take the window size and use that to set itself up!
Cloud::Cloud()
{
    arrSize = 32;
    for (int i = 0; i < arrSize; i++)
    {
        droplets.push_back(droplet1);
        droplets[i].setPostition((1000.f / (float)arrSize) * i, 0);
        droplets[i].setSize((2 * ((float)rand() / (RAND_MAX))) + 1);
    }
    
    droplet2.setReset(true);
    droplet2.setColor(sf::Color(70, 140, 250, 230));
    modifier = 0;
}

bool Cloud::update()
{
    bool flag = false;
    for (int i = 0; i < arrSize + modifier; i++)
    {
        if(droplets[i].update()) flag = true;
    }
    return flag;
}

void Cloud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < arrSize + modifier; i++)
    {
        target.draw(droplets[i], states);
    }
}

int Cloud::append(sf::Vector2i position)
{
    modifier++;
    droplet2.setSize((5 * ((float)rand() / (RAND_MAX))) + 1);
    
    droplet2.setSpeed((((float)rand() / (RAND_MAX))) + 1);
    droplet2.setPostition(position.x, position.y);
    droplets.push_back(droplet2);
    return modifier;
}

void Cloud::reset()
{
    modifier = 0;
    droplets.resize(32);
}