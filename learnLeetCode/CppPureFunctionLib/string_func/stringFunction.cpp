#include "pch.h"
#include "stringFunction.h"


//1. 使用引用传递字符串参数：
//	 函数中的strBig，strsrc和strdst都是字符串类型的参数，如果不使用引用传递参数，会导致频繁的字符串对象的复制，影响程序的性能。 
//2. 使用std::string::replace函数代替手动替换：
//   std::string::replace函数可以直接替换一个指定位置和长度的子串为另一个子串，比手动替换更简单高效。 
//3. 使用std::string::reserve函数预先分配内存：
//	 如果预先知道最终字符串的长度，可以使用std::string::reserve函数预先分配内存，减少字符串扩容和内存分配的次数，提高程序效率。
void stringFunction::string_replace(std::string& strBig, const std::string& strsrc, const std::string& strdst)
{
	const std::string::size_type srclen = strsrc.size(); 
	const std::string::size_type dstlen = strdst.size(); 
	if (srclen == 0 || strBig.empty()) 
	{
		// 源串或目标串为空则不替换 
		return; 
	} 
	
	const std::string::size_type Biglen = strBig.size(); 
	std::string::size_type pos = 0; 
	std::string::size_type count = 0;
	while ((pos = strBig.find(strsrc, pos)) != std::string::npos) 
	{ 
		// 做一次缩容，避免无用内存 
		strBig.replace(pos, srclen, strdst); pos += dstlen; count++; 
	} 

	if (count > 0 && Biglen - count * srclen + count * dstlen > 0)
	{ 
		strBig.resize(Biglen - count * srclen + count * dstlen); 
	}
}
