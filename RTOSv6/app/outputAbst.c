//出力に関するイベントフラグ管理
//
// あいうえお


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
