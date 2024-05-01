#define USE_DAISYSP_LGPL 1

#include "daisy_field.h"
#include "daisysp.h"

using namespace daisy;

DaisyField hw;

int ballPositionX{0};
int ballPositionY{0};
int ballDirectionX{1};
int ballDirectionY{1};
int ballDiameter{2};
int acceleration{1};

void UpdateDisplay()
{
    hw.display.Fill(false);
    hw.display.DrawCircle(ballPositionX, ballPositionY, ballDiameter, true);
    hw.display.Update();
}

void UpdateBallPosition()
{
    if(ballPositionX <= ballDiameter
       || ballPositionX >= hw.display.Width() - ballDiameter)
    {
        ballDirectionX = -ballDirectionX;
        // acceleration   = acceleration + 1;
    }

    if(ballPositionY <= ballDiameter
       || ballPositionY >= hw.display.Height() - ballDiameter)
    {
        ballDirectionY = -ballDirectionY;
        // acceleration   = acceleration + 1;
    }


    ballPositionX = ballPositionX + ballDirectionX * acceleration;
    ballPositionY = ballPositionY + ballDirectionY * acceleration;
}

void drawTitleScreen()
{
    int padding = {5};

    Rectangle rect(padding,
                   padding,
                   hw.display.Width() - 2 * padding,
                   hw.display.Height() - 2 * padding);

    hw.display.Fill(false);
    hw.display.WriteStringAligned(
        "Daisy", Font_16x26, rect, Alignment::topLeft, true);
    hw.display.WriteStringAligned(
        "Pong", Font_16x26, rect, Alignment::bottomRight, true);
    hw.display.Update();
    System::Delay(1000);
    hw.display.Fill(false);
}

void initialzieBallPosition()
{
    ballPositionX = hw.display.Width() / 2;
    ballPositionY = hw.display.Height() / 2;
}

int main(void)
{
    hw.Init();

    drawTitleScreen();
    initialzieBallPosition();

    for(;;)
    {
        UpdateDisplay();
        UpdateBallPosition();
        System::Delay(16.7f);
    }
}
