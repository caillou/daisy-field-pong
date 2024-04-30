#define USE_DAISYSP_LGPL 1

#include "daisy_field.h"
#include "daisysp.h"

using namespace daisy;

DaisyField hw;

int pos_x{0};
int pos_y{0};

void UpdateDisplay()
{
    hw.display.Fill(false);

    hw.display.DrawCircle(pos_x, pos_y, 2, true);

    pos_x = (pos_x + 1) % hw.display.Width();
    pos_y = (pos_y + 1) % hw.display.Height();

    hw.display.hw.display.Update();
}


int main(void)
{
    hw.Init();
    Rectangle rect;

    hw.display.WriteStringAligned(
        "Daisy", Font_16x26, rect, Alignment::centered, true);
    System::Delay(1000);
    hw.display.WriteStringAligned(
        "Pong", Font_16x26, rect, Alignment::centered, true);
    System::Delay(2000);

    pos_x = hw.display.Width() / 2;
    pos_y = hw.display.Height() / 2;

    for(;;)
    {
        UpdateDisplay();
        System::Delay(300);
    }
}
