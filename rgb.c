#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
//int型で送られたt,r,g,bをそれぞれ8bitずつに分割する
//tは8bit＊3分左にシフトする
//rは8bit＊2分左にシフトする
//gは8bit＊1分左にシフトする
//bは8bit＊0分左にシフトする

int	get_t(int trgb)
{
	return (trgb >> 24 & 0xFF);
}

int	get_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	get_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
//trgbを8bitずつに分割したものをそれぞれ取得する