# プロジェクト名
TARGET = BareMetalRP2040

# ツールチェイン
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size
BIN2UF2 = bin2uf2

# ビルドディレクトリ
BUILD = build

# ソースファイル
SRCS = main.c startup.S

# 出力ファイル
ELF = $(BUILD)/$(TARGET).elf
BIN = $(BUILD)/$(TARGET).bin
UF2 = $(BUILD)/$(TARGET).uf2

# フラグ
CFLAGS = -Wall -O2 -nostdlib -mcpu=cortex-m0plus -mthumb -ffreestanding
LDFLAGS = -T link.ld -nostdlib -nostartfiles

# Windows 用ディレクトリ作成
$(BUILD):
	@if not exist $(BUILD) mkdir $(BUILD)

# ビルド
all: $(BUILD) $(UF2)

$(ELF): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(UF2): $(BIN)
	$(BIN2UF2) -i $< -o $@
	@echo Build complete: $@

# サイズ表示
size: $(ELF)
	$(SIZE) $<

# クリーン
clean:
	@if exist $(BUILD) rmdir /s /q $(BUILD)

.PHONY: all clean size
