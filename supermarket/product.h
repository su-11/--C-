#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "flist.h"

//添加商品信息
void product_insert(FLIST** product,GOODS product_data);

//修改商品信息
void product_update(FLIST* product,int* num)

//查询商品信息
void product_select(FLIST* product);

//删除商品信息
void product_delete(FLIST** product);
#endif