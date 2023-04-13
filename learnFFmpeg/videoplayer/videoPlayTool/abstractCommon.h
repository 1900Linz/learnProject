#pragma once
#include <QString>
#include "videoplaytool_global.h"

struct VIDEOPLAYTOOL_EXPORT audioInfo{
	QString fileName; /*文件名*/ 
	QString filePath; /*文件路径*/ 
	QString MD5; /*文件md5值*/ 
	QString formart; /*格式，比如wav*/
	QString codec; /*编解码器，比如ffmpeg*/
	QString encodec; /*编码，比如pcm_sl6*/

	int channels;
	int sampleRate;
	int sampleBit;
	
	qint64 fileSize;
	qint64 bitRate;
	qint64 duration;

	bool vaild;

	//void printInfo();
};
