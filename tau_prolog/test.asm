section .data
    password db 'encrypted_password' ; Replace 'encrypted_password' with the actual encrypted password

section .bss
    user_input resb 100

section .text
    global _start

_start:
    ; Read user input
    mov eax, 3 ; sys_read
    mov ebx, 0 ; stdin
    mov ecx, user_input
    mov edx, 100 ; maximum number of bytes to read
    int 0x80

    ; Compare user input with password
    mov edi, user_input
    mov esi, password
    xor ecx, ecx
    cld
    repe cmpsb

    ; Display message based on comparison result
    jne mismatch
    mov eax, 4 ; sys_write
    mov ebx, 1 ; stdout
    mov ecx, secret_message
    mov edx, secret_message_len
    int 0x80
    jmp exit

mismatch:
    mov eax, 4 ; sys_write
    mov ebx, 1 ; stdout
    mov ecx, no_secret_message
    mov edx, no_secret_message_len
    int 0x80

exit:
    ; Exit the program
    mov eax, 1 ; sys_exit
    xor ebx, ebx ; exit code 0
    int 0x80

section .data
    secret_message db 'Here is my secret', 0
    secret_message_len equ $ - secret_message

    no_secret_message db 'There is no secret', 0
    no_secret_message_len equ $ - no_secret_message
