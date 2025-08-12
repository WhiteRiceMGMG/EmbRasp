/*
 * knldef.h
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */

#ifndef INCLUDE_KNLDEF_H_
#define INCLUDE_KNLDEF_H_


#ifndef KNLDEF_H
#define KNLDEF_H
/*
 *** Try Kernel
 *      カーネル内部共通定義
 */

/* グローバル関数 */
extern void Reset_Handler(void);        /* リセットハンドラ */

/* OSメイン関数 */
extern int main(void);

#endif  /* KNLDEF_H */


#endif /* INCLUDE_KNLDEF_H_ */
