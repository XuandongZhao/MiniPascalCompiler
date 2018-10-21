main:
lui  $4, 0x7fff
ori $4, $4, 0xf4c0
sw $4, 0($4)
addi $11, $0, 0
add $4, $11, $0
addi $13, $0, 0
add $6, $13, $0
addi $15, $0, 10
add $4, $15, $0
j L2
L3:
addi $4, $4, 1
add $4, $4, $0
L2:
addi $21, $0, 1
add $7, $21, $0
addi $23, $0, 20
beq $4, $23, L4
L5:
addi $26, $0, 0
add $7, $26, $0
L4:
addi $28, $0, 0
beq $7, $28, L1
L1:
addi $31, $0, 1
add $4, $31, $0
j L7
L8:
add $4, $6, $4
add $6, $4, $0
L7:
addi $38, $0, 1
add $8, $38, $0
addi $40, $0, 100
sub $41, $4, $40
bltz $41, L9
L10:
addi $43, $0, 0
add $8, $43, $0
L9:
addi $45, $0, 0
beq $8, $45, L6
L6:
j L12
L13:
addi $49, $0, 1
add $6, $49, $0
addi $51, $0, 1
add $4, $51, $0
L12:
addi $53, $0, 1
add $9, $53, $0
addi $55, $0, 0
sub $56, $4, $55
bgtz $56, L14
L15:
addi $58, $0, 0
add $9, $58, $0
L14:
addi $60, $0, 0
beq $9, $60, L11
L11:
