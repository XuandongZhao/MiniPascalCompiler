BEGIN L1
lw $10, 0($5)
lw $9, 8($10)
addi $12, $0, 0
beq $9, $12, L2
L2:
lw $16, 0($5)
lw $15, 4($16)
add $7, $15, $0
j L4
L3:
lw $22, 0($1)
lw $24, 0($5)
lw $23, 8($24)
sw $23, 8($22)
lw $28, 0($5)
lw $27, 8($28)
lw $31, 0($5)
lw $30, 4($31)
add $27, $30, $27
sw $27, 4($22)
lw $33, 0($5)
sw $33, 0($22)
subi $22, $22, 8
sw $22, 0($1)
addi $ra, 4($sp)
call L1
lw $41, 0($1)
addi $41, $41, 8
sw $41, 0($1)
add $7, $L1, $0
j L4
L4:
jr $ra
END L1

main:
lui  $4, 0x7fff
ori $4, $4, 0xf4c0
sw $4, 0($4)
addi $44, $0, 0
add $4, $44, $0
addi $46, $0, 0
add $6, $46, $0
lw $50, 0($1)
addi $51, $0, 36
sw $51, 8($50)
addi $52, $0, 24
sw $52, 4($50)
sw $5, 0($50)
subi $50, $50, 8
sw $50, 0($1)
addi $ra, 4($sp)
call L1
lw $54, 0($1)
addi $54, $54, 8
sw $54, 0($1)
add $6, $L1, $0