/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
#line 1 "parser.y" /* yacc.c:355  */

  //#include "ast.hpp"  //  TODO: Build syntax tree
	#include <string>
	#include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 108 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DATATYPE_INT = 258,
    DATATYPE_CHAR = 259,
    DATATYPE_FLOAT = 260,
    DATATYPE_LONG = 261,
    DATATYPE_SHORT = 262,
    DATATYPE_VOID = 263,
    DATATYPE_AUTO = 264,
    DATATYPE_TYPEDEF = 265,
    DATATYPE_STRUCT = 266,
    DATATYPE_ENUM = 267,
    DATATYPE_REGISTER = 268,
    SIGNED = 269,
    UNSIGNED = 270,
    DATATYPE_DOUBLE = 271,
    TYPE_NAME = 272,
    CONST = 273,
    ELLIPSIS = 274,
    IF = 275,
    ELSE = 276,
    BREAK = 277,
    SWITCH = 278,
    CASE = 279,
    DO = 280,
    WHILE = 281,
    FOR = 282,
    CONTINUE = 283,
    GOTO = 284,
    CONDITIONAL_LT = 285,
    CONDITIONAL_LTET = 286,
    CONDITIONAL_GT = 287,
    CONDITIONAL_GTET = 288,
    CONDITIONAL_EE = 289,
    INC_OP = 290,
    DEC_OP = 291,
    PTR_OP = 292,
    AND_OP = 293,
    OR_OP = 294,
    NE_OP = 295,
    LBRACKET = 296,
    RBRACKET = 297,
    L_SQBRACKET = 298,
    R_SQBRACKET = 299,
    L_CURBRACKET = 300,
    R_CURBRACKET = 301,
    DOT = 302,
    LEFT_OP = 303,
    RIGHT_OP = 304,
    ARITHMETIC_PLUS = 305,
    ARITHMETIC_DEDUCT = 306,
    ARITHMETIC_DASH = 307,
    ARITHMETIC_E = 308,
    MUL_ASSIGN = 309,
    DIV_ASSIGN = 310,
    MOD_ASSIGN = 311,
    ADD_ASSIGN = 312,
    SUB_ASSIGN = 313,
    LEFT_ASSIGN = 314,
    RIGHT_ASSIGN = 315,
    AND_ASSIGN = 316,
    XOR_ASSIGN = 317,
    OR_ASSIGN = 318,
    TYPE_STAR = 319,
    TYPE_AMPERSAND = 320,
    RETURN = 321,
    SEMICOLON = 322,
    L_COMMENT_ML = 323,
    R_COMMENT_ML = 324,
    DEFAULT = 325,
    EXTERN = 326,
    SIZEOF = 327,
    STATIC = 328,
    UNION = 329,
    VOLATILE = 330,
    T_INT = 331,
    T_VARIABLE = 332,
    STRING = 333
  };
