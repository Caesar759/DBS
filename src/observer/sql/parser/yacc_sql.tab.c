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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t having_length;
  size_t orderby_length;
  size_t groupby_length;
  size_t aggrfunc_length;
  size_t from_length;
  size_t value_length;
  size_t project_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  Condition havings[MAX_NUM];
  OrderBy orderbys[MAX_NUM];
  GroupBy groupbys[MAX_NUM];
  Relation froms[MAX_NUM];
  ProjectCol projects[MAX_NUM];
  CompOp comp;
	char id[MAX_NUM];
  AggrFuncType aggrfunctype;
} ParserContext;

typedef struct _FromInfo {
  int from_len;
  int inner_join_conditions_len;
} FromInfo;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

//从字符串指定位置开始，查找指定字符第一次出现的位置
int find(const char *s, int b, const char *t)
{
  int i;
  for (i = b; i < strlen(s); i++) {
		if (s[i] == *t)	return i;
  }
  return -1;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->orderby_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->having_length = 0;
  context->groupby_length = 0;
  context->aggrfunc_length = 0;
  context->project_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 161 "yacc_sql.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    INDEX = 263,
    INNER = 264,
    JOIN = 265,
    SELECT = 266,
    DESC = 267,
    ASC = 268,
    SHOW = 269,
    SYNC = 270,
    INSERT = 271,
    DELETE = 272,
    UPDATE = 273,
    LBRACE = 274,
    RBRACE = 275,
    COMMA = 276,
    TRX_BEGIN = 277,
    TRX_COMMIT = 278,
    TRX_ROLLBACK = 279,
    INT_T = 280,
    STRING_T = 281,
    DATE_T = 282,
    FLOAT_T = 283,
    ORDER = 284,
    GROUP = 285,
    BY = 286,
    IN = 287,
    EXISTS = 288,
    HAVING = 289,
    AGGR_MAX = 290,
    AGGR_MIN = 291,
    AGGR_SUM = 292,
    AGGR_AVG = 293,
    AGGR_COUNT = 294,
    HELP = 295,
    EXIT = 296,
    DOT = 297,
    INTO = 298,
    VALUES = 299,
    FROM = 300,
    WHERE = 301,
    AND = 302,
    SET = 303,
    ON = 304,
    LOAD = 305,
    DATA = 306,
    INFILE = 307,
    NOT = 308,
    LIKE = 309,
    UNIQUE = 310,
    ADD = 311,
    SUB = 312,
    MUL = 313,
    DIV = 314,
    IS = 315,
    NULL_VALUE = 316,
    NULLABLE = 317,
    EQ = 318,
    LT = 319,
    GT = 320,
    LE = 321,
    GE = 322,
    NE = 323,
    LENGTH = 324,
    ROUND = 325,
    DATE_FORMAT = 326,
    NUMBER = 327,
    FLOAT = 328,
    ID = 329,
    PATH = 330,
    SSS = 331,
    STAR = 332,
    STRING_V = 333,
    DATE_STR = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 168 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  struct _UnaryExpr* uexp1;
  struct _Expr* exp1;
  struct _Expr* exp2;
  struct _Expr* exp3;
  struct _Expr* exp4;
  struct _Expr* exp5;
  struct _Expr* exp6;
  struct _Expr* exp7;
  struct _FromInfo* from_info;
  char *string;
  int number;
  float floats;
	char *position;
  int cur_len;
  int comp_op;

#line 314 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

#define YYUNDEFTOK  2
#define YYMAXUTOK   334


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   228,   228,   230,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   255,   260,   265,   271,   277,   283,   289,   295,
     301,   308,   316,   321,   328,   330,   336,   343,   350,   359,
     361,   365,   376,   387,   394,   401,   408,   417,   420,   421,
     422,   423,   426,   435,   441,   443,   447,   458,   470,   473,
     480,   483,   498,   505,   515,   516,   523,   533,   539,   553,
     567,   573,   579,   585,   594,   602,   609,   618,   627,   631,
     634,   637,   640,   645,   648,   651,   654,   657,   663,   671,
     693,   703,   713,   723,   735,   777,   780,   783,   786,   789,
     793,   803,   809,   819,   829,   861,   868,   875,   883,   887,
     894,   901,   910,   918,   924,   929,   937,   940,   945,   948,
     954,   957,   963,   966,   971,   974,   981,   982,   983,   984,
     985,   986,   987,   988,   991,  1000,  1009,  1018,  1027,  1036,
    1046,  1050,  1056,  1059,  1066,  1073,  1082,  1086,  1092,  1095,
    1102
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "INNER", "JOIN", "SELECT", "DESC", "ASC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "DATE_T",
  "FLOAT_T", "ORDER", "GROUP", "BY", "IN", "EXISTS", "HAVING", "AGGR_MAX",
  "AGGR_MIN", "AGGR_SUM", "AGGR_AVG", "AGGR_COUNT", "HELP", "EXIT", "DOT",
  "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "ON", "LOAD", "DATA",
  "INFILE", "NOT", "LIKE", "UNIQUE", "ADD", "SUB", "MUL", "DIV", "IS",
  "NULL_VALUE", "NULLABLE", "EQ", "LT", "GT", "LE", "GE", "NE", "LENGTH",
  "ROUND", "DATE_FORMAT", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "DATE_STR", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "desc_table", "show_index", "create_index", "id_list", "id",
  "drop_index", "create_table", "attr_def_list", "attr_def", "number",
  "type", "ID_get", "insert", "row_value_list", "row_value",
  "sub_select_list", "value_list", "mul_expr", "add_expr", "condition",
  "having_condition", "unary_expr", "aggr_func_type", "aggr_func_expr",
  "func_expr", "sub_select", "value", "delete", "update", "select",
  "select_attr", "attr_list", "from", "rel_list", "inner_join_conditions",
  "where", "condition_list", "opt_having", "having_condition_list",
  "comOp", "sort_unit", "sort_list", "opt_order_by", "groupby_unit",
  "groupby_list", "opt_group_by", "load_data", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};
# endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -234,   327,  -234,     2,   109,    49,   -41,    19,    71,    46,
      64,    57,    93,   113,   124,   130,   147,   101,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,    84,    85,   145,
      89,    91,    -7,  -234,  -234,  -234,  -234,  -234,   178,  -234,
     149,   150,   152,  -234,  -234,   131,  -234,   159,  -234,  -234,
     -37,    -8,  -234,   153,  -234,  -234,  -234,  -234,   138,   182,
     188,   148,  -234,   118,   120,   154,  -234,  -234,  -234,  -234,
    -234,   146,   180,   155,   126,   198,   200,    49,   163,    22,
      18,    32,  -234,  -234,  -234,   223,   223,   223,    25,   105,
    -234,   250,   250,   223,   223,  -234,   151,   133,  -234,  -234,
     135,   166,   165,   144,   143,   157,   158,   187,  -234,  -234,
     184,   164,  -234,    88,   217,  -234,  -234,    24,    -1,    79,
    -234,   159,   199,   159,    -8,  -234,  -234,   -37,   -37,   220,
      41,    14,   165,   240,   225,   223,   242,   183,   210,  -234,
     234,    86,   237,   189,   133,   243,  -234,  -234,  -234,   223,
     223,  -234,    74,  -234,  -234,  -234,  -234,   255,   192,  -234,
     238,  -234,    88,   246,   322,   224,  -234,    88,   264,   157,
     252,  -234,  -234,  -234,  -234,   -10,   201,   254,   165,  -234,
      51,    73,   159,   202,    14,   251,   247,   243,   225,   271,
     223,   223,   -18,  -234,    42,  -234,  -234,  -234,  -234,  -234,
    -234,   223,   223,  -234,   165,   203,   234,   280,   218,   230,
    -234,  -234,   277,   201,   238,  -234,  -234,  -234,   256,  -234,
     226,   223,   272,   283,   246,  -234,    82,    82,   223,   223,
    -234,   245,  -234,    82,   224,   301,   305,  -234,  -234,  -234,
     289,  -234,   201,   290,   277,   247,   223,    14,   270,   292,
    -234,   306,   267,   284,   313,  -234,  -234,    82,    82,  -234,
    -234,  -234,  -234,   -28,   277,   314,   298,   272,   224,  -234,
     259,   226,   274,   223,   223,  -234,   260,  -234,   269,  -234,
    -234,  -234,   332,   316,  -234,  -234,  -234,    82,   267,     4,
     304,  -234,  -234,  -234,  -234,  -234,  -234,  -234,   263,   260,
     134,  -234,  -234,  -234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,     0,   101,
       0,     0,     0,    95,    97,    76,    99,   108,   100,    82,
      64,   108,    60,     0,    80,    79,    81,    75,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,    27,    23,
      22,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      75,     0,    95,    97,    61,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,   107,     0,     0,    30,    29,
       0,     0,   118,     0,     0,     0,     0,     0,    28,    37,
       0,     0,    78,     0,     0,    96,    98,     0,     0,     0,
      77,   108,    76,   108,   108,    63,    62,    65,    66,     0,
       0,   113,   118,     0,     0,     0,     0,     0,     0,    52,
      39,     0,     0,     0,     0,    58,    57,    90,    91,     0,
       0,   106,     0,   109,   111,    89,    88,     0,     0,   112,
     148,    31,     0,    54,     0,   120,   102,     0,     0,     0,
       0,    48,    49,    51,    50,    42,     0,     0,   118,    59,
       0,     0,   108,     0,   113,     0,   122,    58,     0,     0,
       0,     0,     0,   132,     0,   126,   127,   128,   129,   130,
     131,     0,     0,   119,   118,     0,    39,     0,     0,     0,
      46,    36,    34,     0,   148,    92,    93,   110,   116,   114,
       0,     0,   142,     0,    54,    53,    70,    72,     0,     0,
     133,     0,    68,    67,   120,     0,     0,    40,    38,    47,
       0,    45,     0,     0,    34,   122,     0,   113,   144,   147,
     149,     0,   124,     0,     0,    56,    55,    71,    73,    69,
     121,   103,   150,    41,    34,     0,     0,   142,   120,   115,
       0,     0,     0,     0,     0,   123,     0,   104,     0,    44,
      35,    32,     0,     0,   117,   145,   146,    74,   124,   134,
     141,   143,    43,    33,    94,   125,   136,   137,     0,     0,
     135,   140,   138,   139
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -233,  -205,  -234,  -234,   132,   161,
    -234,  -234,  -234,  -234,   112,   160,  -234,  -144,    53,    -5,
    -211,    63,   -42,  -234,  -234,  -234,  -234,   -40,  -234,  -234,
    -234,   265,   -58,   207,  -187,  -234,  -137,  -220,    98,    58,
      96,  -234,    55,   103,  -234,   100,   141,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   253,   222,    30,    31,   180,   150,
     250,   185,   151,    32,   199,   173,    59,   124,    60,   174,
     175,   262,    62,    63,    64,    65,    66,    67,    33,    34,
      35,    68,   100,   142,   169,   257,   146,   213,   232,   285,
     211,   300,   301,   264,   259,   260,   196,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   244,    90,   105,    87,   170,    94,   229,    37,   218,
      38,   189,    42,    99,   238,   239,   306,   307,   254,   158,
     159,   276,   101,   167,   270,   288,    70,    71,    43,    44,
      45,    46,    47,    69,   289,   168,   240,    89,   -58,   123,
     102,   290,   122,   219,   157,   278,   308,   274,   103,   104,
      48,   224,   220,   233,    49,   103,   104,    39,   294,   135,
     136,   166,    50,    51,    52,    53,    54,    88,    42,    56,
     279,   225,    58,   161,    72,   163,   164,   245,   103,   104,
     103,   104,    61,   155,    43,    44,    45,    46,    47,    73,
     127,   128,   129,   226,   134,   241,    76,   103,   104,   130,
     160,   140,   131,   242,   125,   126,    48,   103,   104,    74,
      49,   181,   182,   183,   184,    40,    77,    41,    50,    51,
      52,    53,    54,    55,    42,    56,    57,    78,    58,   103,
     104,    75,   197,    79,   227,   103,   104,   214,   103,   104,
      43,    44,    45,    46,    47,    91,   312,   313,   130,    49,
      80,   192,    81,    84,   190,   191,   137,   138,    82,    83,
      53,    54,    48,    85,    56,    86,    49,    58,    95,    96,
      42,    97,   106,    98,    50,    51,    52,    53,    54,   132,
      99,    56,   133,   107,    58,   108,    43,    44,    45,    46,
      47,   109,   111,   110,   112,   236,   237,    42,   114,   115,
     117,   118,   113,   119,   116,   121,   243,   141,    48,   143,
     144,   145,    49,    43,    44,    45,    46,    47,   147,   148,
      50,    51,    52,    53,    54,    88,   261,    56,   139,   154,
      58,   149,   152,   267,   268,    91,   153,   156,   130,    49,
     165,   162,    42,   171,   172,   176,   177,    50,    51,    52,
      92,    93,    88,   178,    56,   179,   186,    58,    43,    44,
      45,    46,    47,   187,   123,   193,   194,   198,   195,    42,
     215,   212,   217,   223,   235,   221,   228,   246,   297,   261,
      48,   231,   230,   248,    49,    43,    44,    45,    46,    47,
     249,   251,    50,    51,    52,    53,    54,    88,   252,    56,
     258,   263,    58,   265,   271,   256,   269,    91,   272,   273,
     275,    49,   280,   281,   284,   286,   287,   291,   292,    50,
      51,    52,    53,    54,    88,   309,    56,     2,   240,    58,
     302,     3,     4,   295,   299,   303,   304,   310,     5,     6,
     216,     7,     8,     9,    10,    11,   266,   298,   247,    12,
      13,    14,   120,   277,   200,   201,   305,   283,   234,   282,
     203,   188,   103,   104,   311,   255,     0,    15,    16,   205,
     206,   207,   208,   209,   210,   202,   203,    17,   103,   104,
     293,   296,   204,     0,     0,   205,   206,   207,   208,   209,
     210
};

