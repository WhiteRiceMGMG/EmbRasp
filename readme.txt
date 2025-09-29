1.最小限のLED点灯
  boot2.c startup.S main.c memmap.ldのみ
2.IQ社 RTOS
3.μTRONを参考に，

.
├── app イベントフラグや入出力抽象化
│   ├── eventFlag.c
│   ├── eventFlag.h
│   ├── inputAbstif.c
│   ├── appAbst.c
│   └── outputAbstif.c
├── boot マイコンに関するブートローダ
│   ├── boot2.c
│   ├── reset_hdr.c
│   └── vector_tbl.c
├── common マイコンが起動したら実行されるメインループ
│   └── main.c
├── include 入出力機器や型定義，リネーム，オブジェクト化など          
│   ├── led.c
│   ├── led.h
│   ├── button.c
│   ├── button.h
│   ├── kedDriver.c
│   ├── kedDriver.h
│   ├── kedKnl.h
│   ├── knldef.h
│   ├── sysdef.h
│   ├── syslib.h

//とりあえずインタフェース見ながら入れてみる．




│   └── typedef.h
└── kernel
    └── syslib.c




#app  
##eventFlag.c
##eventFlag.h
##inputAbstif.c
##appAbst.c
##outputAbstif.c
#boot
##boot2.c
##reset_hdr.c
##vector_tbl.c
#common
##main.c
#include
##led.c
##led.h
##button.c
##button.h
##kedDriver.c
##kedDriver.h
##kedKnl.h
##knldef.h
##sysdef.h
##syslib.h
##typedef.h
#kernel
##syslib.c

.
├── [module_name] 部品名
│   ├── [edhitor-name]_[module_name].c コード作成者 + 部品名
│   └── [edhitor-name]_[module_name].h コード作成者 + 部品名
└── [module_name]if.h 外部公開関数/変数を記載．

.
├── igsw (イグニッションスイッチ)
│   ├── ymt_igsw.h (yamamoto + igsw)
│   └── ymt_igsw.c (yamamoto + igsw)
└── igswif.h (igsw + "InterFace")