#endif
/* Tokens.  */
#define DATATYPE_INT 258
#define DATATYPE_CHAR 259
#define DATATYPE_FLOAT 260
#define DATATYPE_LONG 261
#define DATATYPE_SHORT 262
#define DATATYPE_VOID 263
#define DATATYPE_AUTO 264
#define DATATYPE_TYPEDEF 265
#define DATATYPE_STRUCT 266
#define DATATYPE_ENUM 267
#define DATATYPE_REGISTER 268
#define SIGNED 269
#define UNSIGNED 270
#define DATATYPE_DOUBLE 271
#define TYPE_NAME 272
#define CONST 273
#define ELLIPSIS 274
#define IF 275
#define ELSE 276
#define BREAK 277
#define SWITCH 278
#define CASE 279
#define DO 280
#define WHILE 281
#define FOR 282
#define CONTINUE 283
#define GOTO 284
#define CONDITIONAL_LT 285
#define CONDITIONAL_LTET 286
#define CONDITIONAL_GT 287
#define CONDITIONAL_GTET 288
#define CONDITIONAL_EE 289
#define INC_OP 290
#define DEC_OP 291
#define PTR_OP 292
#define AND_OP 293
#define OR_OP 294
#define NE_OP 295
#define LBRACKET 296
#define RBRACKET 297
#define L_SQBRACKET 298
#define R_SQBRACKET 299
#define L_CURBRACKET 300
#define R_CURBRACKET 301
#define DOT 302
#define LEFT_OP 303
#define RIGHT_OP 304
#define ARITHMETIC_PLUS 305
#define ARITHMETIC_DEDUCT 306
#define ARITHMETIC_DASH 307
#define ARITHMETIC_E 308
#define MUL_ASSIGN 309
#define DIV_ASSIGN 310
#define MOD_ASSIGN 311
#define ADD_ASSIGN 312
#define SUB_ASSIGN 313
#define LEFT_ASSIGN 314
#define RIGHT_ASSIGN 315
#define AND_ASSIGN 316
#define XOR_ASSIGN 317
#define OR_ASSIGN 318
#define TYPE_STAR 319
#define TYPE_AMPERSAND 320
#define RETURN 321
#define SEMICOLON 322
#define L_COMMENT_ML 323
#define R_COMMENT_ML 324
#define DEFAULT 325
#define EXTERN 326
#define SIZEOF 327
#define STATIC 328
#define UNION 329
#define VOLATILE 330
#define T_INT 331
#define T_VARIABLE 332
#define STRING 333

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:355  */

  const Expression *expr;
  int int_numb;
  double double_num;
  float float_num;
  std::string *string;

#line 284 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 301 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   1425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   333

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,    82,     2,     2,
       2,     2,     2,     2,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,     2,
       2,     2,     2,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    84,     2,    80,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    74,    75,    76,    80,    81,    82,    83,
      84,    85,    86,    87,    91,    92,    96,    97,    98,    99,
     100,   101,   105,   106,   107,   108,   109,   110,   114,   115,
     119,   120,   121,   122,   126,   127,   128,   132,   133,   134,
     138,   139,   140,   141,   142,   146,   147,   148,   152,   153,
     157,   158,   162,   163,   167,   168,   172,   173,   177,   178,
     182,   183,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   201,   202,   206,   210,   211,   215,   216,
     217,   218,   219,   220,   224,   225,   229,   230,   234,   235,
     236,   237,   238,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   257,   258,   259,   263,   264,
     268,   269,   273,   277,   278,   279,   280,   284,   285,   289,
     290,   291,   295,   296,   297,   301,   302,   306,   307,   311,
     312,   316,   317,   321,   322,   323,   324,   325,   326,   327,
     331,   332,   333,   334,   338,   339,   344,   345,   349,   350,
     354,   355,   356,   360,   361,   365,   366,   370,   371,   372,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   388,
     389,   390,   394,   395,   399,   400,   401,   402,   403,   404,
     408,   409,   410,   414,   415,   416,   417,   421,   422,   426,
     427,   431,   432,   436,   437,   438,   442,   443,   444,   445,
     449,   450,   451,   452,   453,   457,   458,   462,   463,   467,
     468,   469,   470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATATYPE_INT", "DATATYPE_CHAR",
  "DATATYPE_FLOAT", "DATATYPE_LONG", "DATATYPE_SHORT", "DATATYPE_VOID",
  "DATATYPE_AUTO", "DATATYPE_TYPEDEF", "DATATYPE_STRUCT", "DATATYPE_ENUM",
  "DATATYPE_REGISTER", "SIGNED", "UNSIGNED", "DATATYPE_DOUBLE",
  "TYPE_NAME", "CONST", "ELLIPSIS", "IF", "ELSE", "BREAK", "SWITCH",
  "CASE", "DO", "WHILE", "FOR", "CONTINUE", "GOTO", "CONDITIONAL_LT",
  "CONDITIONAL_LTET", "CONDITIONAL_GT", "CONDITIONAL_GTET",
  "CONDITIONAL_EE", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "NE_OP", "LBRACKET", "RBRACKET", "L_SQBRACKET", "R_SQBRACKET",
  "L_CURBRACKET", "R_CURBRACKET", "DOT", "LEFT_OP", "RIGHT_OP",
  "ARITHMETIC_PLUS", "ARITHMETIC_DEDUCT", "ARITHMETIC_DASH",
  "ARITHMETIC_E", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_STAR", "TYPE_AMPERSAND", "RETURN", "SEMICOLON",
  "L_COMMENT_ML", "R_COMMENT_ML", "DEFAULT", "EXTERN", "SIZEOF", "STATIC",
  "UNION", "VOLATILE", "T_INT", "T_VARIABLE", "STRING", "','", "'~'",
  "'!'", "'%'", "'^'", "'|'", "'?'", "':'", "$accept",
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
  "jump_statement", "ROOT", "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    44,
     126,    33,    37,    94,   124,    63,    58
};
# endif