static const yytype_int16 yycheck[] =
{
       5,   212,    42,    61,    11,   142,    48,   194,     6,    19,
       8,   155,    19,    21,    32,    33,    12,    13,   223,    20,
      21,   254,    59,     9,   244,    53,     7,     8,    35,    36,
      37,    38,    39,    74,    62,    21,    54,    42,    20,    21,
      77,   274,    20,    53,    20,   256,    42,   252,    56,    57,
      57,   188,    62,   197,    61,    56,    57,    55,   278,   101,
     102,    20,    69,    70,    71,    72,    73,    74,    19,    76,
     257,    20,    79,   131,     3,   133,   134,   214,    56,    57,
      56,    57,    87,   123,    35,    36,    37,    38,    39,    43,
      95,    96,    97,    20,    99,    53,     3,    56,    57,    74,
      21,   106,    77,    61,    72,    73,    57,    56,    57,    45,
      61,    25,    26,    27,    28,     6,     3,     8,    69,    70,
      71,    72,    73,    74,    19,    76,    77,     3,    79,    56,
      57,    74,   172,     3,   192,    56,    57,   177,    56,    57,
      35,    36,    37,    38,    39,    57,    12,    13,    74,    61,
       3,    77,    51,     8,   159,   160,   103,   104,    74,    74,
      72,    73,    57,    74,    76,    74,    61,    79,    19,    19,
      19,    19,    19,    42,    69,    70,    71,    72,    73,    74,
      21,    76,    77,    45,    79,     3,    35,    36,    37,    38,
      39,     3,    74,    45,    74,   200,   201,    19,    52,    19,
      74,     3,    48,     3,    49,    42,   211,    74,    57,    74,
      44,    46,    61,    35,    36,    37,    38,    39,    74,    76,
      69,    70,    71,    72,    73,    74,   231,    76,    77,    45,
      79,    74,    74,   238,   239,    57,    49,    20,    74,    61,
      20,    42,    19,     3,    19,     3,    63,    69,    70,    71,
      72,    73,    74,    43,    76,    21,    19,    79,    35,    36,
      37,    38,    39,    74,    21,    10,    74,    21,    30,    19,
       6,    47,    20,    19,     3,    74,    74,    74,   283,   284,
      57,    34,    31,     3,    61,    35,    36,    37,    38,    39,
      72,    61,    69,    70,    71,    72,    73,    74,    21,    76,
      74,    29,    79,    20,     3,    49,    61,    57,     3,    20,
      20,    61,    42,    21,    47,    31,     3,     3,    20,    69,
      70,    71,    72,    73,    74,    21,    76,     0,    54,    79,
      61,     4,     5,    74,    74,     3,    20,    74,    11,    12,
     179,    14,    15,    16,    17,    18,   234,   284,   216,    22,
      23,    24,    87,   255,    32,    33,   298,   261,   198,    53,
      54,   154,    56,    57,   309,   224,    -1,    40,    41,    63,
      64,    65,    66,    67,    68,    53,    54,    50,    56,    57,
     277,   281,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,     0,     4,     5,    11,    12,    14,    15,    16,
      17,    18,    22,    23,    24,    40,    41,    50,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      96,    97,   103,   118,   119,   120,   137,     6,     8,    55,
       6,     8,    19,    35,    36,    37,    38,    39,    57,    61,
      69,    70,    71,    72,    73,    74,    76,    77,    79,   106,
     108,   109,   112,   113,   114,   115,   116,   117,   121,    74,
       7,     8,     3,    43,    45,    74,     3,     3,     3,     3,
       3,    51,    74,    74,     8,    74,    74,    11,    74,   109,
     117,    57,    72,    73,   112,    19,    19,    19,    42,    21,
     122,    59,    77,    56,    57,   122,    19,    45,     3,     3,
      45,    74,    74,    48,    52,    19,    49,    74,     3,     3,
     121,    42,    20,    21,   107,    72,    73,   109,   109,   109,
      74,    77,    74,    77,   109,   112,   112,   108,   108,    77,
     109,    74,   123,    74,    44,    46,   126,    74,    76,    74,
      99,   102,    74,    49,    45,   117,    20,    20,    20,    21,
      21,   122,    42,   122,   122,    20,    20,     9,    21,   124,
     126,     3,    19,   105,   109,   110,     3,    63,    43,    21,
      98,    25,    26,    27,    28,   101,    19,    74,   123,   107,
     109,   109,    77,    10,    74,    30,   136,   117,    21,   104,
      32,    33,    53,    54,    60,    63,    64,    65,    66,    67,
      68,   130,    47,   127,   117,     6,    99,    20,    19,    53,
      62,    74,    95,    19,   126,    20,    20,   122,    74,   124,
      31,    34,   128,   107,   105,     3,   109,   109,    32,    33,
      54,    53,    61,   109,   110,   126,    74,    98,     3,    72,
     100,    61,    21,    94,    95,   136,    49,   125,    74,   134,
     135,   109,   111,    29,   133,    20,   104,   109,   109,    61,
     127,     3,     3,    20,    95,    20,    94,   128,   110,   124,
      42,    21,    53,   130,    47,   129,    31,     3,    53,    62,
      94,     3,    20,   133,   127,    74,   135,   109,   111,    74,
     131,   132,    61,     3,    20,   129,    12,    13,    42,    21,
      74,   132,    12,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    93,    94,    94,    95,    96,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   101,   101,
     101,   101,   102,   103,   104,   104,   105,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   116,   117,   117,   117,   117,   117,
     117,   117,   118,   119,   120,   121,   121,   121,   122,   122,
     122,   122,   123,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     5,    10,    11,     0,     3,     1,     4,     8,     0,
       3,     5,     2,     7,     6,     4,     3,     1,     1,     1,
       1,     1,     1,     7,     0,     3,     4,     4,     0,     3,
       1,     2,     3,     3,     1,     3,     3,     3,     3,     4,
       3,     4,     3,     4,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     6,     6,    10,     1,     2,     1,     2,     1,
       1,     1,     5,     8,     9,     2,     4,     2,     0,     3,
       5,     3,     2,     0,     3,     5,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     2,     4,     4,
       3,     1,     0,     3,     1,     3,     3,     1,     0,     3,
       8
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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
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
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, scanner);
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
  case 22:
