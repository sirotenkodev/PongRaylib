#include "raylib.h"

#include "paddle.hpp"

//-----------------------------------------------------------------------------
Paddle::Paddle(float x, float y, int speedY, int width, int height) : m_x(x),
    m_y(y),
    m_speedY(speedY),
    m_width(width),
    m_height(height)
{}

//-----------------------------------------------------------------------------
float Paddle::x() const
{
    return m_x;
}

//-----------------------------------------------------------------------------
float Paddle::y() const
{
    return m_y;
}

//-----------------------------------------------------------------------------
int Paddle::speedY() const
{
    return m_speedY;
}

//-----------------------------------------------------------------------------
float Paddle::width() const
{
    return m_width;
}

//-----------------------------------------------------------------------------
float Paddle::height() const
{
    return m_height;
}

//-----------------------------------------------------------------------------
void Paddle::draw()
{
    DrawRectangle(m_x, m_y, m_width, m_height, WHITE);
}

//-----------------------------------------------------------------------------
void Paddle::update()
{
    if(IsKeyDown(KEY_UP)) {
        m_y -= m_speedY;
    } else if(IsKeyDown(KEY_DOWN)) {
        m_y += m_speedY;
    }

    if(m_y <= 0) {
        m_y = 0;
    } else if(m_y + m_height >= GetScreenHeight()) {
        m_y =  GetScreenHeight() - m_height;
    }
}

//-----------------------------------------------------------------------------
void Paddle::setX(int newX)
{
    m_x = newX;
}

//-----------------------------------------------------------------------------
void Paddle::setY(int newY)
{
    m_y = newY;
}