#define YYPACT_NINF -203

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-203)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     644,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
     137,  -203,  -203,  -203,  -203,  -203,  -203,   110,    -9,  -203,
    -203,  -203,  -203,  -203,  -203,   139,   878,   878,  -203,   141,
    -203,   878,   772,    32,    -3,   553,  -203,  -203,    53,    25,
     -22,  -203,  -203,    -9,  -203,    61,  -203,   756,  -203,  -203,
     279,    88,  -203,   316,  -203,   139,  -203,   772,   660,  1107,
      32,  -203,  -203,   140,    45,  -203,    53,  -203,  -203,  -203,
    -203,   110,  1141,  -203,   772,   279,   894,  -203,     3,   279,
     279,   100,   123,   157,  1306,  1089,   176,   178,   154,   147,
    1324,  1324,   474,  -203,  -203,  -203,  -203,  -203,  1159,  -203,
     145,  1344,  -203,   152,  -203,  -203,  -203,  -203,   102,   217,
    1306,  -203,   159,    36,    99,   204,   -18,   180,   160,   163,
     211,   -28,  -203,  -203,    65,  -203,  -203,  -203,   395,   965,
    -203,  -203,  -203,  -203,   198,  -203,  -203,  -203,  -203,    49,
     216,   174,  -203,   -25,  -203,  -203,  -203,  -203,   215,  1306,
    -203,    53,    71,  -203,  1141,  -203,  -203,  -203,  -203,  -203,
    -203,  1306,   117,  -203,   179,  -203,   959,  1306,  -203,  1306,
     182,   236,  1306,  1179,  -203,   197,  1306,  -203,  -203,    -2,
     151,   224,  -203,   121,  1089,   474,  -203,  1089,  -203,  -203,
     221,  1212,  1306,   223,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  1306,  -203,  1306,  1306,  1306,
    1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
    1306,  1306,  1306,  1306,  1306,  1306,  -203,  1306,  -203,  1027,
    -203,  -203,   569,  1230,  -203,     7,  -203,   148,  -203,   845,
    -203,   225,  -203,  -203,  -203,  -203,  -203,    96,  -203,  -203,
       3,  1306,  -203,     9,    21,  1089,   240,    27,  1179,  -203,
    -203,   683,   161,  -203,  1306,  -203,  -203,   246,  -203,  -203,
    -203,    29,  -203,   -15,  -203,  -203,  -203,  -203,  -203,   159,
     159,    36,    36,    99,    99,    99,    99,   204,   204,   -18,
     180,   160,   163,   211,    -7,  -203,  -203,  -203,   250,   266,
    -203,   265,   148,   862,  1268,  -203,  -203,  -203,  -203,   761,
    -203,  -203,  1089,  1089,  -203,  1306,  1089,  1286,  -203,  -203,
    -203,  1306,  -203,  1306,  -203,  -203,  -203,  -203,   268,  -203,
     267,  -203,  -203,   291,  -203,    39,  -203,  1089,    41,  -203,
    -203,  -203,  -203,  1089,   247,  -203,  1089,  -203,  -203,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    94,    98,    97,    95,    93,    91,    88,   108,
       0,    92,   100,   101,    99,   104,   129,     0,   140,    89,
      90,   109,   130,   133,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,     0,   124,
       0,   144,   142,   141,    76,     0,    84,    86,    79,    81,
       0,   107,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,   127,     0,   125,     0,   134,   145,   143,
      77,     0,     0,   210,     0,   114,     0,   110,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,    24,    25,    23,    22,     0,   191,
       0,     0,     3,     2,     4,    26,    27,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   139,   153,   152,
       0,   146,   148,     0,   136,     2,    28,    75,     0,     0,
     122,     0,     0,    85,     0,   169,    87,   209,   113,   106,
     111,     0,     0,   117,   119,   115,     0,     0,   202,     0,
       0,     0,     0,     0,   201,     0,     0,    17,    18,     0,
     155,     0,   203,     0,     0,     0,    20,     0,    12,    13,
       0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   128,   126,   123,   172,     0,   120,   112,
       0,     0,   105,     0,     0,     0,     0,     0,     0,   200,
       5,     0,   157,   156,     0,   204,   182,     0,   180,    11,
       8,     0,    14,     0,    10,    61,    32,    31,    33,    35,
      36,    38,    39,    41,    43,    42,    44,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,   170,     0,
     118,   121,     0,     0,   181,     0,     0,     0,    29,    21,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,     0,   196,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,  -203,   -54,  -203,   -86,  -169,    14,    90,
      37,    93,    94,    95,   112,    92,  -203,   -56,   -20,  -203,
     -73,   -52,     8,     0,  -203,   275,  -203,   133,  -203,  -203,
     257,   -64,   -69,  -203,    97,  -203,   282,   199,    35,   -10,
     -30,    -4,  -203,   -57,  -203,   116,  -203,   164,  -118,  -202,
    -136,  -203,   -83,  -203,     2,    78,   228,  -160,  -203,  -203,
    -203,  -203,   323,  -203
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      76,    77,    78,   162,   163,    30,    64,    65,    31,    32,
      33,    34,    43,   298,   141,   142,   143,   181,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      25,   140,   171,   147,    60,   146,   158,    40,    24,    16,
     165,   224,   160,   258,    42,    47,   218,   240,   246,   179,
      67,   236,   219,   180,   206,   183,    48,    49,   147,   322,
     146,    52,   170,   302,    56,    25,   177,   178,    17,    69,
     260,   279,   280,    24,    17,   134,   231,   186,   232,    73,
     233,   312,   155,    41,   241,    18,   146,   225,   139,   136,
     302,   134,   263,   313,   227,   135,    22,    18,   164,   316,
      66,   320,   227,    58,    23,    59,   157,   227,    68,   323,
      23,   344,   135,   346,    23,    79,   210,   211,   227,   161,
     232,   150,   233,   147,   253,   146,   254,   243,   317,   257,
     227,   266,   160,   179,   268,   147,   227,   146,   321,   248,
      79,    79,   179,    18,    79,    79,   180,   245,   227,   273,
     227,   276,   277,   278,   151,    74,    23,    79,    70,   234,
      63,   128,   226,    80,   155,   235,   135,   188,   189,   190,
      71,   167,   308,   191,   227,   192,   231,   212,   213,   193,
     151,    17,   294,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   272,   314,   332,    18,   309,   262,   147,   318,   146,
      17,   301,    38,    75,   249,   275,    50,    23,   265,   303,
     168,   304,   261,   149,   233,   147,   250,   146,   169,   311,
     227,    79,   261,    18,   233,    60,    44,   295,    75,    75,
     146,   207,    75,    75,    39,    18,    23,   172,    51,   173,
      79,   174,    40,   208,   175,    75,   281,   282,   235,   333,
     334,   184,   139,   336,   214,   215,   216,   217,   187,   139,
     164,   209,   335,   221,   338,   220,   328,   222,   147,   223,
     146,    72,   330,   239,   345,   287,   288,   262,   238,   242,
     347,   139,   256,   349,   259,   251,   264,   340,   255,   146,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   315,     1,     2,     3,     4,     5,     6,   319,   155,
       9,    10,   324,    12,    13,    14,    15,    16,   269,    75,
     274,   339,   307,   139,   283,   284,   285,   286,   325,   326,
     341,   342,   343,   289,   348,   290,   293,   291,    75,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   292,    81,   166,    82,    83,
      84,    85,    86,    87,    88,    89,   153,   310,   152,   267,
     244,    90,    91,    21,    22,   306,   229,    92,    62,     0,
       0,    53,    93,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,     0,     0,   100,    19,   101,    20,
      21,    22,   102,   103,   104,     0,   105,   106,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,    81,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,     0,    92,     0,     0,     0,
      53,   228,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,     0,     0,   100,    19,   101,    20,    21,
      22,   102,   103,   104,     0,   105,   106,     1,     2,     3,
       4,     5,     6,     0,     0,     9,    10,     0,    12,    13,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,   101,     0,    21,    22,
     102,   145,   104,    61,   105,   106,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   297,   233,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,     0,
      23,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,     0,    23,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     0,    17,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   137,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
       0,    23,     0,     0,   261,   297,   233,     0,     0,     0,
       0,    19,     0,    20,    21,    22,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,    53,    92,     0,     0,     0,   154,   331,     0,    72,
       0,    94,    95,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    19,     0,    20,
      21,    22,     0,   101,     0,     0,     0,   102,   145,   104,
       0,   105,   106,    19,     0,    20,    21,    22,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   305,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     1,     2,     3,
       4,     5,     6,     0,   327,     9,    10,     0,    12,    13,
      14,    15,    16,     0,     0,     0,    19,     0,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,    21,    22,
       9,    10,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,    81,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,   252,    92,     0,     0,     0,
      53,   230,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,    21,    22,   100,     0,   101,     0,     0,
       0,   102,   103,   104,     0,   105,   106,    81,     0,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,    92,     0,
       0,     0,    53,   296,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,     0,     0,   100,     0,   101,
       0,     0,     0,   102,   103,   104,     0,   105,   106,    81,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
      92,     0,     0,     0,    53,     0,     0,     0,     0,    94,
      95,     0,    90,    91,     0,     0,     0,     0,    92,     0,
       0,   144,     0,    96,    97,    98,    99,    94,    95,   100,
       0,   101,     0,     0,     0,   102,   103,   104,     0,   105,
     106,    96,    97,     0,     0,     0,    90,    91,     0,   101,
       0,     0,    92,   102,   145,   104,   154,   105,   106,     0,
       0,    94,    95,     0,    90,    91,     0,     0,     0,     0,
      92,     0,     0,     0,     0,    96,    97,     0,     0,    94,
      95,     0,     0,   101,    90,    91,     0,   102,   145,   104,
      92,   105,   106,    96,    97,     0,   182,     0,     0,    94,
      95,   101,     0,     0,     0,   102,   145,   104,     0,   105,
     106,     0,     0,    96,    97,     0,    99,    90,    91,     0,
       0,   101,     0,    92,   270,   102,   145,   104,     0,   105,
     106,     0,    94,    95,     0,    90,    91,     0,     0,     0,
       0,    92,     0,     0,   300,     0,    96,    97,     0,     0,
      94,    95,     0,     0,   101,     0,     0,     0,   102,   145,
     104,     0,   105,   106,    96,    97,     0,     0,     0,     0,
       0,     0,   101,    90,    91,     0,   102,   145,   104,    92,
     105,   106,   329,     0,     0,     0,     0,     0,    94,    95,
       0,    90,    91,     0,     0,     0,     0,    92,   337,     0,
       0,     0,    96,    97,     0,     0,    94,    95,     0,     0,
     101,    90,    91,     0,   102,   145,   104,    92,   105,   106,
      96,    97,     0,     0,     0,     0,    94,    95,   101,    90,
      91,     0,   102,   145,   104,   176,   105,   106,     0,     0,
      96,    97,     0,     0,    94,    95,     0,     0,   101,    90,
      91,     0,   102,   145,   104,   185,   105,   106,    96,    97,
       0,     0,     0,     0,    94,    95,   101,     0,     0,     0,
     102,   145,   104,     0,   105,   106,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
     102,   145,   104,     0,   105,   106
};

