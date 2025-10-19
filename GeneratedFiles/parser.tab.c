/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <iostream>
	#include <vector>
	#include <string>
	#include <math.h>
	#include "../HeaderFiles/node.hpp"
	#include "../HeaderFiles/errorClass.hpp"
	#include "../HeaderFiles/math.hpp"

	extern FILE* yyin;
	extern char* yytext;

	using namespace MagiLang;

    int yylex();
	void yyerror(const char* msg) {
      fprintf(stderr, "%s\n", msg);
   }

	AstNode* root;
	std::vector<MagiLang::errorClass>* errorList;

	#define YYERROR_VERBOSE 1

	/*void ifmem (astNode* parent, astNode* ifn)
	{
		if ()
		{
			if(ifn->nodes[1]->type == token::BRACE || ifn->nodes[1]->type == token::ROOT)
			{
				ifn->nodes[1]->memory->MEMparent = parent->memory;
			}
			if(ifn->nodes.size() == 3)
			{
				if(ifn->nodes[2]->type == token::BRACE || ifn->nodes[2]->type == token::ROOT)
				{
					ifn->nodes[2]->memory->MEMparent = parent->memory;
				}
			}
		}
		else
		{
			ifmem(parent->parent, ifn);
		}
	}*/

#line 118 "./GeneratedFiles/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_OPERATOR0 = 5,                  /* OPERATOR0  */
  YYSYMBOL_OPERATOR1 = 6,                  /* OPERATOR1  */
  YYSYMBOL_OPERATOR2 = 7,                  /* OPERATOR2  */
  YYSYMBOL_OPERATOR3 = 8,                  /* OPERATOR3  */
  YYSYMBOL_UNIOPERATOR0 = 9,               /* UNIOPERATOR0  */
  YYSYMBOL_UNIOPERATOR1 = 10,              /* UNIOPERATOR1  */
  YYSYMBOL_DOT = 11,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_COMMENT = 13,                   /* COMMENT  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 16,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 17,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_NAME = 20,                      /* NAME  */
  YYSYMBOL_TYPE = 21,                      /* TYPE  */
  YYSYMBOL_TAG = 22,                       /* TAG  */
  YYSYMBOL_UNKNOWN = 23,                   /* UNKNOWN  */
  YYSYMBOL_END = 24,                       /* END  */
  YYSYMBOL_CONSTANT = 25,                  /* CONSTANT  */
  YYSYMBOL_FUNC_CALL = 26,                 /* FUNC_CALL  */
  YYSYMBOL_YYACCEPT = 27,                  /* $accept  */
  YYSYMBOL_tree = 28,                      /* tree  */
  YYSYMBOL_lparen = 29,                    /* lparen  */
  YYSYMBOL_paren = 30,                     /* paren  */
  YYSYMBOL_lbrack = 31,                    /* lbrack  */
  YYSYMBOL_brack = 32,                     /* brack  */
  YYSYMBOL_lbrace = 33,                    /* lbrace  */
  YYSYMBOL_brace = 34,                     /* brace  */
  YYSYMBOL_node = 35,                      /* node  */
  YYSYMBOL_ifstmnt = 36,                   /* ifstmnt  */
  YYSYMBOL_iffull = 37,                    /* iffull  */
  YYSYMBOL_ifempty = 38,                   /* ifempty  */
  YYSYMBOL_type = 39,                      /* type  */
  YYSYMBOL_addsub = 40,                    /* addsub  */
  YYSYMBOL_muldiv = 41,                    /* muldiv  */
  YYSYMBOL_powroot = 42,                   /* powroot  */
  YYSYMBOL_equal = 43                      /* equal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    91,    92,    93,    94,    96,    97,    98,    99,
     100,   101,   103,   104,   105,   106,   106,   106,   106,   107,
     108,   109,   110,   111,   112,   113,   113,   115,   121,   122,
     124,   125,   127,   128,   130,   131,   135,   161,   187,   213
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE",
  "OPERATOR0", "OPERATOR1", "OPERATOR2", "OPERATOR3", "UNIOPERATOR0",
  "UNIOPERATOR1", "DOT", "SEMICOLON", "COMMENT", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "NAME", "TYPE", "TAG", "UNKNOWN",
  "END", "CONSTANT", "FUNC_CALL", "$accept", "tree", "lparen", "paren",
  "lbrack", "brack", "lbrace", "brace", "node", "ifstmnt", "iffull",
  "ifempty", "type", "addsub", "muldiv", "powroot", "equal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,    38,   -17,   -17,   -11,     7,   -17,   -17,   -17,   -17,
     -11,   -16,   -17,   -17,   -17,   -17,    70,   -17,    86,   -17,
      54,   -17,    28,   -17,   -17,     2,   -17,   -17,   -17,   -17,
     -17,   103,   -17,   -17,   -11,   -17,   -17,   -17,    28,   -17,
     -17,    28,   -17,   -17,   -17,   -17,    28,     7,     7,     7,
       7,   -17,   103,   -17,    28,    -2,   123,    11,     1,     3,
     -17,    28,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    37,     0,     0,     6,     8,    12,    16,
      32,     0,    30,    24,     7,    31,     0,    35,     0,    36,
       0,     4,     3,     5,    38,    39,    29,    25,    26,    27,
      28,     0,    23,    33,    44,    34,    10,    11,     9,    14,
      15,    13,    19,    20,    21,    18,    17,     0,     0,     0,
       0,    22,     0,    43,    42,     0,    46,    47,    48,    49,
      41,    40,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -17,    -3,   -17,   -17,   -17,    -6,    -5,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    31,     9,     7,    34,    35,    52,    33,     3,    50,
      51,    38,    51,    41,    45,    46,     9,     5,    49,    50,
      51,     7,     0,     8,     0,    53,    54,    10,    11,    12,
      13,    55,    15,    47,    48,    49,    50,    51,     2,     3,
       0,     4,    56,    57,    58,    59,    60,    61,     5,    62,
       6,     0,     7,     0,     8,     3,     9,     0,    10,    11,
      12,    13,    14,    15,     5,     0,    42,     0,     7,     0,
       8,     3,     9,    43,    10,    11,    12,    13,    44,    15,
       5,     0,     0,     0,     7,    36,     8,     3,     0,     0,
      10,    11,    12,    13,    37,    15,     5,     0,     0,     0,
       7,     0,     8,    39,     3,     0,    10,    11,    12,    13,
      40,    15,     0,     5,     0,     0,     0,     7,     0,     8,
       0,     9,     0,    10,    11,    12,    13,     0,    15,    48,
      49,    50,    51
};

static const yytype_int8 yycheck[] =
{
       5,     4,    18,    14,    20,    11,     4,    10,     1,     8,
       9,    16,     9,    18,    20,    20,    18,    10,     7,     8,
       9,    14,    -1,    16,    -1,    31,    31,    20,    21,    22,
      23,    34,    25,     5,     6,     7,     8,     9,     0,     1,
      -1,     3,    47,    48,    49,    50,    52,    52,    10,    55,
      12,    -1,    14,    -1,    16,     1,    18,    -1,    20,    21,
      22,    23,    24,    25,    10,    -1,    12,    -1,    14,    -1,
      16,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      10,    -1,    -1,    -1,    14,    15,    16,     1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    10,    -1,    -1,    -1,
      14,    -1,    16,    17,     1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    10,    -1,    -1,    -1,    14,    -1,    16,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,     6,
       7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,     0,     1,     3,    10,    12,    14,    16,    18,
      20,    21,    22,    23,    24,    25,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    30,    35,    30,    20,    34,    15,    24,    35,    17,
      24,    35,    12,    19,    24,    34,    35,     5,     6,     7,
       8,     9,     4,    34,    35,    30,    35,    35,    35,    35,
      34,    35,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    27,    28,    28,    28,    28,    28,    28,    29,    29,
      30,    30,    31,    31,    32,    32,    33,    33,    33,    33,
      34,    34,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    36,    36,
      37,    37,    38,    38,    39,    39,    40,    41,    42,    43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     1,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     4,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* tree: %empty  */