#line 255 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1744 "yacc_sql.tab.c"
    break;

  case 23:
#line 260 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1752 "yacc_sql.tab.c"
    break;

  case 24:
#line 265 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1760 "yacc_sql.tab.c"
    break;

  case 25:
#line 271 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1768 "yacc_sql.tab.c"
    break;

  case 26:
#line 277 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1776 "yacc_sql.tab.c"
    break;

  case 27:
#line 283 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1784 "yacc_sql.tab.c"
    break;

  case 28:
#line 289 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1793 "yacc_sql.tab.c"
    break;

  case 29:
#line 295 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1801 "yacc_sql.tab.c"
    break;

  case 30:
#line 301 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1810 "yacc_sql.tab.c"
    break;

  case 31:
#line 309 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
		}
#line 1819 "yacc_sql.tab.c"
    break;

  case 32:
#line 317 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;			//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, false, (yyvsp[-7].string), (yyvsp[-5].string));
		}
#line 1828 "yacc_sql.tab.c"
    break;

  case 33:
#line 322 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;			//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, true, (yyvsp[-7].string), (yyvsp[-5].string));
		}
#line 1837 "yacc_sql.tab.c"
    break;

  case 35:
#line 331 "yacc_sql.y"
                {
			/* Do Nothing */
		}
#line 1845 "yacc_sql.tab.c"
    break;

  case 36:
#line 337 "yacc_sql.y"
        {
		create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
	}
#line 1853 "yacc_sql.tab.c"
    break;

  case 37:
#line 344 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1862 "yacc_sql.tab.c"
    break;

  case 38:
#line 351 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1874 "yacc_sql.tab.c"
    break;

  case 40:
#line 361 "yacc_sql.y"
                                   {    }
#line 1880 "yacc_sql.tab.c"
    break;

  case 41:
#line 366 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1895 "yacc_sql.tab.c"
    break;

  case 42:
#line 377 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4, FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1910 "yacc_sql.tab.c"
    break;

  case 43:
#line 388 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-5].number), (yyvsp[-3].number), FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1921 "yacc_sql.tab.c"
    break;

  case 44:
#line 395 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number), TRUE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1932 "yacc_sql.tab.c"
    break;

  case 45:
#line 402 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1943 "yacc_sql.tab.c"
    break;

  case 46:
#line 409 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, TRUE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1954 "yacc_sql.tab.c"
    break;

  case 47:
#line 417 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1960 "yacc_sql.tab.c"
    break;

  case 48:
#line 420 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1966 "yacc_sql.tab.c"
    break;

  case 49:
#line 421 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1972 "yacc_sql.tab.c"
    break;

  case 50:
#line 422 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1978 "yacc_sql.tab.c"
    break;

  case 51:
#line 423 "yacc_sql.y"
                                  { (yyval.number)=DATES; }
#line 1984 "yacc_sql.tab.c"
    break;

  case 52:
#line 427 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1993 "yacc_sql.tab.c"
    break;

  case 53:
#line 436 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_INSERT;		//"insert";
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string));
    }
#line 2002 "yacc_sql.tab.c"
    break;

  case 55:
#line 443 "yacc_sql.y"
                                                 {
			// Do Nothing
		}
#line 2010 "yacc_sql.tab.c"
    break;

  case 56:
#line 448 "yacc_sql.y"
                {
			if (0 != inserts_append_data(&CONTEXT->ssql->sstr.insertion, CONTEXT->values, CONTEXT->value_length)) {
				return -1;
			}
			//临时变量清零
			memset(CONTEXT->values, 0, sizeof(CONTEXT->values));
      CONTEXT->value_length=0;
		}
#line 2023 "yacc_sql.tab.c"
    break;

  case 57:
#line 459 "yacc_sql.y"
    {
      Expr * expr = malloc(sizeof(Expr));
      ListExpr * lexp = malloc(sizeof(ListExpr));
      int v_length = (yyvsp[-1].cur_len) + 1;
      list_expr_init(lexp, &CONTEXT->values[CONTEXT->value_length - v_length], v_length);
      expr_init_list(expr, lexp);
      (yyval.exp7) = expr;
    }
#line 2036 "yacc_sql.tab.c"
    break;

  case 58:
#line 470 "yacc_sql.y"
               {
        (yyval.cur_len) = 0;
    }
#line 2044 "yacc_sql.tab.c"
    break;

  case 59:
#line 473 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
        (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
	  }
#line 2053 "yacc_sql.tab.c"
    break;

  case 60:
#line 480 "yacc_sql.y"
               {
      (yyval.exp2) = (yyvsp[0].exp1);
    }
#line 2061 "yacc_sql.tab.c"
    break;

  case 61:
#line 483 "yacc_sql.y"
                     {
      Value * tmp_val = malloc(sizeof(Value));
      value_init_integer(tmp_val, -1);
      UnaryExpr * tmp_uexpr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(tmp_uexpr, tmp_val);
      Expr * tmp_expr = malloc(sizeof(Expr));
      expr_init_unary(tmp_expr, tmp_uexpr);

      Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, MUL_OP, tmp_expr, (yyvsp[0].exp1));
      binary_expr_set_minus(b_expr);
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 2081 "yacc_sql.tab.c"
    break;

  case 62:
#line 498 "yacc_sql.y"
                               {
      Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, MUL_OP, (yyvsp[-2].exp2), (yyvsp[0].exp1));
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 2093 "yacc_sql.tab.c"
    break;

  case 63:
#line 505 "yacc_sql.y"
                              {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, DIV_OP, (yyvsp[-2].exp2), (yyvsp[0].exp1));
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 2105 "yacc_sql.tab.c"
    break;

  case 64:
#line 515 "yacc_sql.y"
             { (yyval.exp3) = (yyvsp[0].exp2); }
#line 2111 "yacc_sql.tab.c"
    break;

  case 65:
#line 516 "yacc_sql.y"
                            {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, ADD_OP, (yyvsp[-2].exp3), (yyvsp[0].exp2));
      expr_init_binary(expr, b_expr);
      (yyval.exp3) = expr;
    }
#line 2123 "yacc_sql.tab.c"
    break;

  case 66:
#line 523 "yacc_sql.y"
                            {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, SUB_OP, (yyvsp[-2].exp3), (yyvsp[0].exp2));
      expr_init_binary(expr, b_expr);
      (yyval.exp3) = expr;
    }
#line 2135 "yacc_sql.tab.c"
    break;

  case 67:
#line 533 "yacc_sql.y"
                           {
      Condition expr;
      condition_init(&expr, (yyvsp[-1].comp_op), (yyvsp[-2].exp3), (yyvsp[0].exp3));
      // condition_print(&expr, 0);
      CONTEXT->conditions[CONTEXT->condition_length++] = expr;
    }
#line 2146 "yacc_sql.tab.c"
    break;

  case 68:
#line 539 "yacc_sql.y"
                             {
      Value value;
      value_init_null(&value);

      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &value);

    	Expr *expr = malloc(sizeof(Expr));
      expr_init_unary(expr, u_expr);

      Condition cond;
      condition_init(&cond, IS_NULL, (yyvsp[-2].exp3), expr);
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2165 "yacc_sql.tab.c"
    break;

  case 69:
#line 553 "yacc_sql.y"
                                 {
      Value value;
      value_init_null(&value);

      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &value);

    	Expr *expr = malloc(sizeof(Expr));
      expr_init_unary(expr, u_expr);

      Condition cond;
      condition_init(&cond, IS_NOT_NULL, (yyvsp[-3].exp3), expr);
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2184 "yacc_sql.tab.c"
    break;

  case 70:
#line 567 "yacc_sql.y"
                           {
      // TODO
      Condition cond;
      condition_init(&cond, IN_OP, (yyvsp[-2].exp3), (yyvsp[0].exp3));
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2195 "yacc_sql.tab.c"
    break;

  case 71:
#line 573 "yacc_sql.y"
                               {
      // TODO
      Condition cond;
      condition_init(&cond, NOT_IN, (yyvsp[-3].exp3), (yyvsp[0].exp3));
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2206 "yacc_sql.tab.c"
    break;

  case 72:
#line 579 "yacc_sql.y"
                               {
      // TODO
      Condition cond;
      condition_init(&cond, EXISTS_OP, (yyvsp[-2].exp3), (yyvsp[0].exp3));
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2217 "yacc_sql.tab.c"
    break;

  case 73:
#line 585 "yacc_sql.y"
                                   {
      // TODO
      Condition cond;
      condition_init(&cond, NOT_EXISTS, (yyvsp[-3].exp3), (yyvsp[0].exp3));
      CONTEXT->conditions[CONTEXT->condition_length++] = cond;
    }
#line 2228 "yacc_sql.tab.c"
    break;

  case 74:
#line 594 "yacc_sql.y"
                           {
      Condition expr;
      condition_init(&expr, (yyvsp[-1].comp_op), (yyvsp[-2].exp3), (yyvsp[0].exp3));
      CONTEXT->havings[CONTEXT->having_length++] = expr;
    }
#line 2238 "yacc_sql.tab.c"
    break;

  case 75:
#line 602 "yacc_sql.y"
          {
    	Expr *expr = malloc(sizeof(Expr));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &CONTEXT->values[CONTEXT->value_length-1]);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 2250 "yacc_sql.tab.c"
    break;

  case 76:
#line 609 "yacc_sql.y"
         {
    	Expr *expr = malloc(sizeof(Expr));
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[0].string));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_attr(u_expr, &attr);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 2264 "yacc_sql.tab.c"
    break;

  case 77:
#line 618 "yacc_sql.y"
                {
    	Expr *expr = malloc(sizeof(Expr));
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_attr(u_expr, &attr);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 2278 "yacc_sql.tab.c"
    break;

  case 78:
#line 627 "yacc_sql.y"
                             {
      expr_set_with_brace((yyvsp[-1].exp3));
      (yyval.exp1) = (yyvsp[-1].exp3);
    }
#line 2287 "yacc_sql.tab.c"
    break;

  case 79:
#line 631 "yacc_sql.y"
                {
      (yyval.exp1) = (yyvsp[0].exp4);
    }
#line 2295 "yacc_sql.tab.c"
    break;

  case 80:
#line 634 "yacc_sql.y"
                     {
      (yyval.exp1) = (yyvsp[0].exp5);
    }
#line 2303 "yacc_sql.tab.c"
    break;

  case 81:
#line 637 "yacc_sql.y"
                 {
       (yyval.exp1) = (yyvsp[0].exp6);
    }
#line 2311 "yacc_sql.tab.c"
    break;

  case 82:
#line 640 "yacc_sql.y"
                     {
      (yyval.exp1) = (yyvsp[0].exp7);
    }
#line 2319 "yacc_sql.tab.c"
    break;

  case 83:
#line 645 "yacc_sql.y"
             {
      CONTEXT->aggrfunctype = MAX;
    }
#line 2327 "yacc_sql.tab.c"
    break;

  case 84:
#line 648 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = MIN;
    }
#line 2335 "yacc_sql.tab.c"
    break;

  case 85:
#line 651 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = SUM;
    }
#line 2343 "yacc_sql.tab.c"
    break;

  case 86:
#line 654 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = AVG;
    }
