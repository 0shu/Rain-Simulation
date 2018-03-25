#include "droplet.h"

Droplet::Droplet()
{
    m_reset = true;
    m_size = 5;
    m_speed = 2.5;
    m_wibble = 1.5;
    m_body.setSize(sf::Vector2f(m_size,m_size * 9));
    m_body.setOrigin(sf::Vector2f(m_size / 2, m_size * 4.5));
    m_body.setPosition(50, 50);
    m_body.setFillColor(sf::Color::Magenta);
}

bool Droplet::update()
{
    float wibble = m_wibble * ((float)rand() / (RAND_MAX));
    if (m_reset && m_body.getPosition().y > 400 + m_body.getSize().y)
    {
        m_body.setPosition(m_body.getPosition().x, -m_body.getSize().y);
        return true;
    }
    else m_body.move(0, (m_speed + wibble) * m_size);
    return false;
}

void Droplet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_body, states);
}

void Droplet::setPostition(float X, float Y)
{
    m_body.setPosition(X, Y);
}

void Droplet::setSize(float fSize)
{
    m_size = fSize;
    m_body.setSize(sf::Vector2f(m_size, m_size * 9));
    m_body.setOrigin(sf::Vector2f(m_size / 2, m_size * 4.5));
    if(fSize < 3) m_body.setFillColor(sf::Color(20, 90, 255, m_size * 255 / 6));
}

void Droplet::setSpeed(float fSpeed)
{
    m_speed = fSpeed;
}

void Droplet::setReset(bool reset)
{
    m_reset = reset;
}

void Droplet::setColor(sf::Color color)
{
    m_body.setFillColor(color);
}