#include "raylib.h"

#include "ball.hpp"

//-----------------------------------------------------------------------------
Ball::Ball(float x, float y, int sX, int sY, int rad)
    : m_x{x}
    , m_y{y}
    , m_speedX{sX}
    , m_speedY{sY}
    , m_radius{rad}
    , m_playerScore{0}
    , m_aiScore{0}
{}

//-----------------------------------------------------------------------------
float Ball::x() const
{
    return m_x;
}

//-----------------------------------------------------------------------------
float Ball::y() const
{
    return m_y;
}

//-----------------------------------------------------------------------------
int Ball::speedX() const
{
    return m_speedX;
}

//-----------------------------------------------------------------------------
int Ball::speedY() const
{
     return m_speedY;
}

//-----------------------------------------------------------------------------
int Ball::radius() const
{
     return m_radius;
}

//-----------------------------------------------------------------------------
void Ball::draw()
{
    DrawCircle(m_x, m_y, m_radius, WHITE);
}

//-----------------------------------------------------------------------------
void Ball::update()
{
    m_x += m_speedX;
    m_y += m_speedY;

    if(m_y + m_radius >= GetScreenHeight() || m_y + m_radius <= 0) {
        m_speedY *= -1;
    }

    if(m_x + m_radius >= GetScreenWidth()) {
        m_playerScore++;
        RespavnBall();
    }

    if(m_x + m_radius <= 0) {
        m_aiScore++;
        RespavnBall();
    }
}

//-----------------------------------------------------------------------------
void Ball::setSpeedX(int newSpeedX)
{
    m_speedX = newSpeedX;
}

//-----------------------------------------------------------------------------
void Ball::setSpeedY(int newSpeedY)
{
    m_speedY = newSpeedY;
}

//-----------------------------------------------------------------------------
int Ball::playerScore() const
{
    return m_playerScore;
}

//-----------------------------------------------------------------------------
int Ball::aiScore() const
{
    return m_aiScore;
}

//-----------------------------------------------------------------------------
void Ball::RespavnBall()
{
    m_x = GetScreenWidth() / 2;
    m_y = GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    m_speedX *= speed_choices[GetRandomValue(0, 1)];
    m_speedY *= speed_choices[GetRandomValue(0, 1)];
}