#line 79 "parser.y"
                                { (yyval.cnode) = root; }
#line 1316 "./GeneratedFiles/parser.tab.c"
    break;

  case 3: /* tree: tree node  */
#line 80 "parser.y"
                                                  { (yyvsp[-1].cnode)->append((yyvsp[0].node)); }
#line 1322 "./GeneratedFiles/parser.tab.c"
    break;

  case 4: /* tree: tree brace  */
#line 81 "parser.y"
                                                   { (yyvsp[-1].cnode)->append((yyvsp[0].cnode)); }
#line 1328 "./GeneratedFiles/parser.tab.c"
    break;

  case 5: /* tree: tree ifstmnt  */
#line 82 "parser.y"
                                                     { (yyvsp[-1].cnode)->append((yyvsp[0].node)); }
#line 1334 "./GeneratedFiles/parser.tab.c"
    break;

  case 6: /* tree: tree SEMICOLON  */
#line 83 "parser.y"
                                                       { delete (yyvsp[0].t); }
#line 1340 "./GeneratedFiles/parser.tab.c"
    break;

  case 7: /* tree: tree END  */
#line 84 "parser.y"
                                                 { delete (yyvsp[0].t); YYACCEPT; }
#line 1346 "./GeneratedFiles/parser.tab.c"
    break;

  case 8: /* lparen: LPAREN  */
