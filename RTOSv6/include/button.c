/**********************************
イグニッションオン/オフスイッチ
ドライブモードセレクトアップスイッチ
ドライブモードセレクトダウンスイッチ
アクチュエータ稼働確認用スイッチ
***********************************/

#include "Button.h"
#include "kedknl.h"

u2 u2g_btnmodl_igswonoff(void)
{
    return (in_w(GPIO_IN) & (1 << 16)) != 0;
}

u2 u2g_btnmodl_drvmdmsswup(void)
{
    return (in_w(GPIO_IN) & (1 << 18)) != 0;
}

u2 u2g_btnmodl_drvmdmsswdw(void)
{
    return (in_w(GPIO_IN) & ( 1 << 20)) != 0;
}

u2 u2g_btnmodl_confacsw(void)
{
    return (in_w(GPIO_IN) & (1 << 22)) != 0;
}






