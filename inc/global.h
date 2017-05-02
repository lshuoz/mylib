/*
 * =====================================================================================
 *
 *       Filename:  global.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年05月02日 15时47分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lshuoz (), lshuoz.scu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include <stdio.h>
#include <stdlib.h>

#ifndef uchar
#define uchar unsigned char
#endif

#define PRINT_LOG(fmt,arg...) printf(fmt, ##arg)

#endif //__GLOBAL_H__
