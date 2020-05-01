#include "ripple.h"

Ripple::Ripple()
{
    m_reset = true;
    m_scaler = 15;
    m_power = 2.5;
    m_timer = 0;
    m_body.setPosition(50, 50);
    m_body.setOutlineColor(sf::Color::Magenta);
    m_body.setScale(sf::Vector2f(1.0f, m_ratio));
    m_body.setOutlineThickness(1.5f);
    //setBounds(sf::Vector2f(1000, 400));
}

void Ripple::update(float timeDelta)
{
    m_timer += timeDelta;
    if (m_reset || m_timer >= m_power)
    {
        m_body.setRadius(0);
        m_body.setPosition( m_bounds.x * ((float)rand() / (RAND_MAX)), m_bounds.y * ((float)rand() / (RAND_MAX)));
        m_reset = false;
        m_timer = 0;
        setColor(sf::Color(m_body.getOutlineColor().r, m_body.getOutlineColor().g, m_body.getOutlineColor().b, 255));
        return;
    }
    else
    {
        m_body.setRadius(m_timer * m_scaler);
        m_body.setOrigin(sf::Vector2f(m_timer * m_scaler, m_timer * m_scaler / 2));
        setColor(sf::Color(m_body.getOutlineColor().r, m_body.getOutlineColor().g, m_body.getOutlineColor().b, ((m_power - m_timer) / m_power) * 255));
    }
    return;
}

void Ripple::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_body, states);
}

void Ripple::setPostition(float X, float Y)
{
    m_body.setPosition(X, Y);
}

void Ripple::setPower(float fPower)
{
    m_power = fPower;
}

void Ripple::setReset(bool reset)
{
    m_reset = reset;
}

void Ripple::setColor(sf::Color color)
{
    m_body.setOutlineColor(color);
    m_body.setFillColor(sf::Color(0, 0, 0, 0));
}

void Ripple::setThickness(float thickness)
{
    m_body.setOutlineThickness(thickness);
}

void Ripple::setBounds(sf::Vector2f bounds)
{
    m_bounds = bounds;
}

sf::Vector2f Ripple::m_bounds = sf::Vector2f(1000, 400);
