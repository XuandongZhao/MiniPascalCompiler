#include <stdio.h>
#include <string.h>
#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "assem.h"
#include "codegen.h"

// 生成MIPS指令集列表
assem_instr_list code_generate(F_frame f, T_stmList s) {
    // 辅助栈帧
    auxi_frame = f;
    // 解析中间语法树
    for (T_stmList stm_list_it = s; stm_list_it; stm_list_it = stm_list_it->tail) {
        munch_stm(stm_list_it->head);
    }
    // 指令列表
    assem_instr_list assem_instructions = final_instruction_list;
    final_instruction_list = last = NULL;
    return assem_instructions;
}

// 建立指令列表
static void mk_ins_list(assem_instr instr) {
    bool ifcondition = !final_instruction_list;
    if (ifcondition) {
        final_instruction_list = assemInstrList(instr, NULL);
        last = final_instruction_list;
    } else {
        last->tail = assemInstrList(instr, NULL);
        last = last->tail;
    }
}


// 解析exp子树
static Temp_temp munch_exp(T_exp e) {
    // 从临时变量中选取一个空间
    Temp_temp r = Temp_newTemp();
    // MIPS汇编指令码
    char assemString[100];
    char temp_assemString[100];
    string assemStrP;
    switch (e->exp_type) {
        // BINOP二元操作符
        case T_BINOP: {
            T_binOp e_op = e->exp_value.BINOP.op;
            // 操作符左右变量
            char *op = NULL;
            T_exp left = e->exp_value.BINOP.left;
            T_exp right = e->exp_value.BINOP.right;
            // + - * / 类型
            if (e_op == T_plus)
                op = "add";
            else if (e_op == T_minus)
                op = "sub";
            else if (e_op == T_mul)
                op = "mul";
            else if (e_op == T_div)
                op = "div";
            else {
                printf("The operation of the BINOP is not leagal!\n");
                assert(0);
            }
            // 若为表达式 OP 常量
            if (left->exp_type == T_CONST) {
                // 汇编指令生成
                sprintf(temp_assemString, "%si $@d0, $@d0, %x", op, left->exp_value.CONST);
                strcpy(assemString, temp_assemString);
                assemStrP = String(assemString);
                // 递归解析
                Temp_tempList temp_temp_list = Temp_TempList(r = munch_exp(right), NULL);
                assem_instr temp_assem_ins = assemOper(assemStrP, temp_temp_list, NULL, NULL);
                mk_ins_list(temp_assem_ins);
            }
                // 常量 OP 表达式
            else if (e->exp_value.BINOP.right->exp_type == T_CONST) {
                sprintf(temp_assemString, "%si $@d0, $@d0, %x", op, right->exp_value.CONST);
                strcpy(assemString, temp_assemString);
                assemStrP = String(assemString);
                Temp_tempList temp_temp_list = Temp_TempList(r = munch_exp(left), NULL);
                assem_instr temp_assem_ins = assemOper(assemStrP, temp_temp_list, NULL, NULL);
                mk_ins_list(temp_assem_ins);
            }
                // 表达式 OP 表达式
            else {
                sprintf(temp_assemString, "%s $@d0, $@s0, $@d0", op);
                strcpy(assemString, temp_assemString);
                assemStrP = String(assemString);
                // 解析右表达式
                Temp_tempList temp_temp_list_1 = Temp_TempList(r = munch_exp(right), NULL);
                // 解析左表达式
                Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(left), NULL);
                // 分配寄存器
                assem_instr temp_assem_ins = assemOper(assemStrP, temp_temp_list_1, temp_temp_list_2, NULL);
                mk_ins_list(temp_assem_ins);
            }
            return r;
        }
            // MEM 取地址
        case T_MEM: {
            // 地址EXP
            T_exp mem = e->exp_value.MEM;

            bool condi_1 = (mem->exp_type == T_BINOP);
            bool condi_2 = (mem->exp_value.BINOP.op == T_plus);
            bool condi_mem_const = (mem->exp_type == T_CONST);
            // 二元加法表达式
            if (condi_1 && condi_2) {
                T_exp left = mem->exp_value.BINOP.left, right = mem->exp_value.BINOP.right;
                bool condition_left_const = (left->exp_type == T_CONST);
                bool condition_right_const = (right->exp_type == T_CONST);
                // MEM(BINOP(+, CONST, exp))
                if (condition_left_const) {
                    sprintf(temp_assemString, "lw $@d0, %d($@s0)", left->exp_value.CONST);
                    strcpy(assemString, temp_assemString);
                    assemStrP = String(assemString);
                    // 计算Expression
                    Temp_tempList temp_temp_list = Temp_TempList(munch_exp(right), NULL);
                    assem_instr temp_assem_instr = assemMove(assemStrP, Temp_TempList(r, NULL), temp_temp_list);
                    mk_ins_list(temp_assem_instr);
                }
                    // MEM(BINOP(+, exp, CONST))
                else if (condition_right_const) {
                    sprintf(temp_assemString, "lw $@d0, %d($@s0)", right->exp_value.CONST);
                    strcpy(assemString, temp_assemString);
                    assemStrP = String(assemString);
                    // CONST -> 新的临时变量表
                    Temp_tempList temp_temp_list_1 = Temp_TempList(r, NULL);
                    // EXP -> 临时变量表
                    Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(left), NULL);
                    assem_instr temp_assem_instr = assemMove(assemStrP, temp_temp_list_1, temp_temp_list_2);
                    mk_ins_list(temp_assem_instr);
                } else {
                    // 出错
                    printf("Both the left and right are not const!\n");
                }
            }
                // MEM(CONST)
            else if (condi_mem_const) {
                sprintf(temp_assemString, "addi $@d0, $0, %d", mem->exp_value.CONST);
                strcpy(assemString, temp_assemString);
                assemStrP = String(assemString);
                Temp_tempList temp_temp_list = Temp_TempList(r, NULL);
                assem_instr temp_assem_instr = assemMove(assemStrP, temp_temp_list, NULL);
                mk_ins_list(temp_assem_instr);
            }
                // MEM(exp)
            else {
                string temp_str = String("lw $@d0, 0($@s0)");
                Temp_tempList temp_temp_list_1 = Temp_TempList(r, NULL);
                Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(mem->exp_value.MEM), NULL);
                assem_instr temp_assem_instr = assemMove(temp_str, temp_temp_list_1, temp_temp_list_2);
                mk_ins_list(temp_assem_instr);
            }
            return r;
        }
        case T_TEMP: {
            Temp_temp temp_return_temp = e->exp_value.TEMP;
            return temp_return_temp;
        }
            // ESEQ
        case T_ESEQ: {
            // 计算statement
            munch_stm(e->exp_value.ESEQ.stm);
            // 返回expression值
            return munch_exp(e->exp_value.ESEQ.exp);
        }
        case T_NAME: {
            if (F_tempMap)
                Temp_enter(F_tempMap, r, Temp_labelString(e->exp_value.NAME));
            else
                Temp_enter((F_tempMap = Temp_empty()), r, Temp_labelString(e->exp_value.NAME));
            return r;
        }
            // 常量
        case T_CONST: {
            // 常量存入寄存器中
            sprintf(temp_assemString, "addi $@d0, $0, %d", e->exp_value.CONST);
            strcpy(assemString, temp_assemString);
            assemStrP = String(assemString);
            assem_instr temp_assem_instr = assemMove(assemStrP, Temp_TempList(r, NULL), NULL);
            mk_ins_list(temp_assem_instr);
            return r;
        }
            // CALL 调用函数
        case T_CALL: {
            // 对应函数结果在r中
            r = munch_exp(e->exp_value.CALL.fun);
            Temp_temp fp_temp = Temp_newTemp();
            frame_pointer = fp_temp;

            // 保存帧指针
            string temp_instr = String("lw $@d0, 0($1)");
            Temp_tempList temp_temp_list = Temp_TempList(fp_temp, NULL);
            assem_instr temp_assem_instr = assemMove(temp_instr, temp_temp_list, NULL);
            mk_ins_list(temp_assem_instr);


            // 调用函数 传参
            temp_t_call_instr = String("call @s0");
            temp_t_call_list = Temp_TempList(r, munch_args(0, e->exp_value.CALL.args));
            temp_t_call_assem_ins = assemOper(temp_t_call_instr, F_calldefs(), temp_t_call_list, NULL);


            string temp2_instr = String("addi $ra, 4($sp)");
            assem_instr temp2_assem_instr = assemOther(temp2_instr);
            mk_ins_list(temp2_assem_instr);
            mk_ins_list(temp_t_call_assem_ins);

            fp_temp = Temp_newTemp();
            temp_t_call_assem_ins = assemMove(String("lw $@d0, 0($1)"), Temp_TempList(fp_temp, NULL), NULL);
            mk_ins_list(temp_t_call_assem_ins);

            char assem_temp[100];
            char temp_assem_temp[100];
            sprintf(temp_assem_temp, "addi $@d0, $@d0, %x", arg_count * 4);
            strcpy(assem_temp, temp_assem_temp);
            mk_ins_list(assemOper(String(assem_temp), Temp_TempList(fp_temp, NULL), NULL, NULL));
            sprintf(temp_assem_temp, "sw $@d0, 0($1)");
            strcpy(assem_temp, temp_assem_temp);
            mk_ins_list(assemMove(String(assem_temp), Temp_TempList(fp_temp, NULL), NULL));
            return r;
        }
        default: {
            printf("The type of exp is not valid!\n");
            assert(0);
        }
    }
}

