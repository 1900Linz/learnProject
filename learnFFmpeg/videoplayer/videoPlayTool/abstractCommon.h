#pragma once
#include <QString>
#include "videoplaytool_global.h"

struct VIDEOPLAYTOOL_EXPORT audioInfo{
	QString fileName; /*�ļ���*/ 
	QString filePath; /*�ļ�·��*/ 
	QString MD5; /*�ļ�md5ֵ*/ 
	QString formart; /*��ʽ������wav*/
	QString codec; /*�������������ffmpeg*/
	QString encodec; /*���룬����pcm_sl6*/

	int channels;
	int sampleRate;
	int sampleBit;
	
	qint64 fileSize;
	qint64 bitRate;
	qint64 duration;

	bool vaild;

	//void printInfo();
};
