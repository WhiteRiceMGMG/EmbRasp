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









