/*
 * reg_util.h
 *
 *  Created on:
 *  Author: nieki
 */

#ifndef REG_UTIL_H_
#define REG_UTIL_H_

/* Register bit manipulation macros */

#define REG_WRITE(reg, val)   					((reg) = (val))
#define REG_READ(reg)         					((reg))
#define REG_SET_BIT(reg,pos)   					((reg) |=  (1U << (pos)))
#define REG_CLR_BIT(reg,pos)    				((reg) &= ~(1U << (pos)))
#define REG_READ_BIT(reg,pos)    				((reg) &   (1U << (pos)))
#define REG_CLR_VAL(reg,clrmask,pos)   			((reg) &= ~((clrmask) << (pos)))
#define REG_SET_VAL(reg,val,setmask,pos) 		do {\
														REG_CLR_VAL(reg,setmask,pos);\
														((reg) |= ((val) << (pos))); \
												}while(0)

#define REG_READ_VAL(reg,rdmask,pos)            ((REG_READ(reg) >> (pos)) & (rdmask))


#endif /* REG_UTIL_H_ */
