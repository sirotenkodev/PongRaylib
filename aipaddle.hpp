#ifndef AIPADDLE_HPP
#define AIPADDLE_HPP

#include "paddle.hpp"

class AiPaddle : public Paddle
{
public:
    AiPaddle(int x, int y, int speedY, int width, int height);

    void update(int ballY);
};

#endif // AIPADDLE_HPP
