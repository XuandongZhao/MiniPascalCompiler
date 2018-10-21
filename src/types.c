#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "types.h"

static struct Ty_ty_ tynil = {Ty_nil};
static struct Ty_ty_ tyint = {Ty_int};
static struct Ty_ty_ tystring = {Ty_string};
static struct Ty_ty_ tyvoid = {Ty_void};

Ty_ty Ty_Nil() { return &tynil; }

Ty_ty Ty_Int() { return &tyint; }

Ty_ty Ty_String() { return &tystring; }

Ty_ty Ty_Void() { return &tyvoid; }

Ty_ty Ty_Name(S_symbol sym, Ty_ty ty) {
    Ty_ty p = (Ty_ty) malloc(sizeof(*p));
    p->ty_type = Ty_name;
    p->ty_storage.name.sym = sym;
    p->ty_storage.name.ty = ty;
    return p;
}

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail) {
    Ty_tyList p = (Ty_tyList) malloc(sizeof(*p));
    p->head = head;
    p->tail = tail;
    return p;
}

Ty_ty Ty_Array(Ty_ty ty) {
    Ty_ty p = (Ty_ty) malloc(sizeof(*p));
    p->ty_type = Ty_array;
    p->ty_storage.array = ty;
    return p;
}

Ty_ty Ty_UnwrapNamedTy(Ty_ty wrapped_ty) {
    if (!wrapped_ty)
        return wrapped_ty;
    else if (wrapped_ty->ty_type == Ty_name) {
        return Ty_UnwrapNamedTy(wrapped_ty->ty_storage.name.ty);
    } else {
        return wrapped_ty;
    }
}

bool Ty_IsMatch(Ty_ty l, Ty_ty r) {
    Ty_ty l_t = Ty_UnwrapNamedTy(l);
    Ty_ty r_t = Ty_UnwrapNamedTy(r);

    int l_type = l_t->ty_type;
    int r_type = r_t->ty_type;

    return (((l_type == Ty_array) && l_t == r_t) ||
            (l_type == r_type));
}
