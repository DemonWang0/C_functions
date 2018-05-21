#include <stdio.h>

#define BITMASK 0xFFFFU

int store_bit_field(int original_value, int value_to_store, 
		unsigned starting_bit, unsigned ending_bit)
{

	unsigned int i;
	unsigned int mask = 0;
	int returnValue;

	/* 创建掩码 */ 
	for (i = ending_bit; i <= starting_bit; i++)
	{
		mask |= (1 << i);
	}

	returnValue = original_value & (~mask); 	/* 清除原数值中需要被替代的位 */
	value_to_store <<= ending_bit; 	/* 将储存值与储存位对齐 */ 
	value_to_store &= mask; 		/* 保留存储值中需要储存的位 */ 
	returnValue |= value_to_store;

	return returnValue;
}


int main(void)
{
	int originValue, storeValue, result;
	unsigned int startBit, endBit;

	printf("Please input originValue: ");
	scanf("%x", &originValue);
	printf("Please input storeValue: ");
	scanf("%x", &storeValue);
	printf("Please input starting bit: ");
	scanf("%u", &startBit);
	printf("Please input ending bit: ");
	scanf("%u", &endBit);

	result = store_bit_field(originValue, storeValue, startBit, endBit);
	printf("result = %X\n", result);

	return 0;
}

