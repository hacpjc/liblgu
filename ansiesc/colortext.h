#ifndef ANSIESC_COLORTEXT_H_
#define ANSIESC_COLORTEXT_H_

#define CONFIG_USE_COLOR_TEXT (1)

#if CONFIG_USE_COLOR_TEXT
#define KNRM  "\x1B[0m" // Reset color
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#else
#define KNRM
#define KRED
#define KGRN
#define KYEL
#define KBLU
#define KMAG
#define KCYN
#define KWHT
#endif

#endif /* ANSIESC_COLORTEXT_H_ */