// 解析statement
static void munch_stm(T_stm s) {
    // 汇编指令字符串
    string assemStrP;
    char assemString[100];
    char temp_assemString[100];
    switch (s->stm_type) {
        // MOVE指令
        case T_MOVE: {
            T_exp dst = s->stm_value.MOVE.dst, src = s->stm_value.MOVE.src;
            // 判断类型
            bool condition_dst_type_mem = (dst->exp_type == T_MEM);
            bool condition_dst_type_temp = (dst->exp_type == T_TEMP);
            if (condition_dst_type_mem) {
                T_exp temp_dst_expvalue = dst->exp_value.MEM;
                // 是否是加法二元运算
                bool temp_condi_1 = (temp_dst_expvalue->exp_type == T_BINOP);
                bool temp_condi_2 = (temp_dst_expvalue->exp_value.BINOP.op == T_plus);
                bool temp_condi_mem_const = (temp_dst_expvalue->exp_type == T_CONST);
                bool temp_src_mem = (src->exp_type == T_MEM);
                if (temp_condi_1 && temp_condi_2) {
                    bool temp_condi_binop_right_const = (temp_dst_expvalue->exp_value.BINOP.right->exp_type == T_CONST);
                    // MOVE (MEM(BINOP(+, e1, CONST)), e2)
                    if (temp_condi_binop_right_const) {
                        T_exp e1 = dst->exp_value.MEM->exp_value.BINOP.left;
                        T_exp e2 = src;
                        sprintf(temp_assemString, "sw $@s1, %d($@s0)",
                                dst->exp_value.MEM->exp_value.BINOP.right->exp_value.CONST);
                        strcpy(assemString, temp_assemString);
                        assemStrP = String(assemString);
                        Temp_tempList temp_temp_list_1 = Temp_TempList(munch_exp(e2), NULL);
                        Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(e1), temp_temp_list_1);
                        mk_ins_list(assemMove(assemStrP, NULL, temp_temp_list_2));
                    }
                    bool temp_condi_binop_left_const = (temp_dst_expvalue->exp_value.BINOP.left->exp_type == T_CONST);
                    // MOVE (MEM(BINOP(+, CONST, e1)), e2)
                    if (temp_condi_binop_left_const) {
                        T_exp e1 = temp_dst_expvalue->exp_value.BINOP.right;
                        T_exp e2 = src;
                        sprintf(temp_assemString, "sw $@s1, %d($@s0)",
                                dst->exp_value.MEM->exp_value.BINOP.left->exp_value.CONST);
                        strcpy(assemString, temp_assemString);
                        assemStrP = String(assemString);
                        Temp_tempList temp_temp_list_1 = Temp_TempList(munch_exp(e2), NULL);
                        Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(e1), temp_temp_list_1);
                        mk_ins_list(assemMove(assemStrP, NULL, temp_temp_list_2));
                    }
                }
                    // MOVE(MEM(CONST), e)
                else if (temp_condi_mem_const) {
                    sprintf(temp_assemString, "sw $@s0, %d($0)", dst->exp_value.MEM->exp_value.CONST);
                    strcpy(assemString, temp_assemString);
                    assemStrP = String(assemString);
                    mk_ins_list(assemMove(assemStrP, NULL, Temp_TempList(munch_exp(src), NULL)));
                }
                    // MOVE(MEM(e), MEM(e))
                else if (temp_src_mem) {
                    Temp_tempList temp_temp_list_1 = Temp_TempList(munch_exp(src->exp_value.MEM), NULL);
                    Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(dst->exp_value.MEM), temp_temp_list_1);
                    mk_ins_list(assemMove("sw $@s1, 0($@s0)", NULL, temp_temp_list_2));
                }
                    // MOVE(MEM(e), e)
                else {
                    Temp_tempList temp_temp_list_1 = Temp_TempList(munch_exp(src), NULL);
                    Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(dst->exp_value.MEM), temp_temp_list_1);
                    mk_ins_list(assemMove(String("sw $@s1, 0($@s0)"), NULL, temp_temp_list_2));
                }
            }
                // MOVE(TEMP(e), e)
            else if (condition_dst_type_temp) {
                Temp_tempList temp_temp_list_1 = Temp_TempList(munch_exp(dst), NULL);
                Temp_tempList temp_temp_list_2 = Temp_TempList(munch_exp(src), NULL);
                mk_ins_list(assemMove(String("add $@d0, $@s0, $0"), temp_temp_list_1, temp_temp_list_2));
            } else {
                // 报错
                printf("The type of the dst->exp is not valid!\n");
                assert(0);
            }
            break;
        }
        case T_SEQ: {
            //依次计算两个statement
            munch_stm(s->stm_value.SEQ.left);
            munch_stm(s->stm_value.SEQ.right);
            break;
        }
        case T_LABEL: {
            sprintf(temp_assemString, "%s", Temp_labelString(s->stm_value.LABEL));
            strcpy(assemString, temp_assemString);
            assemStrP = String(assemString);
            assem_instr temp_assem_label = assemLabel(assemStrP, s->stm_value.LABEL);
            mk_ins_list(temp_assem_label);
            break;
        }
        case T_JUMP: {
            // 计算JUMP exp
            Temp_temp r = munch_exp(s->stm_value.JUMP.exp);
            Temp_tempList temp_temp_list = Temp_TempList(r, NULL);
            assem_instr temp_assem_oper = assemOper(String("j @d0"), temp_temp_list, NULL,
                                                    assemTar(s->stm_value.JUMP.jumps));
            mk_ins_list(temp_assem_oper);
            break;
        }
        case T_CJUMP: {
            // 提取条件表达式各部分
            char *cmp;
            Temp_temp left = munch_exp(s->stm_value.CJUMP.left), right = munch_exp(s->stm_value.CJUMP.right);
            Temp_temp store_jump = Temp_newTemp();
            // ==判断 beq即可
            if (s->stm_value.CJUMP.op == T_eq) {
                mk_ins_list(
                        assemOper(String("beq $@s0, $@s1, @j0"), NULL, Temp_TempList(left, Temp_TempList(right, NULL)),
                                  assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
                // !=判断 bne即可
            else if (s->stm_value.CJUMP.op == T_ne) {
                mk_ins_list(
                        assemOper(String("bne $@s0, $@s1, @j0"), NULL, Temp_TempList(left, Temp_TempList(right, NULL)),
                                  assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
                // <判断, sub+bltz(使用$zero)
            else if (s->stm_value.CJUMP.op == T_lt) {
                mk_ins_list(assemOper(String("sub $@s0, $@s1, $@s2"), NULL,
                                      Temp_TempList(store_jump, Temp_TempList(left, Temp_TempList(right, NULL))),
                                      NULL));
                mk_ins_list(assemOper(String("bltz $@s0, @j0"), NULL, Temp_TempList(store_jump, NULL),
                                      assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
                // >判断， sub+bgtz
            else if (s->stm_value.CJUMP.op == T_gt) {
                mk_ins_list(assemOper(String("sub $@s0, $@s1, $@s2"), NULL,
                                      Temp_TempList(store_jump, Temp_TempList(left, Temp_TempList(right, NULL))),
                                      NULL));
                mk_ins_list(assemOper(String("bgtz $@s0, @j0"), NULL, Temp_TempList(store_jump, NULL),
                                      assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
                // <=判断， sub+blez
            else if (s->stm_value.CJUMP.op == T_le) {
                mk_ins_list(assemOper(String("sub $@s0, $@s1, $@s2"), NULL,
                                      Temp_TempList(store_jump, Temp_TempList(left, Temp_TempList(right, NULL))),
                                      NULL));
                mk_ins_list(assemOper(String("blez $@s0, @j0"), NULL, Temp_TempList(store_jump, NULL),
                                      assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
                // >=判断， sub+bgez
            else if (s->stm_value.CJUMP.op == T_ge) {
                string temp_string = String("sub $@s0, $@s1, $@s2");
                Temp_tempList temp_temp_list = Temp_TempList(store_jump,
                                                             Temp_TempList(left, Temp_TempList(right, NULL)));
                mk_ins_list(assemOper(temp_string, NULL, temp_temp_list, NULL));
                temp_temp_list = Temp_TempList(store_jump, NULL);
                mk_ins_list(assemOper(String("bgez $@s0, @j0"), NULL, temp_temp_list,
                                      assemTar(Temp_LabelList(s->stm_value.CJUMP.dest_true, NULL))));
            }
            break;
        }
        case T_EXP:
            munch_exp(s->stm_value.EXP);
            break;
        default:
            assert(0);
    }
}

static Temp_tempList munch_args(int i, T_expList args) {
    if (!args) {
        arg_count = i - 1;
        return NULL;
    }
    Temp_tempList Temp_TempListist = munch_args(i + 1, args->tail);
    Temp_temp rarg = munch_exp(args->head);

    char assem_temp[100];
    sprintf(assem_temp, "sw $@d0, %d($@s0)", i * 4);

    mk_ins_list(assemMove(String(assem_temp), Temp_TempList(rarg, NULL), Temp_TempList(frame_pointer, NULL)));
    if (i == 0) {
        sprintf(assem_temp, "subi $@d0, $@d0, %x", arg_count * 4);
        mk_ins_list(assemOper(String(assem_temp), Temp_TempList(frame_pointer, NULL), NULL, NULL));
        sprintf(assem_temp, "sw $@d0, 0($1)");
        mk_ins_list(assemMove(String(assem_temp), Temp_TempList(frame_pointer, NULL), NULL));
    }
    return Temp_TempListist;
}
