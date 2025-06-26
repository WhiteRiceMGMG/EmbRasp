.section .vectors, "a", %progbits
.word  _stack_top
.word  Reset_Handler

.text
.global Reset_Handler
Reset_Handler:
    bl main
    b .

.section .stack
.space 0x1000
.global _stack_top
_stack_top:
