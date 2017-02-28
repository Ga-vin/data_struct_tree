/* ------------------------------------------------------------------------------------------------ */
/* File Name : common_types.h                                                                       */
/* ------------------------------------------------------------------------------------------------ */
/* Function  : Define some common data types and constances for using in other files                */
/* ------------------------------------------------------------------------------------------------ */
/* Time      : 2017.02.22                                                                           */
/* ------------------------------------------------------------------------------------------------ */
/* Author    : Gavin.Bai   gavin_8724@163.com                                                       */
/* ------------------------------------------------------------------------------------------------ */
/* License   : GPL                                                                                  */
/* ------------------------------------------------------------------------------------------------ */
/* Modify    :                                                                                      */
/* ------------------------------------------------------------------------------------------------ */
#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

#ifndef    TRUE
#define    TRUE    (0)
#endif /* TRUE */

#ifndef    FALSE
#define    FALSE    (-1)
#endif /* FALSE */

/*
 * These 3 macros can be used in occuring some return error, print then with other tips can help
 * programmer finding bug quickly.
 */
#define    GET_FILE    (__FILE__)
#define    GET_LINE    (__LINE__)
#define    GET_FUNC    (__func__)

/*
 * Make short name for build-in data type.
 */
typedef unsigned int   UINT32;
typedef unsigned short UINT16;
typedef unsigned char  UINT8;
typedef int            INT32;
typedef short          INT16;
typedef char           INT8;
typedef INT32          BOOL;

typedef INT32          ElementType;

#endif /* COMMON_TYPES_H_ */
