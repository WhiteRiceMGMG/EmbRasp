//インテリジェンス持たせる

void vdg_appAbstif_mainloop(void);
static void vds_appAbst_proceeded(void);
static void vds_appAbst_discrete(void);


void vdg_appAbstif_mainloop(void)
{
    vds_appAbst_proceeded();
    vds_appAbst_discrete();
}

/*連続系処理*/
static void vds_appAbst_proceeded(void)
{
    
}

/*離散系処理*/
static void vds_appAbst_discrete(void)
{

}

static _Bool vds_kedigsw_pushed(void)
{
    return vdg_inputAbstif_igswPush();
}

static _Bool vds_keddrvupsw_pushed(void);
{
    return vdg_inputAbstif_drvswupPush();
}



_Bool vdg_inputAbstif_drvswdwPush(void)
{
    return checkEvent(INPUT_BUTTON_DRVSWDW);
}
_Bool vdg_inputAbstif_confswPush(void)
{
    return checkEvent(INPUT_BUTTON_CONFSW);
}







