//入力についてのイベントフラグ管理

enum 
{
    INPUT_BUTTON_IGSW    = 1 << 0,
    INPUT_BUTTON_DRVSWUP = 1 << 1,
    INPUT_BUTTON_DRVSWDW = 1 << 2,
    INPUT_BUTTON_CONFSW  = 1 << 3
}



void vdg_inputAbstif_eventFlag(void);
_Bool vdg_inputAbstif_igswPush(void);
_Bool vdg_inputAbstif_drvswupPush(void);
_Bool vdg_inputAbstif_drvswdwPush(void);
_Bool vdg_inputAbstif_confswPush(void);

static void vds_inputAbst_igsw(void);
static void vds_inputAbst_devswup(void);
static void vds_inputAbst_drvswdw(void);
static void vds_inputAbst_confsw(void);

/*この関数がMAINLOOPから周期的にコールを受ける．*/
void vdg_inputAbstif_eventFlag(void)
{
    vds_inputAbst_igsw();
    vds_inputAbst_drvswup();
    vds_inputAbst_drvswdw();
    vds_inputAbst_confsw();
}

/*appからコールされ，フラグをチェックする．*/
_Bool vdg_inputAbstif_igswPush(void)
{
    return checkEvent(INPUT_BUTTON_IGSW);
}
_Bool vdg_inputAbstif_drvswupPush(void)
{
    return checkEvent(INPUT_BUTTON_DRVSWUP);
}
_Bool vdg_inputAbstif_drvswdwPush(void)
{
    return checkEvent(INPUT_BUTTON_DRVSWDW);
}
_Bool vdg_inputAbstif_confswPush(void)
{
    return checkEvent(INPUT_BUTTON_CONFSW);
}

/*入力に応じてイベントフラグを立てる */
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





