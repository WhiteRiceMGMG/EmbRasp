//入力についてのイベントフラグ管理

enum 
{
    INPUT_BUTTON_IGSW,
    INPUT_BUTTON_DRVSWUP,
    INPUT_BUTTON_DRVSWDW,
    INPUT_BUTTON_CONFSW
}

void vdg_inputAbstif_eventFlag(void);
static  void vdg_eventFlag(void);
void vdg_inputAbst_button(void);


void vdg_inputAbstif_eventFlag(void)
{
    vdg_inputAbst_igsw();
    vdg_input
}


// bool使って０か１を返したい
void vdg_inputAbst_igsw(void)
{
    if(Ked.IgSw.Push())
    {
        setEventFlag(INPUT_BUTTON_IGSW);
    }
}





