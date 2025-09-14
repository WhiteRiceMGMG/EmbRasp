/******************************************** */
/*イベントフラグ設定ファイル                    */
/******************************************** */

#include "eventFlag.h"

static EventFlag_t eventFlag;

void initialEventFlag(void)
{
    eventFlag.flags = 0;
}

