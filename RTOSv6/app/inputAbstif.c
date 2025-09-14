//入力についてのイベントフラグ管理

enum 
{
    INPUT_BUTTON_IGSW    = 0 >> 1,
    INPUT_BUTTON_DRVSWUP = 1 >> 1,
    INPUT_BUTTON_DRVSWDW = 2 >> 1,
    INPUT_BUTTON_CONFSW  = 3 >> 1
}



void vdg_inputAbstif_eventFlag(void);
static  void vdg_eventFlag(void);
void vdg_inputAbst_button(void);

static void vds_inputAbst_igsw(void);
static void vds_inputAbst_devswup(void);
static void vds_inputAbst_drvswdw(void);
static void vds_inputAbst_confsw(void);


void vdg_inputAbstif_eventFlag(void)
{
    vds_inputAbst_igsw();
    vds_inputAbst_drvswup();
    vds_inputAbst_drvswdw();
    vds_inputAbst_confsw();
}



static void vds_inputAbst_igsw(void)
{
    if(Ked.IgSw.Push())
    {
        setEventFlag(INPUT_BUTTON_IGSW);
    }
}

static void vds_inputAbst_drvswup(void)
{
    if(Ked.UpSw.Push())
    {
        setEventFlag(INPUT_BUTTON_DRVSWUP);
    }
}

static void vds_inputAbst_drvswdw(void)
{
    if(Ked.DwSw.Push())
    {
        setEventFlag(INPUUT_BUTTON_DRVSWDW);
    }
}

static void vds_inputAbst_confsw(void)
{
    if(Ked.ConfSw.Push())
    {
        setEventFlag(INPUT_BUTTON_CONFSW);
    }
}





