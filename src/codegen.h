#ifndef _TIGER_CODEGEN_H
#define _TIGER_CODEGEN_H

static string temp_t_call_instr;
static Temp_tempList temp_t_call_list;
static assem_instr temp_t_call_assem_ins;

static int arg_count = 0;
static Temp_temp frame_pointer;

static Temp_temp munch_exp(T_exp e);

assem_instr_list code_generate(F_frame, T_stmList);

static void mk_ins_list(assem_instr);

static void munch_stm(T_stm);

static Temp_tempList munch_args(int, T_expList);


extern Temp_map F_tempMap;
static assem_instr_list final_instruction_list = NULL;
static assem_instr_list last = NULL;
static F_frame auxi_frame = NULL;
#endif
