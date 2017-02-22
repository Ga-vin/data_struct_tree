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

#define    GET_FILE    (__FILE__)
#define    GET_LINE    (__LINE__)
#define    GET_FUNC    (__func__)

typedef unsigned int   UINT32;
typedef unsigned short UINT16;
typedef unsigned char  UINT8;
typedef int            INT32;
typedef short          INT16;
typedef char           INT8;
typedef INT32          BOOL;

#endif /* COMMON_TYPES_H_ */
