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
  #include <algorithm>

  extern Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
  std::vector<int> func_call;

#line 126 "y.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
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
    TYPEDEF = 273,
    EXTERN = 274,
    STATIC = 275,
    AUTO = 276,
    REGISTER = 277,
    CHAR = 278,
    SHORT = 279,
    INT = 280,
    LONG = 281,
    SIGNED = 282,
    UNSIGNED = 283,
    FLOAT = 284,
    DOUBLE = 285,
    CONST = 286,
    VOLATILE = 287,
    VOID = 288,
    STRUCT = 289,
    UNION = 290,
    ENUM = 291,
    ELLIPSIS = 292,
    CASE = 293,
    DEFAULT = 294,
    IF = 295,
    ELSE = 296,
    SWITCH = 297,
    WHILE = 298,
    DO = 299,
    FOR = 300,
    GOTO = 301,
    CONTINUE = 302,
    BREAK = 303,
    RETURN = 304,
    AND = 305,
    POINTER = 306,
    PLUS = 307,
    MINUS = 308,
    TILDE = 309,
    EXCL = 310,
    EQ_ASSIGN = 311,
    MUL_ASSIGN = 312,
    DIV_ASSIGN = 313,
    MOD_ASSIGN = 314,
    ADD_ASSIGN = 315,
    SUB_ASSIGN = 316,
    LEFT_ASSIGN = 317,
    RIGHT_ASSIGN = 318,
    AND_ASSIGN = 319,
    XOR_ASSIGN = 320,
    OR_ASSIGN = 321
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
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
#define TYPEDEF 273
#define EXTERN 274
#define STATIC 275
#define AUTO 276
#define REGISTER 277
#define CHAR 278
#define SHORT 279
#define INT 280
#define LONG 281
#define SIGNED 282
#define UNSIGNED 283
#define FLOAT 284
#define DOUBLE 285
#define CONST 286
#define VOLATILE 287
#define VOID 288
#define STRUCT 289
#define UNION 290
#define ENUM 291
#define ELLIPSIS 292
#define CASE 293
#define DEFAULT 294
#define IF 295
#define ELSE 296
#define SWITCH 297
#define WHILE 298
#define DO 299
#define FOR 300
#define GOTO 301
#define CONTINUE 302
#define BREAK 303
#define RETURN 304
#define AND 305
#define POINTER 306
#define PLUS 307
#define MINUS 308
#define TILDE 309
#define EXCL 310
#define EQ_ASSIGN 311
#define MUL_ASSIGN 312
#define DIV_ASSIGN 313
#define MOD_ASSIGN 314
#define ADD_ASSIGN 315
#define SUB_ASSIGN 316
#define LEFT_ASSIGN 317
#define RIGHT_ASSIGN 318
#define AND_ASSIGN 319
#define XOR_ASSIGN 320
#define OR_ASSIGN 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

	Expression *expr;
	int int_num;
	double double_num;
	float float_num;
	std::string *string;

#line 277 "y.tab.c"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

