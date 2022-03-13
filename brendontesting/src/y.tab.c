/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

  #include "ast.hpp"

  #include <cassert>
  #include <iostream>
  #include <iomanip>

  extern Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 124 "y.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANT = 258,
    IDENTIFIER = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    TYPE_NAME = 273,
    TYPEDEF = 274,
    EXTERN = 275,
    STATIC = 276,
    AUTO = 277,
    REGISTER = 278,
    CHAR = 279,
    SHORT = 280,
    INT = 281,
    LONG = 282,
    SIGNED = 283,
    UNSIGNED = 284,
    FLOAT = 285,
    DOUBLE = 286,
    CONST = 287,
    VOLATILE = 288,
    VOID = 289,
    STRUCT = 290,
    UNION = 291,
    ENUM = 292,
    ELLIPSIS = 293,
    CASE = 294,
    DEFAULT = 295,
    IF = 296,
    ELSE = 297,
    SWITCH = 298,
    WHILE = 299,
    DO = 300,
    FOR = 301,
    GOTO = 302,
    CONTINUE = 303,
    BREAK = 304,
    RETURN = 305,
    MUL_ASSIGN = 306,
    DIV_ASSIGN = 307,
    MOD_ASSIGN = 308,
    ADD_ASSIGN = 309,
    SUB_ASSIGN = 310,
    LEFT_ASSIGN = 311,
    RIGHT_ASSIGN = 312,
    AND_ASSIGN = 313,
    XOR_ASSIGN = 314,
    OR_ASSIGN = 315
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define IDENTIFIER 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define TYPE_NAME 273
#define TYPEDEF 274
#define EXTERN 275
#define STATIC 276
#define AUTO 277
#define REGISTER 278
#define CHAR 279
#define SHORT 280
#define INT 281
#define LONG 282
#define SIGNED 283
#define UNSIGNED 284
#define FLOAT 285
#define DOUBLE 286
#define CONST 287
#define VOLATILE 288
#define VOID 289
#define STRUCT 290
#define UNION 291
#define ENUM 292
#define ELLIPSIS 293
#define CASE 294
#define DEFAULT 295
#define IF 296
#define ELSE 297
#define SWITCH 298
#define WHILE 299
#define DO 300
#define FOR 301
#define GOTO 302
#define CONTINUE 303
#define BREAK 304
#define RETURN 305
#define MUL_ASSIGN 306
#define DIV_ASSIGN 307
#define MOD_ASSIGN 308
#define ADD_ASSIGN 309
#define SUB_ASSIGN 310
#define LEFT_ASSIGN 311
#define RIGHT_ASSIGN 312
#define AND_ASSIGN 313
#define XOR_ASSIGN 314
#define OR_ASSIGN 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

	Expression *expr;
	int int_num;
	double double_num;
	float float_num;
	std::string *string;

