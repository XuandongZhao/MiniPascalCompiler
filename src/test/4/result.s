BEGIN L1
lw $9, 0($5)
lw $8, 4($9)
add $6, $8, $0
jr $ra
END L1

main:
lui  $4, 0x7fff
ori $4, $4, 0xf4c0
sw $4, 0($4)
addi $12, $0, 0
add $4, $12, $0
lw $16, 0($1)
addi $17, $0, 1
sw $17, 4($16)
sw $5, 0($16)
subi $16, $16, 4
sw $16, 0($1)
addi $ra, 4($sp)
call L1
lw $25, 0($1)
addi $25, $25, 4
sw $25, 0($1)
add $4, $L1, $0
