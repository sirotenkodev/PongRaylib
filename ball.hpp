#ifndef BALL_HPP
#define BALL_HPP


class Ball
{
public:
    Ball(float, float, int, int, int);

public:
    float x() const;
    float y() const;
    int speedX() const;
    int speedY() const;
    int radius() const;

    void draw();
    void update();

    void setSpeedX(int newSpeedX);
    void setSpeedY(int newSpeedY);

    int playerScore() const;
    int aiScore() const;

    void RespavnBall();

private:
    float m_x;
    float m_y;
    int m_speedX;
    int m_speedY;
    int m_radius;
    int m_playerScore;
    int m_aiScore;
};

#endif // BALL_HPP
