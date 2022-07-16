[BITS 64] ;do not compile this as a elf file only build it as a binary otherwise bootboot will cry and spank
; at&t syntax sucks intel syntax is better anyone agrees with me?
; amogus sussy impostor
[extern _idt]
idtDescriptor:
    dw 4096
    dq _idt
%macro PUSHALL 0
    PUSH rax
    PUSH rcx
    PUSH rdx
    PUSH r9
    PUSH r10
    PUSH r11
%endmacro    

%macro POPALL 0
    POP rax
    POP rcx
    POP rdx
    POP r9
    POP r10
    POP r11
%endmacro 
;took from the tutorial i saw lol just tried to turn it into intel syntax instead of at&t cuz i hate at%t syntax 


[extern isrlHandler]

isrl:
    PUSHALL
    call isrlHandler
    POPALL
    iretq
    GLOBAL isrl
LoadIDT:
    lidt [idtDescriptor]
    sti
    ret
    global LoadIDT