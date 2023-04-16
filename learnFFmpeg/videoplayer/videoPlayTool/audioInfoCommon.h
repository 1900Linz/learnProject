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

		//播放状态
		enum PlayerState
		{
			Stopped //未操作，停止状态
			, Paused //暂停
			, Playing //播放
		};
		Q_ENUM(PlayerState)

	};

	struct  VIDEOPLAYTOOL_EXPORT fileInfo {
		//@文件名
		QString fileName; 

		//@文件路径
		QString filePath; 

		//@文件md5
		QString MD5; 

		//@格式，比如wav
		QString formart; 

		//@编解码器，比如ffmpeg
		QString codec;

		//@编码，比如pcm_sl6
		QString encodec;

		//@通道数
		int channels;

		//@采样率:hz
		//pcm时为每秒每个通道采样个数
		int sampleRate;

		//@采样精度:bit
		//s16则以signed short存储一个采样
		int sampleBit;

		//@文件大小
		qint64 fileSize;

		//@比特率:bps
		//比特率=采样率*单个的周期音频数据长度
		//pcm时16bit双声道48KHz音频的比特率：
		//48KHz * 16 * 2 = 1536kbps
		qint64 bitRate;

		//@音频时长，毫秒:ms
		qint64 duration;

		//@有效性标识，默认false
		bool vaild{ false };
	};

	class  VIDEOPLAYTOOL_EXPORT headFormat {
		Q_OBJECT
	public:
		//@文档标识，大写"RIFF"
		char riffFlag[4]; 

		//@文件格式标识，大写"WAVE"
		char waveFlag[4];

		//@格式块标识，小写"fmt
		char fmtFlag[4];

		//@表示数据开头，小写"data"
		char dataFlag[4];

		//@数据长度
		unsigned int riffSize; 

		//@格式块长度，可以是 16、 18 、20、40 等
		unsigned int fmtSize; 

		//@数据块对其单位存储每个采样值所用的二进制数位数。常见的位数有 4、8、12、16、24、32
		unsigned short blockAlign;

		//@采样位数（采样深度）
		unsigned short bitsPerSample;

		//@编码格式代码，1为pcm
		unsigned short compressionCode; 

		//@通道个数
		unsigned short numChannels;
		
		//@数据部分的长度
		unsigned int dataSize; 

		//@采样频率,估计缓冲区的大小,声道数×采样频率×每样本的数据位数/8
		unsigned int sampleRate; 

		//@码率（数据传输速率）,影响缓冲区大小，声道数×位数/8
		unsigned int bytesPerSecond; 

		//
		/**
		 * @brief 判断该文件格式头参数是否有效
		 * 主要用在读取并解析使用该头格式写的文件
		 * @return =true则格式有效
		 */
		virtual bool isValid() const = 0;

	};

};

Q_DECLARE_METATYPE(audioInfo::fileInfo)
