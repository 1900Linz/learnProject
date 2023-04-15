#pragma once
#include <QObject>
#include <QString>
#include "videoplaytool_global.h"


class VIDEOPLAYTOOL_EXPORT audioInfo {
	Q_OBJECT
public:
	struct  fileInfo {
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
	};

	enum CodecType
	{
		None
		, FFmpeg
		, SilkV3
		//,Sndfile
		//,Libav
	};
	Q_ENUM(CodecType)

		//播放状态
		enum PlayerState
	{
		Stopped //未操作，停止状态
		, Paused //暂停
		, Playing //播放
	};
	Q_ENUM(PlayerState)

};

Q_DECLARE_METATYPE(audioInfo::fileInfo)
