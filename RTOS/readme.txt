interface ゼロから作るOS用
自分メモ用
<<<<<<< Updated upstream
<<<<<<< Updated upstream
大体で来た気もするが．．．
いや，まだつかない
=======
=======
>>>>>>> Stashed changes
ROM上に配置されたプログラムを実行する．
マイコンがリセットされるとROM上の定められたアドレスからプログラムを実行する．
ROMの先頭に例外ベクタテーブルがあり，そこにリセット時に実行開始するプログラムアドレスがある．
これをリセットハンドラと呼ぶ．
電源投入時にROMから起動処理専用プログラムがRAMに転送される
例外のハンドラの実行アドレスの設定データがベクタテーブル．
picoは16bKyteのROMがある，ユーザ変更ができない．
外部フラッシュメモリはSPIインターフェースで接続されている．
XIPというハードウェア機能で通常のROMのようにマップされる．
外部フラッシュメモリの先頭256バイトはセカンドステージブートローダのプログラム配置．
その後ろにユーザ定義の例外ベクタテーブルとユーザのプログラムを配置する．
内部ROMと外部フラッシュメモリの例外ベクタテーブルは別物である．
picoは電源投入でリセットされるとROMのリセットハンドラが実行される．
通常モードの場合はファーストステージブートローダ．
これは外部フラッシュメモリの先頭にあるセカンドステージブートローダをSRAMに転送する．
セカンドステージブートローダではまず外部フラッシュメモリのプログラムを最適化する


インターフェースのコードを