#line 263 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    62,    63,    64,    68,    69,    70,    71,
      72,    73,    74,    75,    79,    80,    84,    85,    86,    87,
      88,    89,    93,    94,    95,    96,    97,    98,   102,   103,
     107,   108,   109,   110,   114,   115,   116,   120,   121,   122,
     126,   127,   128,   129,   130,   134,   135,   136,   140,   141,
     145,   146,   150,   151,   155,   156,   160,   161,   165,   166,
     170,   171,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   189,   190,   194,   198,   199,   203,   204,
     205,   206,   207,   208,   212,   213,   217,   218,   222,   223,
     224,   225,   226,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   245,   246,   247,   251,   252,
     256,   257,   261,   265,   266,   267,   268,   272,   273,   277,
     278,   279,   283,   284,   285,   289,   290,   294,   295,   299,
     300,   304,   305,   309,   310,   311,   312,   313,   314,   315,
     319,   320,   321,   322,   326,   327,   332,   333,   337,   338,
     342,   343,   344,   348,   349,   353,   354,   358,   359,   360,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   376,
     377,   378,   382,   383,   387,   388,   389,   390,   391,   392,
     396,   397,   398,   402,   403,   404,   405,   409,   410,   414,
     415,   419,   420,   424,   425,   426,   430,   431,   432,   433,
     437,   438,   439,   440,   441,   445,   446,   450,   451,   455,
     456,   457,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "IDENTIFIER",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1096,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,     4,    90,    -4,  -213,    17,  1263,  1263,  -213,     9,
    -213,  1263,  1011,   -18,    21,   842,  -213,  -213,   -66,    30,
      10,  -213,  -213,    -4,  -213,    31,  -213,   945,  -213,  -213,
      32,  1187,  -213,   286,  -213,    17,  -213,  1011,  1147,   640,
     -18,  -213,  -213,    30,    61,   -15,  -213,  -213,  -213,  -213,
      90,  -213,   546,  -213,  1011,  1187,  1187,   905,  -213,    72,
    1187,  -213,   106,  -213,   780,   826,   826,   850,   115,    40,
     140,   150,   522,   155,   240,   166,   170,   570,   662,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,   182,   939,
     850,  -213,   120,    80,    57,    34,   210,   188,   180,   181,
     242,    -2,  -213,  -213,    37,  -213,  -213,  -213,   356,   404,
    -213,  -213,  -213,  -213,   179,  -213,  -213,  -213,  -213,    18,
     199,   198,  -213,    63,  -213,  -213,  -213,  -213,   202,    -1,
     850,    30,  -213,  -213,   546,  -213,  -213,  -213,   925,  -213,
    -213,  -213,   850,    38,  -213,   187,  -213,   522,   662,  -213,
     850,  -213,  -213,   190,   522,   850,   850,   850,   227,   592,
     191,  -213,  -213,  -213,    46,    81,    85,   212,   272,  -213,
    -213,   710,   850,   273,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,   850,  -213,   850,   850,   850,
     850,   850,   850,   850,   850,   850,   850,   850,   850,   850,
     850,   850,   850,   850,   850,   850,   850,  -213,  -213,   452,
    -213,  -213,  1045,   732,  -213,    12,  -213,   119,  -213,  1238,
    -213,   274,  -213,  -213,  -213,  -213,  -213,    22,  -213,  -213,
      72,  -213,   850,  -213,   219,   522,  -213,   130,   141,   146,
     221,   592,  -213,  -213,  -213,  1167,   139,  -213,   850,  -213,
    -213,   148,  -213,   157,  -213,  -213,  -213,  -213,  -213,   120,
     120,    80,    80,    57,    57,    57,    57,    34,    34,   210,
     188,   180,   181,   242,   -36,  -213,  -213,  -213,   222,   223,
    -213,   224,   119,  1218,   744,  -213,  -213,  -213,   476,  -213,
    -213,  -213,  -213,  -213,   522,   522,   522,   850,   756,  -213,
    -213,   850,  -213,   850,  -213,  -213,  -213,  -213,   225,  -213,
     229,  -213,  -213,   241,  -213,  -213,   151,   522,   156,  -213,
    -213,  -213,  -213,   522,   204,  -213,   522,  -213,  -213,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   129,   130,    93,   108,
     109,     0,     0,   140,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,   124,     0,
       0,   144,   142,   141,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,     0,   127,     0,   125,   134,   145,   143,
       0,    77,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     3,     2,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,   191,   183,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,     0,   122,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    20,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   202,   203,     0,     0,   155,     0,     0,    12,
      13,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,     0,   182,     0,     0,     0,
       0,     0,   200,   204,     5,     0,   157,   156,     0,    11,
       8,     0,    14,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,    21,   181,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,   -48,  -213,   -91,    20,    15,    19,
      35,    76,    77,    75,    78,   100,  -213,   -55,   -70,  -213,
     -38,   -54,     6,     0,  -213,   230,  -213,   -27,  -213,  -213,
     253,   -67,   -24,  -213,    49,  -213,   239,   186,    47,   -13,
     -29,    -3,  -213,   -57,  -213,    99,  -213,   171,  -125,  -212,
    -151,  -213,   -74,  -213,   152,    58,   213,  -172,  -213,  -213,
    -213,  -213,   305,  -213
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    65,    66,    31,    32,
      33,    34,    43,   298,   141,   142,   143,   187,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   140,   155,   246,   147,    60,    24,   261,    38,    40,
     161,   146,    47,    50,   236,   224,     1,    63,   178,   206,
      42,     1,     1,   302,    76,     1,    48,    49,    16,    17,
     226,    52,   147,   173,    64,    25,   169,   171,   172,   146,
      69,    24,   134,    58,   323,    59,   214,   215,    76,    76,
      76,   151,   159,    76,   302,   231,   166,   134,   139,   184,
     185,   267,   146,   135,    23,   151,   165,   212,   213,   152,
      41,    76,    67,   232,   186,   233,     1,   225,    22,   232,
     135,   233,    22,   243,   155,    23,    23,    39,   308,   318,
      68,   161,    51,   253,     1,   147,   244,    70,    80,    44,
     256,   175,   146,   226,   250,    74,   309,   147,   249,   216,
     217,   128,   226,    71,   146,    75,   276,   277,   278,   227,
     251,   272,    80,    80,    80,   240,   234,    80,   263,   241,
     185,    76,   185,    22,   135,   275,   235,   257,   258,   259,
      23,    76,   150,   264,   186,    80,   265,   226,   233,   210,
     211,    22,   162,    23,   273,   231,   295,   332,    23,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   319,   147,   301,
     303,   313,   304,   266,    56,   146,   167,   294,   207,   188,
     189,   190,   314,   208,   209,   174,   226,   147,   311,    73,
     265,   176,   233,   315,   146,    80,    60,   226,   316,   136,
     320,   177,   226,   344,   321,    80,   179,   226,   346,    40,
     146,   322,   226,   226,   218,   219,   157,   281,   282,   235,
     279,   280,   139,   283,   284,   285,   286,   165,   155,   139,
     333,   334,   335,   191,   180,   192,   328,   193,   181,   147,
     330,   339,   182,   287,   288,   220,   146,   221,   223,   222,
      72,   238,   266,   345,   239,   139,   242,   252,   340,   347,
     255,   260,   349,   262,   268,   146,   269,   274,   307,   336,
     338,   312,   317,   343,   324,   325,   348,   341,   326,    81,
      82,    83,    84,   342,    85,    86,   289,   291,   290,   310,
     153,   292,   149,   139,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   293,    87,    88,    89,   158,    90,
      91,    92,    93,    94,    95,    96,    97,   245,   306,   254,
      62,   229,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    81,
      82,    83,    84,     0,    85,    86,     0,     0,   105,    53,
     106,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    87,    88,    89,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,    53,
     228,     0,     0,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,    81,
     144,    83,    84,     0,    85,    86,   105,    53,   230,     0,
       0,    87,    88,    89,     0,    90,    91,    92,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    81,    82,    83,    84,     0,
      85,    86,     0,     0,   105,    53,   296,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    81,
     144,    83,    84,     0,    85,    86,     0,     0,     0,   154,
     331,    87,    88,    89,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    81,   144,    83,    84,     0,    85,    86,
       0,     0,     0,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    81,   144,    83,    84,     0,
      85,    86,     0,     0,   105,    53,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
       0,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,    81,   144,    83,    84,     0,    85,    86,
       0,     0,   183,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    81,   144,    83,    84,     0,
      85,    86,     0,     0,   105,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    98,     0,     0,   145,     0,     0,    99,   100,   101,
     102,   103,   104,    81,   144,    83,    84,     0,    85,    86,
       0,     0,     0,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    81,   144,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,    81,   144,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,    81,
     144,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    98,   270,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,    81,   144,    83,    84,     0,    85,    86,
       0,     0,     0,    98,     0,     0,   300,     0,     0,    99,
     100,   101,   102,   103,   104,    98,     0,     0,   329,     0,
       0,    99,   100,   101,   102,   103,   104,    98,   337,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    81,
     144,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,   168,    61,     0,     0,     0,     1,    99,   100,   101,
     102,   103,   104,    81,   144,    83,    84,     0,    85,    86,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     2,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     2,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,   160,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,    72,     0,    53,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,   232,   297,   233,     0,
       0,     0,     0,    23,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,    23,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     0,     0,     0,   138,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,   265,   297,
     233,     0,     0,     0,     0,    23,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   305,     0,     0,     0,
     327,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
       0,    58,    72,   154,    59,    34,     0,   179,     4,    22,
      77,    59,    25,     4,   139,    17,     4,    83,    92,   110,
      23,     4,     4,   235,    51,     4,    26,    27,    32,    33,
      66,    31,    87,    87,     4,    35,    84,    85,    86,    87,
      43,    35,    55,    61,    80,    63,    12,    13,    75,    76,
      77,    66,    76,    80,   266,   129,    80,    70,    58,    97,
      98,   186,   110,    57,    68,    66,    79,    10,    11,    84,
      23,    98,    62,    61,    98,    63,     4,    79,    61,    61,
      74,    63,    61,    84,   154,    68,    68,    83,    66,   261,
      43,   158,    83,   167,     4,   150,   150,    66,    51,    82,
     174,    61,   150,    66,    66,    47,    84,   162,   162,    75,
      76,    53,    66,    82,   162,    83,   207,   208,   209,    82,
      82,   191,    75,    76,    77,    62,   139,    80,    82,    66,
     168,   158,   170,    61,   128,   205,   139,   175,   176,   177,
      68,   168,    81,    62,   168,    98,    61,    66,    63,    69,
      70,    61,    80,    68,   192,   229,   226,   308,    68,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   268,   233,   233,
      61,   255,    63,   186,    32,   233,    80,   225,    68,     7,
       8,     9,    62,    73,    74,    80,    66,   252,   252,    47,
      61,    61,    63,    62,   252,   158,   235,    66,    62,    57,
      62,    61,    66,    62,    66,   168,    61,    66,    62,   232,
     268,    64,    66,    66,    14,    15,    74,   212,   213,   232,
     210,   211,   232,   214,   215,   216,   217,   250,   308,   239,
     314,   315,   316,    61,     4,    63,   303,    65,    82,   304,
     304,   321,    82,   218,   219,    67,   304,    77,    16,    78,
      81,    62,   265,   337,    66,   265,    64,    80,   323,   343,
      80,    44,   346,    82,    62,   323,     4,     4,     4,   317,
     318,    62,    61,    42,    62,    62,    82,    62,    64,     3,
       4,     5,     6,    64,     8,     9,   220,   222,   221,   250,
      70,   223,    63,   303,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   224,    39,    40,    41,    75,    43,
      44,    45,    46,    47,    48,    49,    50,   151,   239,   168,
      35,   128,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    82,    83,    84,    -1,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    83,    84,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    83,
      84,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    83,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    82,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    61,    -1,    -1,    64,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,    61,    -1,    -1,    64,    -1,
      -1,    67,    68,    69,    70,    71,    72,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,     0,    -1,    -1,    -1,     4,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    18,    -1,    -1,    -1,    62,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    61,    68,   107,   108,   111,   112,   113,   114,
     120,   123,   124,   125,   126,   146,   147,   148,     4,    83,
     124,   123,   126,   127,    82,   109,   110,   124,   108,   108,
       4,    83,   108,    83,   107,   108,   139,   140,    61,    63,
     125,     0,   147,    83,     4,   121,   122,    62,   123,   126,
      66,    82,    81,   139,   140,    83,   112,   115,   116,   117,
     123,     3,     4,     5,     6,     8,     9,    39,    40,    41,
      43,    44,    45,    46,    47,    48,    49,    50,    61,    67,
      68,    69,    70,    71,    72,    82,    84,    86,    87,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   105,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   124,   107,   139,     4,    62,   108,
     128,   129,   130,   131,     4,    64,    89,   102,   106,   121,
      81,    66,    84,   110,    83,   103,   135,   139,   115,   117,
      84,   116,    80,   118,   119,   124,   117,    80,    61,    89,
      61,    89,    89,   106,    80,    61,    61,    61,   137,    61,
       4,    82,    82,    82,   105,   105,   117,   132,     7,     8,
       9,    61,    63,    65,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    81,   104,    91,    68,    73,    74,
      69,    70,    10,    11,    12,    13,    75,    76,    14,    15,
      67,    77,    78,    16,    17,    79,    66,    82,    84,   141,
      84,   137,    61,    63,   124,   126,   133,   134,    62,    66,
      62,    66,    64,    84,   106,   122,   135,   136,    84,   106,
      66,    82,    80,   137,   132,    80,   137,   105,   105,   105,
      44,   142,    82,    82,    62,    61,   126,   133,    62,     4,
      62,    88,   103,   105,     4,   103,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    99,   100,   105,   103,    84,    62,   128,   133,
      64,   106,   134,    61,    63,    38,   130,     4,    66,    84,
     119,   106,    62,   137,    62,    62,    62,    61,   142,    91,
      62,    66,    64,    80,    62,    62,    64,    62,   128,    64,
     106,    84,   135,   137,   137,   137,   105,    62,   105,   103,
     102,    62,    64,    42,    62,   137,    62,   137,    82,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 61 "parser.y"
                                                { std::cout<< "primary_expression -> IDENTIFIER " << std::endl; (yyval.expr) = new Variable(*(yyvsp[0].string)); }
