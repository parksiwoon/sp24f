//설명: open 함수는 kvs_t 인스턴스를 생성하고 초기화
#include "kvs.h"


kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));

	if(kvs)
		kvs->items = 0;
	printf("%d\n", kvs->items);

	return kvs;
}