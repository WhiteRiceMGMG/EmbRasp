/******************************************** */
/*イベントフラグ設定ヘッダーファイル             */
/******************************************** */

#ifndef EVENT_FLAG_H
#define EVENT_FLAG_H

#define INPUT_EVENT_FLAG (&inputEventFlag)
#define OUTPUT_EVENT_FLAG (&outputEventFlag)

typedef struct
{
    u16 flags;
} EventFlag_t;

/******************************************** */
/*外部公開用API                                */
/******************************************** */


void initialEventFlag(void);
void setEventFlag(EventFlag_t *ef, u16 event);
_Bool checkEventFlag(EventFlag_t *ef, u16 event);
_Bool peekEventFlag(EventFlag_t *ef, u16 event);

#endif

