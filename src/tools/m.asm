global	main msg

.text

msg:
	.ascii  "Hello, world!\n" # inline ascii string
	len =   . - msg           # assign (current address - address of msg start) to symbol "len"
main:
        push    r12
        xor     r12d, r12d
        push    rbp
        push    rbx
        jmp     .L7
.L14:
        movsx   esi, BYTE PTR [rbp+67]
.L6:
        mov     rdi, rbx
        add     r12d, 1
        call    std::ostream::put(char)
        mov     rdi, rax
        call    std::ostream::flush()
        cmp     r12d, 10
        je      .L12
.L7:
        mov     esi, r12d
        mov     edi, OFFSET FLAT:std::cout
        call    std::ostream::operator<<(int)
        mov     rbx, rax
        mov     rax, QWORD PTR [rax]
        mov     rax, QWORD PTR [rax-24]
        mov     rbp, QWORD PTR [rbx+240+rax]
        test    rbp, rbp
        je      .L13
        cmp     BYTE PTR [rbp+56], 0
        jne     .L14
        mov     rdi, rbp
        call    std::ctype<char>::_M_widen_init() const
        mov     rax, QWORD PTR [rbp+0]
        mov     esi, 10
        mov     rax, QWORD PTR [rax+48]
        cmp     rax, OFFSET FLAT:_ZNKSt5ctypeIcE8do_widenEc
        je      .L6
        mov     rdi, rbp
        call    rax
        movsx   esi, al
        jmp     .L6
.L12:
        pop     rbx
        xor     eax, eax
        pop     rbp
        pop     r12
        ret
.L13:
        call    std::__throw_bad_cast()

.data
