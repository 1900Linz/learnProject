#pragma once
#include <QObject>
#include <QMetaObject>
#include <QString>
#include "videoplaytool_global.h"

namespace audioInfo
{

	class VIDEOPLAYTOOL_EXPORT stateInfo {
		Q_OBJECT
	public:
		enum CodecType
		{
			None, 
			FFmpeg, 
			SilkV3,
			Sndfile,
			Libav
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

	struct  VIDEOPLAYTOOL_EXPORT fileInfo {
		//@�ļ���
		QString fileName; 

		//@�ļ�·��
		QString filePath; 

		//@�ļ�md5
		QString MD5; 

		//@��ʽ������wav
		QString formart; 

		//@�������������ffmpeg
		QString codec;

		//@���룬����pcm_sl6
		QString encodec;

		//@ͨ����
		int channels;

		//@������:hz
		//pcmʱΪÿ��ÿ��ͨ����������
		int sampleRate;

		//@��������:bit
		//s16����signed short�洢һ������
		int sampleBit;

		//@�ļ���С
		qint64 fileSize;

		//@������:bps
		//������=������*������������Ƶ���ݳ���
		//pcmʱ16bit˫����48KHz��Ƶ�ı����ʣ�
		//48KHz * 16 * 2 = 1536kbps
		qint64 bitRate;

		//@��Ƶʱ��������:ms
		qint64 duration;

		//@��Ч�Ա�ʶ��Ĭ��false
		bool vaild{ false };
	};

	class  VIDEOPLAYTOOL_EXPORT headFormat {
		Q_OBJECT
	public:
		//@�ĵ���ʶ����д"RIFF"
		char riffFlag[4]; 

		//@�ļ���ʽ��ʶ����д"WAVE"
		char waveFlag[4];

		//@��ʽ���ʶ��Сд"fmt
		char fmtFlag[4];

		//@��ʾ���ݿ�ͷ��Сд"data"
		char dataFlag[4];

		//@���ݳ���
		unsigned int riffSize; 

		//@��ʽ�鳤�ȣ������� 16�� 18 ��20��40 ��
		unsigned int fmtSize; 

		//@���ݿ���䵥λ�洢ÿ������ֵ���õĶ�������λ����������λ���� 4��8��12��16��24��32
		unsigned short blockAlign;

		//@����λ����������ȣ�
		unsigned short bitsPerSample;

		//@�����ʽ���룬1Ϊpcm
		unsigned short compressionCode; 

		//@ͨ������
		unsigned short numChannels;
		
		//@���ݲ��ֵĳ���
		unsigned int dataSize; 

		//@����Ƶ��,���ƻ������Ĵ�С,������������Ƶ�ʡ�ÿ����������λ��/8
		unsigned int sampleRate; 

		//@���ʣ����ݴ������ʣ�,Ӱ�컺������С����������λ��/8
		unsigned int bytesPerSecond; 

		//
		/**
		 * @brief �жϸ��ļ���ʽͷ�����Ƿ���Ч
		 * ��Ҫ���ڶ�ȡ������ʹ�ø�ͷ��ʽд���ļ�
		 * @return =true���ʽ��Ч
		 */
		virtual bool isValid() const = 0;

	};

};

Q_DECLARE_METATYPE(audioInfo::fileInfo)
