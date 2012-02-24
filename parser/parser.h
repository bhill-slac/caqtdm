#ifndef PARSER_H
#define PARSER_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <time.h>

#ifndef MAX
#define MAX(a,b)  ((a)>(b)?(a):(b))
#endif
#ifndef MIN
#define MIN(a,b)  ((a)<(b)?(a):(b))
#endif

#ifndef STRDUP
#define STRDUP(a) (strcpy( (char *)malloc(strlen(a)+1),a))
#endif

#define MAX_TOKEN_LENGTH        256     /* max size of strings in adl    */
#define MAX_PENS                8       /* max # of pens on strip chart  */
#define MAX_TRACES              8       /* max # of traces on cart. plot */
#define MAX_FILE_CHARS          256     /* max # of chars in filename    */
#define MAX_CALC_RECORDS        4       /* max # of records for calc     */
#define MAX_CALC_INPUTS         12      /* max # of inputs for calc      */
#define DL_MAX_COLORS           65      /* max # of colors for display   */
#define DL_COLORS_COLUMN_SIZE   5       /* # of colors in each column    */

#if MAX_CALC_RECORDS != 4
#error Need to make changes (CALC_A_RC, etc.) if MAX_CALC_RECORDS != 4
#endif

typedef struct {
    int x, y;
    unsigned int width, height;
} DlObject;

typedef struct {
   int frameX, frameY;
   int frameXprv, frameYprv; 
} FrameOffset;

typedef struct {
    int r, g, b;
    int inten;
} DlColormapEntry;

typedef struct {
    DlObject object;
    int clr, bclr;
    char cmap[MAX_TOKEN_LENGTH];
} DlDisplay;

typedef struct {
    int ncolors;
    DlColormapEntry dl_color[DL_MAX_COLORS];
} DlColormap;

#define X_AXIS_ELEMENT  0
#define Y1_AXIS_ELEMENT 1
#define Y2_AXIS_ELEMENT 2

/* Name-value table (for macro substitutions in display files) */
typedef struct {
    char *name;
    char *value;
} NameValueTable;

typedef struct _DisplayInfo {
    FILE *filePtr;
    //DlFile *dlFile;
    int versionNumber;
    int drawingAreaBackgroundColor;
    int drawingAreaForegroundColor;
    DlColormap  *dlColormap;
    NameValueTable *nameValueTable;
    int numNameValues;
} DisplayInfo;

typedef enum
{ T_WORD, T_EQUAL, T_QUOTE, T_LEFT_BRACE, T_RIGHT_BRACE, T_EOF} TOKEN;


#define MAX_RELATED_DISPLAYS    16
#define MAX_SHELL_COMMANDS      16
#define SC_DEFAULT_UNITS    SECONDS

#define True 1==1
#define False !True
#define Boolean unsigned int

#ifdef __cplusplus
}
#endif

#endif
