#pragma once
#include <QObject>
#include <QString>
#include "videoplaytool_global.h"


class VIDEOPLAYTOOL_EXPORT audioInfo {
	Q_OBJECT
public:
	struct  fileInfo {
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

		//����״̬
		enum PlayerState
	{
		Stopped //δ������ֹͣ״̬
		, Paused //��ͣ
		, Playing //����
	};
	Q_ENUM(PlayerState)

};

Q_DECLARE_METATYPE(audioInfo::fileInfo)