#line 86 "parser.y"
                                       { (yyval.cnode) = new AstNodeMem((yyvsp[0].t)); delete (yyvsp[0].t); yylloc.first_line = (yyval.cnode)->location[0]; yylloc.first_column = (yyval.cnode)->location[1]; }
#line 1352 "./GeneratedFiles/parser.tab.c"
    break;

  case 9: /* lparen: lparen node  */
#line 87 "parser.y"
                                                    { (yyvsp[-1].cnode)->append((yyvsp[0].node)); }
#line 1358 "./GeneratedFiles/parser.tab.c"
    break;

  case 10: /* paren: lparen RPAREN  */
#line 88 "parser.y"
                                              { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; delete (yyvsp[0].t); (yyval.cnode)->type = Token::PAREN; }
#line 1364 "./GeneratedFiles/parser.tab.c"
    break;

  case 11: /* paren: lparen END  */
#line 89 "parser.y"
                                                   { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; }
#line 1370 "./GeneratedFiles/parser.tab.c"
    break;

  case 12: /* lbrack: LBRACK  */
#line 91 "parser.y"
                                       { (yyval.cnode) = new AstNodeMem((yyvsp[0].t)); delete (yyvsp[0].t); }
#line 1376 "./GeneratedFiles/parser.tab.c"
    break;

  case 13: /* lbrack: lbrack node  */
#line 92 "parser.y"
                                                    { (yyvsp[-1].cnode)->append((yyvsp[0].node)); }
#line 1382 "./GeneratedFiles/parser.tab.c"
    break;

  case 14: /* brack: lbrack RBRACK  */
#line 93 "parser.y"
                                              { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; delete (yyvsp[0].t); (yyval.cnode)->type = Token::BRACK; }
#line 1388 "./GeneratedFiles/parser.tab.c"
    break;

  case 15: /* brack: lbrack END  */
#line 94 "parser.y"
                                                   { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; }
#line 1394 "./GeneratedFiles/parser.tab.c"
    break;

  case 16: /* lbrace: LBRACE  */
#line 96 "parser.y"
                                       { (yyval.cnode) = new AstNodeMem((yyvsp[0].t)); delete (yyvsp[0].t); }
#line 1400 "./GeneratedFiles/parser.tab.c"
    break;

  case 17: /* lbrace: lbrace node  */
#line 97 "parser.y"
                                                    { (yyvsp[-1].cnode)->append((yyvsp[0].node)); }
#line 1406 "./GeneratedFiles/parser.tab.c"
    break;

  case 18: /* lbrace: lbrace brace  */
#line 98 "parser.y"
                                                     { (yyvsp[-1].cnode)->append((yyvsp[0].cnode)); (yyvsp[0].cnode)->memory->MEMparent = (yyvsp[-1].cnode)->memory; }
#line 1412 "./GeneratedFiles/parser.tab.c"
    break;

  case 19: /* lbrace: lbrace SEMICOLON  */
#line 99 "parser.y"
                                                         { delete (yyvsp[0].t); }
#line 1418 "./GeneratedFiles/parser.tab.c"
    break;

  case 20: /* brace: lbrace RBRACE  */
#line 100 "parser.y"
                                              { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; delete (yyvsp[0].t); (yyval.cnode)->type = Token::BRACE; }
#line 1424 "./GeneratedFiles/parser.tab.c"
    break;

  case 21: /* brace: lbrace END  */
#line 101 "parser.y"
                                                   { (yyval.cnode) = (yyvsp[-1].cnode); (yyval.cnode)->location[2] = (yyvsp[0].t)->location[0]; (yyval.cnode)->location[3] = (yyvsp[0].t)->location[1]; (yyval.cnode)->type = Token::BRACE;}
#line 1430 "./GeneratedFiles/parser.tab.c"
    break;

  case 22: /* node: node UNIOPERATOR0  */
#line 103 "parser.y"
                                                  { (yyval.node) = new AstNode((yyvsp[0].t)); delete (yyvsp[0].t); (yyval.node)->append((yyvsp[-1].node)); }
#line 1436 "./GeneratedFiles/parser.tab.c"
    break;

  case 23: /* node: UNIOPERATOR1 node  */
