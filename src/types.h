typedef struct Ty_ty_ *Ty_ty;
typedef struct Ty_tyList_ *Ty_tyList;

struct Ty_ty_ {
    enum {
        Ty_nil, Ty_int, Ty_string, Ty_array,
        Ty_name, Ty_void
    } ty_type;
    union {
        Ty_ty array;
        struct {
            S_symbol sym;
            Ty_ty ty;
        } name;
    } ty_storage;
};

struct Ty_tyList_ {
    Ty_ty head;
    Ty_tyList tail;
};

Ty_ty Ty_Nil();

Ty_ty Ty_Int();

Ty_ty Ty_String();

Ty_ty Ty_Void();

Ty_ty Ty_Array(Ty_ty ty);

Ty_ty Ty_Name(S_symbol sym, Ty_ty ty);

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail);

Ty_ty Ty_UnwrapNamedTy(Ty_ty);

bool Ty_IsMatch(Ty_ty, Ty_ty);
