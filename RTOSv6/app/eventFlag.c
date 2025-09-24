/******************************************** */
/*イベントフラグ設定ファイル                    */
/******************************************** */

/*多分return falseとかするためにdefineがいる*/

#include "eventFlag.h"

static EventFlag_t inputEventFlag;
static EventFlag_t outputEventFlag;

void initialEventFlag(void)
{
    inputEventFlag.flags = 0;
    outputEventFlag.flags  = 0;
}

void setEventFlag(u16 event)
{
    eventFlag.flags |= event;
}

_Bool checkEventFlag(u16 event)
{
    if(eventFlag.flags & event)
    {
        eventFlags.flags &= ~event;
        return true;
    }
    return false;
}

_Bool peekEventFlag(u16 event)
{
    return (eventFlag.flags & event) != 0;
}