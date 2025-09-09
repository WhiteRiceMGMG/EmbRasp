#include <kedknl.h>

static void delay_ms( UINT ms)
{
    UINT cnt = ms/TIMER_PERIOD;

    while(cnt) {
        if((in_w(SYST_CSR) & SYST_CSR_COUNTFLAG)!=0) {  //あとで抽象化したい．
            cnt--;
        }
    }
}


int main(void)
{
    while(1)
    {
        if(Ked.IgSw.Push())  
        {
            Ked.FiftLed.On();
        } else {
            Ked.FiftLed.Off();
        }

        if(Ked.UpSw.Push())
        {
            Ked.ThirtLed.On();
        } else {
            Ked.ThirtLed.Off();
        }

        if(Ked.DwSw.Push())
        {
            Ked.ElevLed.On();
        } else {
            Ked.ElevLed.Off();
        }

        if(Ked.ConfSw.Push())
        {
            Ked.NineLed.On();
        } else {
            Ked.NineLed.Off();
        }

        delay_ms(50);

    }
    return 0;
}


