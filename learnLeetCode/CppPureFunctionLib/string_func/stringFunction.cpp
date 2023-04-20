#include "pch.h"
#include "stringFunction.h"


//1. ʹ�����ô����ַ���������
//	 �����е�strBig��strsrc��strdst�����ַ������͵Ĳ����������ʹ�����ô��ݲ������ᵼ��Ƶ�����ַ�������ĸ��ƣ�Ӱ���������ܡ� 
//2. ʹ��std::string::replace���������ֶ��滻��
//   std::string::replace��������ֱ���滻һ��ָ��λ�úͳ��ȵ��Ӵ�Ϊ��һ���Ӵ������ֶ��滻���򵥸�Ч�� 
//3. ʹ��std::string::reserve����Ԥ�ȷ����ڴ棺
//	 ���Ԥ��֪�������ַ����ĳ��ȣ�����ʹ��std::string::reserve����Ԥ�ȷ����ڴ棬�����ַ������ݺ��ڴ����Ĵ�������߳���Ч�ʡ�
void stringFunction::string_replace(std::string& strBig, const std::string& strsrc, const std::string& strdst)
{
	const std::string::size_type srclen = strsrc.size(); 
	const std::string::size_type dstlen = strdst.size(); 
	if (srclen == 0 || strBig.empty()) 
	{
		// Դ����Ŀ�괮Ϊ�����滻 
		return; 
	} 
	
	const std::string::size_type Biglen = strBig.size(); 
	std::string::size_type pos = 0; 
	std::string::size_type count = 0;
	while ((pos = strBig.find(strsrc, pos)) != std::string::npos) 
	{ 
		// ��һ�����ݣ����������ڴ� 
		strBig.replace(pos, srclen, strdst); pos += dstlen; count++; 
	} 

	if (count > 0 && Biglen - count * srclen + count * dstlen > 0)
	{ 
		strBig.resize(Biglen - count * srclen + count * dstlen); 
	}
}