#line 104 "parser.y"
                                                          { (yyval.node) = new AstNode((yyvsp[-1].t)); delete (yyvsp[-1].t); (yyval.node)->append((yyvsp[0].node)); }
#line 1442 "./GeneratedFiles/parser.tab.c"
    break;

  case 24: /* node: UNKNOWN  */
#line 105 "parser.y"
                                                { (yyval.node) = new AstNode((yyvsp[0].t)); delete (yyvsp[0].t); }
#line 1448 "./GeneratedFiles/parser.tab.c"
    break;

  case 25: /* node: addsub  */
#line 106 "parser.y"
                                               { (yyval.node) = (yyvsp[0].node); }
#line 1454 "./GeneratedFiles/parser.tab.c"
    break;

  case 26: /* node: muldiv  */
#line 106 "parser.y"
                                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1460 "./GeneratedFiles/parser.tab.c"
    break;

  case 27: /* node: powroot  */
#line 106 "parser.y"
                                                                                            { (yyval.node) = (yyvsp[0].node);}
#line 1466 "./GeneratedFiles/parser.tab.c"
    break;

  case 28: /* node: equal  */
#line 106 "parser.y"
                                                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1472 "./GeneratedFiles/parser.tab.c"
    break;

  case 29: /* node: type  */
#line 107 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node); }
#line 1478 "./GeneratedFiles/parser.tab.c"
    break;

  case 30: /* node: TAG  */
#line 108 "parser.y"
                                                { (yyval.node) = new AstNode((yyvsp[0].t)); delete (yyvsp[0].t); }
#line 1484 "./GeneratedFiles/parser.tab.c"
    break;

  case 31: /* node: CONSTANT  */
#line 109 "parser.y"
                                                 { (yyval.node) = (yyvsp[0].node); }
#line 1490 "./GeneratedFiles/parser.tab.c"
    break;

  case 32: /* node: NAME  */
#line 110 "parser.y"
                                             { (yyval.node) = new AstNode((yyvsp[0].t)); delete (yyvsp[0].t); }
#line 1496 "./GeneratedFiles/parser.tab.c"
    break;

  case 33: /* node: NAME paren  */
#line 111 "parser.y"
                                                   { (yyval.node) = new AstNode((yyvsp[-1].t)); (yyval.node)->type = Token::FUNCTIONCALL; delete (yyvsp[-1].t); (yyval.node)->append((yyvsp[0].cnode)); }
#line 1502 "./GeneratedFiles/parser.tab.c"
    break;

  case 34: /* node: TYPE brace  */
#line 112 "parser.y"
                                                   { (yyval.node) = (yyvsp[0].cnode); (yyval.node)->type=Token::UNKNOWN; }
#line 1508 "./GeneratedFiles/parser.tab.c"
    break;

  case 35: /* node: paren  */
#line 113 "parser.y"
                                              { (yyval.node) = (yyvsp[0].cnode); }
#line 1514 "./GeneratedFiles/parser.tab.c"
    break;

  case 36: /* node: brack  */
#line 113 "parser.y"
                                                                   { (yyval.node) = (yyvsp[0].cnode); }
#line 1520 "./GeneratedFiles/parser.tab.c"
    break;

  case 37: /* node: error  */
#line 115 "parser.y"
                                              { (yyval.node) = new AstNode(); (yyval.node)->type = Token::UNKNOWN; (yyval.node)->location[0] = yylloc.last_line; (yyval.node)->location[1] = yylloc.last_column; (yyval.node)->chars = yytext; }
#line 1526 "./GeneratedFiles/parser.tab.c"
    break;

  case 38: /* ifstmnt: iffull  */
#line 121 "parser.y"
                                       { (yyval.node) = (yyvsp[0].node); }
#line 1532 "./GeneratedFiles/parser.tab.c"
    break;

  case 39: /* ifstmnt: ifempty  */
#line 122 "parser.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 1538 "./GeneratedFiles/parser.tab.c"
    break;

  case 40: /* iffull: ifempty ELSE node  */
#line 124 "parser.y"
                                                  { (yyval.node) = (yyvsp[-2].node); AstNode* node = new AstNode((yyvsp[-1].t)); delete (yyvsp[-1].t); node->append((yyvsp[0].node)); }
#line 1544 "./GeneratedFiles/parser.tab.c"
    break;

  case 41: /* iffull: ifempty ELSE brace  */
#line 125 "parser.y"
                                                           { (yyval.node) = (yyvsp[-2].node); AstNode* node = new AstNode((yyvsp[-1].t)); delete (yyvsp[-1].t); node->append((yyvsp[0].cnode)); }
