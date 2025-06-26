# ----------------------------
# Makefile for ARM Cortex-M0 + UF2
# ----------------------------

# ツールチェーンプレフィックス
CROSS ?= arm-none-eabi

# sysroot を自動検出（gcc ドライバが返すルートパス）
SYSROOT := $(shell $(CROSS)-gcc --print-sysroot)

# コンパイルフラグ
# -ffunction-sections/fdata-sections で関数/データ毎に独立セクションに分離
CFLAGS  := -mcpu=cortex-m0 -mthumb -Os -Wall -nostdlib \
			-ffunction-sections -fdata-sections \
			--sysroot=$(SYSROOT)

# リンクフラグ
# -Wl,--gc-sections で未参照セクションを削除
LDFLAGS := -T link.ld -Wl,--gc-sections \
			--sysroot=$(SYSROOT)

# ターゲット名
TARGET := main

# デフォルト
all: $(TARGET).uf2

# 1) ELF生成
$(TARGET).elf: startup.o main.o
	$(CROSS)-gcc $(CFLAGS) $^ $(LDFLAGS) -o $@

# 2) Cソースをコンパイル
main.o: main.c
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

# 3) ASMソースをコンパイル
startup.o: startup.S
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

# 4) ELF→BIN
$(TARGET).bin: $(TARGET).elf
	$(CROSS)-objcopy -O binary $< $@

# 5) BIN→UF2
$(TARGET).uf2: $(TARGET).bin
	python3 uf2conv.py $< -c -b 0x10000000 -o $@

# 掃除
clean:
	rm -f *.o *.elf *.bin *.uf2

.PHONY: all clean
