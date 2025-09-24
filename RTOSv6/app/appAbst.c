/******************************************** */
/*周期的に入力を確認しに行き，演算処理を行い出力へ */
/******************************************** */

void vdg_appAbstif_mainloop(void);
static void vds_appAbst_proceeded(void);
static void vds_appAbst_discrete(void);

void vdg_outputAbstif_igledon(void);
void vdg_outputAbstif_drvupledon(void);
void vdg_outputAbstif_drvdwledon(void);
void vdg_outputAbstif_confledon(void);



void vdg_appAbstif_mainloop(void)
{
    vds_appAbst_proceeded();
    vds_appAbst_discrete();
}

/******************************************** */
/*連続系処理                                   */
/******************************************** */
static void vds_appAbst_proceeded(void)
{
    ;
}

/******************************************** */
/*離散系処理                                   */
/******************************************** */
static void vds_appAbst_discrete(void)
{
    if(vds_kedigsw_pushed())
    {
        vdg_outputAbstif_igledon();
    }

    if(vds_keddrvupsw_pushed())
    {
        vdg_outputAbstif_drvupledon();
    }

    if(vds_keddrvdwsw_pushed())
    {
        vdg_outputAbstif_drvdwledon();
    }

    if(vds_kedconfsw_pushed())
    {
        vdg_outputAbstif_confledon();
    }
}


/******************************************** */
/*入力フラグを確認し，２値を返す                 */
/******************************************** */
static _Bool vds_kedigsw_pushed(void)
{
    return vdg_inputAbstif_igswPush();
}

static _Bool vds_keddrvupsw_pushed(void);
{
    return vdg_inputAbstif_drvswupPush();
}

static _Bool vds_keddrvdwsw_pushed(void)
{
    return vdg_inputAbstif_drvswdwPush();
}

static _Bool vds_kedconfsw_pushed(void)
{
    return vdg_inputAbstif_confswPush();
}