#define YYUNDEFTOK  2
#define YYMAXUTOK   321


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
       2,     2,     2,     2,     2,     2,     2,    75,    80,     2,
      67,    68,    73,    76,    72,    77,    71,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    85,
      78,     2,    79,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    82,    87,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    68,    69,    70,    71,    75,    76,    77,
      78,    79,    80,    81,    82,    86,    87,    91,    92,    93,
      94,    95,    96,   100,   101,   102,   103,   104,   105,   109,
     110,   114,   115,   116,   117,   121,   122,   123,   127,   128,
     129,   133,   134,   135,   136,   137,   141,   142,   143,   147,
     148,   152,   153,   157,   158,   162,   163,   167,   168,   172,
     173,   177,   178,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   196,   197,   201,   205,   206,   210,
     211,   212,   213,   214,   215,   219,   220,   224,   225,   229,
     230,   231,   232,   233,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   252,   253,   254,   258,   259,
     263,   264,   268,   272,   273,   274,   275,   279,   280,   284,
     285,   286,   290,   291,   292,   296,   297,   301,   302,   306,
     307,   311,   312,   316,   317,   318,   319,   320,   321,   322,
     326,   327,   328,   329,   333,   334,   339,   340,   344,   345,
     349,   350,   351,   355,   356,   360,   361,   365,   366,   367,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   383,
     384,   385,   389,   390,   394,   395,   396,   397,   398,   399,
     403,   404,   405,   409,   410,   411,   412,   416,   417,   421,
     422,   426,   427,   431,   432,   433,   437,   438,   439,   440,
     444,   445,   446,   447,   448,   452,   453,   457,   458,   462,
     463,   464,   465
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "AND", "POINTER", "PLUS", "MINUS",
  "TILDE", "EXCL", "EQ_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'*'", "'/'", "'%'", "'+'", "'-'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "'?'", "':'", "';'", "'{'", "'}'", "$accept", "HeadNODE",
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
     315,   316,   317,   318,   319,   320,   321,    40,    41,    91,
      93,    46,    44,    42,    47,    37,    43,    45,    60,    62,
      38,    94,   124,    63,    58,    59,   123,   125
};
# endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     713,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
       5,    65,   119,    20,  -221,    19,  1175,  1175,  -221,    11,
    -221,  1175,   771,   -17,    10,   713,  -221,  -221,   -61,    27,
     -15,  -221,  -221,   119,  -221,  -221,   -24,  -221,   732,  -221,
    -221,   -19,   593,  -221,   286,  -221,    19,  -221,   771,   882,
     769,   -17,  -221,    27,    16,   -38,  -221,  -221,  -221,  -221,
      65,  -221,   529,  -221,   771,   593,   593,   973,  -221,    57,
     593,    17,  -221,  -221,   917,   982,   982,  1035,    39,    22,
      62,    70,   522,   129,   206,   146,   150,   582,  -221,  -221,
    -221,  -221,  -221,  -221,   928,  -221,  -221,  -221,   275,   638,
    1035,  -221,   152,    81,   178,   135,   202,   157,   165,   166,
     231,    30,  -221,  -221,    31,  -221,  -221,  -221,   356,   409,
    -221,  -221,  -221,  -221,   201,  -221,  -221,  -221,  -221,    76,
     190,   187,  -221,   112,  -221,  -221,  -221,  -221,   191,   -29,
    1035,    27,  -221,  -221,   529,  -221,  -221,  -221,   987,  -221,
    -221,  -221,  1035,    48,  -221,   176,  -221,   522,   928,  -221,
    1035,  -221,  -221,   180,   522,  1035,  1035,  1035,   223,   589,
     182,  -221,  -221,  -221,    68,   114,     2,   203,   267,  -221,
    -221,   430,  1035,   270,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  1035,  -221,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  -221,  -221,   462,
    -221,  -221,   657,   808,  -221,    85,  -221,    75,  -221,  1155,
    -221,   271,  -221,  -221,  -221,  -221,  -221,   -21,  -221,  -221,
      57,  -221,  1035,  -221,   208,   522,  -221,   122,   123,   134,
     210,   589,  -221,  -221,  -221,  1085,   132,  -221,  1035,  -221,
    -221,   139,  -221,   158,  -221,  -221,  -221,  -221,  -221,   152,
     152,    81,    81,   178,   178,   178,   178,   135,   135,   202,
     157,   165,   166,   231,     1,  -221,  -221,  -221,   211,   212,
    -221,   215,    75,  1104,   829,  -221,  -221,  -221,   469,  -221,
    -221,  -221,  -221,  -221,   522,   522,   522,  1035,   660,  -221,
    -221,  1035,  -221,  1035,  -221,  -221,  -221,  -221,   213,  -221,
     216,  -221,  -221,   237,  -221,  -221,   140,   522,   147,  -221,
    -221,  -221,  -221,   522,   214,  -221,   522,  -221,  -221,  -221
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,    90,    89,    91,    92,    93,    95,    96,    97,
      98,   101,   102,    99,   100,   129,   130,    94,   108,   109,
       0,     0,   140,     0,   208,     0,    79,    81,   103,     0,
     104,    83,     0,   132,     0,     2,   205,   207,   124,     0,
       0,   144,   142,   141,     1,    77,     0,    85,    87,    80,
      82,   107,     0,    84,     0,   187,     0,   212,     0,     0,
       0,   131,   206,     0,   127,     0,   125,   134,   145,   143,
       0,    78,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,     0,   191,   183,     7,    17,    29,
       0,    31,    35,    38,    41,    46,    49,    51,    53,    55,
      57,    59,    61,    74,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    87,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     3,   136,    29,    76,     0,     0,
       0,     0,   122,    86,     0,   169,    88,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    21,
       0,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   202,   203,     0,     0,   155,     0,     0,    13,
      14,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,     0,   182,     0,     0,     0,
       0,     0,   200,   204,     6,     0,   157,   156,     0,    12,
       9,     0,    15,     0,    11,    62,    32,    33,    34,    36,
      37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
      52,    54,    56,    58,     0,    75,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,    22,   181,     0,     0,     0,     0,     0,    30,
      10,     0,     8,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    16,
      60,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,   -48,  -221,   -81,    23,     9,
      38,    25,    67,    72,    66,    73,    74,  -221,   -55,   -70,
    -221,   -94,   -54,     6,     0,  -221,   227,  -221,    42,  -221,
    -221,   225,   -68,   -59,  -221,    52,  -221,   238,   172,    35,
     -14,   -30,    -3,  -221,   -58,  -221,    88,  -221,   175,  -123,
    -220,  -131,  -221,   -74,  -221,    -4,    51,   217,  -155,  -221,
    -221,  -221,  -221,   312,  -221
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,   107,   108,   271,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     205,   124,   148,    55,    56,    46,    47,    26,    27,    28,
      29,    77,    78,    79,   163,   164,    30,    65,    66,    31,
      32,    33,    34,    43,   298,   141,   142,   143,   187,   299,
     237,   156,   247,   125,   126,   127,    58,   129,   130,   131,
     132,   133,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   140,   155,   184,    61,   147,    24,    40,    38,   161,
     185,    48,   146,     1,    51,   302,   236,   159,   178,    42,
      44,   166,     1,   246,   261,    63,    49,    50,    57,   206,
      64,    53,   147,   173,   151,    25,   169,   171,   172,   146,
      69,    24,   134,   151,    73,   186,   302,   224,    70,   152,
      59,   308,    60,    67,   136,   231,   134,    41,   243,   139,
       1,    71,   146,   267,   135,   165,   309,    75,     1,   265,
     157,   233,   150,   226,   185,    22,   185,    21,    68,     1,
     135,   257,   258,   259,   155,   323,    21,    80,     1,   175,
     161,    39,    22,   253,    76,   147,   244,    52,   273,    74,
     256,   167,   146,   226,    45,   128,   318,   147,   249,   186,
      80,    80,    80,   225,   146,    80,   227,    76,    76,    76,
     250,   272,    76,   174,    21,   234,   276,   277,   278,   176,
      22,   294,    21,   251,   135,   275,   235,   177,    22,    80,
     226,   162,   303,   232,   304,   233,    76,   214,   215,    22,
      15,    16,   232,   263,   233,   231,   295,   210,   211,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   332,   147,   301,
     240,   313,   264,   266,   241,   146,   226,   319,   212,   213,
     314,   315,    22,    80,   226,   226,   179,   147,   311,   265,
      76,   233,   316,    80,   146,    61,   226,   320,   344,   180,
      76,   321,   226,   216,   217,   346,   218,   219,    40,   226,
     146,   281,   282,   336,   338,   207,   208,   209,   322,   235,
     226,   181,   139,   279,   280,   182,   165,   220,   155,   139,
     333,   334,   335,   287,   288,   328,   221,   223,   222,   147,
     330,   339,   283,   284,   285,   286,   146,    72,   238,   239,
     252,   242,   266,   345,   255,   139,   260,   262,   340,   347,
     269,   268,   349,   274,   307,   146,   312,   317,   343,   324,
     325,   341,   188,   189,   190,   326,   342,   289,   291,    81,
      82,    83,    84,   290,    85,    86,   292,   153,   293,   348,
     158,   149,   310,   139,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   245,    87,    88,    89,   306,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   191,   254,   192,   229,   193,    62,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,   105,    54,   106,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,    82,    83,    84,     0,    85,    86,
       0,   105,    54,   228,     0,     0,     0,    87,    88,    89,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    81,    82,    83,    84,     0,
      85,    86,   144,    82,    83,    84,   104,    85,    86,     0,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   105,    54,   230,   104,   270,     0,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,    98,
      99,   100,   101,   102,   103,    81,    82,    83,    84,   104,
      85,    86,   144,    82,    83,    84,   104,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,   105,    54,   296,
       0,     0,     0,     0,     0,   154,   331,     0,     0,     0,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,    98,
      99,   100,   101,   102,   103,   144,    82,    83,    84,   104,
      85,    86,   144,    82,    83,    84,   104,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,   105,    54,     0,
       0,     0,     0,     0,     0,   154,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    98,    99,   100,   101,   102,   103,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,   104,     0,     0,     0,
       1,     0,     0,   144,    82,    83,    84,   183,    85,    86,
       0,     0,     0,     0,   105,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     1,     0,     0,     0,
       0,     0,     0,     0,   232,   297,   233,   104,   337,     0,
      22,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,   144,    82,    83,    84,     0,    85,    86,     0,
      21,     0,     0,     0,     0,     0,    22,     0,    72,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,   144,    82,    83,    84,     0,    85,    86,    54,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   144,    82,    83,    84,   104,    85,    86,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   300,    98,
      99,   100,   101,   102,   103,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   329,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
     144,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,   144,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   168,   144,    82,    83,    84,     0,
      85,    86,     0,     0,     0,   104,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   144,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   297,   233,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   305,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    59,    72,    97,    34,    60,     0,    21,     3,    77,
     104,    25,    60,     3,     3,   235,   139,    76,    92,    22,
       0,    80,     3,   154,   179,    86,    26,    27,    32,   110,
       3,    31,    87,    87,    72,    35,    84,    85,    86,    87,
      43,    35,    56,    72,    48,   104,   266,    17,    72,    87,
      67,    72,    69,    68,    58,   129,    70,    22,    87,    59,
       3,    85,   110,   186,    58,    79,    87,    86,     3,    67,
      74,    69,    56,    72,   168,    73,   170,    67,    43,     3,
      74,   175,   176,   177,   154,    84,    67,    52,     3,    67,
     158,    86,    73,   167,    52,   150,   150,    86,   192,    48,
     174,    84,   150,    72,    85,    54,   261,   162,   162,   168,
      75,    76,    77,    83,   162,    80,    85,    75,    76,    77,
      72,   191,    80,    84,    67,   139,   207,   208,   209,    67,
      73,   225,    67,    85,   128,   205,   139,    67,    73,   104,
      72,    84,    67,    67,    69,    69,   104,    12,    13,    73,
      31,    32,    67,    85,    69,   229,   226,    76,    77,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   308,   233,   233,
      68,   255,    68,   186,    72,   233,    72,   268,    10,    11,
      68,    68,    73,   158,    72,    72,    67,   252,   252,    67,
     158,    69,    68,   168,   252,   235,    72,    68,    68,     3,
     168,    72,    72,    78,    79,    68,    14,    15,   232,    72,
     268,   212,   213,   317,   318,    73,    74,    75,    70,   232,
      72,    85,   232,   210,   211,    85,   250,    80,   308,   239,
     314,   315,   316,   218,   219,   303,    81,    16,    82,   304,
     304,   321,   214,   215,   216,   217,   304,    56,    68,    72,
      84,    70,   265,   337,    84,   265,    43,    85,   323,   343,
       3,    68,   346,     3,     3,   323,    68,    67,    41,    68,
      68,    68,     7,     8,     9,    70,    70,   220,   222,     3,
       4,     5,     6,   221,     8,     9,   223,    70,   224,    85,
      75,    63,   250,   303,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   151,    38,    39,    40,   239,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    67,   168,    69,   128,    71,    35,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    85,    86,    87,    -1,    -1,    -1,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,     4,     5,     6,    -1,
       8,     9,     3,     4,     5,     6,    67,     8,     9,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    67,    68,    -1,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    50,
      51,    52,    53,    54,    55,     3,     4,     5,     6,    67,
       8,     9,     3,     4,     5,     6,    67,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    50,
      51,    52,    53,    54,    55,     3,     4,     5,     6,    67,
       8,     9,     3,     4,     5,     6,    67,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    50,    51,    52,    53,    54,    55,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
       3,    -1,    -1,     3,     4,     5,     6,    85,     8,     9,
      -1,    -1,    -1,    -1,    85,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    67,    68,    -1,
      73,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    73,    -1,    56,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    86,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    67,     8,     9,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    50,
      51,    52,    53,    54,    55,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    67,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    67,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    67,    73,    89,   111,   112,   115,   116,   117,   118,
     124,   127,   128,   129,   130,   150,   151,   152,     3,    86,
     128,   127,   130,   131,     0,    85,   113,   114,   128,   112,
     112,     3,    86,   112,    86,   111,   112,   143,   144,    67,
      69,   129,   151,    86,     3,   125,   126,    68,   127,   130,
      72,    85,    56,   143,   144,    86,   116,   119,   120,   121,
     127,     3,     4,     5,     6,     8,     9,    38,    39,    40,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    67,    85,    87,    90,    91,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   109,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   128,   111,   143,     3,    68,   112,
     132,   133,   134,   135,     3,    70,    93,   106,   110,   125,
      56,    72,    87,   114,    86,   107,   139,   143,   119,   121,
      87,   120,    84,   122,   123,   128,   121,    84,    67,    93,
      67,    93,    93,   110,    84,    67,    67,    67,   141,    67,
       3,    85,    85,    85,   109,   109,   121,   136,     7,     8,
       9,    67,    69,    71,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   108,    95,    73,    74,    75,
      76,    77,    10,    11,    12,    13,    78,    79,    14,    15,
      80,    81,    82,    16,    17,    83,    72,    85,    87,   145,
      87,   141,    67,    69,   128,   130,   137,   138,    68,    72,
      68,    72,    70,    87,   110,   126,   139,   140,    87,   110,
      72,    85,    84,   141,   136,    84,   141,   109,   109,   109,
      43,   146,    85,    85,    68,    67,   130,   137,    68,     3,
      68,    92,   107,   109,     3,   107,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    99,    99,   100,
     101,   102,   103,   104,   109,   107,    87,    68,   132,   137,
      70,   110,   138,    67,    69,    37,   134,     3,    72,    87,
     123,   110,    68,   141,    68,    68,    68,    67,   146,    95,
      68,    72,    70,    84,    68,    68,    70,    68,   132,    70,
     110,    87,   139,   141,   141,   141,   109,    68,   109,   107,
     106,    68,    70,    41,    68,   141,    68,   141,    85,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   121,   121,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   141,   141,   141,   141,
     142,   142,   142,   143,   143,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   152,
     152,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
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
#line 64 "parser.y"
                            { g_root = new HeadNode((yyvsp[0].expr)); }
