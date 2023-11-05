#ifndef PADDLE_HPP
#define PADDLE_HPP


class Paddle
{
public:
    Paddle(float x, float y, int speedY, int width, int height);

    float x() const;
    float y() const;
    int speedY() const;
    float width() const;
    float height() const;

    void draw();
    void update();

    void setX(int newX);
    void setY(int newY);

private:
    float m_x;
    float m_y;
    int m_speedY;
    float m_width;
    float m_height;
};

#endif // PADDLE_HPP
