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



void vdg_inputAbstif_eventFlag(void)
{
    vdg_eventFlag();
}

static void vdg_eventFlag(void)
{

}

static void vds_inputAbst_button(void)
{
    
}