#line 1906 "y.tab.c"
    break;

  case 3:
#line 68 "parser.y"
                                                { std::cout<< "primary_expression -> IDENTIFIER " << std::endl; (yyval.expr) = new Variable(*(yyvsp[0].string)); 	}
#line 1912 "y.tab.c"
    break;

  case 4:
#line 69 "parser.y"
                                                        { std::cout<< "primary_expression -> CONSTANT " << std::endl; (yyval.expr) = new Integer(*(yyvsp[0].string)); 		}
#line 1918 "y.tab.c"
    break;

  case 5:
#line 70 "parser.y"
                                                { std::cout<< "primary_expression -> STRING_LITERAL" <<std::endl; /*$$ = new StringLiteral();*/	}
#line 1924 "y.tab.c"
    break;

  case 6:
#line 71 "parser.y"
                                        { std::cout<< "primary_expression -> ( expression )" <<std::endl; /*$$ = new Expression;*/}
#line 1930 "y.tab.c"
    break;

  case 7:
#line 75 "parser.y"
                                                                                                        { 							std::cout<< "postfix_expression -> primary_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1936 "y.tab.c"
    break;

  case 8:
#line 76 "parser.y"
                                                                                        { 							std::cout<< "postfix_expression -> postfix_expression '[' expression ']'	" << std::endl; }
#line 1942 "y.tab.c"
    break;

  case 9:
#line 77 "parser.y"
                                                                                                { func_call.push_back(0); (yyval.expr) = new postfix(1, (yyvsp[-2].expr)); 	std::cout<< "postfix_expression -> postfix_expression '(' ')'" << std::endl; }
#line 1948 "y.tab.c"
    break;

  case 10:
#line 78 "parser.y"
                                                                        { func_call.push_back(0); (yyval.expr) = new postfix(2, (yyvsp[-3].expr));	std::cout<< "postfix_expression -> postfix_expression '(' argument_expression_list ')'" << std::endl; }
#line 1954 "y.tab.c"
    break;

  case 11:
#line 79 "parser.y"
                                                                                                {							std::cout<< "postfix_expression -> postfix_expression '.' IDENTIFIER" << std::endl; }
#line 1960 "y.tab.c"
    break;

  case 12:
#line 80 "parser.y"
                                                                                        { 							std::cout<< "postfix_expression -> postfix_expression PTR_OP IDENTIFIER" << std::endl; }
#line 1966 "y.tab.c"
    break;

  case 13:
#line 81 "parser.y"
                                                                                                        { 							std::cout<< "postfix_expression -> postfix_expression INC_OP" << std::endl; }
#line 1972 "y.tab.c"
    break;

  case 14:
#line 82 "parser.y"
                                                                                                        { 							std::cout<< "postfix_expression -> postfix_expression DEC_OP" << std::endl; }
#line 1978 "y.tab.c"
    break;

  case 15:
#line 86 "parser.y"
                                                                                                        { std::cout<< "argument_expression_list -> assignment_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1984 "y.tab.c"
    break;

  case 16:
#line 87 "parser.y"
                                                                        { std::cout<< "argument_expression_list -> argument_expression_list ',' assignment_expression" << std::endl; }
#line 1990 "y.tab.c"
    break;

  case 17:
#line 91 "parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); std::cout<< "unary_expression -> postfix_expression" << std::endl; }
#line 1996 "y.tab.c"
    break;

  case 18:
#line 92 "parser.y"
                                                        { /*$$ = Unary(0, $2); */ std::cout<< "unary_expression -> INC_OP unary_expression" << std::endl; }
#line 2002 "y.tab.c"
    break;

  case 19:
#line 93 "parser.y"
                                                        { /*$$ = Unary(1, $2); */ std::cout<< "unary_expression -> DEC_OP unary_expression" << std::endl; }
#line 2008 "y.tab.c"
    break;

  case 20:
#line 94 "parser.y"
                                                { (yyval.expr) = new Unary((yyvsp[-1].expr), (yyvsp[0].expr));   std::cout<< "unary_expression -> unary_operator cast_expression" << std::endl; }
#line 2014 "y.tab.c"
    break;

  case 21:
#line 95 "parser.y"
                                                        { /*$$ = Unary(2, $2); */ std::cout<< "unary_expression -> SIZEOF unary_expression" << std::endl; }
#line 2020 "y.tab.c"
    break;

  case 22:
#line 96 "parser.y"
                                                        { /*$$ = Unary(3, $3); */ std::cout<< "unary_expression -> SIZEOF '(' type_name ')'" << std::endl; }
#line 2026 "y.tab.c"
    break;

  case 23:
#line 100 "parser.y"
                                { std::cout<< "unary_operator -> &" << std::endl; (yyval.expr) = new UnaryOperator(0); }
#line 2032 "y.tab.c"
    break;

  case 24:
#line 101 "parser.y"
                                { std::cout<< "unary_operator -> *" << std::endl; (yyval.expr) = new UnaryOperator(1); }
#line 2038 "y.tab.c"
    break;

  case 25:
#line 102 "parser.y"
                                { std::cout<< "unary_operator -> +" << std::endl; (yyval.expr) = new UnaryOperator(2); }
#line 2044 "y.tab.c"
    break;

  case 26:
#line 103 "parser.y"
                                { std::cout<< "unary_operator -> -" << std::endl; (yyval.expr) = new UnaryOperator(3); }
#line 2050 "y.tab.c"
    break;

  case 27:
#line 104 "parser.y"
                                { std::cout<< "unary_operator -> ~" << std::endl; (yyval.expr) = new UnaryOperator(4); }
#line 2056 "y.tab.c"
    break;

  case 28:
#line 105 "parser.y"
                                { std::cout<< "unary_operator -> !" << std::endl; (yyval.expr) = new UnaryOperator(5); }
#line 2062 "y.tab.c"
    break;

  case 29:
#line 109 "parser.y"
                                                                        { std::cout<< "cast_expression -> unary_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2068 "y.tab.c"
    break;

  case 30:
#line 110 "parser.y"
                                                        { std::cout<< "cast_expression -> '(' type_name ')' cast_expression" << std::endl; }
#line 2074 "y.tab.c"
    break;

  case 31:
#line 114 "parser.y"
                                                                                                        { std::cout<<"multiplicative_expression -> cast_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2080 "y.tab.c"
    break;

  case 32:
#line 115 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '*' cast_expression"<<std::endl; (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2086 "y.tab.c"
    break;

  case 33:
#line 116 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '/' cast_expression"<<std::endl; (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2092 "y.tab.c"
    break;

  case 34:
#line 117 "parser.y"
                                                                        { std::cout<<"multiplicative_expression -> multiplicative_expression '%' cast_expression"<<std::endl; (yyval.expr) = new ModOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2098 "y.tab.c"
    break;

  case 35:
#line 121 "parser.y"
                                                                                                { std::cout<<"additive_expression -> multiplicative_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2104 "y.tab.c"
    break;

  case 36:
#line 122 "parser.y"
                                                                { std::cout<<"additive_expression -> additive_expression '+' multiplicative_expression"<<std::endl; (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2110 "y.tab.c"
    break;

  case 37:
#line 123 "parser.y"
                                                                { std::cout<<"additive_expression -> additive_expression '-' multiplicative_expression"<<std::endl; (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2116 "y.tab.c"
    break;

  case 38:
#line 127 "parser.y"
                                                                                                { std::cout<<"shift_expression -> additive_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2122 "y.tab.c"
    break;

  case 39:
#line 128 "parser.y"
                                                                        { std::cout<<"shift_expression -> shift_expression LEFT_OP additive_expression"<<std::endl; (yyval.expr) = new LShiftLeftOperator((yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 2128 "y.tab.c"
    break;

  case 40:
#line 129 "parser.y"
                                                                        { std::cout<<"shift_expression -> shift_expression RIGHT_OP additive_expression"<<std::endl; (yyval.expr) = new LShiftRightOperator((yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 2134 "y.tab.c"
    break;

  case 41:
#line 133 "parser.y"
                                                                                                        { std::cout<<"relational_expression -> shift_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2140 "y.tab.c"
    break;

  case 42:
#line 134 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression '<' shift_expression"<<std::endl; (yyval.expr) = new LTOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2146 "y.tab.c"
    break;

  case 43:
#line 135 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression '>' shift_expression"<<std::endl; (yyval.expr) = new GTOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2152 "y.tab.c"
    break;

  case 44:
#line 136 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression LE_OP shift_expression"<<std::endl; (yyval.expr) = new LEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2158 "y.tab.c"
    break;

  case 45:
#line 137 "parser.y"
                                                                        { std::cout<<"relational_expression -> relational_expression GE_OP shift_expression"<<std::endl; (yyval.expr) = new GEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2164 "y.tab.c"
    break;

  case 46:
#line 141 "parser.y"
                                                                                                { std::cout<<"equality_expression -> relational_expression"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 2170 "y.tab.c"
    break;

  case 47:
#line 142 "parser.y"
                                                                        { std::cout<<"equality_expression -> equality_expression EQ_OP relational_expression"<<std::endl; (yyval.expr) = new EqOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2176 "y.tab.c"
    break;

  case 48:
#line 143 "parser.y"
                                                                        { std::cout<<"equality_expression -> equality_expression NE_OP relational_expression"<<std::endl; (yyval.expr) = new NeqOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2182 "y.tab.c"
    break;

  case 49:
#line 147 "parser.y"
                                                                                                { std::cout<<"and_expression -> equality_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2188 "y.tab.c"
    break;

  case 50:
#line 148 "parser.y"
                                                                                { std::cout<<"and_expression -> and_expression '&' equality_expression"<<std::endl; (yyval.expr) = new bAndOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2194 "y.tab.c"
    break;

  case 51:
#line 152 "parser.y"
                                                                                                        { std::cout<<"exclusive_or_expression -> and_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2200 "y.tab.c"
    break;

  case 52:
#line 153 "parser.y"
                                                                        { std::cout<<"exclusive_or_expression -> exclusive_or_expression '^' and_expression"<<std::endl; (yyval.expr) = new xorOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2206 "y.tab.c"
    break;

  case 53:
#line 157 "parser.y"
                                                                                                { std::cout<<"inclusive_or_expression -> exclusive_or_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2212 "y.tab.c"
    break;

  case 54:
#line 158 "parser.y"
                                                                { std::cout<<"inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression"<<std::endl; (yyval.expr) = new bOrOperator((yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 2218 "y.tab.c"
    break;

  case 55:
#line 162 "parser.y"
                                                                                                { std::cout<<"logical_and_expression -> inclusive_or_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2224 "y.tab.c"
    break;

  case 56:
#line 163 "parser.y"
                                                                { std::cout<<"logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"<<std::endl; (yyval.expr) = new AndOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2230 "y.tab.c"
    break;

  case 57:
#line 167 "parser.y"
                                                                                                { std::cout<<"logical_or_expression -> logical_and_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2236 "y.tab.c"
    break;

  case 58:
#line 168 "parser.y"
                                                                { std::cout<<"logical_or_expression -> logical_or_expression OR_OP logical_and_expression"<<std::endl; (yyval.expr) = new OrOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2242 "y.tab.c"
    break;

  case 59:
#line 172 "parser.y"
                                                                                                                        { std::cout<<"conditional_expression -> logical_or_expression"<<std::endl;  (yyval.expr) = (yyvsp[0].expr); }
#line 2248 "y.tab.c"
    break;

  case 60:
#line 173 "parser.y"
                                                                                { std::cout<<"conditional_expression -> logical_or_expression '?' expression ':' conditional_expression"<<std::endl; }
#line 2254 "y.tab.c"
    break;

  case 61:
#line 177 "parser.y"
                                                                                                                { (yyval.expr) = (yyvsp[0].expr); std::cout << "assignment_expression -> conditional_expression" << std::endl;   }
#line 2260 "y.tab.c"
    break;

  case 62:
#line 178 "parser.y"
                                                                        { (yyval.expr) = new AssignmentOperator((yyvsp[-2].expr), *(yyvsp[-1].string), (yyvsp[0].expr)); std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl; }
#line 2266 "y.tab.c"
    break;

  case 63:
#line 182 "parser.y"
                                                { std::cout << "assignment_operator: =" << std::endl;  (yyval.string) = (yyvsp[0].string);}
#line 2272 "y.tab.c"
    break;

  case 64:
#line 183 "parser.y"
                                        { std::cout << "assignment_operator: *=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2278 "y.tab.c"
    break;

  case 65:
#line 184 "parser.y"
                                        { std::cout << "assignment_operator: /=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2284 "y.tab.c"
    break;

  case 66:
#line 185 "parser.y"
                                        { std::cout << "assignment_operator: %=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2290 "y.tab.c"
    break;

  case 67:
#line 186 "parser.y"
                                        { std::cout << "assignment_operator: +=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2296 "y.tab.c"
    break;

  case 68:
#line 187 "parser.y"
                                        { std::cout << "assignment_operator: -=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2302 "y.tab.c"
    break;

  case 69:
#line 188 "parser.y"
                                        { std::cout << "assignment_operator: <<=" << std::endl;(yyval.string) = (yyvsp[0].string);}
#line 2308 "y.tab.c"
    break;

  case 70:
#line 189 "parser.y"
                                        { std::cout << "assignment_operator: >>=" << std::endl;(yyval.string) = (yyvsp[0].string);}
#line 2314 "y.tab.c"
    break;

  case 71:
#line 190 "parser.y"
                                        { std::cout << "assignment_operator: &=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2320 "y.tab.c"
    break;

  case 72:
#line 191 "parser.y"
                                        { std::cout << "assignment_operator: ^=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2326 "y.tab.c"
    break;

  case 73:
#line 192 "parser.y"
                                                { std::cout << "assignment_operator: |=" << std::endl; (yyval.string) = (yyvsp[0].string);}
#line 2332 "y.tab.c"
    break;

  case 74:
#line 196 "parser.y"
                                                                        { std::cout<<"expression -> assignment_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr);}
#line 2338 "y.tab.c"
    break;

  case 75:
#line 197 "parser.y"
                                                        { std::cout<<"expression -> expression ',' assignment_expression" << std::endl; (yyval.expr) = new a_expr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2344 "y.tab.c"
    break;

  case 76:
#line 201 "parser.y"
                                                                        { std::cout<<"constant_expression -> conditional_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr);	}
#line 2350 "y.tab.c"
    break;

  case 77:
#line 205 "parser.y"
                                                                                        { (yyval.expr) = (yyvsp[-1].expr); std::cout<<"declaration -> declaration_specifiers ;" << std::endl;  }
#line 2356 "y.tab.c"
    break;

  case 78:
#line 206 "parser.y"
                                                                        { (yyval.expr) = new Declaration((yyvsp[-2].expr), (yyvsp[-1].expr)); std::cout<<"declaration -> declaration_specifiers init_declarator_list ;" << std::endl; }
#line 2362 "y.tab.c"
    break;

  case 79:
#line 210 "parser.y"
                                                                                                { (yyval.expr) = new Declaration_Spec("storage", (yyvsp[0].expr));			std::cout<<"declaration_specifiers -> storage_class_specifier"<<std::endl; 							 }
#line 2368 "y.tab.c"
    break;

  case 80:
#line 211 "parser.y"
                                                                        { (yyval.expr) = new Declaration_Spec("storage", (yyvsp[-1].expr), (yyvsp[0].expr));		std::cout<<"declaration_specifiers -> storage_class_specifier declaration_specifiers"<<std::endl;	 }
#line 2374 "y.tab.c"
    break;

  case 81:
#line 212 "parser.y"
                                                                                                        { (yyval.expr) = new Declaration_Spec("specifier", (yyvsp[0].expr));		std::cout<<"declaration_specifiers -> type_specifier"<<std::endl; 							}
#line 2380 "y.tab.c"
    break;

  case 82:
#line 213 "parser.y"
                                                                                { (yyval.expr) = new Declaration_Spec("specifier", (yyvsp[-1].expr), (yyvsp[0].expr));	std::cout<<"declaration_specifiers -> type_specifier declaration_specifiers"<<std::endl;	}
#line 2386 "y.tab.c"
    break;

  case 83:
#line 214 "parser.y"
                                                                                                        { (yyval.expr) = new Declaration_Spec("qualifier", (yyvsp[0].expr));		std::cout<<"declaration_specifiers -> type_qualifier"<<std::endl;							}
#line 2392 "y.tab.c"
    break;

  case 84:
#line 215 "parser.y"
                                                                                { (yyval.expr) = new Declaration_Spec("qualifier", (yyvsp[-1].expr), (yyvsp[0].expr));	std::cout<<"declaration_specifiers -> type_qualifier declaration_specifiers"<<std::endl; 	}
#line 2398 "y.tab.c"
    break;

  case 85:
#line 219 "parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); std::cout<<"init_declarator_list -> init_declarator"<<std::endl;  }
#line 2404 "y.tab.c"
    break;

  case 86:
#line 220 "parser.y"
                                                                {  (yyval.expr) = new Init_Declarator_List((yyvsp[-2].expr), (yyvsp[0].expr)); std::cout<<"init_declarator_list -> init_declarator_list ',' init_declarator"<<std::endl; }
#line 2410 "y.tab.c"
    break;

  case 87:
#line 224 "parser.y"
                                                                                        { (yyval.expr) = new Init_Declarator((yyvsp[0].expr)); 	std::cout<<"init_declarator -> declarator"<<std::endl;  /*	$$ = new Init_Declarator($1, NULL); */}
#line 2416 "y.tab.c"
    break;

  case 88:
#line 225 "parser.y"
                                                                        { (yyval.expr) = new Init_Declarator((yyvsp[-2].expr), (yyvsp[0].expr)); std::cout<<"init_declarator -> declarator '=' initializer"<<std::endl; }
#line 2422 "y.tab.c"
    break;

  case 89:
#line 229 "parser.y"
                                                { std::cout<<"storage_class_specifier -> EXTERN"<<std::endl;   (yyval.expr) = new StorageClassSpecifier(*(yyvsp[0].string));	}
#line 2428 "y.tab.c"
    break;

  case 90:
#line 230 "parser.y"
                                                { std::cout<<"storage_class_specifier -> TYPEDEF"<<std::endl;  (yyval.expr) = new StorageClassSpecifier(*(yyvsp[0].string));	}
#line 2434 "y.tab.c"
    break;

  case 91:
#line 231 "parser.y"
                                                { std::cout<<"storage_class_specifier -> STATIC"<<std::endl;   (yyval.expr) = new StorageClassSpecifier(*(yyvsp[0].string));	}
#line 2440 "y.tab.c"
    break;

  case 92:
#line 232 "parser.y"
                                                { std::cout<<"storage_class_specifier -> AUTO"<<std::endl;     (yyval.expr) = new StorageClassSpecifier(*(yyvsp[0].string));	}
#line 2446 "y.tab.c"
    break;

  case 93:
#line 233 "parser.y"
                                                { std::cout<<"storage_class_specifier -> REGISTER"<<std::endl; (yyval.expr) = new StorageClassSpecifier(*(yyvsp[0].string));	}
#line 2452 "y.tab.c"
    break;

  case 94:
#line 237 "parser.y"
                                                                        { std::cout<<"type_specifier -> VOID"<<std::endl; 								(yyval.expr)  = new TypeSpecifier("void");	}
#line 2458 "y.tab.c"
    break;

  case 95:
#line 238 "parser.y"
                                                                        { std::cout<<"type_specifier -> CHAR"<<std::endl; 								(yyval.expr)  = new TypeSpecifier("char");	}
#line 2464 "y.tab.c"
    break;

  case 96:
#line 239 "parser.y"
                                                                        { std::cout<<"type_specifier -> SHORT"<<std::endl; 								(yyval.expr)  = new TypeSpecifier("short");	}
#line 2470 "y.tab.c"
    break;

  case 97:
#line 240 "parser.y"
                                                                        { std::cout<<"type_specifier -> INT"<<std::endl;							 	(yyval.expr)  = new TypeSpecifier("int");	}
#line 2476 "y.tab.c"
    break;

  case 98:
#line 241 "parser.y"
                                                                        { std::cout<<"type_specifier -> LONG"<<std::endl; 								(yyval.expr)  = new TypeSpecifier("long");	}
#line 2482 "y.tab.c"
    break;

  case 99:
#line 242 "parser.y"
                                                                        { std::cout<<"type_specifier -> FLOAT"<<std::endl; 								(yyval.expr)  = new TypeSpecifier("float");	}
#line 2488 "y.tab.c"
    break;

  case 100:
#line 243 "parser.y"
                                                                        { std::cout<<"type_specifier -> DOUBLE"<<std::endl; 							(yyval.expr)  = new TypeSpecifier("double");	}
#line 2494 "y.tab.c"
    break;

  case 101:
#line 244 "parser.y"
                                                                        { std::cout<<"type_specifier -> SIGNED"<<std::endl; 							(yyval.expr)  = new TypeSpecifier("signed");	}
#line 2500 "y.tab.c"
    break;

  case 102:
#line 245 "parser.y"
                                                                        { std::cout<<"type_specifier -> UNSIGNED"<<std::endl; 							(yyval.expr)  = new TypeSpecifier("unsigned");	}
#line 2506 "y.tab.c"
    break;

  case 103:
#line 246 "parser.y"
                                                        { std::cout<<"type_specifier -> struct_or_union_specifier"<<std::endl; 			(yyval.expr)  = (yyvsp[0].expr);						}
#line 2512 "y.tab.c"
    break;

  case 104:
#line 247 "parser.y"
                                                                { std::cout<<"type_specifier -> enum_specifier"<<std::endl; 					(yyval.expr)  = (yyvsp[0].expr);						}
#line 2518 "y.tab.c"
    break;

  case 105:
#line 252 "parser.y"
                                                                                { (yyval.expr) = new Struct_Or_Union_Specifier((yyvsp[-4].expr), *(yyvsp[-3].string), (yyvsp[-1].expr));	std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER '{' struct_declaration_list '}'"<<std::endl; }
#line 2524 "y.tab.c"
    break;

  case 106:
#line 253 "parser.y"
                                                                                                { (yyval.expr) = new Struct_Or_Union_Specifier((yyvsp[-3].expr), (yyvsp[-1].expr));		std::cout<<"struct_or_union_specifier -> struct_or_union '{' struct_declaration_list '}'"<<std::endl; }
#line 2530 "y.tab.c"
    break;

  case 107:
#line 254 "parser.y"
                                                                                                                { (yyval.expr) = new Struct_Or_Union_Specifier((yyvsp[-1].expr), *(yyvsp[0].string));		std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER"<<std::endl; }
#line 2536 "y.tab.c"
    break;

  case 108:
#line 258 "parser.y"
                                        { std::cout<<"struct_or_union -> STRUCT"<<std::endl; }
#line 2542 "y.tab.c"
    break;

  case 109:
#line 259 "parser.y"
                                        { std::cout<<"struct_or_union -> UNION"<<std::endl;  }
#line 2548 "y.tab.c"
    break;

  case 110:
#line 263 "parser.y"
                                                                                        { std::cout<<"struct_declaration_list -> struct_declaration"<<std::endl; }
#line 2554 "y.tab.c"
    break;

  case 111:
#line 264 "parser.y"
                                                                { std::cout<<"struct_declaration_list -> struct_declaration_list struct_declaration"<<std::endl; }
#line 2560 "y.tab.c"
    break;

  case 112:
#line 268 "parser.y"
                                                                { std::cout<<"struct_declaration -> specifier_qualifier_list struct_declarator_list"<<std::endl; }
#line 2566 "y.tab.c"
    break;

  case 113:
#line 272 "parser.y"
                                                                { (yyval.expr) = new SpecifierQualifierList(0, (yyvsp[-1].expr), (yyvsp[0].expr));	std::cout<<"specifier_qualifier_list -> type_specifier specifier_qualifier_list"<<std::endl; }
#line 2572 "y.tab.c"
    break;

  case 114:
#line 273 "parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr);										std::cout<<"specifier_qualifier_list -> type_specifier"<<std::endl; }
#line 2578 "y.tab.c"
    break;

  case 115:
#line 274 "parser.y"
                                                                { (yyval.expr) = new SpecifierQualifierList(1, (yyvsp[-1].expr), (yyvsp[0].expr));	std::cout<<"specifier_qualifier_list -> type_qualifier specifier_qualifier_list"<<std::endl; }
#line 2584 "y.tab.c"
    break;

  case 116:
#line 275 "parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr);										std::cout<<"specifier_qualifier_list -> type_qualifier"<<std::endl; }
#line 2590 "y.tab.c"
    break;

  case 117:
#line 279 "parser.y"
                                                                                                { std::cout<<"struct_declarator_list -> struct_declarator"<<std::endl; }
#line 2596 "y.tab.c"
    break;

  case 118:
#line 280 "parser.y"
                                                                { std::cout<<"struct_declarator_list -> struct_declarator_list ',' struct_declarator"<<std::endl; }
#line 2602 "y.tab.c"
    break;

  case 119:
#line 284 "parser.y"
                                                                                { std::cout<<"struct_declarator -> declarator"<<std::endl; }
#line 2608 "y.tab.c"
    break;

  case 120:
#line 285 "parser.y"
                                                                        { std::cout<<"struct_declarator -> ':' constant_expression" <<std::endl; }
#line 2614 "y.tab.c"
    break;

  case 121:
#line 286 "parser.y"
                                                        { std::cout<<"struct_declarator -> declarator ':' constant_expression"<<std::endl; }
#line 2620 "y.tab.c"
    break;

  case 122:
#line 290 "parser.y"
                                                                { (yyval.expr) = new EnumSpecifier(0, "EMPTY", (yyvsp[-1].expr));	std::cout << "enum_specifier -> ENUM '{' enumerator_list '}'" << std::endl; }
#line 2626 "y.tab.c"
    break;

  case 123:
#line 291 "parser.y"
                                                        { (yyval.expr) = new EnumSpecifier(1, *(yyvsp[-3].string), (yyvsp[-1].expr));	std::cout << "enum_specifier -> ENUM IDENTIFIER '{' enumerator_list '}'" << std::endl; }
#line 2632 "y.tab.c"
    break;

  case 124:
#line 292 "parser.y"
                                                                                { (yyval.expr) = new EnumSpecifier(2, *(yyvsp[0].string));	std::cout << "enum_specifier -> ENUM IDENTIFIER" << std::endl; }
#line 2638 "y.tab.c"
    break;

  case 125:
#line 296 "parser.y"
                                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "enumerator_list -> enumerator" << std::endl; }
#line 2644 "y.tab.c"
    break;

  case 126:
#line 297 "parser.y"
                                                                { (yyval.expr) = new EnumeratorList((yyvsp[-2].expr), (yyvsp[0].expr));	std::cout << "enumerator_list -> enumerator_list ',' enumerator" << std::endl; }
#line 2650 "y.tab.c"
    break;

  case 127:
#line 301 "parser.y"
                                                                                { (yyval.expr) = new Enumerator(*(yyvsp[0].string));; std::cout << "enumerator -> IDENTIFIER" << std::endl; }
#line 2656 "y.tab.c"
    break;

  case 128:
#line 302 "parser.y"
                                                                { (yyval.expr) = new Enumerator(*(yyvsp[-2].string), (yyvsp[0].expr));	std::cout << "enumerator -> IDENTIFIER '=' constant_expression" << std::endl; }
#line 2662 "y.tab.c"
    break;

  case 129:
#line 306 "parser.y"
                                { std::cout << "type_qualifier -> CONST" << std::endl; }
#line 2668 "y.tab.c"
    break;

  case 130:
#line 307 "parser.y"
                                { std::cout << "type_qualifier -> VOLATILE" << std::endl; }
#line 2674 "y.tab.c"
    break;

  case 131:
#line 311 "parser.y"
                                                        { (yyval.expr) = new Declarator((yyvsp[-1].expr), (yyvsp[0].expr));  std::cout << "declarator -> pointer direct_declarator" << std::endl;}
#line 2680 "y.tab.c"
    break;

  case 132:
#line 312 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); std::cout << "declarator -> direct_declarator" << std::endl;  }
#line 2686 "y.tab.c"
    break;

  case 133:
#line 316 "parser.y"
                                                                                                                { (yyval.expr) = new DirectDeclarator(0, *(yyvsp[0].string));	std::cout << "direct_declarator -> IDENTIFIER" << std::endl;  /*NOT WORKING*/ }
#line 2692 "y.tab.c"
    break;

  case 134:
#line 317 "parser.y"
                                                                                                        { (yyval.expr) = new DirectDeclarator(1, (yyvsp[-1].expr));	std::cout << "direct_declarator -> '(' declarator ')'" << std::endl; }
#line 2698 "y.tab.c"
    break;

  case 135:
#line 318 "parser.y"
                                                                                { (yyval.expr) = new DirectDeclarator(2, (yyvsp[-3].expr), (yyvsp[-1].expr));	std::cout << "direct_declarator -> direct_declarator '[' constant_expression ']'" << std::endl; }
#line 2704 "y.tab.c"
    break;

  case 136:
#line 319 "parser.y"
                                                                                                        { (yyval.expr) = new DirectDeclarator(3, (yyvsp[-2].expr));	std::cout << "direct_declarator -> direct_declarator '[' ']'" << std::endl; }
#line 2710 "y.tab.c"
    break;

  case 137:
#line 320 "parser.y"
                                                                                { (yyval.expr) = new DirectDeclarator(4, (yyvsp[-3].expr), (yyvsp[-1].expr));	std::cout << "direct_declarator -> direct_declarator '(' parameter_type_list ')'" << std::endl; }
#line 2716 "y.tab.c"
    break;

  case 138:
#line 321 "parser.y"
                                                                                        { (yyval.expr) = new DirectDeclarator(5, (yyvsp[-3].expr), (yyvsp[-1].expr));	std::cout << "direct_declarator -> direct_declarator '(' identifier_list ')'" << std::endl; }
#line 2722 "y.tab.c"
    break;

  case 139:
#line 322 "parser.y"
                                                                                                        { (yyval.expr) = new DirectDeclarator(6, (yyvsp[-2].expr));	std::cout << "direct_declarator -> direct_declarator '(' ')'" << std::endl; }
#line 2728 "y.tab.c"
    break;

  case 140:
#line 326 "parser.y"
                                                                                { (yyval.expr) = new pointer();	std::cout << "pointer -> '*'" << std::endl; }
#line 2734 "y.tab.c"
    break;

  case 141:
#line 327 "parser.y"
                                                                { (yyval.expr) = new pointer((yyvsp[0].expr));   std::cout << "pointer -> '*' type_qualifier_list" << std::endl; }
#line 2740 "y.tab.c"
    break;

  case 142:
#line 328 "parser.y"
                                                                        { (yyval.expr) = new pointer((yyvsp[0].expr));	std::cout << "pointer -> '*' pointer" << std::endl; }
#line 2746 "y.tab.c"
    break;

  case 143:
#line 329 "parser.y"
                                                        { (yyval.expr) = new pointer((yyvsp[-1].expr), (yyvsp[0].expr));   std::cout << "pointer -> '*' type_qualifier_list pointer" << std::endl; }
#line 2752 "y.tab.c"
    break;

  case 146:
#line 339 "parser.y"
                                                        {(yyval.expr) = (yyvsp[0].expr);	}
#line 2758 "y.tab.c"
    break;

  case 148:
#line 344 "parser.y"
                                                {(yyval.expr) = (yyvsp[0].expr);	}
#line 2764 "y.tab.c"
    break;

  case 150:
#line 349 "parser.y"
                                            { (yyval.expr) = (yyvsp[-1].expr); }
#line 2770 "y.tab.c"
    break;

  case 153:
#line 355 "parser.y"
                                                                { (yyval.expr) = new IdentifierList(*(yyvsp[0].string));		}
#line 2776 "y.tab.c"
    break;

  case 154:
#line 356 "parser.y"
                                                { (yyval.expr) = new IdentifierList((yyvsp[-2].expr), *(yyvsp[0].string));	}
#line 2782 "y.tab.c"
    break;

  case 155:
#line 360 "parser.y"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr);					std::cout << "type_name -> specifier_qualifier_list" << std::endl; }
#line 2788 "y.tab.c"
    break;

  case 156:
#line 361 "parser.y"
                                                                                { (yyval.expr) = new TypeName((yyvsp[-1].expr), (yyvsp[0].expr));	std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl; }
#line 2794 "y.tab.c"
    break;

  case 157:
#line 365 "parser.y"
                                                                                        {(yyval.expr) = (yyvsp[0].expr);	}
#line 2800 "y.tab.c"
    break;

  case 158:
#line 366 "parser.y"
                                                                {(yyval.expr) = (yyvsp[0].expr);	}
#line 2806 "y.tab.c"
    break;

  case 159:
#line 367 "parser.y"
                                                        {(yyval.expr) = new AbstractDeclarator((yyvsp[-1].expr), (yyvsp[0].expr));	}
#line 2812 "y.tab.c"
    break;

  case 160:
#line 371 "parser.y"
                                                                                                {(yyval.expr) = (yyvsp[-1].expr);										}
#line 2818 "y.tab.c"
    break;

  case 161:
#line 372 "parser.y"
                                                                                                                        {(yyval.expr) = new DirectAbstractDeclarator(0);			}
#line 2824 "y.tab.c"
    break;

  case 162:
#line 373 "parser.y"
                                                                                                {(yyval.expr) = new DirectAbstractDeclarator(1, (yyvsp[-1].expr));		}
#line 2830 "y.tab.c"
    break;

  case 163:
#line 374 "parser.y"
                                                                                        {(yyval.expr) = new DirectAbstractDeclarator(2,(yyvsp[-2].expr));		}
#line 2836 "y.tab.c"
    break;

  case 164:
#line 375 "parser.y"
                                                                        {(yyval.expr) = new DirectAbstractDeclarator(3,(yyvsp[-3].expr), (yyvsp[-1].expr));	}
#line 2842 "y.tab.c"
    break;

  case 165:
#line 376 "parser.y"
                                                                                                                        {(yyval.expr) = new DirectAbstractDeclarator(4);			}
#line 2848 "y.tab.c"
    break;

  case 166:
#line 377 "parser.y"
                                                                                                {(yyval.expr) = new DirectAbstractDeclarator(5, (yyvsp[-1].expr));		}
#line 2854 "y.tab.c"
    break;

  case 167:
#line 378 "parser.y"
                                                                                        {(yyval.expr) = new DirectAbstractDeclarator(6, (yyvsp[-2].expr));		}
#line 2860 "y.tab.c"
    break;

  case 168:
#line 379 "parser.y"
                                                                        {(yyval.expr) = new DirectAbstractDeclarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));	}
#line 2866 "y.tab.c"
    break;

  case 169:
#line 383 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "initializer -> assignment_expression" << std::endl; (yyval.expr) = (yyvsp[0].expr);}
#line 2872 "y.tab.c"
    break;

  case 170:
#line 384 "parser.y"
                                                                { (yyval.expr) = new Initializer("EMPTY", (yyvsp[-1].expr));	std::cout << "initializer -> '{' initializer_list '}'" << std::endl; }
#line 2878 "y.tab.c"
    break;

  case 171:
#line 385 "parser.y"
                                                        { (yyval.expr) = new Initializer("NOTEMPTY", (yyvsp[-2].expr));	std::cout << "initializer -> '{' initializer_list ',' '}'" << std::endl; }
#line 2884 "y.tab.c"
    break;

  case 172:
#line 389 "parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr);	std::cout << "initializer_list -> initializer" << std::endl; }
#line 2890 "y.tab.c"
    break;

  case 173:
#line 390 "parser.y"
                                                        { (yyval.expr) = new InitializerList((yyvsp[-2].expr), (yyvsp[0].expr));	std::cout << "initializer_list -> initializer_list ',' initializer" << std::endl; }
#line 2896 "y.tab.c"
    break;

  case 174:
#line 394 "parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> labeled_statement" << std::endl; }
#line 2902 "y.tab.c"
    break;

  case 175:
#line 395 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> compound_statement" << std::endl; }
#line 2908 "y.tab.c"
    break;

  case 176:
#line 396 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> expression_statement" << std::endl; }
#line 2914 "y.tab.c"
    break;

  case 177:
#line 397 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> selection_statement" << std::endl; }
#line 2920 "y.tab.c"
    break;

  case 178:
#line 398 "parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> iteration_statement" << std::endl; }
#line 2926 "y.tab.c"
    break;

  case 179:
#line 399 "parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr);	std::cout << "statement -> jump_statement" << std::endl; }
#line 2932 "y.tab.c"
    break;

  case 180:
#line 403 "parser.y"
                                                                        {(yyval.expr) = new LabeledStatement(*(yyvsp[-2].string), (yyvsp[0].expr));	}
#line 2938 "y.tab.c"
    break;

  case 181:
#line 404 "parser.y"
                                                        {(yyval.expr) = new LabeledStatement(*(yyvsp[-3].string), (yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 2944 "y.tab.c"
    break;

  case 182:
#line 405 "parser.y"
                                                                        {(yyval.expr) = new LabeledStatement(*(yyvsp[-2].string), (yyvsp[0].expr));	}
#line 2950 "y.tab.c"
    break;

  case 183:
#line 409 "parser.y"
                                                                                        {											std::cout << "compound_statement -> '{' '}'" << std::endl;   }
#line 2956 "y.tab.c"
    break;

  case 184:
#line 410 "parser.y"
                                                                        {(yyval.expr) = (yyvsp[-1].expr);									std::cout << "compound_statement -> '{' statement_list '}'" << std::endl;	}
#line 2962 "y.tab.c"
    break;

  case 185:
#line 411 "parser.y"
                                                                        {(yyval.expr) = (yyvsp[-1].expr);									std::cout << "compound_statement -> '{' declaration_list '}'" << std::endl; 	}
#line 2968 "y.tab.c"
    break;

  case 186:
#line 412 "parser.y"
                                                        {(yyval.expr) = new CompoundStatement((yyvsp[-2].expr), (yyvsp[-1].expr)); 	std::cout << "compound_statement -> '{' declaration_list statement_list '}'" << std::endl;	}
#line 2974 "y.tab.c"
    break;

  case 187:
#line 416 "parser.y"
                                                                                {(yyval.expr) = (yyvsp[0].expr);									std::cout << "declaration_list -> declaration" << std::endl; }
#line 2980 "y.tab.c"
    break;

  case 188:
#line 417 "parser.y"
                                                                {(yyval.expr) = new DeclarationList((yyvsp[-1].expr), (yyvsp[0].expr));			std::cout << "declaration_list -> declaration_list declaration" << std::endl; }
#line 2986 "y.tab.c"
    break;

  case 189:
#line 421 "parser.y"
                                                                                        {(yyval.expr) = (yyvsp[0].expr);									std::cout << "statement_list -> statement" << std::endl; }
#line 2992 "y.tab.c"
    break;

  case 190:
#line 422 "parser.y"
                                                                        {(yyval.expr) = new StatementList((yyvsp[-1].expr), (yyvsp[0].expr));			std::cout << "statement_list -> statement_list statement" << std::endl; }
#line 2998 "y.tab.c"
    break;

  case 191:
#line 426 "parser.y"
                                                                                        { std::cout << "expression_statement -> ';'" << std::endl; }
#line 3004 "y.tab.c"
    break;

  case 192:
#line 427 "parser.y"
                                                                                { (yyval.expr) = (yyvsp[-1].expr); std::cout << "expression_statement -> expression ';'" << std::endl; }
#line 3010 "y.tab.c"
    break;

  case 193:
#line 431 "parser.y"
                                                                                {(yyval.expr) = new SelectionStatement(0, (yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 3016 "y.tab.c"
    break;

  case 194:
#line 432 "parser.y"
                                                                {(yyval.expr) = new SelectionStatement((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 3022 "y.tab.c"
    break;

  case 195:
#line 433 "parser.y"
                                                                        {(yyval.expr) = new SelectionStatement(1, (yyvsp[-2].expr), (yyvsp[0].expr));	}
#line 3028 "y.tab.c"
    break;

  case 196:
#line 437 "parser.y"
                                                                                                                                {(yyval.expr) = new IterationStatement(0, (yyvsp[-2].expr), (yyvsp[0].expr));	/*TODO: Implement*/}
#line 3034 "y.tab.c"
    break;

  case 197:
#line 438 "parser.y"
                                                                                                                                {(yyval.expr) = new IterationStatement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));	}
#line 3040 "y.tab.c"
    break;

  case 198:
#line 439 "parser.y"
                                                                                                        {(yyval.expr) = new IterationStatement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 3046 "y.tab.c"
    break;

  case 199:
#line 440 "parser.y"
                                                                                        {(yyval.expr) = new IterationStatement(3, (yyvsp[-4].expr), (yyvsp[-2].expr));	}
#line 3052 "y.tab.c"
    break;

  case 200:
#line 444 "parser.y"
                                                {(yyval.expr) = new JumpStatement(1, *(yyvsp[-1].string));	/*	This may or may not work	*/							}
#line 3058 "y.tab.c"
    break;

  case 201:
#line 445 "parser.y"
                                                        {(yyval.expr) = new JumpStatement(2); 																	}
#line 3064 "y.tab.c"
    break;

  case 202:
#line 446 "parser.y"
                                                                {(yyval.expr) = new JumpStatement(3); 																	}
#line 3070 "y.tab.c"
    break;

  case 203:
#line 447 "parser.y"
                                                        {(yyval.expr) = new JumpStatement(4); 																	}
#line 3076 "y.tab.c"
    break;

  case 204:
#line 448 "parser.y"
                                                {(yyval.expr) = new JumpStatement(5, (yyvsp[-1].expr));  std::cout<<"jump_statement -> RETURN expression ;"<<std::endl; }
#line 3082 "y.tab.c"
    break;

  case 205:
#line 452 "parser.y"
                                                                        { (yyval.expr) = new Translation_Unit((yyvsp[0].expr));		std::cout<<"translation_unit -> external_declaration"<<std::endl; /* Put the function in here?*/}
#line 3088 "y.tab.c"
    break;

  case 206:
#line 453 "parser.y"
                                                        { (yyval.expr) = new Translation_Unit((yyvsp[-1].expr), (yyvsp[0].expr));	std::cout<<"translation_unit -> translation_unit external_declaration"<<std::endl; /* Put the function in here?*/	}
#line 3094 "y.tab.c"
    break;

  case 207:
#line 457 "parser.y"
                                                { func_call.push_back(1); (yyval.expr) = (yyvsp[0].expr); /*new ExternalDeclaration("function" , $1); 	*/std::cout<<"external_declaration -> function_definition"<<std::endl; }
#line 3100 "y.tab.c"
    break;

  case 208:
#line 458 "parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); /*new ExternalDeclaration("declaration" , $1);*/ std::cout<<"external_declaration -> declaration"<<std::endl; }
#line 3106 "y.tab.c"
    break;

  case 209:
#line 462 "parser.y"
                                                                                                { (yyval.expr) = new FunctionDefinition((yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));		std::cout<<"1: function_definition -> declaration_specifiers declarator declaration_list compound_statement"<<std::endl; }
#line 3112 "y.tab.c"
    break;

  case 210:
#line 463 "parser.y"
                                                                                                                { (yyval.expr) = new FunctionDefinition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr), 0);		std::cout<<"2: function_definition -> declaration_specifiers declarator compound_statement"<<std::endl; }
#line 3118 "y.tab.c"
    break;

  case 211:
#line 464 "parser.y"
                                                                                                                        { (yyval.expr) = new FunctionDefinition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr), 1);		std::cout<<"3: function_definition -> declarator declaration_list compound_statement"<<std::endl; }
#line 3124 "y.tab.c"
    break;

  case 212:
#line 465 "parser.y"
                                                                                                                                        { (yyval.expr) = new FunctionDefinition((yyvsp[-1].expr), (yyvsp[0].expr));				std::cout<<"4: function_definition -> declarator compound_statement	"<<std::endl; }
#line 3130 "y.tab.c"
    break;


#line 3134 "y.tab.c"

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
#line 468 "parser.y"


#include "lex.yy.c"

void yyerror (char const *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

Expression *g_root; // Definition of variable (to match declaration earlier)

Expression *parseAST()
{
  g_root=NULL;
  yyparse();
  return g_root;
}

int main()
{
// Parse the AST
    Expression *ast = parseAST();
//Compile AST? Need function in the class

	std::map< std::string, std::pair < std::string, int > > g_Var; 		//name, <type, mem location>
	std::map< std::string, std::pair < std::string, int > > loc_Var;	//name, <type, mem location>
	std::string type_check = "update";
	int initial_memory = 0;
	bool isConstant, isLocal = 0;

	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;

	for(int i = 0; i < func_call.size(); i++)
	{
		std::cout << i << ": " << func_call[i] << std::endl;
	}

	std::string MIPS;
	
	MIPS = ast->Compile(initial_memory, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
	std::cout<<"MIPS: \n" << MIPS <<std::endl;
    return 0;
}
