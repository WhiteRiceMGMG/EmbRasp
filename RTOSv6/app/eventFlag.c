/******************************************** */
/*イベントフラグ設定ファイル                    */
/******************************************** */


#include "eventFlag.h"

static EventFlag_t inputEventFlag;
static EventFlag_t outputEventFlag;

void initialEventFlag(void)
{
    inputEventFlag.flags = 0;
    outputEventFlag.flags  = 0;
}

void setEventFlag(EventFlag_t *ef, u16 event)
{
    ef->flags |= event;
}

_Bool checkEventFlag(EventFlag_t *ef, u16 event)
{
    if(eventFlag.flags & event)
    {
        ef->flags &= ~event;
        return true;
    }
    return false;
}

_Bool peekEventFlag(EventFlag_t *ef, u16 event)
{
    return (ef->flags & event) != 0;
}