#line 1908 "y.tab.c"
    break;

  case 3:
#line 62 "parser.y"
                                                        { std::cout<< "primary_expression -> CONSTANT " << std::endl; (yyval.expr) = new Integer((yyvsp[0].int_num)); }
#line 1914 "y.tab.c"
    break;

  case 4:
#line 63 "parser.y"
                                                { std::cout<< "primary_expression -> STRING_LITERAL" <<std::endl; }
#line 1920 "y.tab.c"
    break;

  case 5:
#line 64 "parser.y"
                                        { std::cout<< "primary_expression -> ( expression )" <<std::endl; }
#line 1926 "y.tab.c"
    break;

  case 6:
#line 68 "parser.y"
                                                                                                        { std::cout<< "postfix_expression -> primary_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr);}
#line 1932 "y.tab.c"
    break;

  case 7:
#line 69 "parser.y"
                                                                                        { std::cout<< "postfix_expression -> postfix_expression '[' expression ']'	" << std::endl; }
#line 1938 "y.tab.c"
    break;

  case 8:
#line 70 "parser.y"
                                                                                                { std::cout<< "postfix_expression -> postfix_expression '(' ')'" << std::endl; }
#line 1944 "y.tab.c"
    break;

  case 9:
#line 71 "parser.y"
                                                                        { std::cout<< "postfix_expression -> postfix_expression '(' argument_expression_list ')'" << std::endl; }
#line 1950 "y.tab.c"
    break;

  case 10:
#line 72 "parser.y"
                                                                                                { std::cout<< "postfix_expression -> postfix_expression '.' IDENTIFIER" << std::endl; }
#line 1956 "y.tab.c"
    break;

  case 11:
#line 73 "parser.y"
                                                                                        { std::cout<< "postfix_expression -> postfix_expression PTR_OP IDENTIFIER" << std::endl; }
#line 1962 "y.tab.c"
    break;

  case 12:
#line 74 "parser.y"
                                                                                                        { std::cout<< "postfix_expression -> postfix_expression INC_OP" << std::endl; }
#line 1968 "y.tab.c"
    break;

  case 13:
#line 75 "parser.y"
                                                                                                        { std::cout<< "postfix_expression -> postfix_expression DEC_OP" << std::endl; }
#line 1974 "y.tab.c"
    break;

  case 14:
#line 79 "parser.y"
                                                                                                        { std::cout<< "argument_expression_list -> assignment_expression" << std::endl; }
#line 1980 "y.tab.c"
    break;

  case 15:
#line 80 "parser.y"
                                                                        { std::cout<< "argument_expression_list -> argument_expression_list ',' assignment_expression" << std::endl; }
#line 1986 "y.tab.c"
    break;

  case 16:
#line 84 "parser.y"
                                                        { std::cout<< "unary_expression -> postfix_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1992 "y.tab.c"
    break;

  case 17:
#line 85 "parser.y"
                                                        { std::cout<< "unary_expression -> INC_OP unary_expression" << std::endl; }
#line 1998 "y.tab.c"
    break;

  case 18:
#line 86 "parser.y"
                                                        { std::cout<< "unary_expression -> DEC_OP unary_expression" << std::endl; }
#line 2004 "y.tab.c"
    break;

  case 19:
#line 87 "parser.y"
                                                { std::cout<< "unary_expression -> unary_operator cast_expression" << std::endl; }
#line 2010 "y.tab.c"
    break;

  case 20:
#line 88 "parser.y"
                                                        { std::cout<< "unary_expression -> SIZEOF unary_expression" << std::endl; }
#line 2016 "y.tab.c"
    break;

  case 21:
#line 89 "parser.y"
                                                        { std::cout<< "unary_expression -> SIZEOF '(' type_name ')'" << std::endl; }
#line 2022 "y.tab.c"
    break;

  case 22:
#line 93 "parser.y"
                                { std::cout<< "unary_operator -> &" << std::endl; }
#line 2028 "y.tab.c"
    break;

  case 23:
#line 94 "parser.y"
                                { std::cout<< "unary_operator -> *" << std::endl; }
#line 2034 "y.tab.c"
    break;

  case 24:
#line 95 "parser.y"
                                { std::cout<< "unary_operator -> +" << std::endl; }
#line 2040 "y.tab.c"
    break;

  case 25:
#line 96 "parser.y"
                                { std::cout<< "unary_operator -> -" << std::endl; }
#line 2046 "y.tab.c"
    break;

  case 26:
#line 97 "parser.y"
                                { std::cout<< "unary_operator -> ~" << std::endl; }
#line 2052 "y.tab.c"
    break;

  case 27:
#line 98 "parser.y"
                                { std::cout<< "unary_operator -> !" << std::endl; }
#line 2058 "y.tab.c"
    break;

  case 28:
#line 102 "parser.y"
                                                                        { std::cout<< "cast_expression -> unary_expression" << std::endl; (yyval.expr)=(yyvsp[0].expr); }
#line 2064 "y.tab.c"
    break;

  case 29:
#line 103 "parser.y"
                                                        { std::cout<< "cast_expression -> '(' type_name ')' cast_expression" << std::endl; }
#line 2070 "y.tab.c"
    break;

  case 30:
#line 107 "parser.y"
                                                                                                        { std::cout<<"multiplicative_expression -> cast_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2076 "y.tab.c"
    break;

  case 31:
#line 108 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '*' cast_expression"<<std::endl; (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2082 "y.tab.c"
    break;

  case 32:
#line 109 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '/' cast_expression"<<std::endl; (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2088 "y.tab.c"
    break;

  case 33:
#line 110 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '%' cast_expression"<<std::endl; (yyval.expr) = new ModOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2094 "y.tab.c"
    break;

  case 34:
#line 114 "parser.y"
                                                                                                { std::cout<<"additive_expression -> multiplicative_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2100 "y.tab.c"
    break;

  case 35:
#line 115 "parser.y"
                                                                { std::cout<<"additive_expression -> additive_expression '+' multiplicative_expression"<<std::endl; (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2106 "y.tab.c"
    break;

  case 36:
#line 116 "parser.y"
                                                                { std::cout<<"additive_expression -> additive_expression '-' multiplicative_expression"<<std::endl; (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2112 "y.tab.c"
    break;

  case 37:
#line 120 "parser.y"
                                                                                                { std::cout<<"shift_expression -> additive_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2118 "y.tab.c"
    break;

  case 38:
#line 121 "parser.y"
                                                                        { std::cout<<"shift_expression -> shift_expression LEFT_OP additive_expression"<<std::endl; (yyval.expr) = new AShiftLeftOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2124 "y.tab.c"
    break;

  case 39:
#line 122 "parser.y"
                                                                        { std::cout<<"shift_expression -> shift_expression RIGHT_OP additive_expression"<<std::endl; (yyval.expr) = new AShiftRightOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2130 "y.tab.c"
    break;

  case 40:
#line 126 "parser.y"
                                                                                                        { std::cout<<"relational_expression -> shift_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2136 "y.tab.c"
    break;

  case 41:
#line 127 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression '<' shift_expression"<<std::endl; (yyval.expr) = new LTOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2142 "y.tab.c"
    break;

  case 42:
#line 128 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression '>' shift_expression"<<std::endl; (yyval.expr) = new GTOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2148 "y.tab.c"
    break;

  case 43:
#line 129 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression LE_OP shift_expression"<<std::endl; (yyval.expr) = new LEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2154 "y.tab.c"
    break;

  case 44:
#line 130 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression GE_OP shift_expression"<<std::endl; (yyval.expr) = new GEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2160 "y.tab.c"
    break;

  case 45:
#line 134 "parser.y"
                                                                                                { std::cout<<"equality_expression -> relational_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2166 "y.tab.c"
    break;

  case 46:
#line 135 "parser.y"
                                                                        { std::cout<<"equality_expression -> equality_expression EQ_OP relational_expression"<<std::endl; (yyval.expr) = new EqOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2172 "y.tab.c"
    break;

  case 47:
#line 136 "parser.y"
                                                                        { std::cout<<"equality_expression -> equality_expression NE_OP relational_expression"<<std::endl; (yyval.expr) = new NeqOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2178 "y.tab.c"
    break;

  case 48:
#line 140 "parser.y"
                                                                                                { std::cout<<"and_expression -> equality_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2184 "y.tab.c"
    break;

  case 49:
#line 141 "parser.y"
                                                                                { std::cout<<"and_expression -> and_expression '&' equality_expression"<<std::endl; (yyval.expr) = new bAndOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2190 "y.tab.c"
    break;

  case 50:
#line 145 "parser.y"
                                                                                                        { std::cout<<"exclusive_or_expression -> and_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2196 "y.tab.c"
    break;

  case 51:
#line 146 "parser.y"
                                                                        { std::cout<<"exclusive_or_expression -> exclusive_or_expression '^' and_expression"<<std::endl; (yyval.expr) = new xorOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2202 "y.tab.c"
    break;

  case 52:
#line 150 "parser.y"
                                                                                                { std::cout<<"inclusive_or_expression -> exclusive_or_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2208 "y.tab.c"
    break;

  case 53:
#line 151 "parser.y"
                                                                { std::cout<<"inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression"<<std::endl; (yyval.expr) = new bOrOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2214 "y.tab.c"
    break;

  case 54:
#line 155 "parser.y"
                                                                                                { std::cout<<"logical_and_expression -> inclusive_or_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2220 "y.tab.c"
    break;

  case 55:
#line 156 "parser.y"
                                                                { std::cout<<"logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"<<std::endl; (yyval.expr) = new AndOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2226 "y.tab.c"
    break;

  case 56:
#line 160 "parser.y"
                                                                                                { std::cout<<"logical_or_expression -> logical_and_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2232 "y.tab.c"
    break;

  case 57:
#line 161 "parser.y"
                                                                { std::cout<<"logical_or_expression -> logical_or_expression OR_OP logical_and_expression"<<std::endl; (yyval.expr) = new OrOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2238 "y.tab.c"
    break;

  case 58:
#line 165 "parser.y"
                                                                                                                        { std::cout<<"conditional_expression -> logical_or_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2244 "y.tab.c"
    break;

  case 59:
#line 166 "parser.y"
                                                                                { std::cout<<"conditional_expression -> logical_or_expression '?' expression ':' conditional_expression"<<std::endl; }
#line 2250 "y.tab.c"
    break;

  case 60:
#line 170 "parser.y"
                                                                                                                { std::cout << "assignment_expression -> conditional_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2256 "y.tab.c"
    break;

  case 61:
#line 171 "parser.y"
                                                                        { std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl; }
#line 2262 "y.tab.c"
    break;

  case 62:
#line 175 "parser.y"
                                                { std::cout << "assignment_operator: =" << std::endl; }
#line 2268 "y.tab.c"
    break;

  case 63:
#line 176 "parser.y"
                                        { std::cout << "assignment_operator: *=" << std::endl; }
#line 2274 "y.tab.c"
    break;

  case 64:
#line 177 "parser.y"
                                        { std::cout << "assignment_operator: /=" << std::endl; }
#line 2280 "y.tab.c"
    break;

  case 65:
#line 178 "parser.y"
                                        { std::cout << "assignment_operator: %=" << std::endl; }
#line 2286 "y.tab.c"
    break;

  case 66:
#line 179 "parser.y"
                                        { std::cout << "assignment_operator: +=" << std::endl; }
#line 2292 "y.tab.c"
    break;

  case 67:
#line 180 "parser.y"
                                        { std::cout << "assignment_operator: -=" << std::endl; }
#line 2298 "y.tab.c"
    break;

  case 68:
#line 181 "parser.y"
                                        { std::cout << "assignment_operator: <<=" << std::endl; }
#line 2304 "y.tab.c"
    break;

  case 69:
#line 182 "parser.y"
                                        { std::cout << "assignment_operator: >>=" << std::endl; }
#line 2310 "y.tab.c"
    break;

  case 70:
#line 183 "parser.y"
                                        { std::cout << "assignment_operator: &=" << std::endl; }
#line 2316 "y.tab.c"
    break;

  case 71:
#line 184 "parser.y"
                                        { std::cout << "assignment_operator: ^=" << std::endl; }
#line 2322 "y.tab.c"
    break;

  case 72:
#line 185 "parser.y"
                                                { std::cout << "assignment_operator: |=" << std::endl; }
#line 2328 "y.tab.c"
    break;

  case 73:
#line 189 "parser.y"
                                                                        { std::cout<<"expression -> assignment_expression" << std::endl; }
#line 2334 "y.tab.c"
    break;

  case 74:
#line 190 "parser.y"
                                                        { std::cout<<"expression -> expression ',' assignment_expression" << std::endl; }
#line 2340 "y.tab.c"
    break;

  case 75:
#line 194 "parser.y"
                                                                        { std::cout<<"constant_expression -> conditional_expression" << std::endl; }
#line 2346 "y.tab.c"
    break;

  case 76:
#line 198 "parser.y"
                                                                                        { std::cout<<"declaration -> declaration_specifiers ;" << std::endl; }
#line 2352 "y.tab.c"
    break;

  case 77:
#line 199 "parser.y"
                                                                        { std::cout<<"declaration -> declaration_specifiers init_declarator_list ;" << std::endl; }
#line 2358 "y.tab.c"
    break;

  case 78:
#line 203 "parser.y"
                                                                                                { std::cout<<"declaration_specifiers -> storage_class_specifier"<<std::endl; }
#line 2364 "y.tab.c"
    break;

  case 79:
#line 204 "parser.y"
                                                                        { std::cout<<"declaration_specifiers -> storage_class_specifier declaration_specifiers"<<std::endl; }
#line 2370 "y.tab.c"
    break;

  case 80:
#line 205 "parser.y"
                                                                                                        { std::cout<<"declaration_specifiers -> type_specifier"<<std::endl; }
#line 2376 "y.tab.c"
    break;

  case 81:
#line 206 "parser.y"
                                                                                { std::cout<<"declaration_specifiers -> type_specifier declaration_specifiers"<<std::endl; }
#line 2382 "y.tab.c"
    break;

  case 82:
#line 207 "parser.y"
                                                                                                        { std::cout<<"declaration_specifiers -> type_qualifier"<<std::endl; }
#line 2388 "y.tab.c"
    break;

  case 83:
#line 208 "parser.y"
                                                                                { std::cout<<"declaration_specifiers -> type_qualifier declaration_specifiers"<<std::endl; }
#line 2394 "y.tab.c"
    break;

  case 84:
#line 212 "parser.y"
                                                                                        { std::cout<<"init_declarator_list -> init_declarator"<<std::endl; }
#line 2400 "y.tab.c"
    break;

  case 85:
#line 213 "parser.y"
                                                                { std::cout<<"init_declarator_list -> init_declarator_list ',' init_declarator"<<std::endl; }
#line 2406 "y.tab.c"
    break;

  case 86:
#line 217 "parser.y"
                                                                                        { std::cout<<"init_declarator -> declarator"<<std::endl; }
#line 2412 "y.tab.c"
    break;

  case 87:
#line 218 "parser.y"
                                                                        { std::cout<<"init_declarator -> declarator '=' initializer"<<std::endl; (yyval.expr) = new AssignOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2418 "y.tab.c"
    break;

  case 88:
#line 222 "parser.y"
                                                { std::cout<<"storage_class_specifier -> TYPEDEF"<<std::endl; }
#line 2424 "y.tab.c"
    break;

  case 89:
#line 223 "parser.y"
                                                { std::cout<<"storage_class_specifier -> EXTERN"<<std::endl; }
#line 2430 "y.tab.c"
    break;

  case 90:
#line 224 "parser.y"
                                                { std::cout<<"storage_class_specifier -> STATIC"<<std::endl; }
#line 2436 "y.tab.c"
    break;

  case 91:
#line 225 "parser.y"
                                                { std::cout<<"storage_class_specifier -> AUTO"<<std::endl; }
#line 2442 "y.tab.c"
    break;

  case 92:
#line 226 "parser.y"
                                                { std::cout<<"storage_class_specifier -> REGISTER"<<std::endl; }
#line 2448 "y.tab.c"
    break;

  case 93:
#line 230 "parser.y"
                                                                        { std::cout<<"type_specifier -> VOID"<<std::endl; }
#line 2454 "y.tab.c"
    break;

  case 94:
#line 231 "parser.y"
                                                                        { std::cout<<"type_specifier -> CHAR"<<std::endl; }
#line 2460 "y.tab.c"
    break;

  case 95:
#line 232 "parser.y"
                                                                        { std::cout<<"type_specifier -> SHORT"<<std::endl; }
#line 2466 "y.tab.c"
    break;

  case 96:
#line 233 "parser.y"
                                                                        { std::cout<<"type_specifier -> INT"<<std::endl; }
#line 2472 "y.tab.c"
    break;

  case 97:
#line 234 "parser.y"
                                                                        { std::cout<<"type_specifier -> LONG"<<std::endl; }
#line 2478 "y.tab.c"
    break;

  case 98:
#line 235 "parser.y"
                                                                        { std::cout<<"type_specifier -> FLOAT"<<std::endl; }
#line 2484 "y.tab.c"
    break;

  case 99:
#line 236 "parser.y"
                                                                        { std::cout<<"type_specifier -> DOUBLE"<<std::endl; }
#line 2490 "y.tab.c"
    break;

  case 100:
#line 237 "parser.y"
                                                                        { std::cout<<"type_specifier -> SIGNED"<<std::endl; }
#line 2496 "y.tab.c"
    break;

  case 101:
#line 238 "parser.y"
                                                                        { std::cout<<"type_specifier -> UNSIGNED"<<std::endl; }
#line 2502 "y.tab.c"
    break;

  case 102:
#line 239 "parser.y"
                                                        { std::cout<<"type_specifier -> struct_or_union_specifier"<<std::endl; }
#line 2508 "y.tab.c"
    break;

  case 103:
#line 240 "parser.y"
                                                                { std::cout<<"type_specifier -> enum_specifier"<<std::endl; }
#line 2514 "y.tab.c"
    break;

  case 104:
#line 241 "parser.y"
                                                                        { std::cout<<"type_specifier -> TYPE_NAME"<<std::endl; }
#line 2520 "y.tab.c"
    break;

  case 105:
#line 245 "parser.y"
                                                                                { std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER '{' struct_declaration_list '}'"<<std::endl; }
#line 2526 "y.tab.c"
    break;

  case 106:
#line 246 "parser.y"
                                                                                                { std::cout<<"struct_or_union_specifier -> struct_or_union '{' struct_declaration_list '}'"<<std::endl; }
#line 2532 "y.tab.c"
    break;

  case 107:
#line 247 "parser.y"
                                                                                                                { std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER"<<std::endl; }
#line 2538 "y.tab.c"
    break;

  case 108:
#line 251 "parser.y"
                                        { std::cout<<"struct_or_union -> STRUCT"<<std::endl; }
#line 2544 "y.tab.c"
    break;

  case 109:
#line 252 "parser.y"
                                        { std::cout<<"struct_or_union -> UNION"<<std::endl; }
#line 2550 "y.tab.c"
    break;

  case 110:
#line 256 "parser.y"
                                                                                        { std::cout<<"struct_declaration_list -> struct_declaration"<<std::endl; }
#line 2556 "y.tab.c"
    break;

  case 111:
#line 257 "parser.y"
                                                                { std::cout<<"struct_declaration_list -> struct_declaration_list struct_declaration"<<std::endl; }
#line 2562 "y.tab.c"
    break;

  case 112:
#line 261 "parser.y"
                                                                { std::cout<<"struct_declaration -> specifier_qualifier_list struct_declarator_list"<<std::endl; }
#line 2568 "y.tab.c"
    break;

  case 113:
#line 265 "parser.y"
                                                                { std::cout<<"specifier_qualifier_list -> type_specifier specifier_qualifier_list"<<std::endl; }
#line 2574 "y.tab.c"
    break;

  case 114:
#line 266 "parser.y"
                                                                                        { std::cout<<"specifier_qualifier_list -> type_specifier"<<std::endl; }
#line 2580 "y.tab.c"
    break;

  case 115:
#line 267 "parser.y"
                                                                { std::cout<<"specifier_qualifier_list -> type_qualifier specifier_qualifier_list"<<std::endl; }
#line 2586 "y.tab.c"
    break;

  case 116:
#line 268 "parser.y"
                                                                                        { std::cout<<"specifier_qualifier_list -> type_qualifier"<<std::endl; }
#line 2592 "y.tab.c"
    break;

  case 117:
#line 272 "parser.y"
                                                                                                { std::cout<<"struct_declarator_list -> struct_declarator"<<std::endl; }
#line 2598 "y.tab.c"
    break;

  case 118:
#line 273 "parser.y"
                                                                { std::cout<<"struct_declarator_list -> struct_declarator_list ',' struct_declarator"<<std::endl; }
#line 2604 "y.tab.c"
    break;

  case 119:
#line 277 "parser.y"
                                                                                { std::cout<<"struct_declarator -> declarator"<<std::endl; }
#line 2610 "y.tab.c"
    break;

  case 120:
#line 278 "parser.y"
                                                                        { std::cout<<"struct_declarator -> ':' constant_expression" <<std::endl; }
#line 2616 "y.tab.c"
    break;

  case 121:
#line 279 "parser.y"
                                                        { std::cout<<"struct_declarator -> declarator ':' constant_expression"<<std::endl; }
#line 2622 "y.tab.c"
    break;

  case 122:
#line 283 "parser.y"
                                                                { std::cout << "enum_specifier -> ENUM '{' enumerator_list '}'" << std::endl; }
#line 2628 "y.tab.c"
    break;

  case 123:
#line 284 "parser.y"
                                                        { std::cout << "enum_specifier -> ENUM IDENTIFIER '{' enumerator_list '}'" << std::endl; }
#line 2634 "y.tab.c"
    break;

  case 124:
#line 285 "parser.y"
                                                                                { std::cout << "enum_specifier -> ENUM IDENTIFIER" << std::endl; }
#line 2640 "y.tab.c"
    break;

  case 125:
#line 289 "parser.y"
                                                                                { std::cout << "enumerator_list -> enumerator" << std::endl; }
#line 2646 "y.tab.c"
    break;

  case 126:
#line 290 "parser.y"
                                                                { std::cout << "enumerator_list -> enumerator_list ',' enumerator" << std::endl; }
#line 2652 "y.tab.c"
    break;

  case 127:
#line 294 "parser.y"
                                                                                { std::cout << "enumerator -> IDENTIFIER" << std::endl; }
#line 2658 "y.tab.c"
    break;

  case 128:
#line 295 "parser.y"
                                                        { std::cout << "enumerator -> IDENTIFIER '=' constant_expression" << std::endl; }
#line 2664 "y.tab.c"
    break;

  case 129:
#line 299 "parser.y"
                                { std::cout << "type_qualifier -> CONST" << std::endl; }
#line 2670 "y.tab.c"
    break;

  case 130:
#line 300 "parser.y"
                                { std::cout << "type_qualifier -> VOLATILE" << std::endl; }
#line 2676 "y.tab.c"
    break;

  case 131:
#line 304 "parser.y"
                                                        { std::cout << "declarator -> pointer direct_declarator" << std::endl; (yyval.expr) = new Declarator((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2682 "y.tab.c"
    break;

  case 132:
#line 305 "parser.y"
                                                                { std::cout << "declarator -> direct_declarator" << std::endl; (yyval.expr) = new Declarator(NULL, (yyvsp[0].expr)); }
#line 2688 "y.tab.c"
    break;

  case 133:
#line 309 "parser.y"
                                                                                                                { std::cout << "direct_declarator -> IDENTIFIER" << std::endl; (yyval.expr) = new Variable(*(yyvsp[0].string)); }
#line 2694 "y.tab.c"
    break;

  case 134:
#line 310 "parser.y"
                                                                                                        { std::cout << "direct_declarator -> '(' declarator ')'" << std::endl; (yyval.expr) = (yyvsp[-1].expr); }
#line 2700 "y.tab.c"
    break;

  case 135:
#line 311 "parser.y"
                                                                                { std::cout << "direct_declarator -> direct_declarator '[' constant_expression ']'" << std::endl; }
#line 2706 "y.tab.c"
    break;

  case 136:
#line 312 "parser.y"
                                                                                                        { std::cout << "direct_declarator -> direct_declarator '[' ']'" << std::endl; }
#line 2712 "y.tab.c"
    break;

  case 137:
#line 313 "parser.y"
                                                                                { std::cout << "direct_declarator -> direct_declarator '(' parameter_type_list ')'" << std::endl; }
#line 2718 "y.tab.c"
    break;

  case 138:
#line 314 "parser.y"
                                                                                        { std::cout << "direct_declarator -> direct_declarator '(' identifier_list ')'" << std::endl; }
#line 2724 "y.tab.c"
    break;

  case 139:
#line 315 "parser.y"
                                                                                                        { std::cout << "direct_declarator -> direct_declarator '(' ')'" << std::endl; }
#line 2730 "y.tab.c"
    break;

  case 140:
#line 319 "parser.y"
                                                                                { std::cout << "pointer -> '*'" << std::endl; }
#line 2736 "y.tab.c"
    break;

  case 141:
#line 320 "parser.y"
                                                                { std::cout << "pointer -> '*' type_qualifier_list" << std::endl; }
#line 2742 "y.tab.c"
    break;

  case 142:
#line 321 "parser.y"
                                                                        { std::cout << "pointer -> '*' pointer" << std::endl; }
#line 2748 "y.tab.c"
    break;

  case 143:
#line 322 "parser.y"
                                                        { std::cout << "pointer -> '*' type_qualifier_list pointer" << std::endl; }
#line 2754 "y.tab.c"
    break;

  case 155:
#line 353 "parser.y"
                                                                                                        { std::cout << "type_name -> specifier_qualifier_list" << std::endl; }
#line 2760 "y.tab.c"
    break;

  case 156:
#line 354 "parser.y"
                                                                                { std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl; }
#line 2766 "y.tab.c"
    break;

  case 169:
#line 376 "parser.y"
                                                                { std::cout << "initializer -> assignment_expression" << std::endl; }
#line 2772 "y.tab.c"
    break;

  case 170:
#line 377 "parser.y"
                                                                { std::cout << "initializer -> '{' initializer_list '}'" << std::endl; }
#line 2778 "y.tab.c"
    break;

  case 171:
#line 378 "parser.y"
                                                        { std::cout << "initializer -> '{' initializer_list ',' '}'" << std::endl; }
#line 2784 "y.tab.c"
    break;

  case 172:
#line 382 "parser.y"
                                                                        { std::cout << "initializer_list -> initializer" << std::endl; }
#line 2790 "y.tab.c"
    break;

  case 173:
#line 383 "parser.y"
                                                        { std::cout << "initializer_list -> initializer_list ',' initializer" << std::endl; }
#line 2796 "y.tab.c"
    break;

  case 174:
#line 387 "parser.y"
                                                                        { std::cout << "statement -> labeled_statement" << std::endl; }
#line 2802 "y.tab.c"
    break;

  case 175:
#line 388 "parser.y"
                                                                { std::cout << "statement -> compound_statement" << std::endl; }
#line 2808 "y.tab.c"
    break;

  case 176:
#line 389 "parser.y"
                                                                { std::cout << "statement -> expression_statement" << std::endl; }
#line 2814 "y.tab.c"
    break;

  case 177:
#line 390 "parser.y"
                                                                { std::cout << "statement -> selection_statement" << std::endl; }
#line 2820 "y.tab.c"
    break;

  case 178:
#line 391 "parser.y"
                                                                { std::cout << "statement -> iteration_statement" << std::endl; }
#line 2826 "y.tab.c"
    break;

  case 179:
#line 392 "parser.y"
                                                                        { std::cout << "statement -> jump_statement" << std::endl; }
#line 2832 "y.tab.c"
    break;

  case 191:
#line 419 "parser.y"
                                                                { std::cout << "expression_statement -> ';'" << std::endl; }
#line 2838 "y.tab.c"
    break;

  case 192:
#line 420 "parser.y"
                                                        { std::cout << "expression_statement -> expression ';'" << std::endl; }
#line 2844 "y.tab.c"
    break;

  case 204:
#line 441 "parser.y"
                                                { std::cout<<"jump_statement -> RETURN expression ;"<<std::endl; }
#line 2850 "y.tab.c"
    break;

  case 205:
#line 445 "parser.y"
                                                                        { std::cout<<"translation_unit -> external_declaration"<<std::endl; /* Put the function in here?*/}
#line 2856 "y.tab.c"
    break;

  case 206:
#line 446 "parser.y"
                                                        { std::cout<<"translation_unit -> translation_unit external_declaration"<<std::endl; /* Put the function in here?*/}
#line 2862 "y.tab.c"
    break;

  case 207:
#line 450 "parser.y"
                                                { std::cout<<"external_declaration -> function_definition"<<std::endl; }
#line 2868 "y.tab.c"
    break;

  case 208:
#line 451 "parser.y"
                                                        { std::cout<<"external_declaration -> declaration"<<std::endl; }
#line 2874 "y.tab.c"
    break;

  case 209:
#line 455 "parser.y"
                                                                                                { std::cout<<"function_definition -> declaration_specifiers declarator declaration_list compound_statement"<<std::endl; }
#line 2880 "y.tab.c"
    break;

  case 210:
#line 456 "parser.y"
                                                                                                                { std::cout<<"function_definition -> declaration_specifiers declarator compound_statement"<<std::endl; }
#line 2886 "y.tab.c"
    break;

  case 211:
#line 457 "parser.y"
                                                                                                                        { std::cout<<"function_definition -> declarator declaration_list compound_statement"<<std::endl; }
#line 2892 "y.tab.c"
    break;

  case 212:
#line 458 "parser.y"
                                                                                                                                        { std::cout<<"function_definition -> declarator compound_statement	"<<std::endl; }
#line 2898 "y.tab.c"
    break;


#line 2902 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 461 "parser.y"


#include "lex.yy.c"

void yyerror (char const *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

//int main() {
//    yyparse(); // parse user input
//}

Expression *g_root; // Definition of variable (to match declaration earlier)

Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

int main()
{
// Parse the AST
    Expression *ast=parseAST();
//Compile AST? Need function in the class

	std::string current_func;
	std::map<std::string, std::string> g_Var;
	std::map<std::string, bool> reg_available;
	std::string type_check;
	int initial_memory = 0;
	
	std::string MIPS;
	//MIPS += ast->Compile( current_func, initial_memory, g_Var, reg_available, type_check );
	//std::cout<<"MIPS: " << ast-> <<std::endl;
    return 0;
}