#line 2351 "yacc_sql.tab.c"
    break;

  case 87:
#line 657 "yacc_sql.y"
                 {
      CONTEXT->aggrfunctype = COUNT;
    }
#line 2359 "yacc_sql.tab.c"
    break;

  case 88:
#line 664 "yacc_sql.y"
    {
      AggrFuncExpr* afexpr = malloc(sizeof(AggrFuncExpr));
      aggr_func_expr_init(afexpr, CONTEXT->aggrfunctype, (yyvsp[-1].exp3));
      Expr* expr = malloc(sizeof(Expr));
      expr_init_aggr_func(expr, afexpr);
      (yyval.exp5) = expr;
    }
#line 2371 "yacc_sql.tab.c"
    break;

  case 89:
#line 672 "yacc_sql.y"
    {
      if (CONTEXT->aggrfunctype != COUNT) {
        return -1;
      }
      // regard as a string value
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], "*");

    	Expr *param = malloc(sizeof(Expr));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &CONTEXT->values[CONTEXT->value_length-1]);
      expr_init_unary(param, u_expr);

      AggrFuncExpr* afexpr = malloc(sizeof(AggrFuncExpr));
      aggr_func_expr_init(afexpr, COUNT, param);
      Expr* expr = malloc(sizeof(Expr));
      expr_init_aggr_func(expr, afexpr);
      (yyval.exp5) = expr;
    }
#line 2394 "yacc_sql.tab.c"
    break;

  case 90:
#line 694 "yacc_sql.y"
    {
      FuncExpr* fexpr = malloc(sizeof(FuncExpr));
      func_expr_init_type(fexpr, 0);
      func_expr_init_params(fexpr, (yyvsp[-1].exp3), NULL);
      Expr* expr = malloc(sizeof(Expr));
      expr_init_func(expr, fexpr);
      (yyval.exp4) = expr;
    }
#line 2407 "yacc_sql.tab.c"
    break;

  case 91:
#line 704 "yacc_sql.y"
    {
      FuncExpr* fexpr = malloc(sizeof(FuncExpr));
      func_expr_init_type(fexpr, 1);
      func_expr_init_params(fexpr, (yyvsp[-1].exp3), NULL);
      Expr* expr = malloc(sizeof(Expr));
      expr_init_func(expr, fexpr);
      (yyval.exp4) = expr;
    }
#line 2420 "yacc_sql.tab.c"
    break;

  case 92:
#line 714 "yacc_sql.y"
    {
      FuncExpr* fexpr = malloc(sizeof(FuncExpr));
      func_expr_init_type(fexpr, 1);
      func_expr_init_params(fexpr, (yyvsp[-3].exp3), (yyvsp[-1].exp3));
      Expr* expr = malloc(sizeof(Expr));
      expr_init_func(expr, fexpr);
      (yyval.exp4) = expr;
    }
#line 2433 "yacc_sql.tab.c"
    break;

  case 93:
#line 724 "yacc_sql.y"
    {
      FuncExpr* fexpr = malloc(sizeof(FuncExpr));
      func_expr_init_type(fexpr, 2);
      func_expr_init_params(fexpr, (yyvsp[-3].exp3), (yyvsp[-1].exp3));
      Expr* expr = malloc(sizeof(Expr));
      expr_init_func(expr, fexpr);
      (yyval.exp4) = expr;
    }
#line 2446 "yacc_sql.tab.c"
    break;

  case 94:
#line 735 "yacc_sql.y"
                                                                                          {
      // printf("THE SUBQUERY has %d projects %d froms %d inner_join_conditions %d conditions %d groupbys %d havings %d orderbys\n", $3, $5->from_len, $5->inner_join_conditions_len, $6, $7, $8, $9);

      Selects * sub_select = (Selects *)malloc(sizeof(Selects));
      memset(sub_select, 0 ,sizeof(Selects));

			selects_append_projects(sub_select,  &CONTEXT->projects[CONTEXT->project_length - (yyvsp[-7].cur_len)], (yyvsp[-7].cur_len));
    
      size_t from_len = (yyvsp[-5].from_info)->from_len;
      size_t inner_join_conditions_len = (yyvsp[-5].from_info)->inner_join_conditions_len;
			selects_append_froms(sub_select,  &CONTEXT->froms[CONTEXT->from_length - from_len], from_len);

      size_t all_condition_len = (yyvsp[-4].cur_len) + inner_join_conditions_len;
			selects_append_conditions(sub_select, &CONTEXT->conditions[CONTEXT->condition_length - all_condition_len], all_condition_len);

			selects_append_groupbys(sub_select, &CONTEXT->groupbys[CONTEXT->groupby_length - (yyvsp[-3].cur_len)], (yyvsp[-3].cur_len));

			selects_append_havings(sub_select, &CONTEXT->havings[CONTEXT->having_length - (yyvsp[-2].cur_len)], (yyvsp[-2].cur_len));

			selects_append_orderbys(sub_select, &CONTEXT->orderbys[CONTEXT->orderby_length - (yyvsp[-1].cur_len)], (yyvsp[-1].cur_len));

			//CONTEXT->ssql->flag=SCF_SELECT;//"select";

			CONTEXT->orderby_length -= (yyvsp[-1].cur_len);
      CONTEXT->having_length -= (yyvsp[-2].cur_len);
			CONTEXT->groupby_length -= (yyvsp[-3].cur_len);
			CONTEXT->condition_length -= all_condition_len;
      CONTEXT->from_length -= from_len;
      CONTEXT->project_length -= (yyvsp[-7].cur_len);
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;

      // TODO cons expr
      SubQueryExpr * s_expr = malloc(sizeof(SubQueryExpr));
      sub_query_expr_init(s_expr, sub_select);
      Expr* expr = malloc(sizeof(Expr));
      expr_init_sub_query(expr, s_expr);
      (yyval.exp6) = expr;
    }