#line 1550 "./GeneratedFiles/parser.tab.c"
    break;

  case 42: /* ifempty: IF paren node  */
#line 127 "parser.y"
                                              { (yyval.node) = new AstNode((yyvsp[-2].t)); delete (yyvsp[-2].t); (yyval.node)->append((yyvsp[-1].cnode)); (yyval.node)->append((yyvsp[0].node)); }
#line 1556 "./GeneratedFiles/parser.tab.c"
    break;

  case 43: /* ifempty: IF paren brace  */
#line 128 "parser.y"
                                                       { (yyval.node) = new AstNode((yyvsp[-2].t)); delete (yyvsp[-2].t); (yyval.node)->append((yyvsp[-1].cnode)); (yyval.node)->append((yyvsp[0].cnode)); }
#line 1562 "./GeneratedFiles/parser.tab.c"
    break;

  case 44: /* type: TYPE NAME  */
#line 130 "parser.y"
                                          { (yyval.node) = new AstNode((yyvsp[-1].t)); (yyval.node)->append(new AstNode((yyvsp[0].t))); delete (yyvsp[-1].t); delete (yyvsp[0].t); }
#line 1568 "./GeneratedFiles/parser.tab.c"
    break;

  case 45: /* type: TYPE NAME paren brace  */
#line 131 "parser.y"
                                                              { (yyval.node) = new AstNode((yyvsp[-3].t)); (yyval.node)->append(new AstNode((yyvsp[-2].t))); delete (yyvsp[-3].t); delete (yyvsp[-2].t); (yyval.node)->append((yyvsp[-1].cnode)); (yyval.node)->append((yyvsp[0].cnode)); }
#line 1574 "./GeneratedFiles/parser.tab.c"
    break;

  case 46: /* addsub: node OPERATOR0 node  */
#line 136 "parser.y"
                                {
					(yyval.node) = new AstNode(*(yyvsp[-1].t));
					delete (yyvsp[-1].t);
					(yyval.node)->append((yyvsp[-2].node));
					(yyval.node)->append((yyvsp[0].node));
				}
#line 1585 "./GeneratedFiles/parser.tab.c"
    break;

  case 47: /* muldiv: node OPERATOR1 node  */
#line 162 "parser.y"
                                {
					(yyval.node) = new AstNode(*(yyvsp[-1].t));
					delete (yyvsp[-1].t);
					(yyval.node)->append((yyvsp[-2].node));
					(yyval.node)->append((yyvsp[0].node));
				}
#line 1596 "./GeneratedFiles/parser.tab.c"
    break;

  case 48: /* powroot: node OPERATOR2 node  */
#line 188 "parser.y"
                                {
					(yyval.node) = new AstNode(*(yyvsp[-1].t));
					delete (yyvsp[-1].t);
					(yyval.node)->append((yyvsp[-2].node));
					(yyval.node)->append((yyvsp[0].node));
				}
#line 1607 "./GeneratedFiles/parser.tab.c"
    break;

  case 49: /* equal: node OPERATOR3 node  */
#line 214 "parser.y"
                                {
					(yyval.node) = new AstNode(*(yyvsp[-1].t));
					delete (yyvsp[-1].t);
					(yyval.node)->append((yyvsp[-2].node));
					(yyval.node)->append((yyvsp[0].node));
				}
#line 1618 "./GeneratedFiles/parser.tab.c"
    break;


#line 1622 "./GeneratedFiles/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 239 "parser.y"


AstNode* parser_main(int argc, char *argv[], std::vector<MagiLang::errorClass>* errorListIn)
{
	/*
	stmnts:	stmnt { root->append(*$1); printf("????")}
	  |	stmnts stmnt { $1->append(*$2); printf("?!??!??!?!??!?")}
	*/
	root = new AstNode();
	root->type = Token::ROOT;

	errorList = errorListIn;

	std::string fileName = argv[argc - 1];
	std::string fileEnding = ".mgl";

	if (fileName.length() > fileEnding.length())
	{
		if (fileName.compare(fileName.length() - fileEnding.length(), fileEnding.length(), fileEnding) == -1)
		{
			fileName += fileEnding;
		}
	}
	else
	{
		fileName += fileEnding;
	}

	//read = new char[line.substr(i).size() + 1];
	//strcpy(read, line.substr(i).c_str());

	yyin = fopen(fileName.c_str(), "r");

	if (!yyin) 
	{
		printf("\nError: Failed to run file. Make sure that the specified file exists\n\n");
		exit(0);
	}

	yyparse();

	return root;
}

int yyerror (char* s)
{
	printf("ERROR: %s\n", s);
	return 0;
}
