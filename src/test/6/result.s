BEGIN L1
addi $€1A13, $0, 0
add $7, $€1A13, $0
lw $17, 0($1)
lw $20, 0($5)
lw $19, 4($20)
addi $19, $19, 1
sw $19, 4($17)
sw $5, 0($17)
subi $17, $17, 4
sw $17, 0($1)
addi $ra, 4($sp)
call L2
lw $29, 0($1)
addi $29, $29, 4
sw $29, 0($1)
add $6, $L2, $0
jr $ra
END L1

BEGIN L2
addi $31, $0, 0
add $9, $31, $0
lw $35, 0($1)
lw $38, 0($5)
lw $37, 4($38)
addi $37, $37, 1
sw $37, 4($35)
sw $5, 0($35)
subi $35, $35, 4
sw $35, 0($1)
addi $ra, 4($sp)
call L3
lw $41, 0($1)
addi $41, $41, 4
sw $41, 0($1)
add $8, $L3, $0
jr $ra
END L2

BEGIN L3
addi $43, $0, 0
add $11, $43, $0
addi $45, $0, 10
add $11, $45, $0
lw $48, 0($5)
lw $47, 4($48)
add $10, $47, $0
addi $51, $0, 11
add $7, $51, $0
addi $53, $0, 12
add $9, $53, $0
jr $ra
END L3

main:
lui  $4, 0x7fff
ori $4, $4, 0xf4c0
sw $4, 0($4)
addi $55, $0, 0
add $4, $55, $0
lw $59, 0($1)
addi $60, $0, 1
sw $60, 4($59)
sw $5, 0($59)
subi $59, $59, 4
sw $59, 0($1)
addi $ra, 4($sp)
call L1
lw $62, 0($1)
addi $62, $62, 4
sw $62, 0($1)
add $4, $L1, $0