#line 2490 "yacc_sql.tab.c"
    break;

  case 95:
#line 777 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2498 "yacc_sql.tab.c"
    break;

  case 96:
#line 780 "yacc_sql.y"
               {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], -((yyvsp[0].number)));
		}
#line 2506 "yacc_sql.tab.c"
    break;

  case 97:
#line 783 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2514 "yacc_sql.tab.c"
    break;

  case 98:
#line 786 "yacc_sql.y"
              {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], -((yyvsp[0].floats)));
		}
#line 2522 "yacc_sql.tab.c"
    break;

  case 99:
#line 789 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2531 "yacc_sql.tab.c"
    break;

  case 100:
#line 793 "yacc_sql.y"
                          {
			int p1 = find((yyvsp[0].string),1,"-");
			int p2 = find((yyvsp[0].string),p1+1,"-");
			char *y = substr((yyvsp[0].string),1,p1-1);							// year
			char *m = substr((yyvsp[0].string),p1+1,p2-1);						// month
			char *d = substr((yyvsp[0].string),p2+1,strlen((yyvsp[0].string))-2);		// day
			if (0 != value_init_date(&CONTEXT->values[CONTEXT->value_length++], y, m, d)){
				return -1;
			}
		}
#line 2546 "yacc_sql.tab.c"
    break;

  case 101:
#line 803 "yacc_sql.y"
                {
      value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 2554 "yacc_sql.tab.c"
    break;

  case 102:
#line 810 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2566 "yacc_sql.tab.c"
    break;

  case 103:
#line 820 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2578 "yacc_sql.tab.c"
    break;

  case 104:
#line 830 "yacc_sql.y"
                {
      // printf("THE QUERY has %d projects %d froms %d inner_join_conditions %d conditions %d groupbys %d havings %d orderbys\n\n", $2, $4->from_len, $4->inner_join_conditions_len, $5, $6, $7, $8);

			selects_append_projects(&CONTEXT->ssql->sstr.selection, CONTEXT->projects, CONTEXT->project_length);

			selects_append_froms(&CONTEXT->ssql->sstr.selection, CONTEXT->froms, CONTEXT->from_length);

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			selects_append_orderbys(&CONTEXT->ssql->sstr.selection, CONTEXT->orderbys, CONTEXT->orderby_length);

			selects_append_groupbys(&CONTEXT->ssql->sstr.selection, CONTEXT->groupbys, CONTEXT->groupby_length);

			selects_append_havings(&CONTEXT->ssql->sstr.selection, CONTEXT->havings, CONTEXT->having_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
      CONTEXT->having_length=0;
			CONTEXT->groupby_length=0;
			CONTEXT->orderby_length=0;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
      CONTEXT->project_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 2611 "yacc_sql.tab.c"
    break;

  case 105:
#line 861 "yacc_sql.y"
                   {  
			ProjectCol project_col;
			projectcol_init_star(&project_col, NULL);
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
		}
#line 2622 "yacc_sql.tab.c"
    break;

  case 106:
#line 868 "yacc_sql.y"
                         {
      ProjectCol project_col;
			projectcol_init_star(&project_col, (yyvsp[-3].string));
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2633 "yacc_sql.tab.c"
    break;

  case 107:
#line 875 "yacc_sql.y"
                      {
      ProjectCol project_col;
      projectcol_init_expr(&project_col, (yyvsp[-1].exp3));
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2644 "yacc_sql.tab.c"
    break;

  case 108:
#line 883 "yacc_sql.y"
                {
      (yyval.cur_len) = 0;
    }
#line 2652 "yacc_sql.tab.c"
    break;

  case 109:
#line 887 "yacc_sql.y"
                         {  
			ProjectCol project_col;
			projectcol_init_star(&project_col, NULL);
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
		}
#line 2663 "yacc_sql.tab.c"
    break;

  case 110:
#line 894 "yacc_sql.y"
                               {
      ProjectCol project_col;
			projectcol_init_star(&project_col, (yyvsp[-3].string));
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2674 "yacc_sql.tab.c"
    break;

  case 111:
#line 901 "yacc_sql.y"
                            {
      ProjectCol project_col;
      projectcol_init_expr(&project_col, (yyvsp[-1].exp3));
			CONTEXT->projects[CONTEXT->project_length++]=project_col;
      (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2685 "yacc_sql.tab.c"
    break;

  case 112:
#line 910 "yacc_sql.y"
                {
			CONTEXT->froms[CONTEXT->from_length++]=(yyvsp[-1].string);
      (yyval.from_info) = (yyvsp[0].from_info);
      (yyval.from_info)->from_len++;
    }
#line 2695 "yacc_sql.tab.c"
    break;

  case 113:
#line 918 "yacc_sql.y"
                {
      // new FromInfo
      (yyval.from_info) = (FromInfo*)malloc(sizeof(FromInfo));
      (yyval.from_info)->from_len = 0;
      (yyval.from_info)->inner_join_conditions_len = 0;
    }
#line 2706 "yacc_sql.tab.c"
    break;

  case 114:
#line 924 "yacc_sql.y"
                        {	
        CONTEXT->froms[CONTEXT->from_length++]=(yyvsp[-1].string);
        (yyval.from_info) = (yyvsp[0].from_info);
        (yyval.from_info)->from_len++;
		  }
#line 2716 "yacc_sql.tab.c"
    break;

  case 115:
#line 929 "yacc_sql.y"
                                                  {
        CONTEXT->froms[CONTEXT->from_length++]=(yyvsp[-2].string);
        (yyval.from_info) = (yyvsp[0].from_info);
        (yyval.from_info)->from_len++;
        (yyval.from_info)->inner_join_conditions_len += (yyvsp[-1].cur_len);
    }
#line 2727 "yacc_sql.tab.c"
    break;

  case 116:
#line 937 "yacc_sql.y"
                    {
    (yyval.cur_len) = 0;
  }
#line 2735 "yacc_sql.tab.c"
    break;

  case 117:
#line 940 "yacc_sql.y"
                                     {
    (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
	}
#line 2743 "yacc_sql.tab.c"
    break;

  case 118:
#line 945 "yacc_sql.y"
                {
      (yyval.cur_len) = 0;
    }
#line 2751 "yacc_sql.tab.c"
    break;

  case 119:
#line 948 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
        (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
			}
#line 2760 "yacc_sql.tab.c"
    break;

  case 120:
#line 954 "yacc_sql.y"
                {
      (yyval.cur_len) = 0;
    }
#line 2768 "yacc_sql.tab.c"
    break;

  case 121:
#line 957 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
        (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
			}
#line 2777 "yacc_sql.tab.c"
    break;

  case 122:
#line 963 "yacc_sql.y"
                 { 
      (yyval.cur_len) = 0;
    }
#line 2785 "yacc_sql.tab.c"
    break;

  case 123:
#line 966 "yacc_sql.y"
                                                    {	
        (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2793 "yacc_sql.tab.c"
    break;

  case 124:
#line 971 "yacc_sql.y"
                {
      (yyval.cur_len) = 0;
    }
#line 2801 "yacc_sql.tab.c"
    break;

  case 125:
#line 974 "yacc_sql.y"
                                                 {
        (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
    }
#line 2809 "yacc_sql.tab.c"
    break;

  case 126:
#line 981 "yacc_sql.y"
             { (yyval.comp_op) = EQUAL_TO; }
#line 2815 "yacc_sql.tab.c"
    break;

  case 127:
#line 982 "yacc_sql.y"
         { (yyval.comp_op) = LESS_THAN; }
#line 2821 "yacc_sql.tab.c"
    break;

  case 128:
#line 983 "yacc_sql.y"
         { (yyval.comp_op) = GREAT_THAN; }
#line 2827 "yacc_sql.tab.c"
    break;

  case 129:
#line 984 "yacc_sql.y"
         { (yyval.comp_op) = LESS_EQUAL; }
#line 2833 "yacc_sql.tab.c"
    break;

  case 130:
#line 985 "yacc_sql.y"
         { (yyval.comp_op) = GREAT_EQUAL; }
#line 2839 "yacc_sql.tab.c"
    break;

  case 131:
#line 986 "yacc_sql.y"
         { (yyval.comp_op) = NOT_EQUAL; }
#line 2845 "yacc_sql.tab.c"
    break;

  case 132:
#line 987 "yacc_sql.y"
           { (yyval.comp_op) = LIKE_OP; }
#line 2851 "yacc_sql.tab.c"
    break;

  case 133:
#line 988 "yacc_sql.y"
               { (yyval.comp_op) = NOT_LIKE_OP; }
#line 2857 "yacc_sql.tab.c"
    break;

  case 134:
#line 992 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2869 "yacc_sql.tab.c"
    break;

  case 135:
#line 1001 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2881 "yacc_sql.tab.c"
    break;

  case 136:
#line 1010 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, FALSE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2893 "yacc_sql.tab.c"
    break;

  case 137:
#line 1019 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2905 "yacc_sql.tab.c"
    break;

  case 138:
#line 1028 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, FALSE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2917 "yacc_sql.tab.c"
    break;

  case 139:
#line 1037 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2929 "yacc_sql.tab.c"
    break;

  case 140:
#line 1047 "yacc_sql.y"
                {
    (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
	}
#line 2937 "yacc_sql.tab.c"
    break;

  case 141:
#line 1051 "yacc_sql.y"
                {
    (yyval.cur_len) = 1;
	}
#line 2945 "yacc_sql.tab.c"
    break;

  case 142:
#line 1056 "yacc_sql.y"
                    {
   (yyval.cur_len) = 0;
  }
#line 2953 "yacc_sql.tab.c"
    break;

  case 143:
#line 1060 "yacc_sql.y"
                {
      (yyval.cur_len) = (yyvsp[0].cur_len);
	}
#line 2961 "yacc_sql.tab.c"
    break;

  case 144:
#line 1067 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->groupbys[CONTEXT->groupby_length++] = attr;
	}
#line 2971 "yacc_sql.tab.c"
    break;

  case 145:
#line 1074 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->groupbys[CONTEXT->groupby_length++] = attr;
	}
#line 2981 "yacc_sql.tab.c"
    break;

  case 146:
#line 1083 "yacc_sql.y"
                {
    (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
	}
#line 2989 "yacc_sql.tab.c"
    break;

  case 147:
#line 1087 "yacc_sql.y"
                {
    (yyval.cur_len) = 1;
	}
#line 2997 "yacc_sql.tab.c"
    break;

  case 148:
#line 1092 "yacc_sql.y"
                    {
    (yyval.cur_len) = 0;
  }
#line 3005 "yacc_sql.tab.c"
    break;

  case 149:
#line 1096 "yacc_sql.y"
                {
    (yyval.cur_len) = (yyvsp[0].cur_len) + 1;
	}
#line 3013 "yacc_sql.tab.c"
    break;

  case 150:
#line 1103 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3022 "yacc_sql.tab.c"
    break;


#line 3026 "yacc_sql.tab.c"

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
      yyerror (scanner, YY_("syntax error"));
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
        yyerror (scanner, yymsgp);
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
                      yytoken, &yylval, scanner);
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
                  yystos[yystate], yyvsp, scanner);
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
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, scanner);
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
#line 1108 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
