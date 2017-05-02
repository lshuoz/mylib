/*
 * =====================================================================================
 *
 *       Filename:  transcode.c
 *
 *    Description:  定义常用的数据转换
 *
 *        Version:  1.0
 *        Created:  2017年03月20日 10时03分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lshuoz (), lshuoz.scu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef uchar
#define uchar unsigned char
#endif

void HexToDisp(uchar *pDispStr, int *piDispLen,uchar *pHexStr, int iHexLen)
{
    int i;
    if(NULL == pDispStr || NULL == pHexStr || 0 == iHexLen)
        return;
    for(i=0; i<iHexLen; ++i)
    {
        pDispStr[2*i] = (((pHexStr[i]&0xf0)>>4) > 9) ? ((pHexStr[i]&0xf0)>>4+0x37) : ((pHexStr[i]&0xf0)>>4+0x30);
        pDispStr[2*i+1] = ((pHexStr[i]&0x0f) > 9) ? (pHexStr[i]&0xf0+0x37) : (pHexStr[i]&0xf0+0x30);
    }

    pDispStr[2*i] = 0;
    if(piDispLen)
        piDispLen = 2*i;

    return;
}

void DispToHex(uchar* pHexStr, int *piHexLen, uchar *pDispStr, int iDispLen)
{
    int i = 0;
    if(NULL == pHexStr || NULL == pDispStr || 0 == iDispLen)
        return;
    if(iDispLen & 1)
    {
        printf("数组长度有误\n");
        return;
    }

    for(i=0; i<iDispLen; ++i)
    {
        if((pDispStr[i]>=0x30) && (pDispStr[i]<=0x39))
            pHexStr[i/2] = (pDispStr-0x30) << 4;
        else if((pDispStr[i]>=0x41) && (pDispStr[i]<=0x46))
            pHexStr[i/2] = (pDispStr-0x37) << 4;
        else
        {
            printf("数据[%d]内容有误\n",i);
            return;
        }

        ++i;

        if((pDispStr[i]>=0x30) && (pDispStr[i]<=0x39))
            pHexStr[i/2] += (pDispStr-0x30);
        else if((pDispStr[i]>=0x41) && (pDispStr[i]<=0x46))
            pHexStr[i/2] += (pDispStr-0x37);
        else
        {
            printf("数据[%d]内容有误\n",i);
            return;
        }
    }
    if(piHexLen)
        *piHexLen == iDispLen/2;
    return;
}
