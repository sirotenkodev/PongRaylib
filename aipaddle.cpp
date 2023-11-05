#include "aipaddle.hpp"

//-----------------------------------------------------------------------------
AiPaddle::AiPaddle(int x, int y, int speedY, int width, int height)
    : Paddle(x, y, speedY, width, height)
{}

//-----------------------------------------------------------------------------
void AiPaddle::update(int ballY)
{
    if(y() + height() / 2 > ballY) {
        setY(y() - speedY());
    } else {
        setY(y() + speedY());
    }
}
