//インテリジェンス持たせる

void vdg_appAbstif_mainloop(void);
static vds_appAbst_proceeded(void);
static vds_appAbst_discrete(void);


void vdg_appAbstif_mainloop(void)
{
    vds_appAbst_proceeded();
    vds_appAbst_discrete();
}






う～ン，どういう構造にすればいいかね
メインからコールされるのが連続と非連続のやつ，？