static const yytype_int16 yycheck[] =
{
       0,    58,    85,    59,    34,    59,    75,    17,     0,    18,
      79,    39,    76,   173,    18,    25,    34,    42,   154,    92,
      42,   139,    40,    92,   110,    98,    26,    27,    84,    44,
      84,    31,    84,   235,    32,    35,    90,    91,    41,    43,
      42,   210,   211,    35,    41,    55,   129,   101,    41,    47,
      43,    42,    72,    18,    79,    64,   110,    85,    58,    57,
     262,    71,   180,    42,    79,    57,    75,    64,    78,    42,
      45,    42,    79,    41,    77,    43,    74,    79,    43,    86,
      77,    42,    74,    42,    77,    50,    50,    51,    79,    86,
      41,    46,    43,   149,   167,   149,   169,   149,   258,   172,
      79,   184,   166,   176,   187,   161,    79,   161,    79,   161,
      75,    76,   185,    64,    79,    80,   185,    46,    79,   192,
      79,   207,   208,   209,    79,    47,    77,    92,    67,   139,
      77,    53,    67,    45,   154,   139,   128,    35,    36,    37,
      79,    41,    46,    41,    79,    43,   229,    48,    49,    47,
      79,    41,   225,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   191,   255,   309,    64,    79,   180,   233,   264,   233,
      41,   233,    45,    50,    67,   205,    45,    77,    67,    41,
      67,    43,    41,    53,    43,   251,    79,   251,    41,   251,
      79,   166,    41,    64,    43,   235,    67,   227,    75,    76,
     264,    52,    79,    80,    77,    64,    77,    41,    77,    41,
     185,    67,   232,    64,    77,    92,   212,   213,   232,   312,
     313,    86,   232,   316,    30,    31,    32,    33,    86,   239,
     250,    82,   315,    83,   317,    65,   303,    84,   304,    38,
     304,    53,   304,    79,   337,   218,   219,   261,    42,    44,
     343,   261,    26,   346,    67,    86,    42,   323,    86,   323,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    41,     3,     4,     5,     6,     7,     8,    42,   309,
      11,    12,    42,    14,    15,    16,    17,    18,    77,   166,
      77,   321,    77,   303,   214,   215,   216,   217,    42,    44,
      42,    44,    21,   220,    67,   221,   224,   222,   185,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   223,    20,    80,    22,    23,
      24,    25,    26,    27,    28,    29,    71,   250,    66,   185,
     151,    35,    36,    74,    75,   239,   128,    41,    35,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    78,     0,    80,    81,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    73,    74,    75,    -1,
      77,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    74,    75,    -1,    77,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    42,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    74,    75,
      -1,    77,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    71,    -1,    73,    74,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    73,    74,    75,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    45,    41,    -1,    -1,    -1,    45,    46,    -1,    53,
      -1,    50,    51,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    71,    -1,    73,
      74,    75,    -1,    72,    -1,    -1,    -1,    76,    77,    78,
      -1,    80,    81,    71,    -1,    73,    74,    75,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     3,     4,     5,
       6,     7,     8,    -1,    42,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    71,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    73,    74,    75,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    74,    75,
      11,    12,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    46,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    74,    75,    70,    -1,    72,    -1,    -1,
      -1,    76,    77,    78,    -1,    80,    81,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    77,    78,    -1,    80,    81,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,    64,    65,    66,    67,    50,    51,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81,    64,    65,    -1,    -1,    -1,    35,    36,    -1,    72,
      -1,    -1,    41,    76,    77,    78,    45,    80,    81,    -1,
      -1,    50,    51,    -1,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    50,
      51,    -1,    -1,    72,    35,    36,    -1,    76,    77,    78,
      41,    80,    81,    64,    65,    -1,    67,    -1,    -1,    50,
      51,    72,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81,    -1,    -1,    64,    65,    -1,    67,    35,    36,    -1,
      -1,    72,    -1,    41,    42,    76,    77,    78,    -1,    80,
      81,    -1,    50,    51,    -1,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    64,    65,    -1,    -1,
      50,    51,    -1,    -1,    72,    -1,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    35,    36,    -1,    76,    77,    78,    41,
      80,    81,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    35,    36,    -1,    -1,    -1,    -1,    41,    42,    -1,
      -1,    -1,    64,    65,    -1,    -1,    50,    51,    -1,    -1,
      72,    35,    36,    -1,    76,    77,    78,    41,    80,    81,
      64,    65,    -1,    -1,    -1,    -1,    50,    51,    72,    35,
      36,    -1,    76,    77,    78,    41,    80,    81,    -1,    -1,
      64,    65,    -1,    -1,    50,    51,    -1,    -1,    72,    35,
      36,    -1,    76,    77,    78,    41,    80,    81,    64,    65,
      -1,    -1,    -1,    -1,    50,    51,    72,    -1,    -1,    -1,
      76,    77,    78,    -1,    80,    81,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    77,    78,    -1,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    41,    64,    71,
      73,    74,    75,    77,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   148,   149,   150,    45,    77,
     126,   125,   128,   129,    67,   111,   112,   126,   110,   110,
      45,    77,   110,    45,   109,   110,   141,   142,    41,    43,
     127,     0,   149,    77,   123,   124,    45,    42,   125,   128,
      67,    79,    53,   141,   142,   114,   117,   118,   119,   125,
      45,    20,    22,    23,    24,    25,    26,    27,    28,    29,
      35,    36,    41,    46,    50,    51,    64,    65,    66,    67,
      70,    72,    76,    77,    78,    80,    81,    88,    89,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   107,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   126,   109,   141,    42,    77,   110,
     130,   131,   132,   133,    44,    77,    91,   104,   108,    53,
      46,    79,   123,   112,    45,   105,   137,   141,   119,    46,
     118,    86,   120,   121,   126,   119,   117,    41,    67,    41,
     108,   139,    41,    41,    67,    77,    41,    91,    91,   107,
     119,   134,    67,   107,    86,    41,    91,    86,    35,    36,
      37,    41,    43,    47,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   106,    93,    52,    64,    82,
      50,    51,    48,    49,    30,    31,    32,    33,    34,    40,
      65,    83,    84,    38,    39,    85,    67,    79,    46,   143,
      46,   139,    41,    43,   126,   128,   135,   136,    42,    79,
      42,    79,    44,   108,   124,    46,   137,   138,   108,    67,
      79,    86,    46,   107,   107,    86,    26,   107,   144,    67,
      42,    41,   128,   135,    42,    67,   139,   134,   139,    77,
      42,    90,   105,   107,    77,   105,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    97,    98,
      99,   100,   101,   102,   107,   105,    46,    42,   130,   135,
      44,   108,   136,    41,    43,    19,   132,    77,    46,    79,
     121,   108,    42,    42,   139,    41,    42,   144,    93,    42,
      42,    79,    44,    86,    42,    42,    44,    42,   130,    44,
     108,    46,   137,   139,   139,   107,   139,    42,   107,   105,
     104,    42,    44,    21,    42,   139,    42,   139,    67,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   137,
     137,   137,   138,   138,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   141,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   150
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
      
#line 1877 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 473 "parser.y" /* yacc.c:1906  */

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
