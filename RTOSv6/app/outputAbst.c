/********************************************* */
/*APPからコールされたら出力用のフラグをたてる      */
/********************************************* */
enum 
{
    OUTPUT_LED_IG    = 1 << 0,
    OUTPUT_LED_DRVUP = 1 << 1,
    OUTPUT_LED_DRVDW = 1 << 2,
    OUTPUT_LED_CONF  = 1 << 3
};


void
vdg_outputAbstif_igledon(void)
{
    setEventFlag(OUTPUT_EVENT_FLAG, OUTPUT_LED_IG);
}

void
vdg_outputAbstif_drvupledon(void)
{
    setEventFlag(OUTPUT_EVENT_FLAG, OUTPUT_LED_DRVUP);
}

void
vdg_outputAbstif_drvdwledon(void)
{
    setEventFlag(OUTPUT_EVENT_FLAG, OUTPUT_LED_DRVDW);
}

void
vdg_outputAbstif_confledon(void)
{
    setEventFlag(OUTPUT_EVEMT_FLAG, OUTPUT_LED_CONF);
}
